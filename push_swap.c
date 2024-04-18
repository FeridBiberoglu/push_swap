/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:56:35 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/18 16:22:15 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "push_swap.h"
#include <unistd.h>

int	check_doubles(node_t *stack_a)
{
	node_t	*temp;

	if (stack_a->data > 2147483647 || stack_a->data < -2147483648)
		return (0);
	while (stack_a)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (temp->data > 2147483647 || temp->data < -2147483648)
				return (0);
			if (stack_a->data == temp->data)
				return (0);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

node_t	*add_last_node(node_t *head, long long data)
{
	node_t	*new_node;

	new_node = malloc(sizeof(node_t));
	if (!new_node)
		return (NULL);
	head->next = new_node;
	new_node->prev = head;
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc < 2)
		return (0);
	while (argc > j)
	{
		if ((argv[j][i] < '0' || argv[j][i] > '9') && (argv[j][i] != '+'
				|| argv[j][i] != '-'))
			return (0);
		if (i != 0 && (argv[j][i] == '-' || argv[j][i] == '+'))
			return (0);
		i++;
		if (argv[j][i] == '\0')
		{
			j++;
			i = 0;
		}
	}
	return (1);
}

node_t	*make_stack_a(node_t *stack_a, int argc, char **argv)
{
	int		i;
	node_t	*temp;

	if (!stack_a)
		return (0);
	if (!check_args(argc, argv))
		return (0);
	stack_a->data = ft_atoi(argv[1]);
	stack_a->next = NULL;
	i = 2;
	temp = stack_a;
	while (argc > i)
	{
		stack_a = add_last_node(stack_a, ft_atoi(argv[i]));
		i++;
	}
	stack_a = temp;
	if (!check_doubles(stack_a))
		return (0);
	return (stack_a);
}

node_t	*make_stack_b(node_t **stack_a, int argc)
{
	node_t	*stack_b;
	int		i;

	i = 0;
	if (!stack_b)
		return (0);
	stack_b = add_last_node(stack_b, (*stack_a)->data);
	remove_first_node(stack_a);
	ft_printf("pb\n");
	if (argc > 5)
		pa(stack_a, &stack_b, 'b');
	return (stack_b);
}

int	main(int argc, char **argv)
{
	node_t	*stack_a;

	stack_a = malloc(sizeof(node_t));
	stack_a = make_stack_a(stack_a, argc, argv);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		free_list(&stack_a);
		return (0);
	}
	if (argc <= 4)
	{
		sort_three(&stack_a);
		free_list(&stack_a);
		return (0);
	}
	sort(&stack_a, argc);
	free_list(&stack_a);
	return (0);
}
