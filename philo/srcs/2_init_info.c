/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:41:53 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/24 13:43:01 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void    set_arg(t_info *all_info, int argc, char **argv)
{
    all_info->num_of_philo = ft_atoi(argv[1]);
    all_info->time_to_die = ft_atoi(argv[2]);
    all_info->time_to_eat = ft_atoi(argv[3]);
    all_info->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
    {
        all_info->finish_eating_count = (int)ft_atoi(argv[5]);
        all_info->need_to_count = true;
    }
    else
    {
        all_info->finish_eating_count = 0;
        all_info->need_to_count = false;
    }
}

bool    set_other_info(t_info *all_info)
{
    all_info->can_continue = true;
    all_info->num_of_philo_finish_eating = 0;
    all_info->all_philos = (t_each_philo *)malloc(sizeof(t_each_philo) * all_info->num_of_philo);
    all_info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * all_info->num_of_philo);
    all_info->time = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * all_info->num_of_philo);
    all_info->thread = (pthread_t *)malloc(sizeof(pthread_t) * all_info->num_of_philo); 
    if (!all_info->all_philos || !all_info->fork || !all_info->time || !all_info->thread)
        return (error_msg("init data:gettimeofday error or malloc error"));
    return (true);
}

bool    init_info(t_info *all_info, int argc, char **argv)
{
    set_arg(all_info, argc, argv);
    if (set_other_info(all_info) == false || all_info->num_of_philo == 0)
        return (false);
    return (true);   
}