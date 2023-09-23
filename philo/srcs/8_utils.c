/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:29:48 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/23 12:42:13 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

bool error_msg(char *message)
{
    printf("%s\n", message);
    return (false);
}

size_t ft_atoi(char *str)
{
    size_t  num;
    size_t  i;

    num = 0;
    i = 0;
    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num);
}

int free_all(t_info *all_info)
{
    //free系
    if (all_info->all_philos)
        free(all_info->all_philos);
    if (all_info->fork)
        free(all_info->fork);
    if (all_info->time)
        free(all_info->time);
    if (all_info->thread)
        free(all_info->thread);
    free(all_info);
    return (1);
}

int free_and_destroy_all(t_info *all_info)
{
    size_t i;

    i = 0;
    //mutexの解放
    while (i < all_info->num_of_philo)
    {
        pthread_mutex_destroy(&all_info->fork[i]);
        pthread_mutex_destroy(&all_info->time[i]);
        i++;
    }
    pthread_mutex_destroy(&all_info->end_flag);
    pthread_mutex_destroy(&all_info->count_meals);
    pthread_mutex_destroy(&all_info->write);
    //free系
    if (all_info->all_philos)
        free(all_info->all_philos);
    if (all_info->fork)
        free(all_info->fork);
    if (all_info->time)
        free(all_info->time);
    if (all_info->thread)
        free(all_info->thread);
    free(all_info);
    return (1);
}

size_t  get_current_time(void)
{
    struct timeval  time;
    size_t          current_time;

    if (gettimeofday(&time, NULL) == -1)
        return (0);
    current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (current_time);
}

void    print_time_and_routine(t_info *all_info, size_t id, size_t routine, int color)
{
	size_t  current_time;

    //複数の哲学者スレッドがアクセスするので、ロックする
	pthread_mutex_lock(&all_info->write);
	current_time = get_current_time();
	if (routine == NUM_TAKE_FORK && judge_continue(all_info))//int colorを使って色を変える
        printf("\x1b[%dm%zu %zu has taken a fork\x1b[0m\n", color, current_time, id);
	else if (routine == NUM_EAT && judge_continue(all_info))
		printf("\x1b[%dm%zu %zu is eating\x1b[0m\n", color, current_time, id);
	else if (routine == NUM_SLEEP && judge_continue(all_info))
		printf("\x1b[%dm%zu %zu is sleeping\x1b[0m\n", color, current_time, id);
	else if (routine == NUM_THINK && judge_continue(all_info))
		printf("\x1b[%dm%zu %zu is thinking\x1b[0m\n", color, current_time, id);
	else if (routine == NUM_DIE && judge_continue(all_info))
		printf("\x1b[%dm%zu %zu died\x1b[0m\n", color, current_time, id);
	pthread_mutex_unlock(&all_info->write);
	return ;
}

bool	judge_continue(t_info *all_info)
{
    pthread_mutex_lock(&all_info->end_flag);
	if (all_info->can_continue == false)
    {
        pthread_mutex_unlock(&all_info->end_flag);
        return (false);
    }
    pthread_mutex_unlock(&all_info->end_flag);
    return (true);
}




