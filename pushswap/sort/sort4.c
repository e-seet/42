/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:22:40 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:22:41 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort4.h"

// printf("smallest:%d,\n second smallest:%d,\n 2nd large%d,\n
// largest:%d\n", element4.smallest, element4.secondsmallest,
// element4.secondlargest, element4.largest);
// printf("sorted\n");
// displaylinkedlist2(stack_a->top);
int	sort4wrapper(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
	t_element4	element4;
	int			size;

	element4.smallest = INT_MAX;
	element4.secondsmallest = INT_MAX;
	element4.secondlargest = INT_MIN;
	element4.largest = INT_MIN;
	size = ft_lstsize_modified(stack_a->top);
	find4_numbers(stack_a->top, &element4, size);
	sort4_al(stack_a, numberofop, &element4);
	exitsafe(stack_a, stack_b);
	return (0);
}

// Function to find the smallest, 2nd smallest, middle,
// 2nd largest, and largest numbers in the linked list
void	find4_numbers(t_node *head, t_element4 *element4, int size)
{
	struct s_node	*current;
	int				i;

	i = 0;
	current = head;
	while (size >= i)
	{
		if (current->value < element4->smallest)
		{
			element4->secondsmallest = element4->smallest;
			element4->smallest = current->value;
		}
		else if (current->value < element4->secondsmallest)
			element4->secondsmallest = current->value;
		if (current->value > element4->largest)
		{
			element4->secondlargest = element4->largest;
			element4->largest = current->value;
		}
		else if (current->value > element4->secondlargest)
			element4->secondlargest = current->value;
		current = current->next;
		i = i + 1;
	}
}

void	sort_4_top3(t_element4 *element4, t_stack *stack_a, int *numberofop)
{
	t_element3	element3;

	init3_element(&element3);
	element3.smallest = element4->smallest;
	element3.middle = element4->secondsmallest;
	element3.largest = element4->secondlargest;
	element3.smallestpos = scan_num_pos(stack_a, element4->smallest);
	element3.middlepos = scan_num_pos(stack_a, element4->secondsmallest);
	element3.largestpos = scan_num_pos(stack_a, element4->secondlargest);
	sort5elementstop3(stack_a, numberofop, &element3);
}

// void	sort4_al(t_stack *stack_a, t_stack *stack_b, int *numberofop,
// printf("\npositions\n");
// printf("smallest:%d,\nsecond smallest:%d,\n2nd large%d,\nlargest:%d\n\n", 
// element4->smallestpos, element4->secondsmallestpos,
// element4->secondlargestpos, element4->largestpos);
void	sort4_al(t_stack *stack_a, int *numberofop,
		t_element4 *element4)
{
	element4->smallestpos = scan_num_pos(stack_a, element4->smallest);
	element4->secondsmallestpos = scan_num_pos(stack_a,
			element4->secondsmallest);
	element4->secondlargestpos = scan_num_pos(stack_a, element4->secondlargest);
	element4->largestpos = scan_num_pos(stack_a, element4->largest);
	if (element4->largestpos == 0)
		rotate_stack(stack_a, numberofop, 0);
	else if (element4->largestpos == 1)
	{
		swap_top_two(stack_a, numberofop, 0);
		rotate_stack(stack_a, numberofop, 0);
	}
	else if (element4->largestpos == 2)
		reverse_rotate_stack(stack_a, numberofop, 0);
	else if (element4->largestpos == 3)
	{
	}
	sort_4_top3(element4, stack_a, numberofop);
}
