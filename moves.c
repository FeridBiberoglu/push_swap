#include "push_swap.h"

void sa(node_t **stack_a, char c)
{
	node_t *temp;

	temp  = (*stack_a)->next;
	temp->prev = (*stack_a)->prev;

	(*stack_a)->next = temp->next;
	(*stack_a)->next->prev = (*stack_a);
	temp->next = *stack_a;

	(*stack_a)->prev = temp;
	*stack_a = temp;
	(*stack_a)->prev = NULL;
	if(c != 'x')
		printf("s%c\n", c);
}

void sb(node_t **stack_a, node_t **stack_b)
{
	sa(stack_a, 'x');
	sa(stack_b, 'x');
	printf("ss\n");
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
	printf("p%c\n", c);
}

void ra(node_t **stack_a, char c)
{
	node_t *temp;
	temp = *stack_a;
	if(!temp || !temp->next)
		return;
	while(temp->next)
		temp = temp->next;
	temp->next = *stack_a;
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
	if(c != 'x')
		printf("r%c\n", c);
}	

void rr(node_t **stack_a, node_t **stack_b)
{
	ra(stack_a, 'x');
	ra(stack_b, 'x');
	printf("rr\n");
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
		printf("rr%c\n", c);
}

void rrr(node_t **stack_a, node_t **stack_b)
{
	rra(stack_a, 'x');
	rra(stack_b, 'x');
	printf("rrr\n");
}