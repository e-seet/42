#include "sort5c.h"

void	sort5_case1(t_stack *stack_a, int *numberofop, t_element5 *element5)
{
	if (element5->secondlargestpos == 1)
	{
		swap_top_two(stack_a, numberofop);
		bringtobot(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 2)
	{
		swap_top_two(stack_a, numberofop);
		rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		bringtobot(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 3)
	{
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		rotate_stack(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 4)
		rotate_stack(stack_a, numberofop);
}

void	sort5_case2(t_stack *stack_a, int *numberofop, t_element5 *element5)
{
	if (element5->secondlargestpos == 0)
		bringtobot(stack_a, numberofop);
	else if (element5->secondlargestpos == 2)
	{
		rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		bringtobot(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 3)
	{
		swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		rotate_stack(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 4)
	{
		swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		bringtobot(stack_a, numberofop);
	}
}

void	sort5_case3(t_stack *stack_a, int *numberofop, t_element5 *element5)
{
	if (element5->secondlargestpos == 0)
	{
		swap_top_two(stack_a, numberofop);
		rotate_stack(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 1)
		rotate_stack(stack_a, numberofop);
	else if (element5->secondlargestpos == 3)
	{
		rotate_stack(stack_a, numberofop);
		rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 4)
	{
		reverse_rotate_stack(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
	}
	bringtobot(stack_a, numberofop);
}

void	sort5_case4(t_stack *stack_a, int *numberofop, t_element5 *element5)
{
	if (element5->secondlargestpos == 0 || element5->secondlargestpos == 1)
	{
		if (element5->secondlargestpos == 1)
			swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		bringtobot(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 2)
		reverse_rotate_stack(stack_a, numberofop);
	else if (element5->secondlargestpos == 4)
	{
		reverse_rotate_stack(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		bringtobot(stack_a, numberofop);
	}
}

void	sort5_case5(t_stack *stack_a, int *numberofop, t_element5 *element5)
{
	if (element5->secondlargestpos == 0)
	{
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		bringtobot(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 1)
	{
		printf("this runs\n");
		swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		bringtobot(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 2)
	{
		reverse_rotate_stack(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		rotate_stack(stack_a, numberofop);
	}
	else if (element5->secondlargestpos == 3)
		printf("no action required");
}
