#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*sec;
	t_node	*bot;
	int		numofelements;
}	t_stack;

// Store the stack data
// top data, next data, last data
// typedef struct s_data
// {
// 	int stack_a_top;
// 	int stack_a_sec;
// 	int stack_a_third;
// 	int stack_a_last;
// 	int stack_a_numofelements;

// 	int stack_b_top;
// 	int stack_b_sec;
// 	int stack_b_third;
// 	int stack_b_last;
// 	int stack_b_numofelements;
// }	s_datastore;

void	initstack(t_stack *stack);
int		isempty(t_stack *stack);

// void	push(t_stack *stack, int value, s_datastore *stackdetails);
void	push(t_stack *stack, int value);
void	addtoback(t_stack *stack, int value);
int		pop(t_stack *stack);
void	displaystack(t_stack *stack);

// void	initdatastore(s_datastore *stackdetails);

// Stack operations
/*
// Swap the first 2 elements at the top of stack
void	sa(t_stack *a);
void	sb(t_stack *b);
*/
// void	swap_top_two(t_stack *stack);
// void	ss(t_stack *a, t_stack *b);

/*
// Shift up all elements of stack by 1
void	ra(t_stack *a);
void	rb(t_stack *b);
*/
// void	rotate_stack(t_stack *stack);
// void	rr(t_stack *a, t_stack *b);

// void	reverse_rotate_stack(t_stack *stack);
// void	rrr(t_stack *a, t_stack *b);
// t_node	*ft_rralastnode(t_node *head, int tonull);

// Take the first element at the top of b and put it at the top of a
// void	pa(t_stack *a, t_stack *b);
// Take the first element at the top of a and put it at the top of b
// void	pb(t_stack *a, t_stack *b);

/*
// Shift down all elements of stack by 1
void	rra(t_stack *a);
void	rrb(t_stack *b);
*/

typedef struct s_element5
{
	int				smallest;
	int				secondsmallest;
	int				middle;
	int				secondlargest;
	int				largest;

	int				smallestpos;
	int				secondsmallestpos;
	int				middlepos;
	int				secondlargestpos;
	int				largestpos;

}	s_element5;

typedef struct s_element3
{
	int				smallest;
	int				middle;
	int				largest;

	int				smallestpos;
	int				middlepos;
	int				largestpos;

}	s_element3;



// int scanSmallestNum(t_stack *stack);
// int scan2SmallestNum(t_stack *stack);

// int scanlargestNum(t_stack *stack);
// int scan2largestNum(t_stack *stack);


int	scanNumPos(t_stack *stack, int num);
// int scanSmallestNumPos(t_stack *stack, int num);
// int scanLargestNumPos(t_stack *stack, int num);

void	bringtobot(t_stack	*stack, int *numberofop);

#endif
