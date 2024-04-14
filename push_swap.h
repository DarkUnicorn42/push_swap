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
	int				*array;
	int				top;
	int				bottom;	
	int				data;
	struct Stack	*next;
	struct Stack	*prev;
}	t_Stack;

typedef struct SortingAlgorithm
{
	t_Stack	a;
	t_Stack	b;
	int		limit;/* Instruction limit */
}	t_SortingAlgorithm;

size_t	ft_strlen(const char *str);
void	ft_printfp(unsigned long int c, int *len);
void	ft_printfc(char c, int *len);


#endif