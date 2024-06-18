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

void insertsort(t_stack *stackA, t_stack *stackB)
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

int	count_r(t_node *stack, int n)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != n)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void k_sort1(t_stack *stack_a, t_stack *stack_b, int length) {
    int i;
    int range;

    i = 0;
    range = ft_sqrt(length) * 14 / 10;
    while (stack_a->top) {
        if (stack_a->top->index <= i) {
            pb(stack_a, stack_b);
            rb(stack_b);
            i++;
        } else if (stack_a->top->index <= i + range) {
            pb(stack_a, stack_b);
            i++;
        } else {
            ra(stack_a);
        }
		// print_stacks(stack_a, stack_b);
        // printf("k_sort1: i = %d, range = %d\n", i, range);  // Debug print
        // print_stacks(stack_a, stack_b);  // Debug print for stack states
    }
}

void k_sort2(t_stack *stack_a, t_stack *stack_b, int length) {
    int rb_count;
    int rrb_count;

    // printf("Starting k_sort2: length = %d\n", length);  // Debug print
    while (length > 0) {
        if (stack_b->top == NULL) {
            // printf("Error: Stack B is empty\n");
            break;
        }
        rb_count = count_r(stack_b->top, length - 1);
        rrb_count = (length + 3) - rb_count;
        if (rb_count <= rrb_count) {
            while (stack_b->top && stack_b->top->index != length - 1)
                rb(stack_b);
            if (stack_b->top) {
                pa(stack_a, stack_b);
                length--;
            }
        } else {
            while (stack_b->top && stack_b->top->index != length - 1)
                rrb(stack_b);
            if (stack_b->top) {
                pa(stack_a, stack_b);
                length--;
            }
        }
        // printf("k_sort2: length = %d, rb_count = %d, rrb_count = %d\n", length, rb_count, rrb_count);  // Debug print
        // print_stacks(stack_a, stack_b);  // Debug print for stack states
    }
}



