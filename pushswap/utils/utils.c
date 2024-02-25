#include "utils.h"
#include "timsort.h"
#include "operations.h"
#include "operations2.h"

void	initstack(t_stack *stack)
{
	stack->top = NULL;
	stack->bot = NULL;
	stack->numofelements = -1;
}

t_node	*create_node(int value)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
	{
		printf("Failed to allocate memory.\n");
		return (NULL);
	}
	newnode->value = value;
	newnode->next = NULL;
	newnode->pos = 0;
	newnode->prev = NULL;
	return (newnode);
}

void	addtoback(t_stack *stack, int value)
{
	t_node	*head;
	t_node	*curr;
	t_node	*newnode;

	newnode = create_node(value);
	head = stack->top;
	// if there is no node
	if (head == NULL)
		stack->top = newnode;
	else
	{
		curr = head;
		// if there is 1 node
		if (curr->next == NULL)
		{
			printf("only 1 node\n");
			curr -> next = newnode;
			curr -> prev = newnode;
			newnode -> next = curr;
			newnode -> prev = curr;
		}
		// if there is 2 nodes
		else
		{
			while (curr -> next != head)
			{
				curr = curr ->next;
			}
			curr -> next = newnode;
			newnode -> next = head;
			newnode -> prev = curr;
			head->prev = newnode;
		}
		stack->numofelements += 1;
		stack->bot = newnode;
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
	if (stack->numofelements == -1)
	{
		stack->bot = newnode;
		stack->numofelements = 1;
	}
	else
	{
		stack->numofelements += 1;
	}
	stack->top = newnode;
}

// Function to display the elements in the linked list
void	displaylinkedlist(t_node *head)
{
	t_node	*current;

	current = head;
	printf("Linked List: ");
	printf("\n%d  ", current->value);
	current = current ->next;
	while (current != head)
	{
		printf("\n%d  ", current->value);
		current = current->next;
	}
	printf("\n\n");
}

// Function to display the elements in the linked list
void	displaylinkedlist2(t_node *head)
{
	t_node	*current;
	int		i;

	current = head;
	i = 0;
	if (current == NULL)
	{
		// printf("curr is null\n");
		return ;
	}
	printf("Linked List: ");
	printf("\nvalue%d", current->value);
	printf("+pos:%d  ", current->pos);
	printf("\nprev:%p  ", current->prev);
	printf("\ncurr:%p  ", current);
	printf("\nnext:%p  ", current->next);
	current = current->next;
	while (current != head)
	{
		// printf("\ncurr:%p  ", current);
		printf("\n%d  ", current->value);
		printf("+pos:%d  ", current->pos);
		printf("\nprev:%p  ", current->prev);
		printf("\ncurr:%p  ", current);
		printf("\nnext:%p  ", current->next);
		if (current == current->next || i > 8)
		{
			printf("curr == curr->Next or i > 6\n");
			break ;
		}
		current = current->next;
		i ++;
	}
	/*printf("\n\nreverse it");
	printf("\n%d  ", current->value);
	printf("\nprev:%p  ", current->prev);
	printf("\ncurr:%p  ", current);
	printf("\nnext:%p  ", current->next);
	current = current->prev;
	while (current != head)
	{
		// printf("\ncurr:%p  ", current);
		printf("\n%d  ", current->value);
		printf("\nprev:%p  ", current->prev);
		printf("\ncurr:%p  ", current);
		 printf("\nnext:%p  ", current->next);
		// printf("\nnext:%p  ", current->next);
		if (current == current->prev || i > 20)
		{
			printf("curr == curr->prev or i > 12\n");
			break;
		}
		current = current->prev;
		i ++;
	}
	printf("\n\n");*/
}

// Function to display the elements in the stack (linked list)
void	displaystack(t_stack *stack)
{
	printf("display linked list:\n");
	displaylinkedlist(stack->top);
	// /* displaylinkedlist2(stack->top);*/
}

int	scan_num_pos(t_stack *stack, int num)
{
	t_node	head;
	int		pos;

	head = *stack->top;
	pos = 0;
	while (head.value != num)
	{
		head = *head.next;
		pos ++;
	}
	return (pos);
}

void	bringtobot(t_stack *stack, int *numberofop)
{
	rotate_stack(stack, numberofop);
	printf("after roate stack\n");
	rotate_stack(stack, numberofop);
}

// int scanSmallestNumPos(t_stack *stack, int num)
// {
// 	t_node head;
// 	head = *stack->top;
// 	int pos = 0;

// 	while(head.value != num)
// 	{
// 		head = *head.next;
// 		pos ++;
// 	}
// 	return pos;
// }

// int scanSmallestNum(t_stack *stack)
// {
// 	t_node *head = stack ->top;
// 	int smallestnum;

// 	smallestnum = INT_MAX;
// 	while (head != NULL)
// 	{
// 		if (smallestnum > head->value)
// 			smallestnum = head->value;
// 		head = head->next;
// 	}
// 	return (smallestnum);
// }

// // just do a basic assignment for the first two number
// int scan2SmallestNum(t_stack *stack)
// {
// 	t_node *head = stack ->top;
// 	int smallestnum = INT_MAX;
// 	int secondsmallest = INT_MAX;

// 	while (head != NULL)
// 	{
// 		if (smallestnum > head->value)
// 		{
// 			secondsmallest = smallestnum;
// 			smallestnum = head->value;
// 		}
// 		else if (secondsmallest > head->value)
// 			secondsmallest = head->value;
// 		head = head->next;
// 	}
// 	if (secondsmallest != INT_MAX)
// 		return (secondsmallest);
// 	else
// 		return (-1);
// }

// int scan2largestNum(t_stack *stack)
// {
// 	t_node *head = stack ->top;
// 	int biggestnum = INT_MIN;
// 	int secondbiggest = INT_MIN;

// 	while (head != NULL)
// 	{
// 		if (head->value > biggestnum)
// 		{
// 			secondbiggest = biggestnum;
// 			biggestnum = head->value;
// 		}
// 		else if (head->value > secondbiggest)
// 			secondbiggest = head->value;
// 		head = head->next;
// 	}
// 	if (secondbiggest != INT_MAX)
// 		return (secondbiggest);
// 	else
// 		return (-1);
// }

// int scanlargestNum(t_stack *stack)
// {
// 	t_node *head = stack ->top;
// 	int largest;

// 	if (head != NULL)
// 	{
// 		largest = head->value;
// 	}

// 	while (head != NULL)
// 	{
// 		if (head->value > largest)
// 		{
// 			largest = head->value;
// 		}
// 		head = head->next;
// 	}
// 	return (largest);
// }

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

// initElement

// counting by rotate 

//counting by reverse rotate
