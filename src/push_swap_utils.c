/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:36:25 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/27 20:55:15 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

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
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	print_operation(char *operation)
{
	printf("%s\n", operation);
}

int	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (-1);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (0);
}

void	set_indices(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;
	int		index;

	current = stack->top;
	while (current)
	{
		index = 0;
		runner = stack->top;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}

/*
void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;

	current = stack->top;
	printf("Stack %s: ", name);
	while (current != NULL)
	{
		printf("%d (index %d) -> ", current->value, current->index);
		current = current->next;
	}
	printf("NULL\n");
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
}
*/