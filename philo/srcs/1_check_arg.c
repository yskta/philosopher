/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:40:41 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/24 13:38:54 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

bool    check_args_are_number(int argc, char **argv)
{
    int     i;
    size_t  j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

bool    check_input(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
		return (error_msg("invalid arguments:too few or too many arguments!"));
    if (check_args_are_number(argc, argv) == false)
        return (error_msg("invalid arguments:arguments must be number!"));
    return (true);
}

