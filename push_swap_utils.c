/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:36:25 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/04/14 12:12:32 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* free functions*/
void	freeStack(Stack *s)
{
	free(s->array);
	s->array = NULL;
	s->top = -1;
}