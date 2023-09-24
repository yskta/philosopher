/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:50:23 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/24 13:21:55 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define NUM_TAKE_FORK 0
# define NUM_EAT 1
# define NUM_SLEEP 2
# define NUM_THINK 3
# define NUM_DIE 4

# define RED		31
# define GREEN		32
# define YELLOW		33
# define BLUE		34
# define MAZENTA	35

typedef struct each_philo{
	size_t			id;
	size_t			eat_times;
	size_t			last_eat_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*time;
	void			*all_info;
	bool			*can_continue;
}	t_each_philo;

typedef struct info{
	size_t				num_of_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				finish_eating_count;
	bool				need_to_count;
	bool				can_continue;
	size_t				num_of_philo_finish_eating;
	t_each_philo		*all_philos;
	pthread_mutex_t		*fork;
	pthread_mutex_t		*time;
	pthread_t     		*thread;
	pthread_t			monitor;
	pthread_mutex_t		end_flag;
	pthread_mutex_t		count_meals;
	pthread_mutex_t		write;
}	t_info;


bool	check_input(int argc, char **argv);
void    set_arg(t_info *all_info, int argc, char **argv);
bool    set_other_info(t_info *all_info);
bool	init_info(t_info *all_info, int argc, char **argv);
bool	init_mutex(t_info *all_info);
void	init_each_philo(t_info *all_info);
bool	all_about_thread(t_info *all_info);
void	wait_time(size_t time_to_wait);
void	wait_for_die(t_each_philo *philo);
void	*philo_routine(void *each_philo);
void	take_fork_routine(t_each_philo *philo, t_info *all_info);
void	eat_count_check(t_each_philo *philo, t_info *all_info);
void	eat_routine(t_each_philo *philo, t_info *all_info);
void	sleep_routine(t_each_philo *philo, t_info *all_info);
void	think_routine(t_each_philo *philo, t_info *all_info);
void	*monitor(void *all_info);
bool	death_check(size_t current_time, size_t start_time, t_each_philo *philo);
bool	judge_die_latest(size_t current_time, size_t last_eat_time, t_each_philo *philo, t_info *info);
bool	judge_die_start(size_t current_time,size_t start_time, t_each_philo *philo, t_info *info);
bool	error_msg(char *message);
size_t	ft_atoi(char *str);
int		free_all(t_info *all_info);
int 	free_and_destroy_all(t_info *all_info);
size_t  get_current_time(void);
void    print_time_and_routine(t_info *all_info, size_t id, size_t routine, int color);
bool	judge_continue(t_info *all_info);

#endif