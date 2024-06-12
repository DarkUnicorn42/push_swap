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
	int		data;
	int		index; //binary value
}	t_node;

typedef struct s_stack
{
	t_node			*data;
	int				top;
	int				size;
}	t_stack;


int stack_init(int argc, t_stack **stackA, t_stack **stackB);
int parse_args(t_stack *stack, int argc, char **argv);
int fill_nums_array(int ac, char **av, int *nums);

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
void	push(t_stack *stack, int num);
void	print_stack(t_stack *stack);
void	sort_small_stack(t_stack *stackA, t_stack *stackB);
void	turksort(t_stack *stackA, t_stack *stackB);
void	insert_into_b(t_stack *stackA, t_stack *stackB);
void	sort3(t_stack **stack);
void	ft_error(void);

int		find_min_index(t_stack *stack);
int		check_duplicates(int *nums, int len);
int		ft_word_countv2(char const *s, char c);
int		ft_atoi2(const char *nptr);
int		is_sorted(t_stack *stack);

#endif