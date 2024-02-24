#include "utils.h"

int	count_elements_in_stack(t_node *head)
{
	// printf("count element in stack\n");
	if (head == NULL)
		return (0);


	int	i;
	t_node *curr;

	curr = head;
	i = 1;


	curr = curr ->next;
	while (curr != head)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

// not sorted returns 1
// sorted return 0
int	stack_is_sorted(t_stack *stack)
{
	// printf("stack is sorted \n");

	t_node	*head;
	t_node	*curr;
	int		val;

	head = stack->top;
	val = head->value;
	curr = head->next;
	while (curr->next != head)
	{
		if (curr->value > val)
			val = curr->value;
		else
		{
			return (1);
		}
		curr = curr->next;
	}
	if (curr->value > val)
			val = curr->value;
		else
		{
			return (1);
		}
	return (0);
}

int	stack_is_sorted2(t_stack *stack)
{
	// printf("stack is sorted 2 \n");
	t_node	*head;
	t_node	*curr;
	int		pos;

	head = stack->top;
	if (head == NULL)
	{
		// printf("meow :%p \n", head);
		// printf("meow :%d \n", head->pos); // the issue is here
		// printf("meow :%p \n", head);

		return (1);
	}

	pos = head->pos;
	curr = head->next;
	while (curr->next != head)
	{
		if (curr->pos > pos)
			pos = curr->pos;
		else
		{
			// printf("end of sorted 2\n");

			return (1);
		}
		curr = curr->next;
	}
	if (curr->pos > pos)
			pos = curr->pos;
		else
		{
			// printf("end of sorted 2\n");
			return (1);
		}
			// printf("end of sorted 2\n");

	return (0);
}

int	stack_is_rev_sorted(t_stack *stack)
{
	// printf("stack is rev sorted 2 \n");
	t_node	*head;
	t_node	*curr;
	int		pos;

	head = stack->top;
	if (head == NULL)
	{
		return (1);
	}

	pos = head->pos;
	curr = head->next;
	while (curr->next != head)
	{
		if (curr->pos < pos)
			pos = curr->pos;
		else
		{
			// printf("end of sorted 2\n");

			return (1);
		}
		curr = curr->next;
	}
	if (curr->pos < pos)
			pos = curr->pos;
	else
	{
		printf("end of sorted 2\n");
		return (1);
	}
	printf("end of sorted 2\n");

	return (0);
}
