/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:36:25 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/27 20:55:15 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// t_stack *init_stack(void) {
//     t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
//     stack->top = NULL;
//     stack->size = 0;
//     return stack;
// }

// void push(t_stack *stack, int value) {
//     t_node *new_node = (t_node *)malloc(sizeof(t_node));
//     new_node->value = value;
//     new_node->next = stack->top;
//     stack->top = new_node;
//     stack->size++;
// }

// int pop(t_stack *stack) {
//     if (stack->size == 0) 
// 		return -1;
//     t_node *temp = stack->top;
//     int value = temp->value;
//     stack->top = stack->top->next;
//     free(temp);w
//     stack->size--;
//     return value;
// }

// void swap(t_stack *stack) {
//     if (stack->size < 2) return;
//     int first = pop(stack);
//     int second = pop(stack);
//     push(stack, first);
//     push(stack, second);
// }

// void rotate(t_stack *stack) {
//     if (stack->size < 2) return;
//     int value = pop(stack);
//     t_node *current = stack->top;
//     while (current->next != NULL) {
//         current = current->next;
//     }
//     t_node *new_node = (t_node *)malloc(sizeof(t_node));
//     new_node->value = value;
//     new_node->next = NULL;
//     current->next = new_node;
//     stack->size++;
// }

// void reverse_rotate(t_stack *stack) {
//     if (stack->size < 2) return;
//     t_node *current = stack->top;
//     while (current->next->next != NULL) {
//         current = current->next;
//     }
//     t_node *last = current->next;
//     current->next = NULL;
//     last->next = stack->top;
//     stack->top = last;
// }

// void print_operations(char *operation) {
//     write(1, operation, strlen(operation));
//     write(1, "\n", 1);
// }

// Initializes a stack
t_stack *init_stack(void) {
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->size = 0;
    stack->top = NULL;
    return (stack);
}

// Frees the memory allocated for a stack
void free_stack(t_stack *stack) {
    t_node *current;
    t_node *next;

    current = stack->top;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

// Pushes a value onto the stack
void push(t_stack *stack, int value) {
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pops a value from the stack
int pop(t_stack *stack) {
    int value;
    t_node *temp;

    if (stack->size == 0)
        return (0);
    temp = stack->top;
    value = temp->value;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return (value);
}

// Prints the current state of the stack (for debugging)
void print_stack(t_stack *stack) {
    t_node *current;

    current = stack->top;
    while (current) {
        printf("%d\n", current->value);
        current = current->next;
    }
}