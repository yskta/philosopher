/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_2_each_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:31:52 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/24 13:19:59 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	take_fork_routine(t_each_philo *philo, t_info *all_info)
{
	pthread_mutex_lock(philo->right_fork);
	print_time_and_routine(all_info, philo->id, NUM_TAKE_FORK, GREEN);
	pthread_mutex_lock(philo->left_fork);
	print_time_and_routine(all_info, philo->id, NUM_TAKE_FORK, GREEN);
}

void	eat_count_check(t_each_philo *philo, t_info *all_info)
{
	pthread_mutex_lock(&all_info->end_flag);
	if (philo->eat_times == all_info->finish_eating_count)
		all_info->num_of_philo_finish_eating++;
	if (all_info->num_of_philo_finish_eating == all_info->num_of_philo)
		all_info->can_continue = false;
	pthread_mutex_unlock(&all_info->end_flag);
}

void	eat_routine(t_each_philo *philo, t_info *all_info)
{
	pthread_mutex_lock(philo->time);
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(philo->time);
	print_time_and_routine(all_info, philo->id, NUM_EAT, BLUE);
	if (all_info->need_to_count)
	{
		philo->eat_times++;
		eat_count_check(philo, all_info);
	}
	wait_time(all_info->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_routine(t_each_philo *philo, t_info *all_info)
{
	print_time_and_routine(all_info, philo->id, NUM_SLEEP, MAZENTA);
	wait_time(all_info->time_to_sleep);
}

void	think_routine(t_each_philo *philo, t_info *all_info)
{
	print_time_and_routine(all_info, philo->id, NUM_THINK, YELLOW);
}