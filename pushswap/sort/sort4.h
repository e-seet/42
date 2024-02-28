#ifndef SORT4_H
# define SORT4_H

# include "../utils/operations.h"
# include "../utils/operations2.h"
# include "../utils/utils.h"
# include "./sort3.h"

int		sort4wrapper(t_stack *stack_a, t_stack *stack_b, int *numberofop);

void	init4_element(t_element4 *element4);
void	find4_numbers(t_node *head, t_element4 *element4);
void	sort4_al(t_stack *stack_a, t_stack *stack_b, int *numberofop,
			t_element4 *element4);
int		ft_lstsize_modified(t_node *head);
#endif
