/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:39:02 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/25 19:51:50 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dict*		create_dict_node(int key, int value)
{
	t_dict *dict_node = malloc(sizeof(t_dict));
	if (!dict_node)
		ft_error();
	dict_node->next = NULL;
	dict_node->key = key;
	dict_node->value = value;
	// printf(" here init_d ");
	return (dict_node); // one node
}

t_dict*		add_dict_node(t_dict* head, int key, int value) 
{
    t_dict* dict_node;
    t_dict* current;

    dict_node = create_dict_node(key, value);
	if (head == NULL) {
		printf(" here-add_node-2 ");
        // Если список пуст, новый узел становится головой
        return (dict_node);
    }
    // Иначе, находим последний узел и добавляем новый узел
    current = head;
    while (current->next != NULL) 
	{
		printf(" here-add_node-3 ");
        current = current->next;
    }
    current->next = dict_node;
	// printf(" here-add_node-final ");
    return (head);
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

void print_list(t_dict* head) {
    t_dict* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int		find_target_to_change(t_stack *a, t_stack *b)
{
	// how to find the closest min number??
	// t_element *min_b;
	// t_element *max;
	// t_element *min;
	// t_element *last;
	t_element *tmp_a;
	t_element *tmp_b;

	// last = get_last_elem(a);
	// max = find_max(a);
	// min = find_min(a);
	
	int target;
	
	// min_b = find_min(b);
	tmp_a = a->top;
	tmp_b = b->top;
	
	t_dict *dict_node;
	t_dict *head_dict;
	// head_dict = NULL;
	// dict_node = NULL;
	//inside while
	//dict_node = add_dict_node();

	t_dict *target_dict;
	t_dict *target_dict_head;

	target_dict = NULL;
	target_dict_head = NULL;
	target = 0;
	
	target_dict = add_dict_node(target_dict_head, 0, 0);
	target_dict_head = target_dict;
	target_dict = target_dict->next;
	
	while(tmp_a)
	{
		head_dict = NULL;
		dict_node = NULL;
		dict_node = add_dict_node(head_dict, tmp_b->data, tmp_a->data - tmp_b->data);
		head_dict = dict_node;
		dict_node = dict_node->next;

		// check this number -> find target and count steps
		
		while(tmp_b)
		{
			printf("\na: %d, b:%d\n", tmp_a->data, tmp_b->data);
			dict_node = add_dict_node(dict_node, tmp_b->data, tmp_a->data - tmp_b->data);
			tmp_b = tmp_b->next;
			dict_node = dict_node->next;
			
		}
		if (dict_node->value >= 0)
			target = l_find_min(dict_node);
		else if (dict_node->value < 0)
			target = l_find_max(dict_node);
		// if (target_dict->key == 0 && target_dict->value == 0)
		// {
		// 	target_dict->key = tmp_a->data;
		// 	target_dict->value = target;
		// }
		target_dict = add_dict_node(target_dict, tmp_a->data, target);
		printf("target for '%d' number of 'a' stack is: %d\n", tmp_a->data, target);
		free_dict(head_dict);
		tmp_b = b->top;
		tmp_a = tmp_a->next;
		target_dict = target_dict->next;
	}

	print_list(target_dict);

	//delete first node of target_dict (becuse there are 0 and 0);


	
	// target = l_find_min(dict_node);
	// printf("target for one number of 'a' stack is: %d\n", target);
	
	
	
	// if (a->top->data < min_b)
	// {
	// 	push_move(a, b);
	// 	rotate_move(b);
	// }
	// else if ()
	
	// a->top->data 
	return (0); //return число в стаке b на которое встанет число a->top;
}



