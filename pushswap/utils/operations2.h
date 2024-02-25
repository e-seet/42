#ifndef OPERATIONS2_H
# define OPERATIONS2_H

# include "utils.h"

void	reverse_rotate_stack(t_stack *stack, int *numberofop);

void	rrr(t_stack *a, t_stack *b, int *numberofop );

t_node	*ft_rralastnode(t_node *head, int tonull);

void	pb(t_stack *a, t_stack *b, int *numberofop);

void	pa(t_stack *a, t_stack *b, int *numberofop);

#endif