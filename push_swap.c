/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:56:35 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/16 20:52:37 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../printf.h"
#include <unistd.h>

void	print_list_data(node_t *stacka, node_t *stackb)
{
	int	i;

	i = 1;
	if (stacka == NULL)
		printf("PRINT LIST DATA: Stack a is empty!\n");
	while (stacka != NULL)
	{
		printf("Node %d - Num %d\n", i, stacka->data);
		stacka = stacka->next;
		i++;
	}
	i = 1;
	printf("\n");
	if (stackb == NULL)
		printf("PRINT LIST DATA: Stack B is empty!\n");
	while (stackb != NULL)
	{
		printf("Node %d - Num: %d- cheapest: %d, middle %i cost %i index %i \n",
			i, stackb->data, stackb->cheapest, stackb->middle, stackb->cost,
			stackb->index);
		stackb = stackb->next;
		i++;
	}
}

int check_doubles(node_t *stack_a)
{
	int j;
	node_t *temp;

	while(stack_a)
	{
		temp = stack_a->next;
		while(temp)
		{
			if(stack_a->data == temp->data)
				return 0;
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return 1;
}

node_t	*add_last_node(node_t *head, int data)
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
		if((argv[j][i] < '0' || argv[j][i] > '9') && 
			(argv[j][i] != '+' || argv[j][i] != '-'))
			return 0;
		if (i != 0  && (argv[j][i] == '-' || argv[j][i] == '+'))
			return 0;
		i++;
		if(argv[j][i] == '\0')
			{
				j++;
				i = 0;
			}
	}
	return 1;
}

node_t	*make_stack_a(node_t *stack_a, int argc, char **argv)
{
	int		i;
	node_t	*temp;

	if (!stack_a)
		return (0);
	if (!check_args(argc, argv))
		return (0);
	i = 1;
	stack_a->data = atoi(argv[i]);
	stack_a->prev = NULL;
	stack_a->next = NULL;
	i++;
	temp = stack_a;
	while (argc > i)
	{
		stack_a = add_last_node(stack_a, ft_atoi(argv[i]));
		i++;
	}
	stack_a = temp;
	if(!check_doubles(stack_a))
		return 0;
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
