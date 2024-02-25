#include "./utils/utils.h"
#include "./utils/utils2.h"
// #include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./sort/sort3.h"
#include "./sort/sort5.h"

void	setpos(t_stack *stack_a, int argc)
{
	int		i;
	int		smallest;
	t_node	*curr;

	i = 1;
	while (argc > i)
	{
		curr = stack_a ->top;
		while (curr->pos != 0)
		{
			curr = curr ->next;
		}
		smallest = curr->value;
		// find the smallest for every iteration
		while (curr ->next != stack_a->top)
		{
			if (smallest > curr->value && curr->pos == 0)
			{
				smallest = curr->value;
			}
			curr = curr->next;
		}
		// check last item
		if (smallest > curr->value && curr->pos == 0)
		{
			smallest = curr->value;
		}
		// find where the node of interest is and set pos
		curr = stack_a->top;
		while (curr->value != smallest)
		{
			curr = curr->next;
		}
		curr ->pos = i;
		i++;
	}
	displaylinkedlist2(stack_a->top);
}

void	loopbit(int num)
{
	int	i;
	int	bit;

	i = 0;
	// Iterate through all 32 bits
	while (i < 32)
	{
		bit = (num >> i) & 1;
		printf("%d", bit);
		i = i + 1;
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
	int		i;
	t_node	*head_a;
	t_node	*head_b;
	t_node	*tail_a;

	tail_a = stack_a->bot;
	i = 0;
	while (32 > i)
	{
		head_a = stack_a->top;
		tail_a = stack_a->bot;
		if (stack_is_sorted(stack_a) == 0 || stack_is_sorted2(stack_a) == 0)
		{
			break ;
		}
		while (head_a != tail_a)
		{
			if (stack_a ->top != NULL)
			{
				head_a = stack_a->top;
			}
			if (((head_a->pos >> i) & 1) == 0)
			{
				pb(stack_a, stack_b, numberofop);
			}
			else
			{
				rotate_stack(stack_a, numberofop);
			}
			head_a = stack_a->top;
		}
		if (((head_a->pos >> i) & 1) == 0)
		{
			pb(stack_a, stack_b, numberofop);
		}
		else
		{
			rotate_stack(stack_a, numberofop);
		}
		head_b = stack_b->top;
		if (head_b != NULL)
		{
			while (head_b != NULL)
			{
				pa(stack_a, stack_b, numberofop);
				head_b = stack_b->top;
			}
		}
		displaylinkedlist2(stack_a->top);
		i = i + 1;
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	t_stack		stack_a;
	t_stack		stack_b;
	int			numberofop;
	t_element3	element3;
	t_element5	element5;

	numberofop = 0;
	i = 1;
	initstack(&stack_a);
	initstack(&stack_b);
	while (argv[i])
	{
		addtoback(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	if (argc == 4)
	{
		init3_element(&element3);
		find3_numbers(stack_a.top, &element3);
		find3_numbers_pos(&stack_a, &element3);
		sort5elementstop3(&stack_a, &numberofop, &element3);
		displaystack(&stack_a);
	}
	else if (argc == 5)
	{
	}
	if (argc == 6)
	{
		init5_element(&element5);
		sort5(stack_a, stack_b, &numberofop, &element5);
	}
	else
	{
		setpos(&stack_a, argc);
		radix_sort(&stack_a, &stack_b, &numberofop);
	}
	displaystack(&stack_a);
	printf("ops:%d\n", numberofop);
	return (0);
}
