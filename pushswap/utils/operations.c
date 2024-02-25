#include "operations.h"

// the reference node for stack->top and stack->next did not change
void	swap_top_two(t_stack *stack, int *numberofop)
{
	t_node	*top;
	t_node	*nextnode;

	printf("SA/SB: swap top two\n");
	top = stack->top;
	nextnode = top->next;
	if (top != NULL && nextnode != NULL)
	{
		top -> next = nextnode ->next;
		nextnode ->prev = top->prev;
		top -> prev = nextnode;
		nextnode->next = top;
	}
	*numberofop = *numberofop +1;
}

void	ss(t_stack *a, t_stack *b, int *numberofop)
{
	printf("SS:");
	swap_top_two(a, numberofop);
	swap_top_two(b, numberofop);
	*numberofop = *numberofop -1;
	printf("\n\n");
}

// Shift up all elements of stack by 1
void	rotate_stack(t_stack *stack, int *numberofop)
{
	t_node	*newlastnode;

	printf("RA/RB: rotate_stack\n");
	newlastnode = stack->top;
	stack -> top = newlastnode -> next;
	stack->bot = newlastnode;
	*numberofop = *numberofop +1;
}

// ra and rb at the same time
void	rr(t_stack *a, t_stack *b, int *numberofop)
{
	printf("RR:");
	rotate_stack(a, numberofop);
	rotate_stack(b, numberofop);
	*numberofop = *numberofop -1;
	printf("\n\n");
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
