/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:00:52 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/29 14:39:39 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int find_min_index(t_stack *stack)
// {
//     int min_index;
//     int i;
    
//     i = stack->top - 1;
//     min_index = stack->top;
//     while (i >= 0)
//     {
//         if (stack->data[i] < stack->data[min_index]) 
//             min_index = i;
//         i--;
//     }
//     return (min_index);
// }
int find_min_index(t_stack *stack)
{
    int min_index = 0; // Start with the bottom of the stack
   // printf("Initial min_index: %d, value: %d\n", min_index, stack->data[min_index]);
    for (int i = 1; i <= stack->top; i++) 
    {
        //printf("Checking index %d, value: %d\n", i, stack->data[i]);
        if (stack->data[i] < stack->data[min_index]) 
        {
            min_index = i;
           // printf("New min_index found: %d (value: %d)\n", min_index, stack->data[min_index]);
        }
    }
    return min_index;
}
void sort_small_stack(t_stack *stack)
{
    if (stack->top == 1) // Two elements
    {
        if (stack->data[stack->top] < stack->data[stack->top - 1])
        {
            sa(stack);
        }
    }
    else if (stack->top == 2) // Three elements
    {
        sort3(&stack);
    }
}


void insert_into_b(t_stack *stackA, t_stack *stackB)
{
    int min_index;
    int rotations;

    min_index = find_min_index(stackA);
    if (min_index >= stackA->top / 2) {
        rotations = stackA->top - min_index;
        while (rotations-- > 0)
            ra(stackA);
    } else {
        rotations = min_index + 1;
        while (rotations-- > 0)
            rra(stackA);
    }
    pb(stackA, stackB);
}
// void insert_into_b(t_stack *stackA, t_stack *stackB) {
//     int min_index = find_min_index(stackA);
//     int rotations;

//     printf("min_index: %d\n", min_index);

//     // Calculate rotations considering the index from the right
//     if (min_index <= stackA->top / 2) {
//         rotations = min_index;
//         printf("Using ra for %d times\n", rotations);
//         while (rotations-- > 0)
//             ra(stackA);
//     } else {
//         rotations = stackA->top - min_index;
//         printf("Using rra for %d times\n", rotations);
//         while (rotations-- > 0)
//             rra(stackA);
//     }
//     pb(stackA, stackB);
// }
void turksort(t_stack *stackA, t_stack *stackB)
{
    while (stackA->top > 2) {
        insert_into_b(stackA, stackB);
    }

    sort_small_stack(stackA);

    while (stackB->top != -1) {
        pa(stackA, stackB);
    }
}

