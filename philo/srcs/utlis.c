/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:29:48 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/16 18:45:23 by yokitaga         ###   ########.fr       */
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




