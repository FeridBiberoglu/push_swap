/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targetb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:22:36 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/10 14:03:31 by fbiberog         ###   ########.fr       */
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
		acurrent = stack_b;
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
			(stack_b)->target = smallestnumber(stack_b);
		else
			(stack_b)->target = target_a;
		(stack_b) = (stack_b)->next;
	}
	stack_b = temp;
}

void calculate_cheapest_b(node_t **stack_a, node_t **stack_b)
{
	int size_a;
	int size_b;
	node_t *temp;

	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	temp = *stack_b;
	while((*stack_b))
	{
		(*stack_b)->cost = (*stack_b)->index;
		if((*stack_b)->middle == 0)
			(*stack_b)->cost = size_b - (*stack_b)->index;
		if((*stack_b)->target->middle == 1)
			(*stack_b)->cost += (*stack_b)->target->index;
		else
			(*stack_b)->cost += size_a - (*stack_b)->target->index;
		(*stack_b) = (*stack_b)->next;
	}
	*stack_b = temp;
}

void init_stack_b(node_t **stack_a, node_t **stack_b)
{
	set_middle_node(*stack_a);
	set_middle_node(*stack_b);
	target_node_b(*stack_b, *stack_a);
	calculate_cheapest_b(stack_b, stack_a);
	mark_cheapest(stack_b);
}