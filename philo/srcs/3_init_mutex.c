/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_init_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:01:35 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/16 19:13:20 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

bool    init_mutex(t_info *all_info)
{
	size_t i;

	i = 0;
	while (i < all_info->num_of_philo)
	{
		if (pthread_mutex_init(&all_info->fork[i], NULL) != 0)
			return (error_msg("init mutex:pthread_mutex_init error"));
		if (pthread_mutex_init(&all_info->time[i], NULL) != 0)
			return (error_msg("init mutex:pthread_mutex_init error"));
		i++;
	}
	if (pthread_mutex_init(&all_info->end_flag, NULL) != 0 || pthread_mutex_init(&all_info->count_meals, NULL) != 0 || pthread_mutex_init(&all_info->write, NULL) != 0)
		return (error_msg("init mutex:pthread_mutex_init error"));
	return (true);
}