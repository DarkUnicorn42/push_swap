/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:00:52 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/29 13:34:15 by mwojtcza         ###   ########.fr       */
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

void	partition(t_stack *stackA, t_stack *stackB, int low, int high)
{
    if (low < high) {
        int pivot = stackA->data[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (stackA->data[j] < pivot) {
                i++;
                // Move all elements < pivot to stackB
                while (stackA->top > i) {
                    pb(stackA, stackB);
                }
                pa(stackA, stackB);
            }
        }
        // Move pivot to its correct position
        while (stackA->top > i + 1) {
            pb(stackA, stackB);
        }
        pa(stackA, stackB);

        int pi = i + 1;
        partition(stackA, stackB, low, pi - 1);
        partition(stackA, stackB, pi + 1, high);
    }
}

void	qs(t_stack *stackA, t_stack *stackB, int size)
{
    partition(stackA, stackB, 0, size - 1);
}