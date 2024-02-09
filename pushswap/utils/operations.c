#include "operations.h"

// the reference node for stack->top and stack->next did not change
void	swap_top_two(t_stack *stack)
{
	t_node	*top;
	t_node	*nextnode;
	int		value;

	top = stack->top;
	nextnode = top->next;
	if (top != NULL && nextnode != NULL)
	{
		value = top->value;
		top->value = nextnode->value;
		nextnode->value = value;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
}
// Swap the first 2 elements at the top of stack a
// void	sa(t_stack *stack)
// {
// 	t_node	*top;
// 	t_node	*nextnode;
// 	int		value;

// 	top = stack->top;
// 	nextnode = top->next;
// 	if (top != NULL && nextnode != NULL)
// 	{
// 		value = top->value;
// 		top->value = nextnode->value;
// 		nextnode->value = value;
// 	}
// }

// Swap the first 2 elements at the top of stack b
// void	sb(t_stack *stack)
// {
// 	t_node	*top;
// 	t_node	*nextnode;
// 	int		value;

// 	top = stack->top;
// 	nextnode = top->next;
// 	if (top != NULL && nextnode != NULL)
// 	{
// 		value = top->value;
// 		top->value = nextnode->value;
// 		nextnode->value = value;
// 	}
// }

// Shift up all elements of stack a by 1
// void	ra(t_stack *a)
// {
// 	t_node	*curr;
// 	t_node	*lastnode;

// 	lastnode = a->top;
// 	a -> top = lastnode -> next;
// 	lastnode -> next = NULL;
// 	curr = a->top;
// 	while (curr->next != NULL)
// 	{
// 		curr = curr->next;
// 	}
// 	curr->next = lastnode;
// }

// Shift up all elements of stack b by 1
// void	rb(t_stack *b)
// {
// 	t_node	*curr;
// 	t_node	*lastnode;

// 	lastnode = b->top;
// 	b -> top = lastnode -> next;
// 	lastnode -> next = NULL;
// 	curr = b->top;
// 	while (curr->next != NULL)
// 	{
// 		curr = curr->next;
// 	}
// 	curr->next = lastnode;
// }

// Shift up all elements of stack by 1
void	rotate_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*lastnode;

	lastnode = stack->top;
	stack -> top = lastnode -> next;
	lastnode -> next = NULL;
	curr = stack->top;
	// may have issue here
	if (curr -> next != NULL)
		stack->sec = curr->next;
	else
		stack->sec = lastnode;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = lastnode;
	stack->bot = lastnode;
}

// ra and rb at the same time
void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}
