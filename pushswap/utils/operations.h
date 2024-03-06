#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "operations2.h"
# include "utils.h"

void	swap_top_two(t_stack *stack, int *numberofop, int print);

void	ss(t_stack *a, t_stack *b, int *numberofop);

void	rotate_stack(t_stack *stack, int *numberofop, int print);

void	rr(t_stack *a, t_stack *b, int *numberofop);

#endif