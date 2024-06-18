/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:23:41 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/06/18 14:56:45 by mwojtcza         ###   ########.fr       */
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

void	parse_split_input(char *input, int *nums)
{
	char	**split;
	int		i;
	int		num;

	split = ft_split(input, ' ');
	if (!split)
		ft_error();
	i = 0;
	while (split[i])
	{
		num = ft_atoi2(split[i]);
		if (num == -1 && (split[i][0] != '-' || ft_atoi2(&split[i][1]) != 0))
		{
			free(split);
			ft_error();
		}
		nums[i] = num;
		i++;
	}
	free(split);
}
