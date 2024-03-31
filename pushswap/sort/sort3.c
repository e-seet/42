/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:22:33 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:22:33 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "sort3.h"

int	sort3wrapper(t_stack *stack_a, t_stack *stack_b,
		int *numberofop, int sorttype)
{
	t_element3	element3;

	init3_element(&element3);
	find3_numbers(stack_a->top, &element3);
	element3.smallestpos = scan_num_pos(stack_a, element3.smallest);
	element3.middlepos = scan_num_pos(stack_a, element3.middle);
	element3.largestpos = scan_num_pos(stack_a, element3.largest);
	if (sorttype == 0)
		sort5elementstop3v1(stack_a, numberofop, &element3);
	exitsafe(stack_a, stack_b);
	return (0);
}

void	find3_numbers(t_node *head, t_element3 *element3)
{
	int	temp;

	element3->smallest = head->value;
	element3->middle = head->next->value;
	element3->largest = head->next->next->value;
	if (element3->smallest > element3->middle)
	{
		temp = element3->smallest;
		element3->smallest = element3->middle;
		element3->middle = temp;
	}
	if (element3->smallest > element3->largest)
	{
		temp = element3->smallest;
		element3->smallest = element3->largest;
		element3->largest = temp;
	}
	if (element3->middle > element3->largest)
	{
		temp = element3->middle;
		element3->middle = element3->largest;
		element3->largest = temp;
	}
}

void	sort5elementstop3v1(t_stack *stack_a, int *numberofop,
		t_element3 *element3)
{
	if (element3->smallestpos == 0 && element3->largestpos == 2)
	{
	}
	else if (element3->smallestpos == 0 && element3->largestpos == 1)
	{
		rotate_stack(stack_a, numberofop, 0);
		swap_top_two(stack_a, numberofop, 0);
		reverse_rotate_stack(stack_a, numberofop, 0);
	}
	else if (element3->smallestpos == 1 && element3->largestpos == 2)
		swap_top_two(stack_a, numberofop, 0);
	else if (element3->smallestpos == 2 && element3->largestpos == 1)
		reverse_rotate_stack(stack_a, numberofop, 0);
	else if (element3->smallestpos == 1 && element3->largestpos == 0)
		rotate_stack(stack_a, numberofop, 0);
	else if (element3->smallestpos == 2 && element3->largestpos == 0)
	{
		swap_top_two(stack_a, numberofop, 0);
		reverse_rotate_stack(stack_a, numberofop, 0);
	}
}

void	sort5elementstop3_2(t_stack *stack_a, int *numberofop,
	t_element3 *element3)
{
	if (element3->smallestpos == 1 && element3->largestpos == 0)
	{
		swap_top_two(stack_a, numberofop, 0);
		rotate_stack(stack_a, numberofop, 0);
		swap_top_two(stack_a, numberofop, 0);
		reverse_rotate_stack(stack_a, numberofop, 0);
	}
	else if (element3->smallestpos == 2 && element3->largestpos == 0)
	{
		swap_top_two(stack_a, numberofop, 0);
		rotate_stack(stack_a, numberofop, 0);
		swap_top_two(stack_a, numberofop, 0);
		reverse_rotate_stack(stack_a, numberofop, 0);
		swap_top_two(stack_a, numberofop, 0);
	}
}

void	sort5elementstop3(t_stack *stack_a, int *numberofop,
	t_element3 *element3)
{
	if (element3->smallestpos == 0 && element3->largestpos == 2)
	{
	}
	else if (element3->smallestpos == 0 && element3->largestpos == 1)
	{
		rotate_stack(stack_a, numberofop, 0);
		swap_top_two(stack_a, numberofop, 0);
		reverse_rotate_stack(stack_a, numberofop, 0);
	}
	else if (element3->smallestpos == 1 && element3->largestpos == 2)
		swap_top_two(stack_a, numberofop, 0);
	else if (element3->smallestpos == 2 && element3->largestpos == 1)
	{
		rotate_stack(stack_a, numberofop, 0);
		swap_top_two(stack_a, numberofop, 0);
		reverse_rotate_stack(stack_a, numberofop, 0);
		swap_top_two(stack_a, numberofop, 0);
	}
	else
		sort5elementstop3_2(stack_a, numberofop, element3);
}
