/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:33:57 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 14:42:51 by sabdulki         ###   ########.fr       */
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

//dictionary
typedef struct s_dict{ 
	int				a_int;
	int				value;
	int				b_int;
	struct s_dict	*next;
}	t_dict;

// target
t_dict		*find_value(int num_a, t_stack *b, t_dict *head_dict);
int			define_target(t_dict *h_dict, char flag, t_stack *a, t_elem *tmp_a);
int			find_target(t_dict *head_dict, int pos, int neg, char flag);

// list dict
t_dict		*create_dictinary(t_stack *b);
int			l_find_min(t_dict *dict);
int			l_find_max(t_dict *dict);
int			l_find_min_pos(t_dict *head_dict, int pos);
int			l_find_max_neg(t_dict *head_dict, int neg);
void		free_dict(t_dict *head);

// count steps
t_elem		*find_target_index(t_stack *b, t_elem *target);
t_dict		*step_find_min(t_dict *step_dict);
int			count_steps(t_stack *a, t_stack *b, t_elem *tmp_a, t_elem *target);
int			count_a_steps(t_stack *a, t_elem *tmp_a);
int			count_b_steps(t_stack *b, t_elem *target);

#endif