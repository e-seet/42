#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

void initStack(t_stack *stack);
int isEmpty(t_stack *stack);

void push(t_stack *stack, int value);
int pop(t_stack *stack) ;

// Stack operations
void sa(t_stack *a); // Swap the first 2 elements at the top of stack a
void sb(t_stack *b); // Swap the first 2 elements at the top of stack b
void ss(t_stack *a, t_stack *b); // sa and sb at the same time

void pa(t_stack *a, t_stack *b); // Take the first element at the top of b and put it at the top of a
void pb(t_stack *a, t_stack *b); // Take the first element at the top of a and put it at the top of b

void ra(t_stack *a); // Shift up all elements of stack a by 1
void rb(t_stack *b); // Shift up all elements of stack b by 1
void rr(t_stack *a, t_stack *b); // ra and rb at the same time

void rra(t_stack *a); // Shift down all elements of stack a by 1
void rrb(t_stack *b); // Shift down all elements of stack b by 1
void rrr(t_stack *a, t_stack *b); // rra and rrb at the same time

#endif
