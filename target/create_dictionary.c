/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dictionary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:38:01 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/15 15:54:28 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

t_dict* create_dictinary(t_stack *b) 
{
	t_dict* head;
	t_dict* current;
	int		i;
	
	if (b->amount <= 0)
		return (NULL);
	head = NULL;
	current = NULL;
	head = (t_dict*)malloc(sizeof(t_dict));
	if (head == NULL)
		return (NULL);
	i = 1;
	head->a_int = 0;
	head->value = 0;
	head->next = NULL;
	current = head;
	while (i < b->amount)
	{
		t_dict* newNode = (t_dict*)malloc(sizeof(t_dict));
		if (newNode == NULL)
			return (NULL);
		newNode->next = NULL;
		newNode->a_int = 0;
		newNode->value = 0;
		current->next = newNode;
		current = newNode;
		i++;
	}
	return (head);
}
