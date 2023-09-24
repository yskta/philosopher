/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:20:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/24 13:46:35 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int main(int argc, char **argv)
{
    t_info  *all_info;

    all_info = (t_info *)malloc(sizeof(t_info));
    if (!all_info)
        return (error_msg("main:malloc error"));
    if (check_input(argc, argv) == false)
    {
        free(all_info);
        return (0);
    }
    if (init_info(all_info, argc, argv) == false)
        return (free_all(all_info));
    if (init_mutex(all_info) == false)
        return (free_and_destroy_all(all_info));
    init_each_philo(all_info);
    if (all_about_thread(all_info) == false)
        return (free_and_destroy_all(all_info));
    free_and_destroy_all(all_info);
    return (0);
}