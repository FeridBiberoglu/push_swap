/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targetb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:22:36 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/13 16:08:26 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

node_t *smallestnumber(node_t *stack)
{
	node_t *temp;
	node_t *smallest;

	temp = stack;
	smallest = stack;
	while (temp != NULL)
	{
		if (temp->data < smallest->data)
			smallest = temp;
		temp = temp->next;
	}
	return (smallest);
}

void target_node_b(node_t *stack_a, node_t *stack_b)
{
	node_t *acurrent;
	node_t *target_a;
	int closest;
	node_t *temp = stack_b;
	while((stack_b))
	{
		closest = 2147483647;
		acurrent = stack_a;
		while(acurrent)
		{
			if(acurrent->data > (stack_b)->data && acurrent->data < closest)
			{
				closest = acurrent->data;
				target_a = acurrent;
			}
			acurrent = acurrent->next;
		}
		if(closest == 2147483647)
			(stack_b)->target = smallestnumber(stack_a);
		else
			(stack_b)->target = target_a;

		(stack_b) = (stack_b)->next;
	}
	stack_b = temp;
}

void init_stack_b(node_t **stack_a, node_t **stack_b)
{
	set_middle_node(*stack_a);
	set_middle_node(*stack_b);
	target_node_b(*stack_a, *stack_b);
}