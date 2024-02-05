#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

void	initstack(t_stack *stack);
int		isempty(t_stack *stack);

void	push(t_stack *stack, int value);
void	addtoback(t_stack *stack, int value);
int		pop(t_stack *stack);
void	displaystack(t_stack *stack);

// Stack operations

// Swap the first 2 elements at the top of stack a
void	sa(t_stack *a);
// Swap the first 2 elements at the top of stack b
void	sb(t_stack *b);
// sa and sb at the same time
void	ss(t_stack *a, t_stack *b);

// Take the first element at the top of b and put it at the top of a
void	pa(t_stack *a, t_stack *b);
// Take the first element at the top of a and put it at the top of b
void	pb(t_stack *a, t_stack *b);

// Shift up all elements of stack a by 1
void	ra(t_stack *a);
// Shift up all elements of stack b by 1
void	rb(t_stack *b);
// ra and rb at the same time
void	rr(t_stack *a, t_stack *b);

// Shift down all elements of stack a by 1
void	rra(t_stack *a);
// Shift down all elements of stack b by 1
void	rrb(t_stack *b);
// rra and rrb at the same time
void	rrr(t_stack *a, t_stack *b);

#endif
