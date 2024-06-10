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

int find_min_index(t_stack *stack)
{
    int min_index;
    int i;

    i = 0;
    min_index = 0;
    while (i <= stack->top) 
    {
        if (stack->data[i] < stack->data[min_index]) 
            min_index = i;
        i++;
    }
    return min_index;
}
void sort_small_stack(t_stack *stack)
{
    if (stack->top == 1)
    {
        if (stack->data[stack->top] < stack->data[stack->top - 1])
        {
            sa(stack);
        }
    }
    else if (stack->top == 2)
    {
        sort3(&stack);
    }
}

void insert_into_b(t_stack *stackA, t_stack *stackB)
{
    int min_index;
    int rotations;

    min_index = find_min_index(stackA);
    if (min_index >= stackA->top / 2)
    {
        rotations = stackA->top - min_index;
        while (rotations-- > 0)
            ra(stackA);
    }
    else
    {
        rotations = min_index + 1;
        while (rotations-- > 0)
            rra(stackA);
    }
    pb(stackA, stackB);
}

void turksort(t_stack *stackA, t_stack *stackB)
{
    while (stackA->top > 2)
    {
        insert_into_b(stackA, stackB);
    }
    sort_small_stack(stackA);
    while (stackB->top != -1)
    {
        pa(stackA, stackB);
    }
}

