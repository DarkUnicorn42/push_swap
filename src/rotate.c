/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:29:48 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/27 17:30:43 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_stack(t_stack **stack, int smallest_index)
{
	if (smallest_index <= (*stack)->top / 2)
	{
		while ((*stack)->top != smallest_index)
		{
			ra(*stack);
		}
	}
	else
	{
		while ((*stack)->top != smallest_index)
		{
			rra(*stack);
		}
	}
}