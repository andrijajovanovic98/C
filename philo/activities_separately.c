/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities_separately.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:27:51 by ajovanov          #+#    #+#             */
/*   Updated: 2024/08/26 18:27:54 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "piloshopers.h"

void	uninterrupted_meal(t_struct *common_var, int thisphilo, int print_id)
{
	long int	timestamp;

	timestamp_calc(&timestamp, common_var);
	pthread_mutex_lock(&common_var->monitor);
	if (common_var->game_over != 1
		&& common_var->philos[thisphilo].this_philo_need_to_eat != 0)
		printf("%ld %d is eating\n", timestamp, print_id);
	pthread_mutex_unlock(&common_var->monitor);
	pthread_mutex_lock(&common_var->eat);
	common_var->last_meal_times[thisphilo]
		= time_calc(common_var->last_meal_times[thisphilo]);
	pthread_mutex_unlock(&common_var->eat);
	ft_mysleep(common_var->time_eat, common_var);
}

void	uninterrupted_sleep(t_struct *common_var, int print_id, int thisphilo)
{
	long int	timestamp;

	timestamp_calc(&timestamp, common_var);
	pthread_mutex_lock(&common_var->monitor);
	if (common_var->game_over != 1
		&& common_var->philos[thisphilo].this_philo_need_to_eat != 0)
		printf("%ld %d is sleeping\n", timestamp, print_id);
	pthread_mutex_unlock(&common_var->monitor);
	ft_mysleep(common_var->time_sleep, common_var);
}

void	uninterrupted_unlock(t_struct *common_var, int thisphilo)
{
	int	left_fork;
	int	right_fork;

	left_fork = thisphilo;
	right_fork = (thisphilo + 1) % common_var->nb_filos;
	if (left_fork < right_fork)
	{
		pthread_mutex_unlock(&common_var->forks[right_fork]);
		pthread_mutex_unlock(&common_var->forks[left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&common_var->forks[left_fork]);
		pthread_mutex_unlock(&common_var->forks[right_fork]);
	}
}

void	uninterrupted_couting_and_finishing(t_struct *common_var, int thisphilo)
{
	pthread_mutex_lock(&common_var->monitor);
	if (common_var->philos[thisphilo].this_philo_need_to_eat > 0 && common_var->philos[thisphilo].this_philo_need_to_eat != 999)
		common_var->philos[thisphilo].this_philo_need_to_eat--;
	pthread_mutex_unlock(&common_var->monitor);
	if (check_everybody_has_aten(common_var) == 1)
	{
		pthread_mutex_lock(&common_var->monitor);
		common_var->philos[thisphilo].game_over = 1;
		pthread_mutex_unlock(&common_var->monitor);
	}
}

void	uninterrupted_taking_the_forks(t_struct *common_var, int print_id)
{
	long int	timestamp;

	timestamp_calc(&timestamp, common_var);
	pthread_mutex_lock(&common_var->monitor);
	if (common_var->game_over != 1)
	{
		printf("%ld %d has taken a fork\n", timestamp, print_id);
		printf("%ld %d has taken a fork\n", timestamp, print_id);
	}
	pthread_mutex_unlock(&common_var->monitor);
}
