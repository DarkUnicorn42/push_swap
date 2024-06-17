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
void	sa(t_stack *stack)
{
	int	temp;	
	t_node	*first = stack->top;
	t_node	*second = stack->top->next;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	print_operation("sa");
}

void	sb(t_stack *stack)
{
	int	temp;	
	t_node	*first = stack->top;
	t_node	*second = stack->top->next;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	print_operation("sb");
}

void	pa(t_stack *stackA, t_stack *stackB)
{
	t_node	*node_to_move = stackB->top;
	if (stackB->top != NULL)
	{
		stackB->top = stackB->top->next;
		node_to_move->next = stackA->top;
		stackA->top = node_to_move;
		stackB->size--;
		stackA->size++;
	}
	print_operation("pa");
}

/* Function to push the top element from stack A to stack B */
void	pb(t_stack *stackA, t_stack *stackB)
{
	t_node	*node_to_move = stackA->top;
	if (stackA->top != NULL)
	{
		stackA->top = stackA->top->next;
		node_to_move->next = stackB->top;
		stackB->top = node_to_move;
		stackA->size--;
		stackB->size++;
	}
	print_operation("pb");
}

/* Function to rotate stack A (shift all elements up by one position) */
void	ra(t_stack *stack)
{
	t_node	*first = stack->top;
	t_node	*last = stack->top;

	while (last->next != NULL)
	{
		last = last->next;
	}

	stack->top = first->next;
	first->next = NULL;
	last->next = first;
	print_operation("ra");
}
