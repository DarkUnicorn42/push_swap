/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:37:42 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/29 14:35:25 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	pa(t_stack *stackA, t_stack *stackB);
void	pb(t_stack *stackA, t_stack *stackB);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stackA, t_stack *stackB);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stackA, t_stack *stackB);

void	print_operation(char *operation);
void	sort_small_stack(t_stack *stackA);
void	insertsort(t_stack *stackA, t_stack *stackB);
void	insert_into_b(t_stack *stackA, t_stack *stackB);

void	sort3(t_stack **stack);
void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length);
void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length);
void	ft_error(void);
void	set_indices(t_stack *stack);
void	execute_sort(t_stack **stack, int a, int b, int c);
void	ft_atoi_error_check(long res, int sign);
void	rotate_stack_b(t_stack *b, int length, int rb_count, int rrb_count);
void	parse_split_input(char *input, int *nums);
void	initialize_nums_array(int argc, char **argv, int **nums, int *num_nums);
void	free_stack(t_stack *stack);

int		push(t_stack *stack, int value);
int		find_min_index(t_stack *stack);
int		stack_init(int argc, char **argv, t_stack **stackA, t_stack **stackB);
int		check_duplicates(int *nums, int len);
int		ft_word_countv2(char const *s, char c);
int		ft_atoi2(const char *nptr);
int		is_sorted(t_stack *stack);
int		allocate_stacks(t_stack **stackA, t_stack **stackB);
int		ft_sqrt(int number);

long	ft_parse_number(const char *nptr, int *i);

/*
void	print_stack(t_stack *stack, char *name);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
*/

#endif