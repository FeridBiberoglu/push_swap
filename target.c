#include "push_swap.h"

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

	while(a)
	{
		closest = -2147483648;
		bcurrent = stack_b;
		while(bcurrent)
		{
			if(bcurrent->data < stack_a->data && bcurrent->data > closest)
			{
				closest = bcurrent->data;
				target = bcurrent;
			}
			bcurrent = bcurrent->next;
		}
		if(closest == -2147483648)
			stack_a->target_node = biggestnumber(stack_b);
		else
			stack_a->target_node = target_node;
		a = a->next;
	}
}
void set_middle_node(node_t *stack)
{
	int i;
	int j;

	i = 0;
	j = stack_size(stack) / 2;
	while(stack)
	{
		if(i <= j)
			stack->middle = 1;
		else
			stack->middle = 0;
		stack->index = i;
		stack = stack->next;
		i++;
	}
}