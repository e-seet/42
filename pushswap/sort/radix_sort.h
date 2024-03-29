#ifndef RADIX_SORT_H
# define RADIX_SORT_H

# include "../utils/operations.h"
# include "../utils/operations2.h"
# include "../utils/operations3.h"
# include "../utils/utils.h"
# include "../utils/utils2.h"
# include "../utils/utils3.h"
// # include "../utils/utils4.h"

int		radix_sort_wrapper(int argc, t_stack *stack_a,
			t_stack *stack_b, int *numberofop);
void	setpos(t_stack *stack_a, int argc, int i);
void	radix_sort(t_stack *stack_a, t_stack *stack_b, int *numberofop);

#endif