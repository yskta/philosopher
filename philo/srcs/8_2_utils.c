/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_2_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:10:44 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/24 13:20:30 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"	

void    print_time_and_routine(t_info *all_info, size_t id, size_t routine, int color)
{
	size_t  current_time;

	pthread_mutex_lock(&all_info->write);
	current_time = get_current_time();
	if (routine == NUM_TAKE_FORK && judge_continue(all_info))
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