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

// void	ra(node_t **stack, char c) //Define a function that rotates the stack's top node to the bottom of the stack
// {
// 	node_t	*last_node; //To store a pointer to the last node of a stack

// 	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
// 		return ;
// 	while(last_node->next)
// 		last_node = last_node->next;
// 	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
// 	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
// 	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
// 	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
// 	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
// 	if(c != 'x')
// 		printf("r%c\n", c);
// }	

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
		printf("rr%c", c);
}

void rrr(node_t **stack_a, node_t **stack_b)
{
	rra(stack_a, 'x');
	rra(stack_b, 'x');
	printf("rrr");
}