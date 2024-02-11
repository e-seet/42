#include "utils.h"
#include "timsort.h"
#include "operations.h"
#include "operations2.h"

void	initstack(t_stack *stack)
{
	stack->top = NULL;
	stack->sec = NULL;
	stack->bot = NULL;
	stack->numofelements = -1;
}

// void	initdatastore(s_datastore *stackdetails)
// {
// 	stackdetails->stack_a_top = -1;
// 	stackdetails->stack_a_sec = -1;
// 	stackdetails->stack_a_third = -1;
// 	stackdetails->stack_a_last = -1;
// 	stackdetails->stack_a_numofelements = -1;

// 	stackdetails->stack_b_top = -1;
// 	stackdetails->stack_b_sec = -1;
// 	stackdetails->stack_b_third = -1;
// 	stackdetails->stack_b_last = -1;
// 	stackdetails->stack_b_numofelements = -1;
// }

// int	isempty(t_stack *stack)
// {
// 	return (stack->top == NULL);
// }

// void	addtoback(t_stack *stack, int value)
// {
// 	t_node	*curr;
// 	t_node	*newnode;

// 	curr = stack->top;
// 	newnode = (t_node *)malloc(sizeof(t_node));
// 	if (newnode == NULL)
// 	{
// 		printf("Failed to allocate memory.\n");
// 		return ;
// 	}
// 	newnode->value = value;
// 	if (stack -> top == NULL)
// 	{
// 		stack->top = newnode;
// 	}
// 	else
// 	{
// 		while (curr -> next != NULL)
// 		{
// 			curr = curr ->next;
// 		}
// 		curr ->next = newnode;
// 	}
// }

// void	push(t_stack *stack, int value, s_datastore *stackdetails)
// {
// 	t_node	*newnode;

// 	newnode = (t_node *)malloc(sizeof(t_node));
// 	if (newnode == NULL)
// 	{
// 		printf("Failed to allocate memory.\n");
// 		return ;
// 	}
// 	if (stackdetails->stack_a_last == -1)
// 		stackdetails ->stack_a_last = value;
// 	stackdetails->stack_a_top = value;
// 	newnode->value = value;
// 	newnode->next = stack->top;

// 	// t_node *temp;
// 	// temp = stack->top;
// 	if (stack->top != NULL)
// 		stackdetails->stack_a_sec = stack->top->value;
	
// 	stack->top = newnode;
// }
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
	
	if (stack->numofelements == -1)
	{
		stack->bot = newnode;
		stack->numofelements = 1;
	}
	else
	{
		stack->sec = stack->top;
		stack->numofelements += 1;
	}

	stack->top = newnode;
}

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
	printf("\n\n");
}

// Function to display the elements in the stack (linked list)
void	displaystack(t_stack *stack)
{
	displaylinkedlist(stack->top);
}

int scanSmallestNum(t_stack *stack)
{
	t_node *head = stack ->top;
	int smallestnum;

	smallestnum = INT_MAX;
	while (head != NULL)
	{
		if (smallestnum > head->value)
			smallestnum = head->value;
		head = head->next;
	}
	return (smallestnum);
}

// just do a basic assignment for the first two number
int scan2SmallestNum(t_stack *stack)
{
	t_node *head = stack ->top;
	int smallestnum;
	int secondsmallest;

	if (head->next != NULL)
	{
		if ((head ->next)->value > head->value)
		{
			secondsmallest = head->value;
			smallestnum = head->next->value;
		}
		else
		{
			smallestnum = head->value;
		 	secondsmallest = head->next->value;
		}
	}
	while (head != NULL)
	{
		if (smallestnum > head->value)
		{
			secondsmallest = smallestnum;
			smallestnum = head->value;
		}
		head = head->next;
	}
	return (secondsmallest);
}
