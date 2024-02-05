/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:33:57 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/05 15:49:15 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGET_H
# define TARGET_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../stack/stack.h"

typedef struct s_dict{  //dictionary
	int a_int;
	int value; // разница a->data - b->data
	int b_int;
	struct s_dict *next;
} t_dict;

// target
t_dict*	find_value(int num_a, t_stack *b, t_dict *head_dict);
// int		find_target(t_dict* head_dict); //, t_stack *a, t_stack *b);
int		find_target(t_dict* head_dict, char flag);
// int	target_for_max_min(t_dict *head_dict, t_stack *a, t_stack *b);

// list dict
t_dict* create_dictinary(t_stack *b);
int		l_find_min(t_dict *dict);
int		l_find_max(t_dict* dict);
int		l_find_min_pos(t_dict *head_dict, int pos);
int		l_find_max_neg(t_dict *head_dict, int neg);
void print_list(t_dict* head);
void free_dict(t_dict* head);

// count steps
int		count_steps(t_stack *a, t_stack *b, t_element *tmp_a, t_element *target);
int		count_a_steps(t_stack *a, t_element* tmp_a);
int		count_b_steps(t_stack *b, t_element *target);
t_element *find_target_index(t_stack *b, t_element *target);
t_dict*		step_find_min(t_dict *step_dict);

#endif