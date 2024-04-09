#include "push_swap.h"

void ready_for_push(node_t **stack_a, node_t **stack_b, node_t *cheapest)
{
    while((*stack_a) != cheapest && cheapest->middle == 1)
        ra(stack_a, 'a');
    while((*stack_b) != cheapest->target && cheapest->middle == 1)
            ra(stack_b, 'b');
    while((*stack_a) != cheapest && cheapest->middle == 0)
        rra(stack_a, 'a');
    while((*stack_b) != cheapest->target && cheapest->middle == 0)
        rra(stack_b, 'b');
}

void rotate(node_t **stack_a, node_t **stack_b, node_t *cheapest)
{
    while((*stack_a) != cheapest && (*stack_b) != cheapest->target)
        rr(stack_a, stack_b);
    while((*stack_a) != cheapest)
        ra(stack_a, 'a');
    while((*stack_b) != cheapest->target)
        ra(stack_b, 'b');
}

void reverse_rotate(node_t **stack_a, node_t **stack_b, node_t *cheapest)
{
    while((*stack_a) != cheapest && (*stack_b) != cheapest->target)
        rrr(stack_a, stack_b);
    while((*stack_a) != cheapest)
        rra(stack_a, 'a');
    while((*stack_b) != cheapest->target)
        rra(stack_b, 'b');
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
    print_list_data(*stack_a, *stack_b);
    if(cheapest->middle == 1 && cheapest->target->middle == 1)
        rotate(stack_a, stack_b, cheapest);
    else if(cheapest->middle == 0 && cheapest->target->middle == 0)
        reverse_rotate(stack_a, stack_b, cheapest);
    else 
        ready_for_push(stack_a, stack_b, cheapest);
    pa(stack_a, stack_b, 'b');
}

void sort(node_t **stack_a, int argc)
{
    int size_a;
    node_t *stack_b;

    stack_b = make_stack_b(stack_a, argc);
    size_a = stack_size(*stack_a);
    while(size_a > 3)
    {
        init_stack_a(stack_a, &stack_b);
        a_to_b(stack_a, &stack_b);
        size_a--;
    }
    while(!check_sorted_b(stack_b))
        ra(&stack_b, 'b');
        print_list_data(*stack_a, stack_b);
    return;
    while(stack_b)
}
