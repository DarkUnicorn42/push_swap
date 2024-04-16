/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:37:42 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/04/16 14:43:03 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_stack
{
	int				*data;
	int				top;
}	t_stack;

typedef struct s_node
{
	int		datanode;
	t_node	*next;
}	t_node;


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

#endif