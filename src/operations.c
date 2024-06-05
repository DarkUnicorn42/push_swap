/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:41:56 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/29 13:40:01 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* stack is a pointer to a t_stack struct
stack->data is a pointer to an array of integers
stack->top is an integer that represents the index 
...of the top element of the stack
stack->data[stack->top] is the top element of the stack
stack->data[stack->top - 1] is the second-to-top element of the stack
stack->data[stack->top - 2] is the third-to-top element of the stack
etc... */

// Function to swap the top two elements of a stack
void sa(t_stack *stack)
{
    int temp;

    if (stack->top > 0)
    {
        temp = stack->data[stack->top];
        stack->data[stack->top] = stack->data[stack->top - 1];
        stack->data[stack->top - 1] = temp;
    }
    print_operation("sa");
}


void	sb(t_stack *stack)
{
	int	temp;

	if (stack->top >= 1)
	{
		temp = stack->data[stack->top];
		stack->data[stack->top] = stack->data[stack->top - 1];
		stack->data[stack->top - 1] = temp;
	}
	print_operation("sb");
}

void	pa(t_stack *stackA, t_stack *stackB)
{
	if (stackB->top >= 0)
	{
		stackA->top++;
		stackA->data[stackA->top] = stackB->data[stackB->top];
		stackB->top--;
		stackA->size++;
		stackB->size--;
	}
	print_operation("pa");
}

/* Function to push the top element from stack A to stack B */
void	pb(t_stack *stackA, t_stack *stackB)
{
	if (stackA->top >= 0)
	{
		stackB->top++;
		stackB->data[stackB->top] = stackA->data[stackA->top];
		stackA->top--;
		stackA->size--;
		stackB->size++;
	}
	print_operation("pb");
}

/* Function to rotate stack A (shift all elements up by one position) */
void ra(t_stack *stack)
{
    int temp;
    int i;

    if (stack->top >= 1)
    {
        temp = stack->data[stack->top];
        for (i = stack->top; i > 0; i--)
        {
            stack->data[i] = stack->data[i - 1];
        }
        stack->data[0] = temp;
    }
    print_operation("ra");
}
