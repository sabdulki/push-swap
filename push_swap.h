/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:55:35 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/04 18:39:08 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./stack/stack.h"
# include "./target/target.h"
// # include "./ft_printf/ft_printf.h"

t_stack *make_base_for_stack();
t_stack *preparation(int argc, char **argv);

// sorting
int			min(int x, int y);
int			sort(t_stack *a, t_stack *b);
int			first_pushes(t_stack *a, t_stack *b, char flag);
int			push_to_a(t_stack *a, t_stack *b, int flag);
int			push_to_b(t_stack *a, t_stack *b, int flag);
int			make_a_move(t_stack *a, t_stack *b, t_dict *moving_num, char flag);
void		move_in_a(t_stack* a, t_dict *moving_num, char flag);
void		move_in_b(t_stack* b,  t_dict *moving_num, char flag);
void		target_in_b_is_top(t_stack *b, t_element* b_move, char flag);
t_dict*		find_most_profit_num (t_stack *a, t_stack *b,  char flag);
t_element*	find_position_in_a(t_stack* a, t_dict *moving_num);
t_element*	find_position_in_b(t_stack* b, t_dict *moving_num);

#endif