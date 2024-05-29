/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:00:52 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/29 14:30:04 by mwojtcza         ###   ########.fr       */
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

void sort_small_stack(t_stack *stackA) {
    if (stackA->top == 1 && stackA->data[0] > stackA->data[1]) {
        sa(stackA);
    }
    if (stackA->top == 2) {
        if (stackA->data[1] > stackA->data[2]) {
            sa(stackA);
        }
        if (stackA->data[0] > stackA->data[2]) {
            ra(stackA);
            ra(stackA);
        }
        if (stackA->data[0] > stackA->data[1]) {
            sa(stackA);
        }
    }
}

void turksort(t_stack *stackA, t_stack *stackB, int size) {
    if (size <= 3) {
        sort_small_stack(stackA);
        return;
    }

    int mid = size / 2;

    for (int i = 0; i < mid; i++) {
        pb(stackA, stackB);
    }

    turksort(stackA, stackB, size - mid);
    turksort(stackB, stackA, mid);

    while (stackB->top != -1) {
        pa(stackA, stackB);
    }
}
