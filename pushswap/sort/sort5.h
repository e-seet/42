#ifndef SORT5_H
# define SORT5_H

# include "../utils/operations.h"
# include "../utils/operations2.h"
# include "../utils/utils.h"
# include "./sort3.h"

int		sort5wrapper(t_stack *stack_a, t_stack *stack_b, int *numberofop);

void	init5_element(t_element5 *element5);
void	find5_numbers(t_node *head, t_element5 *element5);
void	sort5(t_stack *stack_a, t_stack *stack_b, int *numberofop,
			t_element5 *element5);
int		ft_lstsize_modified(t_node *head);
#endif
