/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:50:23 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/23 13:19:09 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//メモ
//コンパイル時：CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

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

# define RED 	31
# define GREEN	32
# define YELLOW	33
# define BLUE	34
# define GRAY	37

//各哲学者が持つデータを保持する構造体
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

//哲学者の数や時間などのデータを保持する構造体
typedef struct info{
	size_t				num_of_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				finish_eating_count;//食事する回数
	bool				need_to_count;//食事回数をカウントするかどうか
	bool				can_continue;//全哲学者が生きてるかどうか→falseなら終了。monitorで監視
	size_t				num_of_philo_finish_eating;//食事を終えた哲学者の数
	t_each_philo		*all_philos;//各哲学者のデータを保持するための配列
	pthread_mutex_t		*fork;//各哲学者が持つフォークを保持するための配列
	pthread_mutex_t		*time;//時間を取得するためのmutex。monitorも哲学者も使う。ここでだけphilo->last_eat_timeを更新/アクセスする。
	pthread_t     		*thread;//各哲学者のスレッドを保持するための配列
	pthread_t			monitor;//監視用のスレッド
	pthread_mutex_t		end_flag;//このmutexでlockした時だけ、can_continueを編集する。
	pthread_mutex_t		count_meals;//食事回数をカウントするためのmutex
	pthread_mutex_t		write;
}	t_info;


//関数一覧
//1_check_input.c
bool	check_input(int argc, char **argv);
//2_init_data.c
void    set_arg(t_info *all_info, int argc, char **argv);
bool    set_other_info(t_info *all_info);
bool	init_info(t_info *all_info, int argc, char **argv);
//3_init_mutex.c
bool	init_mutex(t_info *all_info);
//4_init_philo.c
//void	set_ideal_time(t_each_philo *philo, t_info *all_info);
void	init_each_philo(t_info *all_info);
//5_all_about_thread.c
bool	all_about_thread(t_info *all_info);
//6_1_philo_routine.c
void	wait_time(size_t time_to_wait);
void	wait_for_die(t_each_philo *philo);
void	*philo_routine(void *each_philo);

//6_2_each_routine.c
void	take_fork_routine(t_each_philo *philo, t_info *all_info);
void	eat_count_check(t_each_philo *philo, t_info *all_info);
void	eat_routine(t_each_philo *philo, t_info *all_info);
void	sleep_routine(t_each_philo *philo, t_info *all_info);
void	think_routine(t_each_philo *philo, t_info *all_info);

//7_monitor.c
void	*monitor(void *all_info);
bool	death_check(size_t current_time, size_t start_time, t_each_philo *philo);
bool	judge_die_latest(size_t current_time, size_t last_eat_time, t_each_philo *philo, t_info *info);
bool	judge_die_start(size_t current_time,size_t start_time, t_each_philo *philo, t_info *info);

//utils.c
bool	error_msg(char *message);
size_t	ft_atoi(char *str);
int		free_all(t_info *all_info);
int 	free_and_destroy_all(t_info *all_info);
size_t  get_current_time(void);
void    print_time_and_routine(t_info *all_info, size_t id, size_t routine, int color);
bool	judge_continue(t_info *all_info);







#endif