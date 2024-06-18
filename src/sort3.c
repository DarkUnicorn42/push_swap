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

void	execute_sort(t_stack **stack, int a, int b, int c)
{
	if (a > b && a > c && b < c)
		ra(*stack);
	else if (a > b && b > c && a > c)
	{
		ra(*stack);
		sa(*stack);
	}
	else if (a > b && b < c && a < c)
		sa(*stack);
	else if (a < b && a < c && b > c)
	{
		rra(*stack);
		sa(*stack);
	}
	else if (a < b && a > c && b > c)
		rra(*stack);
}

void	sort3(t_stack **stack)
{
	int		a;
	int		b;
	int		c;
	t_node	*node;

	node = (*stack)->top;
	a = node->value;
	b = node->next->value;
	c = node->next->next->value;
	execute_sort(stack, a, b, c);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

int	find_min_index(t_stack *stack)
{
	int		min_index;
	int		min_value;
	int		current_index;
	t_node	*current;	

	min_index = 0;
	current_index = 0;
	current = stack->top;
	min_value = current->value;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (min_index);
}

void	sort_small_stack(t_stack *stack)
{
	if (stack->size == 2)
	{
		if (stack->top->value < stack->top->next->value)
		{
			sa(stack);
		}
	}
	else if (stack->size == 3)
		sort3(&stack);
}
