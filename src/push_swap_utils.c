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

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	check_duplicates(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] == nums[j])
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void print_stack(t_stack *stack)
{
    int i;

    i = 0;
    while (i <= stack->top)
    {
        printf("Data: %d, Index: %d\n", stack->data[i].data, stack->data[i].index);
        i++;
    }
}

void push(t_stack *stack, int num)
{
    if (stack->top < stack->size - 1)
    {
        stack->top++;
        stack->data[stack->top].data = num;
    }
}

int find_min_index(t_stack *stack)
{
    int i;
    int min_index;

    i = 0;
    min_index = stack->data[0].index;
    while (i <= stack->top)
    {
        if (stack->data[i].index < min_index)
            min_index = stack->data[i].index;
        i++;
    }
    return (min_index);
}