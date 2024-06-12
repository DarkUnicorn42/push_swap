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

void insert_into_b(t_stack *stackA, t_stack *stackB)
{
    int min_index;
    int rotations;

    min_index = find_min_index(stackA);
    if (min_index > stackA->top / 2)
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

void sort_small_stack(t_stack *stackA, t_stack *stackB)
{
    while (stackA->top > 2)
        insert_into_b(stackA, stackB);

    sort3(&stackA);

    while (stackB->top >= 0)
        pa(stackA, stackB);
}

void turksort(t_stack *stackA, t_stack *stackB)
{
    int min_index;

    while (stackA->top >= 0)
    {
        min_index = find_min_index(stackA);
        while (stackA->data[stackA->top].index != min_index)
        {
            if (stackA->data[stackA->top].index > min_index)
                ra(stackA);
            else
                rra(stackA);
        }
        pb(stackA, stackB);
    }
    while (stackB->top >= 0)
        pa(stackA, stackB);
}