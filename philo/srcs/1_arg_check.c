/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_arg_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:48:45 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/28 14:41:16 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

bool check_args(int argc, char **argv)
{
    bool check_arg;
    size_t i;

    check_arg = true;
    i = 0;
    if (argc != 5 && argc != 6)
        check_arg = false;
    else if (check_args_num_or_not(argc, argv) == false)
        check_arg = false;
    else if (check_each_param(argc, argv) == false)
        check_arg = false;
    return (check_arg);
}

bool check_args_num_or_not(int argc, char **argv)
{
    int     i;
    bool    check_result;

    i = 1;
    check_result = true;
    while (i < argc)
    {
        check_result = check_each_arg_num_or_not(argv[i]);
        if (check_result == false)
            break;
        i++;
    }
    return (check_result);
}

bool check_each_arg_num_or_not(char *argv)
{
    bool    check_result;
    size_t  i;
    
    check_result = true;
    i = 0;
    if (argv[i] == '\0')
    {
        check_result = false;
        return (check_result);
    }
    while (argv[i] != '\0')
    {
        if (ft_isdigit(argv[i]) == 0)
        {
            check_result = false;
            break ;
        }
        i++;
    }
    return (check_result);
}

bool    check_each_param(int argc, char **argv)
{
    bool check_result;

    
    check_result = true;


    return (check_result);
}