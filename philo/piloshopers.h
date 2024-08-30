/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piloshopers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:12:14 by ajovanov          #+#    #+#             */
/*   Updated: 2024/08/26 19:12:17 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philo_args
{
	int				id;
	int				this_philo_need_to_eat;
	int				print_id;
	int				game_over;
	int				forkunlockrichtung;
	int				philo_game_over;
	struct s_struct	*common_var;
}				t_philo_args;

typedef struct s_struct
{
	int				passent;
	long int		start_time;
	int				forkunlockrichtung;
	int				time;
	int				i;
	int				nb_filos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eats;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	monitor;
	pthread_mutex_t	eat;
	int				stop_print;
	long int		*last_meal_times;
	int				game_over;
	int				philoid;
	int				just_one_philo;
	t_philo_args	*philos;
}				t_struct;

void		get_time(struct timeval *time);
void		*monitor_philos(void *arg);
int			check_and_init_args(int argc, char **argv);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// Check Argumentums

int			is_number(char num);
int			in_range(int num);
long int	ft_atoi(char *str);

// Creating and init

int			creating_philos(t_struct *common_var, pthread_t *threads);
void		join_threads(pthread_t *threads, int nb_filos);
int			init_forks(t_struct *common_var);
void		convert_args_and_init(t_struct *common_var, char **argv);

// philos

void		*filos(void *arg);
int			onephilo_util(t_struct *common_var);

// time

long int	time_calc(long int time);
void		timestamp_calc(long int *timestamp, t_struct *common_var);
void		ft_mysleep(int time, t_struct *common_var);

//activities_separately

void		uninterrupted_meal(t_struct *common_var,
				int thisphilo, int print_id);
void		uninterrupted_sleep(t_struct *common_var,
				int print_id, int thisphilo);
void		uninterrupted_unlock(t_struct *common_var, int thisphilo);
void		uninterrupted_couting_and_finishing(t_struct *common_var,
				int thisphilo);
void		uninterrupted_taking_the_forks(t_struct *common_var, int print_id);
void		uninterrupted_thinking(t_struct *common_var,
				int print_id, int thisphilo);
void		uninterrupted_activites(t_struct *common_var,
				int thisphilo, int print_id);

// monitoring

void		*monitor_philos(void *arg);
int			check_everybody_has_aten(t_struct *common_var);
void		just_one_philo(t_struct *common_var, int print_id);

// free && destroy

void		free_everything(t_struct *common_var, pthread_t *threads);
void		destroying(t_struct *common_var);
