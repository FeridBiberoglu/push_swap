/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:30:21 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/23 21:30:33 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_a(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->next && (temp->data > temp->next->data))
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_sorted_b(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_node	*biggestnumber(t_node *stack)
{
	t_node	*temp;
	t_node	*biggest;

	temp = stack;
	biggest = stack;
	while (temp != NULL)
	{
		if (temp->data > biggest->data)
			biggest = temp;
		temp = temp->next;
	}
	return (biggest);
}

int	stack_size(t_node *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
