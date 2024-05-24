/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:51:49 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/24 12:22:34 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
function sort_stack_a(stackA, stackB):
    while stackA is not sorted:
        find the smallest number in stackA
        use the appropriate operations to move it to the top of stackA
        use the 'pb' operation to move it to stackB
    while stackB is not empty:
        use the 'pa' operation to move all numbers back to stackA

*/

#include "../includes/push_swap.h"

static int	find_smallest(t_stack **stack)
{
	int	i;
	int	smallest;
	int	smallest_index;

	i = 0;
	smallest_index = 0;
	smallest = (*stack)->data[0];
	while (i < (*stack)->size)
	{
		if ((*stack)->data[i] < smallest)
		{
			smallest = (*stack)->data[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

void	sortbig(t_stack **stackA, t_stack **stackB)
{
	int	counter;
	int	smallest_index;

	smallest_index = find_smallest(stackA);
	counter = 0;

while ((*stackA)->top != 0)
{
	while ((*stackA)->top != smallest_index)
	{
		// if (smallest_index < ((*stackA)->size / 2))
			ra(*stackA);
		// else
			// rra(*stackA);
		counter++;
		smallest_index = find_smallest(stackA);
	}
	pb(*stackA, *stackB);
	counter++;
}

while ((*stackB)->top != -1)
{
	pa(*stackA, *stackB);
	counter++;
}

    printf("ilosc rotacji = %d\n\n", counter);
}