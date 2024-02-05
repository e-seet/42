#include "utils.h"
#include "operations.h"
#include "operations2.h"

void	initstack(t_stack *stack)
{
	stack->top = NULL;
}

// int	isempty(t_stack *stack)
// {
// 	return (stack->top == NULL);
// }

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

// void	push(t_stack *stack, int value)
// {
// 	t_node	*newnode;

// 	newnode = (t_node *)malloc(sizeof(t_node));
// 	if (newnode == NULL)
// 	{
// 		printf("Failed to allocate memory.\n");
// 		return ;
// 	}
// 	newnode->value = value;
// 	newnode->next = stack->top;
// 	stack->top = newnode;
// }

// int	pop(t_stack *stack)
// {
// 	int		poppedvalue;
// 	t_node	*temp;

// 	if (isempty(stack))
// 	{
// 		printf("Stack is empty.\n");
// 		return (-1);
// 	}
// 	temp = stack->top;
// 	poppedvalue = temp->value;
// 	stack->top = temp->next;
// 	free(temp);
// 	return (poppedvalue);
// }

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
