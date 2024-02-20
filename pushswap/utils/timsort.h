#ifndef TIMSORT_H
# define TIMSORT_H

# include "./utils.h"
# include "./utils2.h"

#include "./operations.h"
#include "./operations2.h"

void tim_sort(t_stack *stack_a, t_stack *stack_b, int *numberofop);

void insert_sort();

void merge_sort();

int calculate_minrun(int n);

// int count_elements_in_stack(t_node *head);

#endif