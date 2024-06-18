/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:23:41 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/06/18 14:41:07 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insertsort(t_stack *stackA, t_stack *stackB)
{
	while (stackA->size > 3)
		insert_into_b(stackA, stackB);
	sort_small_stack(stackA);
	while (stackB->size > 0)
		pa(stackA, stackB);
}
