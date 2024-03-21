#include "push_swap.h"

void sa(node_t **stack_a)
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
}

void pa(node_t **stack_new, node_t **stack_old)
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
}

void rra(node_t **stack_a)
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
}