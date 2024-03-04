#include "radix_sort.h"

int	radix_sort_wrapper(int argc, t_stack *stack_a, t_stack *stack_b,
	int *numberofop)
{
	int	i;

	i = 1;
	setpos(stack_a, argc, i);
	radix_sort(stack_a, stack_b, numberofop);
	return (0);
}

void	setpos2(t_node *curr, int smallest, int i)
{
	while (curr->value != smallest)
	{
		curr = curr->next;
	}
	curr ->pos = i;
}

void	setpos(t_stack *stack_a, int argc, int i)
{
	int		smallest;
	t_node	*curr;

	i = 1;
	while (argc + 1 > i)
	{
		curr = stack_a ->top;
		while (curr->pos != 0)
		{
			curr = curr ->next;
		}
		smallest = curr->value;
		while (curr ->next != stack_a->top)
		{
			if (smallest > curr->value && curr->pos == 0)
				smallest = curr->value;
			curr = curr->next;
		}
		if (smallest > curr->value && curr->pos == 0)
			smallest = curr->value;
		curr = stack_a->top;
		setpos2(curr, smallest, i);
		i++;
	}
}

void	radix_sort_a(t_stack *stack_a, t_stack *stack_b, int *numberofop, int i)
{
	t_node	*head_a;
	t_node	*tail_a;

	head_a = stack_a->top;
	tail_a = stack_a->bot;
	while (head_a != tail_a)
	{
		head_a = stack_a->top;
		tail_a = stack_a->bot;
		if (stack_a ->top != NULL)
			head_a = stack_a->top;
		if (((head_a->pos >> i) & 1) == 0)
			pb(stack_a, stack_b, numberofop);
		else
			rotate_stack(stack_a, numberofop, 0);
		head_a = stack_a->top;
	}
	if (((head_a->pos >> i) & 1) == 0)
		pb(stack_a, stack_b, numberofop);
	else
		rotate_stack(stack_a, numberofop, 0);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
	int		i;
	t_node	*head_b;

	i = 0;
	while (32 > i)
	{
		if (stack_is_sorted(stack_a) == 0 || stack_is_sorted2(stack_a) == 0)
			break ;
		radix_sort_a(stack_a, stack_b, numberofop, i);
		head_b = stack_b->top;
		if (head_b != NULL)
		{
			while (head_b != NULL)
			{
				pa(stack_a, stack_b, numberofop);
				head_b = stack_b->top;
			}
		}
		i = i + 1;
	}
}
