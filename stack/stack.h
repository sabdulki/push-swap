/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:21:15 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/09 16:08:41 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_element{
	struct	s_element *next;
	struct	s_element *prev;
	int		data;
	int 	index;
}	t_element;

typedef struct s_stack{
	t_element *top;
	int amount; // how many elements does it have
}	t_stack;


// parsing
void	parsing(int argc, char **argv, t_stack *stack);
int		arr_strlen(char **arr);
void	check_if_in_int(char **arr);
void	check_if_int(char *str);
void	check_dups(t_stack *stack);
char	*ft_ex_join(int size, char **strs, char *sep);

// utils
void	print_args(char **argv);
void	ft_error(void);
void	print_elements(t_stack* stack);
void	change_index(t_stack *stack);
void	print_elem_index(t_stack* stack);
int		finish(t_stack* a, t_stack* b);

// methods
int		push(t_stack* stack, int num); //, int index);
int		pop(t_stack* stack);
int		peek(t_stack * stack);
int		destroy(t_stack *stack);
bool	is_empty(t_stack* stack);
t_element *get_last_elem(t_stack *stack);

// build
// t_stac* preparation(int argc, char **argv);
// t_stack* make_base_for_stack();
t_element* find_min(t_stack* stack);
t_element* find_max(t_stack *stack);

int		sort_2_3(t_stack *a);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a, char flag);
void	sort_three_rev(t_stack* b);

int		is_ascending(t_stack *a);
int		is_decreasing(t_stack *stack);

// operations
void	swap_move(t_stack *stack, char flag);
void	push_move(t_stack *a, t_stack *b, char flag);
void	rotate_move(t_stack *stack, char flag);
void	rev_rotate_move(t_stack *stack, char flag);

#endif