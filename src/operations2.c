/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:41:56 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/27 20:57:54 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Function to rotate stack B (shift all elements up by one position) */
void	rb(t_stack *stackB)
{
	int	i;
	int	temp;

	if (stackB->top >= 1)
	{
		temp = stackB->data[stackB->top];
		i = 0;
		while (i < stackB->top)
		{
			stackB->data[stackB->top - i] = stackB->data[stackB->top - i - 1];
			i++;
		}
		stackB->data[0] = temp;
	}
	print_operation("rb");
}

/* Function to rotate both stack A and stack B simultaneously */
void	rr(t_stack *stackA, t_stack *stackB)
{
	ra(stackA);
	rb(stackB);
	print_operation("rr");
}

void	rra(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	if (stack->top >= 1)
	{
		temp = stack->data[0];
		while (i < stack->top)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->top] = temp;
	}
	print_operation("rra");
}

void	rrb(t_stack *stackB)
{
	int	i;
	int	temp;

	if (stackB->top >= 1)
	{
		temp = stackB->data[0];
		i = 0;
		while (i < stackB->top)
		{
			stackB->data[i] = stackB->data[i + 1];
			i++;
		}
		stackB->data[stackB->top] = temp;
	}
	print_operation("rrb");
}

/* Function to reverse rotate both stack A and stack B simultaneously */
void	rrr(t_stack *stackA, t_stack *stackB)
{
	rra(stackA);
	rrb(stackB);
	print_operation("rrr");
}
