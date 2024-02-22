# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 14:55:30 by sabdulki          #+#    #+#              #
#    Updated: 2023/10/04 18:46:32 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRC_S_DIR := stack
# SRC_T_DIR := target

SRC_S = stack/ex_join.c \
		stack/methods.c \
		stack/moves.c \
		stack/parsing.c \
		stack/utils_stack.c \
		stack/utils.c \
		stack/sort_2_3.c \
		stack/create_stack.c

SRC_T = target/create_dictionary.c \
		target/find_target_num.c \
		target/utils_dict.c \
		target/count_steps.c

SRC = 	push_swap.c \
		sorting.c \
		make_a_move.c \
		move_utils.c

SRCS = $(SRC_S) $(SRC_T) $(SRC)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
#  -fsanitize=address -g3

NAME = push_swap

$(NAME): $(OBJS)
	cd libft && make
	cd ft_printf && make
	$(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a libft/libft.a -o $(NAME)

all: $(NAME)

clean : 
	rm -f push_swap $(OBJS)
	cd libft && make clean
	cd ft_printf && make clean

fclean : clean
	rm -f $(NAME)
	cd libft && make fclean
	cd ft_printf && make fclean

re : fclean all
	cd libft && make fclean && make all
	cd ft_printf && make fclean && make all

.PHONY : all clean fclean re
