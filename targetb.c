/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targetb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:22:36 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/23 21:29:04 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

t_node	*smallestnumber(t_node *stack)
{
	t_node	*temp;
	t_node	*smallest;

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

void	target_node_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*acurrent;
	t_node	*target_a;
	int		closest;
	t_node	*temp;

	temp = stack_b;
	while ((stack_b))
	{
		closest = 2147483647;
		acurrent = stack_a;
		while (acurrent)
		{
			if (acurrent->data > (stack_b)->data && acurrent->data < closest)
			{
				closest = acurrent->data;
				target_a = acurrent;
			}
			acurrent = acurrent->next;
		}
		if (closest == 2147483647)
			(stack_b)->target = smallestnumber(stack_a);
		else
			(stack_b)->target = target_a;
		(stack_b) = (stack_b)->next;
	}
}

void	init_stack_b(t_node **stack_a, t_node **stack_b)
{
	set_middle_node(*stack_a);
	set_middle_node(*stack_b);
	target_node_b(*stack_a, *stack_b);
}
