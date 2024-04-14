/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:41:56 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/04/14 13:42:06 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack is a pointer to a t_stack struct
//stack->data is a pointer to an array of integers
//stack->top is an integer that represents the index of the top element of the stack
//stack->data[stack->top] is the top element of the stack
//stack->data[stack->top - 1] is the second-to-top element of the stack
//stack->data[stack->top - 2] is the third-to-top element of the stack
//etc...

// Function to swap the top two elements of a stack
void sa(t_Stack *stack) {
    int temp;

    // Check if the stack has at least two elements
    // (since we can't swap the top two elements if there are less than two elements)
    if (stack->top >= 1) {
        // Store the top element of the stack in the temporary variable
        // This is necessary because we're about to overwrite the top element in the next step
        temp = stack->data[stack->top];

        // Replace the top element of the stack with the second-to-top element
        // After this line, the top two elements of the stack are the same
        stack->data[stack->top] = stack->data[stack->top - 1];

        // Replace the second-to-top element of the stack with the original top element
        // (which we stored in the temporary variable)
        // After this line, the top two elements of the stack have been swapped
        stack->data[stack->top - 1] = temp;
    }
    // If the stack has less than two elements, do nothing
}

void sb(t_Stack *stack) {
    int temp;

    if (stack->top >= 1) {
        temp = stack->data[stack->top];
        stack->data[stack->top] = stack->data[stack->top - 1];
        stack->data[stack->top - 1] = temp;
    }
}

// Function to push the top element from stack B to stack A
void pa(t_Stack *stackA, t_Stack *stackB)
{
    // Check if stack B is not empty
    if (stackB->top >= 0)
    {
        // Increment the top index of stack A
        stackA->top++;

        // Copy the top element of stack B to the top of stack A
        stackA->data[stackA->top] = stackB->data[stackB->top];

        // Decrement the top index of stack B
        stackB->top--;
    }

}

// Function to push the top element from stack A to stack B
void pb(t_Stack *stackA, t_Stack *stackB)
{
    if (stackA->top >= 0)
    {
        stackB->top++;
        stackB->data[stackB->top] = stackA->data[stackA->top;
        stackA->top--;]
    }
}

// Function to rotate stack A (shift all elements up by one position)
void ra(t_Stack *stack)
{
    int i;
    int temp;

    if (stackA->top >= 1)
    {
        temp = stackA->data[stackA->top];
        i = 0;
        while(i < stackA->top)
        {
            stackA->data[stackA->top - i] = stackA->data[stackA->top - i - 1];
            i++;
        }
        stackA->data[0] = temp;
    }
}

// Function to rotate stack B (shift all elements up by one position)
void rb(t_Stack *stack)
{
    int i;
    int temp;

    if (stackB->top >= 1)
    {
        temp = stackB->data[stackB->top];
        i = 0;
        while(i < stackB->top)
        {
            stackB->data[stackB->top - i] = stackB->data[stackB->top - i - 1];
            i++;
        }
        stackB->data[0] = temp;
    }
}

// Function to rotate both stack A and stack B simultaneously
void rr(t_Stack *stackA, t_Stack *stackB)
{
    ra(stackA);
    rb(stackB);
}

// Function to reverse rotate stack A (shift all elements down by one position)
void rra(t_Stack *stack)
{
    int i;
    int temp;

    if (stackA->top >= 1)
    {
        temp = stackA->data[0];
        i = 0;
        while(i < stackA->top)
        {
            stackA->data[i] = stackA->data[i + 1];
            i++;
        }
    }
}

// Function to reverse rotate stack B (shift all elements down by one position)
void rrb(t_Stack *stack)
{
    int i;
    int temp;

    if (stackB->top >= 1)
    {
        temp = stackB->data[0];
        i = 0;
        while(i < stackB->top)
        {
            stackB->data[i] = stackB->data[i + 1];
            i++;
        }
    }
}

// Function to reverse rotate both stack A and stack B simultaneously
void rrr(t_Stack *stackA, t_Stack *stackB)
{
    rra(stackA);
    rrb(stackB);
}
