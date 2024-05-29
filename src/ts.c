/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:00:52 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/29 14:39:39 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	swap(int *a, int *b)
// {
// 	int	temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// static int	partition(int *arr, int low, int high)
// {
// 	int	pivot;
// 	int	i;
// 	int	j;

// 	pivot = arr[high];
// 	i = low - 1;
// 	j = low;
// 	while (j < high)
// 	{
// 		if (arr[j] < pivot)
// 		{
// 			i++;
// 			swap(&arr[i], &arr[j]);
// 		}
// 		j++;
// 	}
// 	swap(&arr[i + 1], &arr[high]);
// 	return (i + 1);
// }

// static void	qs_recursive(int *arr, int low, int high)
// {
// 	int	i;

// 	if (low < high)
// 	{
// 		i = partition(arr, low, high);
// 		qs_recursive(arr, low, i - 1);
// 		qs_recursive(arr, i + 1, high);
// 	}
// }

// void	qs(int *arr, int size)
// {
// 	qs_recursive(arr, 0, size - 1);
// }


int find_min_index(t_stack *stack) {
    int min_index = stack->top;
    for (int i = stack->top; i >= 0; i--) {
        if (stack->data[i] < stack->data[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

void sort_small_stack(t_stack *stack) {
    if (stack->top == 1 && stack->data[stack->top] > stack->data[stack->top - 1]) {
        sa(stack);
    }
    if (stack->top == 2) {
        if (stack->data[stack->top] > stack->data[stack->top - 1]) {
            sa(stack);
        }
        if (stack->data[stack->top - 1] > stack->data[stack->top - 2]) {
            ra(stack);
            sa(stack);
            rra(stack);
        }
        if (stack->data[stack->top] > stack->data[stack->top - 1]) {
            sa(stack);
        }
    }
}

void insert_into_b(t_stack *stackA, t_stack *stackB) {
    int min_index = find_min_index(stackA);
    int rotations = stackA->top - min_index;

    while (rotations-- > 0) {
        ra(stackA);
    }
    pb(stackA, stackB);
}

void turksort(t_stack *stackA, t_stack *stackB, int size) {
    while (stackA->top > 2) {
        insert_into_b(stackA, stackB);
    }

    sort_small_stack(stackA);

    while (stackB->top != -1) {
        pa(stackA, stackB);
    }
}
