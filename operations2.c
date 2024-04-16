/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:41:56 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/04/16 13:54:34 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

/* Function to rotate both stack A and stack B simultaneously */
void	rr(t_stack *stackA, t_stack *stackB)
{
	ra(stackA);
	rb(stackB);
}

void	rra(t_stack *stackA)
{
	int	i;
	int	temp;

	if (stackA->top >= 1)
	{
		temp = stackA->data[0];
		i = 0;
		while (i < stackA->top)
		{
			stackA->data[i] = stackA->data[i + 1];
			i++;
		}
	}
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
	}
}

/* Function to reverse rotate both stack A and stack B simultaneously */
void	rrr(t_stack *stackA, t_stack *stackB)
{
	rra(stackA);
	rrb(stackB);
}
