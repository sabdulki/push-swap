/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dictionary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:38:01 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/25 18:45:35 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dict* create_dictinary(t_stack *b) 
{
    if (b->amount <= 0) {
        return NULL; // Некорректная длина списка
    }

    t_dict* head = NULL;
    t_dict* current = NULL;
	int i;
	
    // Создаем голову списка
    head = (t_dict*)malloc(sizeof(t_dict));
    if (head == NULL)
       ft_error();

    // Инициализируем данные и указатель на следующий узел
    head->key = 0; // Например, начнем с 0
	head->value = 0;
	
	i = 0;
    head->next = NULL;
    current = head;
	
	// return (current);
    // Создаем остальные узлы списка
	while(i < b->amount)
	{
        t_dict* newNode = (t_dict*)malloc(sizeof(t_dict));
        if (newNode == NULL)
            ft_error();
        // Инициализируем данные и указатель на следующий узел
        // newNode->data = i;
        newNode->next = NULL;

        // Связываем текущий узел с новым
        current->next = newNode;
        current = newNode;
		i++;
    }

    return head;
}