/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:17:29 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/18 15:45:40 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_list(node_t **head)
{
    node_t *tmp;

    while(*head)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}

void remove_first_node(node_t **head)
{
    node_t *temp;

    temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

void	sort_three(node_t **stack_a)
{
	node_t *max_number;

	max_number = biggestnumber(*stack_a);
	int i = check_sorted_a(*stack_a);
	if (i != 0)
		return ;
	if (*stack_a == max_number)
		ra(stack_a, 'a');
	else if ((*stack_a)->next == max_number)
		rra(stack_a, 'a');
	if (!check_sorted_a(*stack_a) && (*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 'a');
}