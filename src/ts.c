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
	int	min_index = 0;
	int	current_index = 0;
	t_node	*current = stack->top;	
	int	min_value = current->value;

	while (current != NULL) {
		if (current->value < min_value) {
			min_value = current->value;
			min_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (min_index);
}

void sort_small_stack(t_stack *stack)
{
    if (stack->size == 2) {
        if (stack->top->value < stack->top->next->value) {
            sa(stack);
        }
    } else if (stack->size == 3) {
        sort3(&stack);
    }
}

void	insert_into_b(t_stack *stackA, t_stack *stackB)
{
	int	min_index;
	int	rotations;

	min_index = find_min_index(stackA);
	if (min_index < stackA->size / 2)
	{
		rotations = min_index;
		while (rotations-- > 0)
			ra(stackA);
	}
	else
	{
		rotations = stackA->size - min_index;
		while (rotations-- > 0)
			rra(stackA);
	}
	pb(stackA, stackB);
}

void turksort(t_stack *stackA, t_stack *stackB)
{
    while (stackA->size > 3)
    {
        insert_into_b(stackA, stackB);
    }
    sort_small_stack(stackA);
    while (stackB->size > 0)
    {
        pa(stackA, stackB);
    }
}

