/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:57:25 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 15:18:22 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

t_dict	*step_find_min(t_dict *step_dict)
{
	t_dict	*tmp;
	t_dict	*min;

	tmp = step_dict;
	min = step_dict;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	l_find_min(t_dict *dict)
{
	t_dict	*tmp;
	t_dict	*min;

	tmp = dict;
	min = dict->next;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min->b_int);
}

int	l_find_max(t_dict *dict)
{
	t_dict	*tmp;
	t_dict	*max;

	tmp = dict;
	max = dict;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->b_int);
}

void	free_dict(t_dict *head)
{
	t_dict	*current;
	t_dict	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return ;
}
