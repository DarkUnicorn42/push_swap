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

int	ft_atoi2(const char *nptr)
{
	int		i;
	int		sign;
	long		res;

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
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && res > (long)INT_MAX + 1))
			ft_error();
		i++;
	}
	if (nptr[i] != '\0')
		ft_error();
	return ((int)(res * sign));
}

void print_operation(char *operation)
{
    ft_putstr_fd(operation, 1);
    ft_putchar_fd('\n', 1);
}


int stack_is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->top)
    {
        if (stack->data[i].data > stack->data[i + 1].data)
            return (0);
        i++;
    }
    return (1);
}

int parse_args(t_stack *stack, int argc, char **argv)
{
    int *nums;
    int num_count;
    int i;

    nums = (int *)malloc((argc - 1) * sizeof(int));
    if (!nums)
        ft_error();

    num_count = fill_nums_array(argc, argv, nums);

    for (i = 0; i < num_count; i++)
    {
        push(stack, nums[i]);
    }

    free(nums);
    return (1);
}

int is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->top)
    {
        if (stack->data[i].data > stack->data[i + 1].data)
            return (0);
        i++;
    }
    return (1);
}

int fill_nums_array(int ac, char **av, int *nums)
{
    char **split;
    int i;
    int n;

    i = 0;
    if (ac > 2)
    {
        while (i < ac - 1)
        {
            n = ft_atoi2(av[i + 1]);
            if (n == -1 && (av[i + 1][0] != '-' || ft_atoi2(&av[i + 1][1]) != 0))
            {
                ft_error();
            }
            nums[i] = n;
            i++;
        }
    }
    else if (ac == 2)
    {
        split = ft_split(av[1], ' ');
        if (!split)
        {
            ft_error();
        }
        i = 0;
        while (split[i])
        {
            n = ft_atoi2(split[i]);
            if (n == -1 && (split[i][0] != '-' || ft_atoi2(&split[i][1]) != 0))
            {
                free(split);
                ft_error();
            }
            nums[i] = n;
            i++;
        }
        free(split);
    }
    else
    {
        ft_error();
    }
    return (i);
}