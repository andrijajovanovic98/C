/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:36:17 by ajovanov          #+#    #+#             */
/*   Updated: 2024/08/26 18:36:19 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "piloshopers.h"

void	convert_args_and_init(t_struct *common_var, char **argv)
{
	common_var->nb_eats = 999;
	if (argv[5] == NULL)
		common_var->infinity = 1;
	common_var->nb_filos = ft_atoi(argv[1]);
	common_var->time_die = ft_atoi(argv[2]);
	common_var->time_eat = ft_atoi(argv[3]);
	common_var->time_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		common_var->nb_eats = ft_atoi(argv[5]);
	common_var->game_over = 0;
	common_var->forkunlockrichtung = 1;
	common_var->stop_print = 1;
	common_var->just_one_philo = 0;
	common_var->passent = 0;
	justone(common_var);
}

int	init_forks(t_struct *common_var)
{
	int	i;

	i = -1;
	common_var->forks = malloc(sizeof(pthread_mutex_t) * common_var->nb_filos);
	if (!common_var->forks)
		return (1);
	while (++i < common_var->nb_filos)
		if (pthread_mutex_init(&common_var->forks[i], NULL) != 0)
			return (write(2, "Mutex init failed\n", 18), 1);
	return (0);
}

int	creating_philos(t_struct *common_var, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < common_var->nb_filos)
	{
		common_var->philos[i].print_id = i + 1;
		common_var->philos[i].id = i;
		common_var->philos[i].common_var = common_var;
		common_var->philos[i].this_philo_need_to_eat = common_var->nb_eats;
		if (pthread_create(&threads[i], NULL, filos,
				&common_var->philos[i]) != 0)
		{
			pthread_mutex_lock(&common_var->monitor);
			common_var->game_over = 1;
			pthread_mutex_unlock(&common_var->monitor);
			while (i--)
				pthread_join(threads[i], NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

void	join_threads(pthread_t *threads, int nb_filos)
{
	int	i;

	i = 0;
	while (i < nb_filos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
