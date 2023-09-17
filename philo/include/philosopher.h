/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:50:23 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/17 15:05:59 by yokitaga         ###   ########.fr       */
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

//各哲学者が持つデータを保持する構造体
typedef struct each_philo{
	size_t			id;
	size_t			eat_times;
	size_t			last_eat_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*time;
	void			*info;
	bool			*can_continue;
	size_t			ideal_time;
}	t_each_philo;

//哲学者の数や時間などのデータを保持する構造体
typedef struct info{
	size_t				num_of_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					finish_eating_count;
	bool				need_to_count;
	bool				can_continue;
	size_t				num_of_philo_finish_eating;
	size_t				start_time;
	t_each_philo		*all_philos;//各哲学者のデータを保持するための配列
	pthread_mutex_t		*fork;//各哲学者が持つフォークを保持するための配列
	pthread_mutex_t		*time;//時間を取得するためのmutex
	pthread_t     		*thread;//各哲学者のスレッドを保持するための配列
	pthread_mutex_t		end_flag;//全哲学者が食事を終えたかどうかを判定するためのmutex
	pthread_mutex_t		count_meals;//食事回数をカウントするためのmutex
	pthread_mutex_t		write;
}	t_info;

//監視用のデータを保持する構造体

//関数一覧
//utils.c
bool	error_msg(char *message);
size_t	ft_atoi(char *str);
int		free_all(t_info *all_info);
//1_check_input.c
bool	check_input(int argc, char **argv);
//2_init_data.c
void    set_arg(t_info *all_info, int argc, char **argv);
size_t  get_current_time(void);
bool    set_other_info(t_info *all_info);
bool	init_data(t_info *all_info, int argc, char **argv);
//3_init_mutex.c
bool	init_mutex(t_info *all_info);
//4_init_philo.c
void	set_ideal_time(t_each_philo *philo, t_info *all_info);
void	init_each_philo(t_info *all_info);
//5_start_philo.c




#endif