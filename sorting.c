#include "push_swap.h"

void rotate(node_t **stack_a, node_t **stack_b, node_t *cheapest)
{
    while(*stack_a != cheapest && *stack_b != (cheapest)->target)
           {
            printf("z\n");
             rr(stack_a, stack_b);    
            }
    while((cheapest)->target != *stack_b)
            {
                printf("y\n");
            ra(stack_b, 'b');
            }
    while(*stack_a != cheapest)
    {
        printf("c\n");
            ra(stack_a, 'a');
        }
 printf("abc\n");
}

void reverse_rotate(node_t **stack_a, node_t **stack_b, node_t **cheapest)
{
    while(stack_a != cheapest && *stack_b != (*cheapest)->target)
        {
            printf("z\n");
            rrr(stack_a, stack_b);
            }
    while((*cheapest)->target != *stack_b)
        {
            printf("y\n");
            rra(stack_b, 'b');
        }
    while(stack_a != cheapest)
    {
        printf("c\n");
        rra(stack_a, 'a');
        }
    printf("123\n");
}

void a_to_b(node_t **stack_a, node_t **stack_b)
{
    node_t *cheapest;

    cheapest = *stack_a;
    while(cheapest->cheapest != 1)
        cheapest = cheapest->next;
    if(cheapest->middle == 1 && cheapest->target->middle == 1)
        rotate(stack_a, stack_b, cheapest);
    if(cheapest->middle == 0 && cheapest->target->middle == 0)
        reverse_rotate(stack_a, stack_b, &cheapest);
}

void sort(node_t **stack_a, int argc)
{
    int size_a;
    node_t *stack_b;

    stack_b = make_stack_b(stack_a, argc);
    size_a = stack_size(*stack_a);
    while(size_a > 3 && !check_sorted(*stack_a))
    {
        init_stack_a(*stack_a, stack_b);
        a_to_b(stack_a, &stack_b);
        size_a--;
    }
    return;
}