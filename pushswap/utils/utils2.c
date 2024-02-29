#include "utils2.h"

// int	count_elements_in_stack(t_node *head)
// {
// 	int		i;
// 	t_node	*curr;

// 	curr = head;
// 	i = 1;
// 	curr = curr ->next;
// 	while (curr != head)
// 	{
// 		curr = curr->next;
// 		i++;
// 	}
// 	return (i);
// }

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
			return (1);
		curr = curr->next;
	}
	if (curr->value > val)
		val = curr->value;
	else
		return (1);
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
			return (1);
		curr = curr->next;
	}
	if (curr->pos > pos)
		pos = curr->pos;
	else
		return (1);
	return (0);
}

int	ft_atoi_modified(const char *str, int *err)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = str[i] - 48 + num * 10;
		i++;
	}
	if (i == 0 || str[i] != '\0' || num * sign > INT_MAX
		|| num * sign < INT_MIN)
		*err = 1;
	else
		*err = 0;
	return (num * sign);
}

// Function to check for duplicates in a circular linked list
int	has_duplicate(t_node *head)
{
	t_node	*current;
	t_node	*compare;

	current = head->next;
	if (head == NULL || head->next == head)
		return (0);
	while (current != head)
	{
		compare = head;
		while (compare != current)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	ft_lstsize_modified(t_node *head)
{
	int		i;
	t_node	*curr;

	curr = head;
	i = 0;
	if (curr == NULL)
		return (0);
	else
	{
		while (curr->next != head)
		{
			curr = curr -> next;
			i++;
		}
		return (i);
	}
}
