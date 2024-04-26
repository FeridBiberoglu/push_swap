/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:17:29 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/24 18:27:59 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node **head)
{
	t_node	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
	free(*head);
}

void	remove_first_node(t_node **head)
{
	t_node	*temp;

	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

void	sort_three(t_node **stack_a)
{
	t_node	*max_number;
	int		i;

	max_number = biggestnumber(*stack_a);
	i = check_sorted_a(*stack_a);
	if (i != 0)
		return ;
	if (*stack_a == max_number)
		ra(stack_a, 'a');
	else if ((*stack_a)->next == max_number)
		rra(stack_a, 'a');
	if (!check_sorted_a(*stack_a) && (*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 'a');
}

t_node	*add_last_node(t_node *head, long long data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	if (head == NULL)
		head = new_node;
	else if (head != NULL)
		head->next = new_node;
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
