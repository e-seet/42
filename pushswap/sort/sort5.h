#ifndef SORT5_H
# define SORT5_H

# include "../utils/operations.h"
# include "../utils/operations2.h"
# include "../utils/utils.h"
#include "./sort3.h"

void init5Element(s_element5 *element5);
void find5Numbers(t_node * head, s_element5 *element5);
void sort5(t_stack stack_a, t_stack stack_b, int *numberofop, s_element5 *element5);

#endif
