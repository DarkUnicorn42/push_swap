
#include "../includes/push_swap.h"



// void push_all_but_three(t_stack *a, t_stack *b) {
//     while (a->size > 3) {
//         print_operations("pb");
//         push(b, pop(a));
//     }
// }

// void insert_sort_b(t_stack *a, t_stack *b) {
//     while (b->size > 0) {
//         int value = pop(b);
//         if (a->top->value > value) {
//             print_operations("pa");
//             push(a, value);
//         } else {
//             while (a->top->value < value) {
//                 print_operations("ra");
//                 rotate(a);
//             }
//             print_operations("pa");
//             push(a, value);
//             while (a->top->next->value != value) {
//                 print_operations("rra");
//                 reverse_rotate(a);
//             }
//         }
//     }
// }

// // void sort_stack(t_stack *a, t_stack *b) {
// //     if (a->size <= 3) {
// //         sort_three(a);
// //         return;
// //     }

// //     push_all_but_three(a, b);
// //     sort_three(a);
// //     insert_sort_b(a, b);
// // }

// Main sorting function
void sort_stack(t_stack *a, t_stack *b) {
    if (a->size <= 3) {
        simple_sort(a, b);
    } else if (a->size <= 5) {
        small_sort(a, b);
    } else {
        big_sort(a, b);
    }
}

// Sorts a small stack (2-3 elements)
void simple_sort(t_stack *a, t_stack *b) {
    int min = find_min(a);
    int max = find_max(a);

    if (a->size == 2 && a->top->value > a->top->next->value)
        swap_a(a);
    else if (a->size == 3) {
        if (a->top->value == max) {
            rotate_a(a);
            if (a->top->value > a->top->next->value)
                swap_a(a);
        } else if (a->top->next->value == max) {
            reverse_rotate_a(a);
            if (a->top->value > a->top->next->value)
                swap_a(a);
        } else {
            if (a->top->value > a->top->next->value)
                swap_a(a);
        }
    }
}

// Sorts a medium stack (4-5 elements)
void small_sort(t_stack *a, t_stack *b) {
    while (a->size > 3)
        push_b(a, b);
    simple_sort(a, b);
    while (b->size > 0) {
        int value = find_min(b);
        int moves = calculate_moves(a, value);
        if (moves <= a->size / 2) {
            while (a->top->value != value)
                rotate_a(a);
        } else {
            while (a->top->value != value)
                reverse_rotate_a(a);
        }
        push_a(a, b);
    }
}

// Sorts a large stack (more than 5 elements)
void big_sort(t_stack *a, t_stack *b) {
    // Partition the array into roughly equal parts and sort each part
    int pivot = find_median(a);
    while (a->size > 0) {
        if (a->top->value < pivot)
            push_b(a, b);
        else
            rotate_a(a);
    }
    while (b->size > 0) {
        int value = find_min(b);
        int moves = calculate_moves(a, value);
        if (moves <= a->size / 2) {
            while (a->top->value != value)
                rotate_a(a);
        } else {
            while (a->top->value != value)
                reverse_rotate_a(a);
        }
        push_a(a, b);
    }
    while (a->top->value != find_min(a))
        rotate_a(a);
}

// Finds the median value in the stack
int find_median(t_stack *a) {
    int *arr;
    int i = 0;
    t_node *current = a->top;

    arr = (int *)malloc(sizeof(int) * a->size);
    while (current) {
        arr[i++] = current->value;
        current = current->next;
    }
    qsort(arr, a->size, sizeof(int), compare_int);
    int median = arr[a->size / 2];
    free(arr);
    return median;
}

// Helper function for qsort to compare integers
int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}