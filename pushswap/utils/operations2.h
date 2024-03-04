#ifndef OPERATIONS2_H
# define OPERATIONS2_H

# include "utils.h"

void	reverse_rotate_stack(t_stack *stack, int *numberofop, int print);

void	rrr(t_stack *a, t_stack *b, int *numberofop );

// t_node	*ft_rralastnode(t_node *head, int tonull, t_stack *stack);
t_node	*ft_rralastnode(t_node *head, t_stack *stack);

#endif