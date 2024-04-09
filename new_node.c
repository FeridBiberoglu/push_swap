/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:17:29 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/09 15:07:36 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void remove_first_node(struct node **head)
{
	struct node	*temp;

	temp = (*head)->next;
	*head = temp;
	(*head)->prev = NULL;
}

void sort_three(node_t **stack_a)
{
	node_t *max_number;

	max_number = biggestnumber(*stack_a);
	if(check_sorted_a(*stack_a))
		return;
	if(*stack_a == max_number)
		ra(stack_a, 'a');
	else if((*stack_a)->next == max_number)
		rra(stack_a, 'a');
	if((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 'a');
} 