/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:51:44 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/24 12:05:13 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// void    sort3(t_stack **stack)
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	a = (*stack)->data[(*stack)->top];
// 	b = (*stack)->data[(*stack)->top - 1];
// 	c = (*stack)->data[(*stack)->top - 2];
// 	if (a < b && b < c && a < c)
// 		return ;
// 	else if (a < b && b > c && a < c)
// 	{
// 		rra(*stack);
// 		sa(*stack);
// 		return ;
// 	}
// 	else if (a > b && b < c && a < c)
// 	{
// 		sa(*stack);
// 		return ;
// 	}
// 	else if (a < b && b > c && a > c)
// 	{
// 		rra(*stack);
// 		return ;
// 	}
// 	else if (a > b && b < c && a > c)
// 	{
// 		ra(*stack);
// 		return ;
// 	}
// 	else if (a > b && b > c && a > c)
// 	{
// 		ra(*stack);
// 		sa(*stack);
// 		return ;
// 	}
// }

void sort3(t_stack **stack)
{
    if ((*stack)->data[0].data > (*stack)->data[1].data && (*stack)->data[1].data < (*stack)->data[2].data && (*stack)->data[2].data > (*stack)->data[0].data)
        sa(*stack);
    else if ((*stack)->data[0].data > (*stack)->data[1].data && (*stack)->data[1].data > (*stack)->data[2].data && (*stack)->data[2].data < (*stack)->data[0].data)
    {
        sa(*stack);
        rra(*stack);
    }
    else if ((*stack)->data[0].data > (*stack)->data[1].data && (*stack)->data[1].data < (*stack)->data[2].data && (*stack)->data[2].data < (*stack)->data[0].data)
        ra(*stack);
    else if ((*stack)->data[0].data < (*stack)->data[1].data && (*stack)->data[1].data > (*stack)->data[2].data && (*stack)->data[2].data > (*stack)->data[0].data)
    {
        sa(*stack);
        ra(*stack);
    }
    else if ((*stack)->data[0].data < (*stack)->data[1].data && (*stack)->data[1].data > (*stack)->data[2].data && (*stack)->data[2].data < (*stack)->data[0].data)
        rra(*stack);
}
