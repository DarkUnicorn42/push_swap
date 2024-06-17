
#include "../includes/push_swap.h"

// Parses and validates input arguments
int parse_args(int argc, char **argv, t_stack *a) {
    int i;
    int value;

    i = 1;
    while (i < argc) {
        if (!is_integer(argv[i]) || !is_unique(a, atoi(argv[i]))) {
            return (0);
        }
        value = atoi(argv[i]);
        push(a, value);
        i++;
    }
    return (1);
}

// Checks if a string represents a valid integer
int is_integer(char *str) {
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i]) {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

// Checks if a value is unique in the stack
int is_unique(t_stack *a, int value) {
    t_node *current;

    current = a->top;
    while (current) {
        if (current->value == value)
            return (0);
        current = current->next;
    }
    return (1);
}