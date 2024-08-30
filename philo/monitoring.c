/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:12:24 by ajovanov          #+#    #+#             */
/*   Updated: 2024/08/26 19:12:26 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "piloshopers.h"

int	monitor_loop_util2(t_struct *common_var, int currenttime, int timeke, int i)
{
	long int	timestamp;

	timestamp = 0;
	while (check_everybody_has_aten(common_var) == 0)
	{
		currenttime = time_calc(currenttime);
		pthread_mutex_lock(&common_var->meal_check);
		pthread_mutex_lock(&common_var->eat);
		timeke = common_var->last_meal_times[i];
		pthread_mutex_unlock(&common_var->eat);
		if (currenttime - timeke
			>= common_var->time_die && timeke != 0)
		{
			timestamp_calc(&timestamp, common_var);
			pthread_mutex_lock(&common_var->monitor);
			printf("%ld %d is died\n", timestamp + common_var->passent, i + 1);
			pthread_mutex_unlock(&common_var->monitor);
			pthread_mutex_unlock(&common_var->meal_check);
			return (1);
		}
		pthread_mutex_unlock(&common_var->meal_check);
		return (0);
	}
	return (0);
}

int	monitor_loop(t_struct *common_var, int i)
{
	long int	currenttime;
	long int	timeke;

	currenttime = 0;
	timeke = 0;
	pthread_mutex_lock(&common_var->eat);
	if (common_var->last_meal_times[i] == 0)
		common_var->last_meal_times[i]
			= time_calc(common_var->last_meal_times[i]);
	pthread_mutex_unlock(&common_var->eat);
	if (monitor_loop_util2(common_var, currenttime, timeke, i) == 1)
		return (1);
	return (0);
}

int	monitor_util(t_struct *common_var)
{
	int	i;

	i = 0;
	while (i++ < common_var->nb_filos - 1)
	{
		if (monitor_loop(common_var, i) == 1)
		{
			pthread_mutex_lock(&common_var->monitor);
			common_var->game_over = 1;
			pthread_mutex_unlock(&common_var->monitor);
			return (0);
		}
		if (check_everybody_has_aten(common_var) == 1)
		{
			pthread_mutex_lock(&common_var->monitor);
			common_var->game_over = 1;
			pthread_mutex_unlock(&common_var->monitor);
		}
	}
	return (0);
}

void	*monitor_philos(void *arg)
{
	t_struct	*common_var;
	int			game_over;

	common_var = (t_struct *)arg;
	game_over = 0;
	while (!game_over)
	{
		pthread_mutex_lock(&common_var->monitor);
		game_over = common_var->game_over;
		pthread_mutex_unlock(&common_var->monitor);
		usleep(100);
		monitor_util(common_var);
		pthread_mutex_lock(&common_var->monitor);
		game_over = common_var->game_over;
		pthread_mutex_unlock(&common_var->monitor);
	}
	return (NULL);
}

void	uninterrupted_thinking(t_struct *common_var,
			int print_id, int thisphilo)
{
	long int	timestamp;

	timestamp_calc(&timestamp, common_var);
	pthread_mutex_lock(&common_var->monitor);
	if (common_var->game_over != 1
		&& common_var->philos[thisphilo].this_philo_need_to_eat != 0)
		printf("%ld %d is thinking\n", timestamp, print_id);
	pthread_mutex_unlock(&common_var->monitor);
}
