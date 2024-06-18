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

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->top)
	{
		if (stack_a->top->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if (stack_a->top->index <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}
/*
		// print_stacks(stack_a, stack_b);
		// printf("k_sort1: i = %d, range = %d\n", i, range);  // Debug print
		// print_stacks(stack_a, stack_b);  // Debug print for stack states
*/

void	rotate_stack_b(t_stack *b, int length, int rb_count, int rrb_count)
{
	if (rb_count <= rrb_count)
	{
		while (b->top && b->top->index != length - 1)
			rb(b);
	}
	else
	{
		while (b->top && b->top->index != length - 1)
			rrb(b);
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length > 0)
	{
		if (stack_b->top == NULL)
			break ;
		rb_count = count_r(stack_b->top, length - 1);
		rrb_count = (length + 3) - rb_count;
		rotate_stack_b(stack_b, length, rb_count, rrb_count);
		if (stack_b->top)
		{
			pa(stack_a, stack_b);
			length--;
		}
	}
}
