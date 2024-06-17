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

//too be cleared
# include "../libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <ctype.h>

// Structure for stack nodes
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// Structure for stacks
typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;


// Function prototypes
t_stack *init_stack(void);
void free_stack(t_stack *stack);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void print_stack(t_stack *stack);

int parse_args(int argc, char **argv, t_stack *a);
int is_integer(char *str);
int is_unique(t_stack *a, int value);

void swap_a(t_stack *a);
void swap_b(t_stack *b);
void swap_both(t_stack *a, t_stack *b);
void push_a(t_stack *a, t_stack *b);
void push_b(t_stack *a, t_stack *b);
void rotate_a(t_stack *a);
void rotate_b(t_stack *b);
void rotate_both(t_stack *a, t_stack *b);
void reverse_rotate_a(t_stack *a);
void reverse_rotate_b(t_stack *b);
void reverse_rotate_both(t_stack *a, t_stack *b);

void sort_stack(t_stack *a, t_stack *b);
void simple_sort(t_stack *a, t_stack *b);
void small_sort(t_stack *a, t_stack *b);
void big_sort(t_stack *a, t_stack *b);

int find_min(t_stack *a);
int find_max(t_stack *a);
int calculate_moves(t_stack *a, int value);
int find_median(t_stack *a);
int compare_int(const void *a, const void *b);

#endif