#include "operations3.h"

void	pb_c2(t_stack *b, t_node	*topnode_a, t_node	*topnode_b)
{
	if (topnode_b != NULL)
	{
		topnode_a->next = topnode_b;
		if (topnode_b -> prev != NULL)
		{
			topnode_a->prev = topnode_b->prev;
			(topnode_b->prev)->next = topnode_a;
		}
		topnode_b->prev = topnode_a;
		b->top = topnode_a;
	}
	else
	{
		topnode_a->next = topnode_a;
		topnode_a->prev = topnode_a;
	}
}

// NOTE: pa and pb may have issues with regards to stack updates.
// Take the first element at the top of a and put it at the top of b
void	pb(t_stack *a, t_stack *b, int *numberofop)
{
	t_node	*topnode_a;
	t_node	*topnode_b;

	write(1, "pb\n", 3);
	topnode_a = a->top;
	topnode_b = b->top;
	if (topnode_a != NULL)
	{
		if (topnode_a -> next != topnode_a)
		{
			a->top = topnode_a->next;
			(topnode_a->next)->prev = topnode_a ->prev;
			(topnode_a->prev)->next = topnode_a ->next;
		}
		else
		{
			a->top = NULL;
			a->bot = NULL;
		}
		pb_c2(b, topnode_a, topnode_b);
		b->top = topnode_a;
	}
	*numberofop = *numberofop + 1;
}

void	pa_c1(t_stack *b, t_node *topnode_a, t_node	*topnode_b)
{
	if (topnode_b->next != topnode_b)
	{
		b->top = topnode_b->next;
		(topnode_b->next)->prev = topnode_b->prev;
		(topnode_b->prev)->next = topnode_b->next;
	}
	else
	{
		b->top = NULL;
		b->bot = NULL;
	}
	if (topnode_a != NULL)
	{
		topnode_b->next = topnode_a;
		if (topnode_a -> prev != NULL)
		{
			topnode_b->prev = topnode_a->prev;
			(topnode_a->prev)->next = topnode_b;
		}
		topnode_a->prev = topnode_b;
	}
}

// // Take the first element at the top of b and put it at the top of a
void	pa(t_stack *a, t_stack *b, int *numberofop)
{
	t_node	*topnode_a;
	t_node	*topnode_b;

	write(1, "pa\n", 3);
	topnode_a = a->top;
	topnode_b = b->top;
	if (topnode_b != NULL)
	{
		pa_c1(b, topnode_a, topnode_b);
		if (topnode_a == NULL)
		{
			topnode_b->next = topnode_b;
			topnode_b->prev = topnode_b;
		}
		a->top = topnode_b;
	}
	else
	{
		topnode_b->next = topnode_b;
		topnode_b->prev = topnode_b;
		a->top = topnode_b;
	}
	*numberofop = *numberofop +1;
}
