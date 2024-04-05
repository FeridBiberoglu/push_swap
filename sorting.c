#include "push_swap.h"

void rotate(node_t **stack_a, node_t **stack_b, node_t *cheapest)
{
    while(*stack_a != cheapest && *stack_b != (cheapest)->target)
             rr(stack_a, stack_b);    
    while((cheapest)->target != (*stack_b))
            ra(stack_b, 'b');
    while((*stack_a)->data != cheapest->data)
            ra(stack_a, 'a');
}

void reverse_rotate(node_t **stack_a, node_t **stack_b, node_t **cheapest)
{
    while(stack_a != cheapest && *stack_b != (*cheapest)->target)
            rrr(stack_a, stack_b);
    while((*cheapest)->target != *stack_b)
            rra(stack_b, 'b');
    while(stack_a != cheapest)
        rra(stack_a, 'a');
}

void a_to_b(node_t **stack_a, node_t **stack_b)
{
    node_t *cheapest;

    cheapest = *stack_a;
    while(cheapest->next)
    {
        if(cheapest->cheapest == 1)
            break;
        cheapest = cheapest->next;
    }
    if(cheapest->middle == 1 && cheapest->target->middle == 1)
        rotate(stack_a, stack_b, cheapest);
    if(cheapest->middle == 0 && cheapest->target->middle == 0)
        reverse_rotate(stack_a, stack_b, &cheapest);
    pa(stack_a, stack_b, 'b');
}

void sort(node_t **stack_a, int argc)
{
    int size_a;
    node_t *stack_b;

    stack_b = make_stack_b(stack_a, argc);
    size_a = stack_size(*stack_a);
    print_list_data(*stack_a, stack_b);
    while(size_a > 3)
    {
        init_stack_a(stack_a, &stack_b);
        a_to_b(stack_a, &stack_b);
        size_a--;
    }
    return;
}