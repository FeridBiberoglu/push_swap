/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:07:22 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/23 19:15:28 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node(t_node *stack_a, t_node *stack_b)
{
	t_node	*bcurrent;
	t_node	*target_b;
	int		closest;
	t_node	*temp;

	temp = stack_a;
	while ((stack_a))
	{
		closest = -2147483648;
		bcurrent = stack_b;
		while (bcurrent)
		{
			if (bcurrent->data < (stack_a)->data && bcurrent->data > closest)
			{
				closest = bcurrent->data;
				target_b = bcurrent;
			}
			bcurrent = bcurrent->next;
		}
		if (closest == -2147483648)
			(stack_a)->target = biggestnumber(stack_b);
		else
			(stack_a)->target = target_b;
		(stack_a) = (stack_a)->next;
	}
}

void	set_middle_node(t_node *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack_size(stack) / 2;
	while ((stack))
	{
		if (i <= j)
			(stack)->middle = 1;
		else
			(stack)->middle = 0;
		(stack)->index = i;
		(stack) = (stack)->next;
		i++;
	}
}

void	calculate_cheapest(t_node **stack_a, t_node **stack_b)
{
	int		size_a;
	int		size_b;
	t_node	*temp;

	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	temp = *stack_a;
	while ((*stack_a))
	{
		(*stack_a)->cost = (*stack_a)->index;
		if ((*stack_a)->middle == 0)
			(*stack_a)->cost = size_a - (*stack_a)->index;
		if ((*stack_a)->target->middle == 1)
			(*stack_a)->cost += (*stack_a)->target->index;
		else
			(*stack_a)->cost += size_b - (*stack_a)->target->index;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = temp;
}

void	mark_cheapest(t_node *stack)
{
	int		cheap;
	t_node	*cheapest_node;
	t_node	*temp;

	temp = stack;
	cheap = 2147483647;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->cost < cheap)
		{
			cheap = stack->cost;
			cheapest_node = stack;
		}
		stack->cheapest = 0;
		stack = stack->next;
	}
	while (temp)
	{
		if (temp == cheapest_node)
			temp->cheapest = 1;
		temp = temp->next;
	}
}

void	init_stack_a(t_node **stack_a, t_node **stack_b)
{
	set_middle_node(*stack_a);
	set_middle_node(*stack_b);
	target_node(*stack_a, *stack_b);
	calculate_cheapest(stack_a, stack_b);
	mark_cheapest(*stack_a);
}
