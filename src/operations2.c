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
void rb(t_stack *stack) {
    if (stack->top == NULL) {
       // printf("Error: Stack is empty, cannot perform rb\n");
        return;
    }
    if (stack->top && stack->top->next) {
        t_node *first = stack->top;
        t_node *temp = stack->top;
        while (temp->next) {
            temp = temp->next;
        }
        stack->top = first->next;
        first->next = NULL;
        temp->next = first;
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
	if (stack->top != NULL && stack->top->next != NULL)
	{
		t_node	*prev = NULL;
		t_node	*current = stack->top;

		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		if (prev == NULL)
			return;
		prev->next = NULL;
		current->next = stack->top;
		stack->top = current;
	}
	print_operation("rra");
}

void rrb(t_stack *stack) {
    if (stack->top == NULL || stack->top->next == NULL) {
        //printf("Error: Stack has too few elements, cannot perform rrb\n");
        return;
    }
    t_node *temp = stack->top;
    t_node *prev = NULL;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    if (prev) {
        prev->next = NULL;
    }
    temp->next = stack->top;
    stack->top = temp;
	print_operation("rrb");
}

/* Function to reverse rotate both stack A and stack B simultaneously */
void	rrr(t_stack *stackA, t_stack *stackB)
{
	rra(stackA);
	rrb(stackB);
	print_operation("rrr");
}
