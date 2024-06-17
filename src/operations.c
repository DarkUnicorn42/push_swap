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

// Swaps the first two elements of stack a
void swap_a(t_stack *a) {
    int temp;

    if (a->size < 2)
        return;
    temp = a->top->value;
    a->top->value = a->top->next->value;
    a->top->next->value = temp;
}

// Swaps the first two elements of stack b
void swap_b(t_stack *b) {
    int temp;

    if (b->size < 2)
        return;
    temp = b->top->value;
    b->top->value = b->top->next->value;
    b->top->next->value = temp;
}

// Swaps the first two elements of both stacks
void swap_both(t_stack *a, t_stack *b) {
    swap_a(a);
    swap_b(b);
}