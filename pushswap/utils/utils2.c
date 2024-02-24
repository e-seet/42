#include "utils.h"

int	count_elements_in_stack(t_node *head)
{
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
	t_node	*head;
	t_node	*curr;
	int		pos;

	head = stack->top;
	pos = head->pos;
	curr = head->next;
	while (curr->next != head)
	{
		if (curr->pos > pos)
			pos = curr->pos;
		else
		{
			return (1);
		}
		curr = curr->next;
	}
	if (curr->pos > pos)
			pos = curr->pos;
		else
		{
			return (1);
		}
	return (0);
}
