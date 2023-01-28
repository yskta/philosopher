/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:50:23 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/28 16:33:19 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

bool arg_check(int argc, char **argv);

typedef struct s_data{
    size_t  number_of_philosophers;
    size_t  time_to_die;
    size_t  time_to_eat;
    size_t  time_to_sleep;
}t_data;

#endif