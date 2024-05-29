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
/* --------------- TO DO --------------- */
/*
-implement ft_printf library
-makefile for printf
-free checks
-norminette
Functions:
-sort large nums
-...
-profit
*/

int	allocate_stacks(t_stack **stackA, t_stack **stackB, int num_nums)
{
	*stackA = (t_stack *)malloc(sizeof(t_stack));
	*stackB = (t_stack *)malloc(sizeof(t_stack));
	if (*stackA == NULL || *stackB == NULL)
	{
		fprintf(stderr, "Failed to allocate memory\n");
		return (-1);
	}
	(*stackA)->data = (int *)malloc(num_nums * sizeof(int));
	(*stackB)->data = (int *)malloc(num_nums * sizeof(int));
	if ((*stackA)->data == NULL || (*stackB)->data == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for stack data\n");
		free(*stackA);
		free(*stackB);
		return (-1);
	}
	(*stackA)->top = -1;
	(*stackB)->top = -1;
	return (0);
}

int	fill_nums_array(int argc, char **argv, int *nums)
{
	char	**split;
	int		i;

	i = 0;
	if (argc > 2)
	{
		while (i < argc - 1)
		{
			nums[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		i = 0;
		while (split[i])
		{
			nums[i] = ft_atoi(split[i]);
			i++;
		}
		free(split);
	}
	else
	{
		printf("error: no input\n");
		return (-1);
	}
	return (0);
}

int	stack_init(int argc, char **argv, t_stack **stackA, t_stack **stackB)
{
	int	*nums;
	int	num_nums;
	int	i;

	i = 0;
	num_nums = argc - 1;
	nums = (int *)malloc(num_nums * sizeof(int));
	if (nums == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for nums\n");
		return (-1);
	}
	if (allocate_stacks(stackA, stackB, num_nums) == -1)
	{
		free(nums);
		return (-1);
	}
	if (fill_nums_array(argc, argv, nums) == -1)
	{
		free(nums);
		return (-1);
	}
	if (check_duplicates(nums, num_nums))
	{
		free(nums);
		return (-1);
	}
	while (i < num_nums)
	{
		push(*stackA, nums[i++]);
	}
	free(nums);
	return (0);
}

int main(int argc, char **argv) {
    t_stack *stackA;
    t_stack *stackB;

    if (stack_init(argc, argv, &stackA, &stackB) == -1)
        return -1;
    if (stackA->top == 2)
        sort3(&stackA);
    else
        turksort(stackA, stackB, stackA->size);
    printf("Stack A: ");
    print_stack(stackA);
    printf("Stack B: ");
    print_stack(stackB);
    free(stackA->data);
    free(stackB->data);
    free(stackA);
    free(stackB);
    return 0;
}