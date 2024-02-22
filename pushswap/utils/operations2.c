#include "operations2.h"

// break off the last node
// set the 2nd last node's next to null [when 1]
// Else, return the last node.
t_node	*ft_rralastnode(t_node *head, int tonull)
{
	t_node	*prev;

	while (head->next != NULL)
	{
		prev = head;
		head = head->next;
	}
	if (tonull == 1)
		prev ->next = NULL;
	return (head);
}

// Shift down all elements of stack by 1
void	reverse_rotate_stack(t_stack *stack,  int *numberofop)
{
	printf("RRA/RRB: reverse_rotate_stack\n");
	t_node	*head;
	t_node	*lastnode;

	head = stack->top;
	lastnode = ft_rralastnode(head, 1);
	// printf("check my lastnode:%d\n", lastnode->value);
	lastnode -> next = head;
	// head = lastnode;
	stack->top = lastnode;
	// manual check that next is present and then assign it to next
	// if (head -> next != NULL)
	// {
		// head = head->next;
		// stack->sec = head;
	// }	
	lastnode = ft_rralastnode(head, 0);
	stack->bot = lastnode;
	*numberofop = *numberofop + 1;
}

// rra and rrb at the same time
void	rrr(t_stack *a, t_stack *b,  int *numberofop)
{
	printf("RRR:");
	reverse_rotate_stack(a, numberofop);
	reverse_rotate_stack(b, numberofop);
	*numberofop = *numberofop - 1;
	printf("\n\n");
}

// NOTE: pa and pb may have issues with regards to stack updates.
// Take the first element at the top of a and put it at the top of b
void	pb(t_stack *a, t_stack *b,  int *numberofop)
{
	printf("PB\n");
	t_node	*topnode_a;
	t_node	*topnode_b;

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
			b->top = topnode_a;
	}
	*numberofop = *numberofop + 1;
}

// // Take the first element at the top of b and put it at the top of a
void	pa(t_stack *a, t_stack *b, int *numberofop)
{
	printf("PA\n");
	t_node	*topnode_a;
	t_node	*topnode_b;

	topnode_a = a->top;
	topnode_b = b->top;

	if (topnode_b != NULL)
	{
		if (topnode_b->next != topnode_b)
		{
			b->top = topnode_b->next;
			(topnode_b->next)->prev  = topnode_b->prev;
			(topnode_b->prev)->next  = topnode_b->next;
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
			a->top = topnode_b;
		}
		else
		{
			topnode_b->next = topnode_b;
			topnode_b->prev = topnode_b;
			a->top = topnode_b;
		}
	}
	else
	{
		printf("top node B is null\n");
		topnode_b->next = topnode_b;
		topnode_b->prev = topnode_b;
		a->top = topnode_b;
	}
	
	*numberofop = *numberofop +1;

	// printf("end of pa \n\n\n");
}

// Shift down all elements of stack a by 1
// void rra(t_stack *a)
// {
// 	t_node	*head;
// 	t_node	*lastnode;

// 	head = a->top;
// 	lastnode = ft_rralastnode(head, 1);
// 	printf("check my lastnode:%d\n", lastnode->value);
// 	lastnode -> next = head;
// 	head = lastnode;
// 	a->top = head;
// 	lastnode = ft_rralastnode(head, 0);
// }

// Shift down all elements of stack b by 1
// void rrb(t_stack *b)
// {
// 	t_node	*head;
// 	t_node	*lastnode;

// 	head = b->top;
// 	lastnode = ft_rralastnode(head, 1);
// 	printf("check my lastnode:%d\n", lastnode->value);
// 	lastnode -> next = head;
// 	head = lastnode;
// 	b->top = head;
// 	lastnode = ft_rralastnode(head, 0);
// }

