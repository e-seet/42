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
	t_node	*head;
	t_node	*lastnode;

	head = stack->top;
	lastnode = ft_rralastnode(head, 1);
	printf("check my lastnode:%d\n", lastnode->value);
	lastnode -> next = head;
	head = lastnode;
	stack->top = head;
	lastnode = ft_rralastnode(head, 0);
}

// rra and rrb at the same time
void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}

// Take the first element at the top of a and put it at the top of b
void	pb(t_stack *a, t_stack *b)
{
	t_node	*topnode_a;
	t_node	*topnode_b;

	topnode_a = a->top;
	topnode_b = b->top;
	if (topnode_a != NULL)
	{
		if (topnode_a -> next != NULL)
		{
			a->top = topnode_a->next;
			topnode_a->next = topnode_b;
			b->top = topnode_a;
		}
	}
}

// Take the first element at the top of b and put it at the top of a
void	pa(t_stack *a, t_stack *b)
{
	t_node	*topnode_a;
	t_node	*topnode_b;

	topnode_a = a->top;
	topnode_b = b->top;
	if (topnode_b != NULL)
	{
		if (topnode_b -> next != NULL)
		{
			b->top = topnode_b->next;
			topnode_b->next = topnode_a;
			a->top = topnode_b;
		}
	}
}
