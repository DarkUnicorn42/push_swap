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

// Pushes the top element of stack b onto stack a
void push_a(t_stack *a, t_stack *b) {
    if (b->size == 0)
        return;
    push(a, pop(b));
}

// Pushes the top element of stack a onto stack b
void push_b(t_stack *a, t_stack *b) {
    if (a->size == 0)
        return;
    push(b, pop(a));
}

// Rotates all elements of stack a up by one
void rotate_a(t_stack *a) {
    if (a->size < 2)
        return;
    t_node *first = a->top;
    a->top = a->top->next;
    first->next = NULL;
    t_node *current = a->top;
    while (current->next != NULL)
        current = current->next;
    current->next = first;
}

// Rotates all elements of stack b up by one
void rotate_b(t_stack *b) {
    if (b->size < 2)
        return;
    t_node *first = b->top;
    b->top = b->top->next;
    first->next = NULL;
    t_node *current = b->top;
    while (current->next != NULL)
        current = current->next;
    current->next = first;
}

// Rotates all elements of both stacks up by one
void rotate_both(t_stack *a, t_stack *b) {
    rotate_a(a);
    rotate_b(b);
}

// Shifts all elements of stack a down by one
void reverse_rotate_a(t_stack *a) {
    if (a->size < 2)
        return;
    t_node *current = a->top;
    while (current->next->next != NULL)
        current = current->next;
    t_node *last = current->next;
    current->next = NULL;
    last->next = a->top;
    a->top = last;
}

// Shifts all elements of stack b down by one
void reverse_rotate_b(t_stack *b) {
    if (b->size < 2)
        return;
    t_node *current = b->top;
    while (current->next->next != NULL)
        current = current->next;
    t_node *last = current->next;
    current->next = NULL;
    last->next = b->top;
    b->top = last;
}

// Shifts all elements of both stacks down by one
void reverse_rotate_both(t_stack *a, t_stack *b) {
    reverse_rotate_a(a);
    reverse_rotate_b(b);
}