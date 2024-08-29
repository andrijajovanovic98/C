/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:48:27 by ajovanov          #+#    #+#             */
/*   Updated: 2024/08/28 12:48:29 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "piloshopers.h"

int	check_everybody_has_aten(t_struct *common_var)
{
	int	i;
	int	has_eaten;
	int	testke;

	i = 0;
	has_eaten = 0;
	pthread_mutex_lock(&common_var->monitor);
	testke = common_var->philos[i].this_philo_need_to_eat;
	if (common_var->nb_filos > 100)
		testke = common_var->philos
		[common_var->nb_filos - 1].this_philo_need_to_eat;
	pthread_mutex_unlock(&common_var->monitor);
	while (i < common_var->nb_filos)
	{
		if (testke == 0)
			has_eaten++;
		i++;
	}
	if (has_eaten == common_var->nb_filos)
	{
		return (1);
	}
	return (0);
}

void	just_one_philo(t_struct *common_var, int print_id)
{
	ft_mysleep(common_var->time_die, common_var);
	printf("%d %d is died\n", common_var->time_die, print_id);
	pthread_mutex_lock(&common_var->monitor);
	common_var->game_over = 1;
	pthread_mutex_unlock(&common_var->monitor);
}

void	uninterrupted_activites(t_struct *common_var,
			int thisphilo, int print_id)
{
	uninterrupted_meal(common_var, thisphilo, print_id);
	uninterrupted_couting_and_finishing(common_var, thisphilo);
	uninterrupted_unlock(common_var, thisphilo);
	uninterrupted_sleep(common_var, print_id, thisphilo);
	uninterrupted_thinking(common_var, print_id, thisphilo);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]) && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
