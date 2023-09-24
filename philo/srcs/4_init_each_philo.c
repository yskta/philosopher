/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_each_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:16:55 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/24 13:18:42 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void    init_each_philo(t_info *all_info)
{
	size_t i;
	t_each_philo *philos;

	philos = all_info->all_philos;
	i = 0;
	while (i < all_info->num_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].eat_times = 0;
		philos[i].last_eat_time = 0;
		philos[i].right_fork = &(all_info->fork[i]);
		philos[i].left_fork = &(all_info->fork[(i + 1) % all_info->num_of_philo]);
		philos[i].time = &(all_info->time[i]);
		philos[i].all_info = (void *)all_info;
		philos[i].can_continue = &(all_info->can_continue);
		i++;
	}
}