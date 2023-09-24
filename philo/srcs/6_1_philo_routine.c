/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_1_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:38:08 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/24 13:18:51 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	wait_time(size_t time_to_wait)
{
	size_t	start_time;
	size_t	current_time;

	start_time = get_current_time();
	while (1)
	{
		current_time = get_current_time();
		if (current_time - start_time >= time_to_wait)
			return ;
		usleep(500);
	}
}

void	wait_for_die(t_each_philo *philo)
{
	t_info	*all_info;
	size_t	start_time;
	size_t	current_time;
	
	all_info = (t_info *)philo->all_info;
	print_time_and_routine(all_info, philo->id, NUM_TAKE_FORK, GREEN);
	start_time = get_current_time();
	while (1)
	{
		current_time = get_current_time();
		if (current_time - start_time >= all_info->time_to_die)
		{
			print_time_and_routine(all_info, philo->id, NUM_DIE, RED);
			pthread_mutex_lock(&all_info->end_flag);
			all_info->can_continue = false;
			pthread_mutex_unlock(&all_info->end_flag);
			return ;
		}
		usleep(500);
	}
	return ;
}

void	*philo_routine(void *each_philo)
{
	t_each_philo	*philo;
	t_info			*all_info;

	philo = (t_each_philo *)each_philo;
	all_info = philo->all_info;
	if (philo->id % 2 == 0)
		usleep(500);
	if (all_info->num_of_philo == 1)
	{
		wait_for_die(philo);
		return NULL;
	}
	while (judge_continue(all_info) == true)
	{
		take_fork_routine(philo, all_info);
		eat_routine(philo, all_info);
		sleep_routine(philo, all_info);
		think_routine(philo, all_info);
	}
	return (NULL);
}