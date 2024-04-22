/*
function sort_stack_a(stackA, stackB):
    while stackA is not sorted:
        find the smallest number in stackA
        use the appropriate operations to move it to the top of stackA
        use the 'pb' operation to move it to stackB
    while stackB is not empty:
        use the 'pa' operation to move all numbers back to stackA

*/

#include "push_swap.h"

static int  find_smallest(t_stack **stack)
{
    int i;
    int smallest;
    int smallest_index;

    i = 0;
    smallest = (*stack)->data[i];
    while (i < (*stack)->size)
    {
        if ((*stack)->data[i] < smallest)
        {
            smallest = (*stack)->data[i];
            smallest_index = i;
        }
        i++;
    }
    return (smallest_index);
}

void    sortbig(t_stack **stack)
{
    int i;

    i = 0;
    if (find_smallest(stack) < (*stack)->size / 2)
    {
        while ((*stack)->data[(*stack)->top] != find_smallest(stack))
        {
            ra(*stack);
            i++;
        }
    }
    else
    {
        while ((*stack)->data[(*stack)->top] != find_smallest(stack))
        {
            rra(*stack);
            i++;
        }
    }
    printf("ilosc rotacji = %d\n", i);
}