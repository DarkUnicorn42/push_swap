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

// Main function: Entry point of the program
int main(int argc, char **argv) {
    t_stack *a;
    t_stack *b;

    // Check if there are arguments provided
    if (argc < 2)
        return (0);

    // Initialize stacks a and b
    a = init_stack();
    b = init_stack();

    // Parse and validate the input arguments, and populate stack a
    if (!parse_args(argc, argv, a)) {
        write(2, "Error\n", 6);
        free_stack(a);
        free_stack(b);
        return (1);
    }

    // Sort the stack a
    sort_stack(a, b);

    // Free the allocated memory for stacks
    free_stack(a);
    free_stack(b);

    return (0);
}