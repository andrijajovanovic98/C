/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:37:46 by ajovanov          #+#    #+#             */
/*   Updated: 2024/08/26 18:37:49 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "piloshopers.h"

long int	time_calc(long int time)
{
	struct timeval	gettime;

	gettimeofday(&gettime, NULL);
	time = (gettime.tv_sec * 1000) + gettime.tv_usec / 1000;
	return (time);
}

void	timestamp_calc(long int *timestamp, t_struct *common_var)
{
	*timestamp = time_calc(*timestamp);
	*timestamp = *timestamp - common_var->start_time;
}

void	ft_mysleep(int time, t_struct *common_var)
{
	long int	start_time;
	long int	current_time;

	start_time = 0;
	current_time = 0;
	start_time = time_calc(start_time);
	current_time = time_calc(current_time);
	while (current_time - start_time < time)
	{
		pthread_mutex_lock(&common_var->monitor);
		if (common_var->game_over == 1)
		{
			pthread_mutex_unlock(&common_var->monitor);
			return ;
		}
		pthread_mutex_unlock(&common_var->monitor);
		usleep(100);
		current_time = time_calc(current_time);
	}
}

void	free_everything(t_struct *common_var, pthread_t *threads)
{
	if (common_var->forks != NULL)
		free(common_var->forks);
	if (threads != NULL)
		free(threads);
	if (common_var->philos != NULL)
		free(common_var->philos);
	if (common_var->last_meal_times != NULL)
		free(common_var->last_meal_times);
}

void	destroying(t_struct *common_var)
{
	int	c;

	c = -1;
	while (++c < common_var->nb_filos)
		pthread_mutex_destroy(&common_var->forks[c]);
	pthread_mutex_destroy(&common_var->meal_check);
	pthread_mutex_destroy(&common_var->monitor);
}
