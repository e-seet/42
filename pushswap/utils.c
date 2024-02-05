#include "utils.h"

void	initstack(t_stack *stack)
{
	stack->top = NULL;
}

int	isempty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	addtoback(t_stack *stack, int value)
{
	t_node	*curr;
	t_node	*newnode;

	curr = stack->top;
	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
	{
		printf("Failed to allocate memory.\n");
		return ;
	}
	newnode->value = value;
	if (stack -> top == NULL)
	{
		stack->top = newnode;
	}
	else
	{
		while (curr -> next != NULL)
		{
			curr = curr ->next;
		}
		curr ->next = newnode;
	}
}

void	push(t_stack *stack, int value)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
	{
		printf("Failed to allocate memory.\n");
		return ;
	}
	newnode->value = value;
	newnode->next = stack->top;
	stack->top = newnode;
}

int	pop(t_stack *stack)
{
	int		poppedvalue;
	t_node	*temp;

	if (isempty(stack))
	{
		printf("Stack is empty.\n");
		return (-1);
	}
	temp = stack->top;
	poppedvalue = temp->value;
	stack->top = temp->next;
	free(temp);
	return (poppedvalue);
}

// Function to display the elements in the linked list
void	displaylinkedlist(t_node *head)
{
	t_node	*current;

	current = head;
	printf("Linked List: ");
	while (current != NULL)
	{
		printf("\n%d  ", current->value);
		current = current->next;
	}
	printf("\n");
}

// Function to display the elements in the stack (linked list)
void	displaystack(t_stack *stack)
{
	displaylinkedlist(stack->top);
}

// Swap the first 2 elements at the top of stack a
void	sa(t_stack *stack)
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

// Swap the first 2 elements at the top of stack b
void	sb(t_stack *stack)
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

// void ss(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sa(b);
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

// Shift up all elements of stack a by 1
void	ra(t_stack *a)
{
	t_node	*curr;
	t_node	*lastnode;

	lastnode = a->top;
	a -> top = lastnode -> next;
	lastnode -> next = NULL;
	curr = a->top;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = lastnode;
}

// Shift up all elements of stack b by 1
void	rb(t_stack *b)
{
	t_node	*curr;
	t_node	*lastnode;

	lastnode = b->top;
	b -> top = lastnode -> next;
	lastnode -> next = NULL;
	curr = b->top;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = lastnode;
}

// ra and rb at the same time
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}


t_node *ft_rralastnode(t_node *head, int tonull)
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

// Shift down all elements of stack a by 1
void rra(t_stack *a)
{
	t_node	*head;
	t_node	*lastnode;

	head = a->top;
	lastnode = ft_rralastnode(head, 1);
	printf("check my lastnode:%d\n", lastnode->value);
	lastnode -> next = head;
	head = lastnode;
	a->top = head;
	lastnode = ft_rralastnode(head, 0);
	
}
// Shift down all elements of stack b by 1
void rrb(t_stack *b)
{
	t_node	*head;
	t_node	*lastnode;

	head = b->top;
	lastnode = ft_rralastnode(head, 1);
	printf("check my lastnode:%d\n", lastnode->value);
	lastnode -> next = head;
	head = lastnode;
	b->top = head;
	lastnode = ft_rralastnode(head, 0);
}

// rra and rrb at the same time
void rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
