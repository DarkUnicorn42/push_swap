/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:36:25 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/29 14:37:26 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	allocate_stacks(t_stack **stackA, t_stack **stackB)
{
	*stackA = (t_stack *)malloc(sizeof(t_stack));
	*stackB = (t_stack *)malloc(sizeof(t_stack));
	if (*stackA == NULL || *stackB == NULL)
		return (-1);
	(*stackA)->top = NULL;
	(*stackB)->top = NULL;
	(*stackA)->size = 0;
	(*stackB)->size = 0;
	return (0);
}

int	fill_nums_array(int argc, char **argv, int *nums)
{
	int		i;
	int		num;

	i = 0;
	if (argc > 2)
	{
		while (i < argc - 1)
		{
			num = ft_atoi2(argv[i + 1]);
			if (num == -1 && argv[i + 1][0] != '-')
				ft_error();
			else if (num == -1 && ft_atoi2(&argv[i + 1][1]) != 0)
				ft_error();
			nums[i] = num;
			i++;
		}
	}
	else if (argc == 2)
		parse_split_input(argv[1], nums);
	else
		ft_error();
	return (0);
}

void	initialize_nums_array(int argc, char **argv, int **nums, int *num_nums)
{
	if (argc == 2)
		*num_nums = ft_word_countv2(argv[1], ' ');
	else
		*num_nums = argc - 1;
	*nums = (int *)malloc(*num_nums * sizeof(int));
	if (*nums == NULL)
		ft_error();
	if (fill_nums_array(argc, argv, *nums) == -1)
	{
		free(*nums);
		ft_error();
	}
	if (check_duplicates(*nums, *num_nums))
	{
		free(*nums);
		ft_error();
	}
}

int	stack_init(int argc, char **argv, t_stack **stackA, t_stack **stackB)
{
	int	*nums;
	int	num_nums;
	int	i;

	initialize_nums_array(argc, argv, &nums, &num_nums);
	if (allocate_stacks(stackA, stackB) == -1)
	{
		free(nums);
		ft_error();
	}
	i = num_nums - 1;
	while (i >= 0)
		push(*stackA, nums[i--]);
	free(nums);
	set_indices(*stackA);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		len;

	if (stack_init(argc, argv, &stacka, &stackb) == -1)
		return (-1);
	if (is_sorted(stacka))
	{
		free_stack(stacka);
		free_stack(stackb);
		return (0);
	}
	len = stacka->size;
	if (stacka->size == 3)
		sort_small_stack(stacka);
	else if (stacka->size < 10)
		insertsort(stacka, stackb);
	else
	{
		k_sort1(stacka, stackb, len);
		k_sort2(stacka, stackb, len);
	}
	free_stack(stacka);
	free_stack(stackb);
	return (0);
}
