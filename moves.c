#include "push_swap.h"

void sa(node_t **stack_a, char c)
{
	int temp;
	node_t 		*address = (*stack_a)->next;

	temp = (*stack_a)->data;
	(*stack_a)->data = address->data;
	(*stack_a)->prev = address;
	(*stack_a)->next = address->next;
	address->data = temp;
	address->next = (*stack_a);
	address->prev = NULL;
	if(c != 'x')
		printf("s%c", c);
}

void sb(node_t **stack_a, node_t **stack_b)
{
	sa(stack_a, 'x');
	sa(stack_b, 'x');
	printf("ss");
}

void pa(node_t **stack_new, node_t **stack_old, char c)
{
    node_t *temp;

    if(*stack_new ==  NULL)
        return;
    temp = *stack_new; 
    *stack_new = (*stack_new)->next;  
    if (*stack_new != NULL)
        (*stack_new)->prev = NULL;  
    temp->next = *stack_old;  
    if (*stack_old != NULL)
        (*stack_old)->prev = temp;  
    *stack_old = temp;  
	printf("p%c", c);
}

void ra(node_t **stack_a, char c)
{
	node_t *temp;
	
	temp = *stack_a;
	while(temp)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->next = *stack_a;
	temp->prev = NULL;
	(*stack_a)->prev = temp;
	if(c != 'x')
		printf("r%c", c);
}

void rr(node_t **stack_a, node_t **stack_b)
{
	ra(stack_a, 'x');
	ra(stack_b, 'x');
	printf("rr");
}

void rra(node_t **stack_a, char c)
{
	node_t *temp;
	node_t *last;

	if(*stack_a == NULL)
		return;
	temp = *stack_a;
	while(temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = *stack_a;
	temp->prev = NULL;
	(*stack_a)->prev = temp;
	*stack_a = temp;
	if(c != 'x')
		printf("rr%c", c);
}

void rrr(node_t **stack_a, node_t **stack_b)
{
	rra(stack_a, 'x');
	rra(stack_b, 'x');
	printf("rrr");
}