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
				//printf("error: duplicates\n");
				return (-1);
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

int	ft_word_countv2(char const *s, char c)
{
	int	count;
	int	inword;

	inword = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !inword)
		{
			count++;
			inword = 1;
		}
		else if (*s == c)
			inword = 0;
		s++;
	}
	return (count);
}

void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}

int	ft_atoi2(const char *nptr)
{
	int	i;
	int	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		ft_error();
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += (nptr[i] - 48);
		if (sign == 1 && res > INT_MAX)
			ft_error();	
		if (sign == -1 && res > (long)INT_MAX + 1)
			ft_error();

		i++;
	}
	if (nptr[i] != '\0')
		ft_error();
	return ((int)(res * sign));
}

bool is_sorted(t_stack *stack)
{
    int i;

	i = 0;
    if (stack->top < 1)
        return (true);
    while (i < stack->top)
    {
        if (stack->data[i] > stack->data[i + 1])
            return (false);
		i++;
    }
    return (true);
}