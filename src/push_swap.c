/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:36:25 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/05/29 14:37:26 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int stack_init(int argc, t_stack **stackA, t_stack **stackB)
{
    int num_nums = argc - 1;

    *stackA = (t_stack *)malloc(sizeof(t_stack));
    *stackB = (t_stack *)malloc(sizeof(t_stack));
    if (!(*stackA) || !(*stackB))
        return (0);

    (*stackA)->data = (t_node *)malloc(num_nums * sizeof(t_node));
    (*stackB)->data = (t_node *)malloc(num_nums * sizeof(t_node));
    if (!((*stackA)->data) || !((*stackB)->data))
        return (0);

    (*stackA)->top = -1;
    (*stackB)->top = -1;
    (*stackA)->size = num_nums;
    (*stackB)->size = num_nums;
    return (1);
}

int main(int argc, char **argv)
{
    t_stack *stackA;
    t_stack *stackB;

    if (argc < 2)
        return (0);
    if (!stack_init(argc, &stackA, &stackB))
        ft_error();
    if (!parse_args(stackA, argc, argv))
        ft_error();
    if (!is_sorted(stackA))
        turksort(stackA, stackB);
    free(stackA->data);
    free(stackB->data);
    free(stackA);
    free(stackB);
    return (0);
}
