/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:03:30 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/26 14:58:23 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_nodes_b_a(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a) != (*stack_b)->target)
	{
		if ((*stack_b)->target->middle == 1)
			ra(stack_a, 'a');
		else
			rra(stack_a, 'a');
	}
	pa(stack_b, stack_a, 'a');
}

void	final_rotate(t_node **stack, char c)
{
	t_node	*biggest;

	set_middle_node(*stack);
	biggest = biggestnumber(*stack);
	while (!check_sorted_b(*stack) && c == 'b')
	{
		if (biggest->middle)
			ra(stack, c);
		else
			rra(stack, c);
	}
	while (!check_sorted_a(*stack) && c == 'a')
	{
		if (biggest->middle)
			ra(stack, c);
		else
			rra(stack, c);
	}
}

void	sort(t_node **stack_a, int argc)
{
	int		size_a;
	t_node	*stack_b;

	stack_b = make_stack_b(stack_a, argc);
	size_a = stack_size(*stack_a);
	while (size_a > 3)
	{
		init_stack_a(stack_a, &stack_b);
		move_nodes_a_b(stack_a, &stack_b);
		size_a--;
	}
	while (!check_sorted_b(stack_b))
		final_rotate(&stack_b, 'b');
	if (!check_sorted_a(*stack_a))
		sort_three(stack_a);
	while (stack_b)
	{
		init_stack_b(stack_a, &stack_b);
		move_nodes_b_a(stack_a, &stack_b);
	}
	free_list(&stack_b);
	while (!check_sorted_a(*stack_a))
		final_rotate(stack_a, 'a');
	return ;
}
