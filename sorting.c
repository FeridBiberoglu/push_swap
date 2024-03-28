#include "push_swap.h"

void sort(node_t **stack_a)
{
    int size_a;
    node_t *stack_b;

    size_a = stack_size(stack_a);
    stack_b = make_stack_b(stack_a);
    while(size_a > 3 && check_sorted(stack_a))
    {
       init_stack_a(stack_a);
       a_to_b(stack_a,stack_b);
       size_a--;
    }
    sort_three(stack_a);
    while(stack_b)
    {
        
    }
    


}