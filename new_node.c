/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:17:29 by fbiberog          #+#    #+#             */
/*   Updated: 2024/03/20 14:44:30 by fbiberog         ###   ########.fr       */
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

int sort_three(node_t **stack_a)
{
	if(check_sorted(*stack_a))
		return 1;
	if((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->next->next->data)
		ra(stack_a, 'a');
	else if((*stack_a)->next->next->data > (*stack_a)->data && (*stack_a)->next->next->data > (*stack_a)->next->data)
		rra(stack_a, 'a');
	if((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 'a');
} 