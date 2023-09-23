/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_monitor_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:48:47 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/23 15:36:10 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	*monitor(void *all_info)
{
	t_info	*info;
	size_t	i;
	size_t	current_time;
	size_t	start_time;

	info = (t_info *)all_info;
	start_time = get_current_time();
	while (judge_continue(info))
	{	
		i = 0;
		while (i < info->num_of_philo)
		{
			current_time = get_current_time();
			if (death_check(current_time, start_time, &info->all_philos[i]) == false)
				break ;
			i++;
		}
		if (judge_continue(info) == false)
			break ;
		usleep(500);
	}
	return (NULL);
}

bool	death_check(size_t current_time, size_t start_time, t_each_philo *philo)
{
	t_info	*all_info;
	size_t	last_eat_time;

	all_info = (t_info *)philo->all_info;
	pthread_mutex_lock(philo->time);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(philo->time);
	if (last_eat_time != 0)
		return(judge_die_latest(current_time, last_eat_time, philo, all_info));
	return(judge_die_start(current_time, start_time, philo, all_info));
}

bool	judge_die_latest(size_t current_time, size_t last_eat_time, t_each_philo *philo, t_info *all_info)
{
	if (current_time - last_eat_time >= all_info->time_to_die)
	{
		print_time_and_routine(all_info, philo->id, NUM_DIE, RED);
		pthread_mutex_lock(&all_info->end_flag);
		all_info->can_continue = false;
		pthread_mutex_unlock(&all_info->end_flag);
		return (false);
	}
	return (true);
}

bool	judge_die_start(size_t current_time,size_t start_time, t_each_philo *philo, t_info *all_info)
{
	if (current_time - start_time >= all_info->time_to_die)
	{
		print_time_and_routine(all_info, philo->id, NUM_DIE, RED);
		pthread_mutex_lock(&all_info->end_flag);
		all_info->can_continue = false;
		pthread_mutex_unlock(&all_info->end_flag);
		return (false);
	}
	return (true);
}