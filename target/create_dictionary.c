/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dictionary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:38:01 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 14:35:25 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

t_dict	*create_dictinary(t_stack *b)
{
	t_dict	*head;
	t_dict	*new_node;
	t_dict	*current;
	int		i;

	if (b->amount <= 0)
		return (NULL);
	head = NULL;
	current = NULL;
	head = (t_dict*) malloc (sizeof(t_dict));
	if (head == NULL)
		return (NULL);
	i = 1;
	head->a_int = 0;
	head->value = 0;
	head->next = NULL;
	current = head;
	while (i < b->amount)
	{
		new_node = (t_dict*) malloc (sizeof(t_dict));
		if (new_node == NULL)
			return (NULL);
		new_node->next = NULL;
		new_node->a_int = 0;
		new_node->value = 0;
		current->next = new_node;
		current = new_node;
		i++;
	}
	return (head);
}
