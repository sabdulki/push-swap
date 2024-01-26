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
// # include "./ft_printf/ft_printf.h"

typedef struct s_element{
	struct	s_element *next;
	struct	s_element *prev;
	int		data;
}	t_element;

typedef struct s_stack{
	t_element *top;
	int amount;
}	t_stack;

typedef struct s_dict{  //dictionary
	int a_int;
	int value; // разница a->data - b->data
	int b_int;
	struct s_dict *next;
} t_dict;


// parsing
void parsing(int argc, char **argv, t_stack *stack);
int	arr_strlen(char **arr);
void	check_if_in_int(char **arr);
void	check_if_int(char *str);
void check_dups(t_stack *stack);
char	*ft_ex_join(int size, char **strs, char *sep);

// utils
void print_args(char **argv);
void ft_error(void);
void print_elements(t_stack* stack);

// methods
int	push(t_stack* stack, int num); //, int amount);
int	pop(t_stack* stack);
int	peek(t_stack * stack);
int destroy(t_stack *stack);
bool	is_empty(t_stack* stack);
t_element *get_last_elem(t_stack *stack);

// build
// t_stac* preparation(int argc, char **argv);
// t_stack* make_base_for_stack();
t_element* find_min(t_stack* stack);
t_element* find_max(t_stack *stack);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
int	determination(t_stack *a);
int		is_ascending(t_stack *a);

// sorting
int		min(int x, int y);
void	sort(t_stack *a, t_stack *b);
void	main_process (t_stack *a, t_stack *b);

// target
t_dict*	find_value(int num_a, t_stack *b, t_dict *head_dict);
int		find_target(t_dict* head_dict, t_stack *a, t_stack *b);
int	target_for_max_min(t_dict *head_dict, t_stack *a, t_stack *b);

// list dict
t_dict* create_dictinary(t_stack *b);
int		l_find_min(t_dict *dict);
int		l_find_max(t_dict* dict);
void print_list(t_dict* head);
void free_dict(t_dict* head);

// operations
void	swap_move(t_stack *stack);
void	push_move(t_stack *a, t_stack *b);
void	rotate_move(t_stack *stack);
void	rev_rotate_move(t_stack *stack);
#endif
