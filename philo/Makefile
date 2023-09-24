# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 12:43:29 by yokitaga          #+#    #+#              #
#    Updated: 2023/09/24 13:46:40 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = 0_main.c 1_check_arg.c 2_init_info.c 3_init_mutex.c 4_init_each_philo.c 5_all_about_thread.c 6_1_philo_routine.c 6_2_each_routine.c 7_monitor_thread.c 8_1_utils.c 8_2_utils.c

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INCLUDES = -I ./include

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRC:%.c=$(OBJ_DIR)%.o)
CC = cc -pthread
CFLAGS= -Wall -Werror -Wextra -g -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(INCLUDES) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@-mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test1 : all
	./philo 1 800 200 200

test2 : all
	./philo 5 800 200 200

test3 : all
	./philo 5 800 200 200 7

test4 : all
	./philo 4 410 200 200

test5 : all
	./philo 4 310 200 100

.PHONY: all clean re fclean

