/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:36:25 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/24 12:02:48 by mwojtcza         ###   ########.fr       */
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
				printf("error: duplicates\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// Function to print an operation
void	print_operation(char *operation)
{
	printf("%s\n", operation);
}

// Function to push an integer onto a stack
void	push(t_stack *stack, int num)
{
	stack->top++;
	stack->data[stack->top] = num;
	stack->size++;
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i++ <= stack->top)
		printf("%d ", stack->data[stack->top - i + 1]);
	printf("\n");
}

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

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	if (stack_init(argc, argv, &stackA, &stackB) == -1)
		return (-1);
	if (stackA->top == 2)
		sort3(&stackA);
	else
		sortbig(&stackA, &stackB);
	printf("Stack A: ");
	print_stack(stackA);
	printf("Stack B: ");
	print_stack(stackB);
	return (0);
}
