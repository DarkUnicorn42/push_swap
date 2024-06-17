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

// Finds the minimum value in the stack
int find_min(t_stack *a) {
    int min;
    t_node *current;

    if (a->size == 0)
        return (0);
    min = a->top->value;
    current = a->top->next;
    while (current) {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

// Finds the maximum value in the stack
int find_max(t_stack *a) {
    int max;
    t_node *current;

    if (a->size == 0)
        return (0);
    max = a->top->value;
    current = a->top->next;
    while (current) {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

// Calculates the number of moves required to sort the stack
int calculate_moves(t_stack *a, int value) {
    int moves;
    t_node *current;

    moves = 0;
    current = a->top;
    while (current) {
        if (current->value == value)
            break;
        moves++;
        current = current->next;
    }
    return (moves);
}