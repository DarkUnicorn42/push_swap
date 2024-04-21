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

int	stack_init(int argc, char **argv, t_stack **stackA, t_stack **stackB)
{
	int		*nums;  // The numbers to sort
	int		num_nums;  // The number of numbers
	int		i;
	char	**split;
	
	num_nums = argc - 1;
	nums = (int *)malloc(num_nums * sizeof(int));
	*stackA = (t_stack *)malloc(num_nums * sizeof(t_stack));
	*stackB = (t_stack *)malloc(num_nums * sizeof(t_stack));
	if (*stackA == NULL || *stackB == NULL) {
    	fprintf(stderr, "Failed to allocate memory\n");
    return (-1);
	}
	i = 0;
	if (argc > 2)
	{
		while (i < num_nums)
		{
			nums[i] = ft_atoi(argv[i + 1]);
			printf("nums input[%d]: %d\n", i, nums[i]);
			i++;
		}
	}
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[i])
		{
			nums[i] = ft_atoi(split[i]);
			printf("nums input[%d]: %d\n", i, nums[i]);
			i++;
		}
	}
	else
		printf("error: no input\n");

//stack init
	(*stackA)->top = -1;
	(*stackB)->top = -1;
//push nums on stackA
return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;
	
//	stack_init(argc, argv, &stackA, &stackB);
	if (stack_init(argc, argv, &stackA, &stackB) == -1)
   		return -1;
	return (0);
}
