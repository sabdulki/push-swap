/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:21:15 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 17:50:37 by sabdulki         ###   ########.fr       */
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
# include "../ft_printf/ft_printf.h"

// element of stack
typedef struct s_elem{
	struct s_elem	*next;
	struct s_elem	*prev;
	int				data;
	int				index;
}	t_elem;

typedef struct s_stack{
	t_elem		*top;
	int			amount;
}	t_stack;

// parsing
int		create_stack(t_stack *stack, char	**future_stack);
int		parsing(int argc, char **argv, t_stack *stack);
int		arr_strlen(char **arr);
int		check_if_in_int(char **arr);
int		check_if_int(char *str);
int		check_dups(t_stack *stack);
char	*ft_ex_join(int size, char **strs, char *sep);

// methods
int		push(t_stack *stack, int num);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
int		destroy(t_stack *stack);
t_elem	*get_last_elem(t_stack *stack);

// operations
void	swap_move(t_stack *stack, char flag);
int		push_move(t_stack *a, t_stack *b, char flag);
void	rotate_move(t_stack *stack, char flag);
void	rev_rotate_move(t_stack *stack, char flag);

// sort 2 and 3
int		sort_2_3(t_stack *a);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a, char flag);
void	sort_three_rev(t_stack *b);

// stack_utils
t_elem	*find_min(t_stack *stack);
t_elem	*find_max(t_stack *stack);
bool	is_empty(t_stack *stack);
int		is_ascending(t_stack *a);
int		is_decreasing(t_stack *stack);

// utils
void	ft_error(void);
void	print_elements(t_stack *stack);
void	change_index(t_stack *stack);
void	finish(t_stack *a, t_stack *b);

#endif