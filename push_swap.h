/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:37:42 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/04/14 13:35:50 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct Stack
{
	int				*data;
	int				top;
}	t_Stack;


void	sa(t_Stack *stack);
void	sb(t_Stack *stack);
void	pa(t_Stack *stackA, t_Stack *stackB);
void	pb(t_Stack *stackA, t_Stack *stackB);
void	ra(t_Stack *stack);
void	rb(t_Stack *stack);
void	rr(t_Stack *stackA, t_Stack *stackB);
void	rra(t_Stack *stack);
void	rrb(t_Stack *stack);
void	rrr(t_Stack *stackA, t_Stack *stackB);

#endif