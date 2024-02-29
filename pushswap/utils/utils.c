#include "utils.h"
#include "utils2.h"
#include "utils3.h"
#include "operations.h"
#include "operations2.h"

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

void	addtoback2(t_node *curr, t_node *head, t_node *newnode)
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

void	addtoback(t_stack *stack, int value)
{
	t_node	*head;
	t_node	*curr;
	t_node	*newnode;

	newnode = create_node(value);
	head = stack->top;
	if (head == NULL)
		stack->top = newnode;
	else
	{
		curr = head;
		if (curr->next == NULL)
		{
			curr -> next = newnode;
			curr -> prev = newnode;
			newnode -> next = curr;
			newnode -> prev = curr;
		}
		else
		{
			addtoback2(curr, head, newnode);
		}
		stack->numofelements += 1;
		stack->bot = newnode;
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
// 	if (stack->numofelements == -1)
// 	{
// 		stack->bot = newnode;
// 		stack->numofelements = 1;
// 	}
// 	else
// 		stack->numofelements += 1;
// 	stack->top = newnode;
// }

//temp
int	ft_lstsize2(t_node *head)
{
	int		i;
	t_node	*curr;

	printf("ft_lstsize2\n");
	curr = head;
	i = 0;
	if (curr == NULL)
		return (0);
	else
	{
		printf("value: %d\n", curr->value);
		i ++;
		curr = curr -> next;
		while (curr != head)
		{
			printf("value: %d\n", curr->value);
			curr = curr -> next;
			i++;
		}
		printf("size i = %d\n\n", i);
		return (i);
	}
}

int	scan_num_pos(t_stack *stack, int num)
{
	t_node	*head;
	int		pos;
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize_modified(stack->top);
	head = stack->top;
	pos = 0;
	while (size > i)
	{
		if (head->value == num)
			break ;
		head = head->next;
		pos ++;
		i = i + 1;
	}
	printf("number:%d", num);
	printf("pos:%d\n", pos);
	return (pos);
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