/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:48:08 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/23 19:09:22 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a, char c)
{
	t_node	*temp;

	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (c != 'x')
		ft_printf("s%c\n", c);
}

void	sb(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, 'x');
	sa(stack_b, 'x');
	ft_printf("ss\n");
}

void	pa(t_node **stack_new, t_node **stack_old, char c)
{
	t_node	*temp;

	if (*stack_new == NULL)
		return ;
	temp = *stack_new;
	*stack_new = (*stack_new)->next;
	temp->next = *stack_old;
	*stack_old = temp;
	ft_printf("p%c\n", c);
}

void	ra(t_node **stack_a, char c)
{
	t_node	*temp;

	temp = *stack_a;
	if (!temp || !temp->next)
		return ;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack_a;
	(*stack_a) = (*stack_a)->next;
	temp->next->next = NULL;
	if (c != 'x')
		ft_printf("r%c\n", c);
}

void	rra(t_node **stack_a, char c)
{
	t_node	*temp;
	t_node	*last;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	if (c != 'x')
		ft_printf("rr%c\n", c);
}
