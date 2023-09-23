/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_all_about_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:33 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/23 15:27:34 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

bool all_about_thread(t_info *all_info)
{
	size_t i;

	i = 0;
	while (i < all_info->num_of_philo)
	{
		if (pthread_create(&(all_info->thread[i]), NULL, &philo_routine, &(all_info->all_philos[i])) != 0)
			return (error_msg("all_about_thread:pthread_create error"));
		i++;
	}
	if (pthread_create(&all_info->monitor, NULL, &monitor, (void *)all_info) != 0)
		return (error_msg("all_about_thread:pthread_create error"));
	i = 0;
	while (i < all_info->num_of_philo)
	{
		if (pthread_join(all_info->thread[i], NULL) != 0)
			return (error_msg("all_about_thread:pthread_join error"));
		i++;
	}
	if (pthread_join(all_info->monitor, NULL) != 0)
		return (error_msg("all_about_thread:pthread_join error"));
	return (true);
}