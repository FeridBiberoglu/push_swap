#include "push_swap.h"
#include <unistd.h>

node_t *biggestnumber(node_t *stack)
{
	node_t *temp;
	node_t *biggest;

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

int stack_size(node_t *stack)
{
	int i;
	node_t *temp;

	i = 0;
	temp = stack;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void target_node(node_t *stack_a, node_t *stack_b)
{
	node_t *bcurrent;
	node_t *target;
	int closest;
	node_t *temp = stack_a;
	while((stack_a))
	{
		closest = -2147483648;
		bcurrent = stack_b;
		while(bcurrent)
		{
			if(bcurrent->data < (stack_a)->data && bcurrent->data > closest)
			{
				closest = bcurrent->data;
				target = bcurrent;
			}
			bcurrent = bcurrent->next;
		}
		if(closest == -2147483648)
			(stack_a)->target = biggestnumber(stack_b);
		else
			(stack_a)->target = target;
		(stack_a) = (stack_a)->next;
	}
}

void set_middle_node(node_t *stack)
{
	int i;
	int j;

	i = 0;
	j = stack_size(stack) / 2;
	while((stack))
	{
		if(i <= j)
			(stack)->middle = 1;
		else
			(stack)->middle = 0;
		(stack)->index = i;
		(stack) = (stack)->next;
		i++;
	}
}

void calculate_cheapest(node_t **stack_a, node_t **stack_b)
{
	int size_a;
	int size_b;
	node_t *temp;

	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	temp = *stack_a;
	while((*stack_a))
	{
		(*stack_a)->cost = (*stack_a)->index;
		if((*stack_a)->middle == 0)
			(*stack_a)->cost = size_a - (*stack_a)->index;
		if((*stack_a)->target->middle == 1)
			(*stack_a)->cost += (*stack_a)->target->index;
		else
			(*stack_a)->cost += size_b - (*stack_a)->target->index;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = temp;
}

void mark_cheapest(node_t **stack_a)
{
	int cheap;
	node_t *cheapest_node;
	node_t *temp = *stack_a;

	cheap = (*stack_a)->cost;
	while((*stack_a))
	{
		if((*stack_a)->cost < cheap)
		{
			cheap = (*stack_a)->cost;
			cheapest_node = *stack_a;
		}
		if((*stack_a)->next)
			*stack_a = (*stack_a)->next;
		else 
			break;
	}
	while(*stack_a)
	{
		if((*stack_a)->cost == cheap)
		{
			(*stack_a)->cheapest = 1;
			break;
		}
		else
			(*stack_a)->cheapest = 0;
		*stack_a = (*stack_a)->prev;
	}
	*stack_a = temp;
}

void init_stack_a(node_t **stack_a, node_t **stack_b)
{
	set_middle_node(*stack_a);
	set_middle_node(*stack_b);
	target_node(*stack_a, *stack_b);
	calculate_cheapest(stack_a, stack_b);
	mark_cheapest(stack_a);
}