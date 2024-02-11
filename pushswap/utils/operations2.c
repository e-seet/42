#include "operations2.h"

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
void	reverse_rotate_stack(t_stack *stack)
{
	printf("RRA/RRB: reverse_rotate_stack\n");
	t_node	*head;
	t_node	*lastnode;

	head = stack->top;
	lastnode = ft_rralastnode(head, 1);
	// printf("check my lastnode:%d\n", lastnode->value);
	lastnode -> next = head;
	head = lastnode;
	stack->top = head;
	// manual check that next is present and then assign it to next
	if (head -> next != NULL)
	{
		head = head->next;
		stack->sec = head;
	}	
	lastnode = ft_rralastnode(head, 0);
	stack->bot = lastnode;
}

// rra and rrb at the same time
void	rrr(t_stack *a, t_stack *b)
{
	printf("RRR:");
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}

// Take the first element at the top of a and put it at the top of b
void	pb(t_stack *a, t_stack *b)
{
	printf("PB\n");
	t_node	*topnode_a;
	t_node	*topnode_b;

	topnode_a = a->top;
	topnode_b = b->top;
	// check not null
	if (topnode_a != NULL)
	{
		// check there is 2nd node
		if (topnode_a -> next != NULL)
		{
			// change the top ref
			a->top = topnode_a->next;
			// if there is third node, set it to second node
			if ((topnode_a->next)->next != NULL)
			{
				a->sec = (topnode_a->next)->next;
			}
			// set new top node
			topnode_a->next = topnode_b;
			if (b->top != NULL)
				b->sec = b->top;

			b->top = topnode_a;
			b->bot = ft_rralastnode(b->top, 0); 
		}
	}
}

// Take the first element at the top of b and put it at the top of a
void	pa(t_stack *a, t_stack *b)
{
	printf("PA\n");
	t_node	*topnode_a;
	t_node	*topnode_b;

	topnode_a = a->top;
	topnode_b = b->top;
	if (topnode_b != NULL)
	{
		if (topnode_b -> next != NULL)
		{
			b->top = topnode_b->next;
			if ((topnode_b->next)->next != NULL)
			{
				b->sec = (topnode_b->next)->next;
			}

		}
		else
		{
			b->top = NULL;
			b->sec = NULL;
			b->bot = NULL;
		}
			topnode_b->next = topnode_a;
			a->top = topnode_b;
	}
}
