/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dictionary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:38:01 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 17:47:29 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

t_dict	*create_dictinary(t_stack *b)
{
	t_dict	*head;
	t_dict	*current;
	int		i;

	if (b->amount <= 0)
		return (NULL);
	head = malloc(sizeof(t_dict));
	if (!head)
		return (NULL);
	i = 1;
	head->a_int = 0;
	head->value = 0;
	head->next = NULL;
	current = head;
	if (fill_elem(b, current) == 1)
		return (NULL);
	return (head);
}

int	fill_elem(t_stack *b, t_dict *current)
{
	t_dict	*new_node;
	int		i;

	i = 1;
	while (i < b->amount)
	{
		new_node = malloc(sizeof(t_dict));
		if (new_node == NULL)
			return (1);
		new_node->next = NULL;
		new_node->a_int = 0;
		new_node->value = 0;
		current->next = new_node;
		current = new_node;
		i++;
	}
	return (0);
}

int	l_find_min_pos(t_dict *head_dict, int pos)
{
	t_dict	*dict;

	dict = head_dict;
	if (pos == 1)
		return (l_find_max(head_dict));
	while (dict)
	{
		if (dict->value < 0)
			dict->value = 2147483647;
		dict = dict->next;
	}
	return (l_find_min(head_dict));
}

int	l_find_max_neg(t_dict *head_dict, int neg)
{
	t_dict	*dict;

	dict = head_dict;
	if (neg == 1)
		return (l_find_min(head_dict));
	while (dict)
	{
		if (dict->value > 0)
			dict->value = -2147483648;
		dict = dict->next;
	}
	return (l_find_max(head_dict));
}
