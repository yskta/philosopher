/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:50:23 by yokitaga          #+#    #+#             */
/*   Updated: 2023/08/26 16:28:20 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

bool            check_args(int argc, char **argv);
bool            check_args_num_or_not(int argc, char **argv);
bool            check_each_arg_num_or_not(char *argv);
bool            check_each_param(int argc, char **argv);

int	            ft_isdigit(int c);
unsigned int	ft_isspace(int c);
const char	    *ft_skipspace(const char *str);
const char	    *ft_flag(const char *str, int *sign);
int	            ft_atoi(const char	*str);

typedef struct s_data{
    
}t_data;

typedef struct s_each_philo{
    
}t_each_philo;

#endif