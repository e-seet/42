#include "utils.h"

int	count_elements_in_stack(t_node *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

// not sorted returns 1
// sorted return 0
int	stack_is_sorted(t_stack *stack)
{
	t_node	head;
	int		val;

	head = *stack->top;
	val = INT_MIN;
	while (head.next != NULL)
	{
		if (head.value > val)
			val = head.value;
		else
		{
			return (1);
		}
		head = *head.next;
	}
	return (0);
}
