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
    // Swap the first 2 elements at the top of stack b.
}

// etc...