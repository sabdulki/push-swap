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
t_stack*	copy_stack(t_stack *stack);

// sorting
int		min(int x, int y);
void	sort(t_stack *a, t_stack *b);
t_dict *	find_most_profit_num (t_stack *a, t_stack *b);

//moving
void	make_a_move(t_stack *a, t_stack *b, t_dict *moving_num);
void	move_in_a(t_stack* a, t_dict *moving_num);
t_element* find_position_in_a(t_stack* a, t_dict *moving_num);
t_element* find_position_in_b(t_stack* b, t_dict *moving_num);
void	move_in_b(t_stack* b,  t_dict *moving_num);
bool	is_descending(t_stack *stack);
#endif
