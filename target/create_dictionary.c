/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dictionary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:38:01 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/26 21:38:25 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

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
	
	i = 1;
    head->a_int = 0;
	head->value = 0;
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
        newNode->a_int = 0;
	    newNode->value = 0;
        // Связываем текущий узел с новым
        current->next = newNode;
        current = newNode;
		i++;
    }
    // print_list(head);
    return (head);
}

