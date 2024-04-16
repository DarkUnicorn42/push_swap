/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:36:25 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/04/16 14:43:18 by mwojtcza         ###   ########.fr       */
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
	stack->data[stack->top] = num;
}

int	main()
{
	t_stack	stackA;
	t_stack	stackB;
	int		i;
	int		nums[] = {4, 3, 2, 1};  // The numbers to sort
	int		num_nums = sizeof(nums) / sizeof(nums[0]);  // The number of numbers

	stackA.data = (int *)malloc(num_nums * sizeof(int));
	stackB.data = (int *)malloc(num_nums * sizeof(int));
	if (stackA.data == NULL || stackB.data == NULL)
	{
		printf("Error: malloc failed\n");
		return (1);
	}
	// Initialize the stacks
	stackA.top = -1;
	stackB.top = -1;	
	// Push the numbers onto stackA
	i = 0;
	while (i < num_nums)
	{
		push(&stackA, nums[i]);
		i++;
	}
	// Sort the numbers
	//sort_stack_a(&stackA, &stackB);
	printf("Sorting complete\n");
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