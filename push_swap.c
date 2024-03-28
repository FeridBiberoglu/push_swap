/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:56:35 by fbiberog          #+#    #+#             */
/*   Updated: 2024/03/13 15:39:17 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	print_list_data(node_t *stacka, node_t *stackb)
{
	int		i = 1;

	if (stacka == NULL)
		printf("PRINT LIST DATA: Stack a is empty!\n");
	while (stacka != NULL)
	{
		printf("Node %d - Num: %d\n", i, stacka->data);
		stacka = stacka->next;
		i++;
	}
	i = 1;
	printf("\n");
	if (stackb == NULL)
		printf("PRINT LIST DATA: Stack B is empty!\n");
	while (stackb != NULL)
	{
		printf("Node %d - Num: %d\n", i, stackb->data);
		stackb = stackb->next;
		i++;
	}
}


struct node	*add_last_node(struct node *head, int data)
{
	struct node	*new_node;

	new_node = malloc(sizeof(struct node));
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
		if (argv[j][i] < 48 || argv[j][i] > 57 && (argv[j][i] != 45
			|| argv[j][i] != 32))
			return (0);
		if ((argv[j][i] == 45 && argv[j][i + 1] == 45) || (argv[j][i] == 32
			&& argv[j][i + 1] == 32))
			return (0);
		if (argv[j][i] == 45 && argv[j][i + 1] == 32)
			return (0);
		i++;
		if(argv[j][i] =='\0')
		{
			i = 0;
			j++;
		}
	}
	return (1);
}


struct node	*make_stack_a(struct node *stack_a, int argc, char **argv)
{
	int	i;
	struct node *temp;

	if(!stack_a)
		return (0);
	temp = malloc(sizeof(struct node));
	if (!check_args(argc, argv) || !temp || !stack_a)
		return (0);
	i = 1;
	stack_a->data = atoi(argv[i]);
	stack_a->prev = NULL;
	stack_a->next = NULL;
	i++;
	temp = stack_a;
	while (argc > i)
	{
		temp = add_last_node(temp, atoi(argv[i]));
		i++;
	}
	temp = stack_a;	
	return (stack_a);
}

struct node	*make_stack_b(struct node **stack_a, int argc)
{
	struct node	*stack_b;
	int i;
	
	i = 0;

	stack_b = malloc(sizeof(struct node));
	if (!stack_b)
		return (0);
	stack_b = add_last_node(stack_b, (*stack_a)->data);
	remove_first_node(stack_a);
	printf("pa\n");
	if(argc > 5)
		pa(stack_a, &stack_b,'a');
	return (stack_b);
}

int	main(int argc, char **argv)
{
	int			i;
	struct node	*stack_a;
	struct node	*stack_b;

	stack_a = malloc(sizeof(struct node));
	stack_a = make_stack_a(stack_a, argc, argv);
	if(!stack_a)
		return (0);
	if(argc <= 4)
		return (sort_three(&stack_a));
	// sort(&stack_a);
	return (0);
}

// first push 2 top numbers to stack b
// find which numbers is the cheapest to push to stack b and keep order
// keep repeating until 3 numbers are left in stack a
// then sort the 3 numbers in stack a
// push  from stack b to stack a
// with every push to stack a check if its the smallest number while not keep pushhing
// if its the smallest number sort stack a
// keep repeating until stack b is empty
// then sort stack a
// print the operations
// free the stacks
// return 0