/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:57:25 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/01 17:47:11 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

t_dict*		step_find_min(t_dict *step_dict)
{
	t_dict *tmp;
	t_dict *min;

	tmp = step_dict;
	min = step_dict->next;
	while(tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	// printf("\nthe min is: %d\n", min->b_int);

	return (min);
}

int		l_find_min(t_dict *dict) //, char c)
{
	t_dict *tmp;
	t_dict *min;

	tmp = dict;
	min = dict->next;
	while(tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	// printf("\nthe min is: %d\n", min->b_int);
	return (min->b_int);
	// if (c == 'a')
	// 	return (min->b_int);
	// else if (c == 'b')
	// 	return (min->a_int);
}

int		l_find_max(t_dict* dict)
{
	t_dict *tmp;
	t_dict *max;

	tmp = dict;
	max = dict;

	while(tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	// printf("\nthe max is: %d\n", max->b_int);
	return (max->b_int);
}

void free_dict(t_dict* head) 
{
    t_dict* current = head;
    t_dict* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void print_list(t_dict* head) 
{
    t_dict* current = head;
    while (current != NULL) {
		printf("\n\t'%d' steps: %d -> ", current->a_int, current->value);
        // printf("\t%d-%d = %d -> ", current->a_int, current->b_int, current->value);
        current = current->next;
    }
    printf("NULL\n");
}
