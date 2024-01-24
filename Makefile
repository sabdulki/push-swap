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

SRCS = push_swap.c ex_join.c utils.c alg_utils.c \
		parsing.c moves.c methods.c sort_2_3.c \
		sorting.c find_target_num.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
# LIBFT = ./libft-42/libft.a
NAME = push_swap

$(NAME): $(OBJS)
	cd libft && make && make bonus
	$(CC) $(CFLAGS) $(OBJS)  libft/libft.a -o $(NAME)

all: $(NAME)

clean : 
	rm -f push_swap $(OBJS)
	cd libft && make clean

fclean : clean
	rm -f $(NAME)
	cd libft && make fclean

re : fclean all
	cd libft && make fclean && make all

.PHONY : all clean fclean re bonus
