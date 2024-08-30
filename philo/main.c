/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:39:35 by ajovanov          #+#    #+#             */
/*   Updated: 2024/08/26 18:39:38 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "piloshopers.h"

int	decide_to_eat(t_struct *common_var, int thisphilo, int print_id)
{
	int			left_fork;
	int			right_fork;

	if (onephilo_util(common_var) == 1)
		return (1);
	left_fork = thisphilo;
	right_fork = (thisphilo + 1) % common_var->nb_filos;
	if (thisphilo % 2 == 0)
		usleep(1000);
	else
		usleep(500);
	if (common_var->time_eat / common_var->time_sleep == 2)
		usleep(100000);
	if (left_fork < right_fork)
	{
		pthread_mutex_lock(&common_var->forks[left_fork]);
		pthread_mutex_lock(&common_var->forks[right_fork]);
	}
	else
	{
		pthread_mutex_lock(&common_var->forks[right_fork]);
		pthread_mutex_lock(&common_var->forks[left_fork]);
	}
	uninterrupted_taking_the_forks(common_var, print_id);
	return (0);
}

void	*filos(void *arg)
{
	t_philo_args	*philo;
	t_struct		*common_var;
	int				thisphilo;
	int				print_id;
	int				game_over;

	game_over = 0;
	philo = (t_philo_args *)arg;
	common_var = philo->common_var;
	thisphilo = philo->id;
	print_id = philo->print_id;
	while (!game_over)
	{
		pthread_mutex_lock(&common_var->monitor);
		game_over = common_var->game_over;
		pthread_mutex_unlock(&common_var->monitor);
		if (decide_to_eat(common_var, thisphilo, philo->print_id) == 1)
			break ;
		uninterrupted_activites(common_var, thisphilo, print_id);
	}
	if (common_var->just_one_philo == 1)
		just_one_philo(common_var, print_id);
	return (0);
}

void	looping_philos(t_struct *common_var)
{
	pthread_t	monitor_thread;
	pthread_t	*threads;

	common_var->philos = malloc(sizeof(t_philo_args) * common_var->nb_filos);
	if (!common_var->philos)
		return (free_everything(common_var, NULL), (void)0);
	threads = malloc(sizeof(pthread_t) * common_var->nb_filos);
	if (!threads)
		return (free_everything(common_var, NULL), (void)0);
	if (pthread_mutex_init(&common_var->meal_check, NULL) != 0)
		return (free_everything(common_var, threads), (void)0);
	if (pthread_mutex_init(&common_var->eat, NULL) != 0)
		return (free_everything(common_var, threads), (void)0);
	if (pthread_mutex_init(&common_var->monitor, NULL) != 0)
		return (free_everything(common_var, threads), (void)0);
	if (creating_philos(common_var, threads) == 1)
		return (free_everything(common_var, threads), (void)0);
	if (pthread_create(&monitor_thread, NULL, monitor_philos, common_var) != 0)
		return (free_everything(common_var, threads), (void)0);
	pthread_join(monitor_thread, NULL);
	join_threads(threads, common_var->nb_filos);
	destroying(common_var);
	free_everything(common_var, threads);
}

int	tryingtoinitmeal(t_struct *common_var)
{
	int	i;

	i = 0;
	common_var->last_meal_times
		= malloc(sizeof(long int) * common_var->nb_filos);
	if (common_var->last_meal_times == NULL)
		return (1);
	while (i < common_var->nb_filos)
	{
		common_var->last_meal_times[i] = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	common_var;

	if (check_and_init_args(argc, argv) == 1)
		return (1);
	convert_args_and_init(&common_var, argv);
	if (init_forks(&common_var) == 1)
		return (1);
	if (tryingtoinitmeal(&common_var) == 1)
		return (free(common_var.forks), 1);
	common_var.start_time = time_calc(common_var.start_time);
	looping_philos(&common_var);
	return (0);
}
