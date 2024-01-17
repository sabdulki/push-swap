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

SRCS = push_swap.c ex_join.c utils.c start_sorting.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
# LIBFT = ./libft-42/libft.a
NAME = push_swap

$(NAME): $(OBJS)
	cd libft-42 && make && make bonus
	$(CC) $(CFLAGS) $(OBJS)  libft-42/libft.a -o $(NAME)

all: $(NAME)

clean : 
	rm -f push_swap $(OBJS)
	cd libft-42 && make clean

fclean : clean
	rm -f $(NAME)
	cd libft-42 && make fclean

re : fclean all
	cd libft-42 && make fclean && make all

.PHONY : all clean fclean re bonus
