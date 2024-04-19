/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:36:25 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/04/19 14:36:18 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to print an operation
void	print_operation(char *operation)
{
	printf("%s\n", operation);
}

// Function to push an integer onto a stack
void	push(t_stack *stack, int num)
{
	stack->top++;
//	stack->data = &num;
	stack->data[stack->top] = num;
}

int	stack_init(int argc, char **argv, t_stack *stackA, t_stack *stackB)
{
	int		*nums;  // The numbers to sort
	int		num_nums;  // The number of numbers
	int		i;
	
	num_nums = argc - 1;
	nums = (int *)malloc(num_nums * sizeof(int));
	if (nums == NULL)
	{
		printf("Error: malloc failed\n");
		return (1);
	}
	i = 0;
	if (argc > 2)
	{
		while (i < num_nums)
		{
			nums[i] = *argv[i + 1] - '0';
			i++;
		}
	}
	else if (argc == 2)
	{
		//atoi;
	}
	else
		printf("error");

printf("num_nums: %d\n", num_nums);

//stack init
	stackA->top = -1;
	stackB->top = -1;
//push nums on stackA
	i = 0;
	while (i < num_nums + 1)
	{
		push(stackA, nums[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stackA;
	t_stack	stackB;
	int		i;
	
	stack_init(argc, argv, &stackA, &stackB);
	i = 0;
	while (stackA.top > i)
	{
		printf("%d\n", stackA.data[i]);
		i++;
		//stackA.top--;
	}
	// Sort the numbers
	//sort_stack_a(&stackA, &stackB);
	//printf("%d", stackA.top);
	return (0);
}


/* ************************************************************************** */
/*
int	main(int ac, char **av)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	int		stack_size;
	
	if (ac < 2)
		return (0);
    // Parse the command-line arguments into an array of integers.
    // This will be the initial state of stack A. Stack B will be empty.

    // Implement a sorting algorithm that uses the stack operations to sort the numbers.
    // The algorithm should aim to use the smallest possible number of operations.

    // Print the operations used by the sorting algorithm.

    return (0);
}
*/