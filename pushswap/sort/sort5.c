
#include "sort5.h"

void	sort_5_top3(t_element5 *element5, t_stack *stack_a, int *numberofop)
{
	t_element3	element3;

	init3_element(&element3);
	element3.smallest = element5->smallest;
	element3.middle = element5->secondsmallest;
	element3.largest = element5->middle;
	element3.smallestpos = scan_num_pos(stack_a, element5->smallest);
	element3.middlepos = scan_num_pos(stack_a, element5->secondsmallest);
	element3.largestpos = scan_num_pos(stack_a, element5->middle);
	printf("\nsort the top 3 numbers\n");
	sort5elementstop3(stack_a, numberofop, &element3);
	printf("end of sort 5\n\n");
}

int	sort5wrapper(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
	t_element5	element5;

	element5.smallest = INT_MAX;
	element5.secondsmallest = INT_MAX;
	element5.middle = INT_MAX;
	element5.secondlargest = INT_MIN;
	element5.largest = INT_MIN;
	sort5(stack_a, stack_b, numberofop, &element5);
	return (0);
}

void	find5_numbers_p2(t_node *head, t_element5 *element5, t_stack *stack_a)
{
	int		i;
	t_node	*head_ptr;

	i = 0;
	head_ptr = head;
	while (ft_lstsize_modified(head) >= i)
	{
		if (
			head_ptr -> value != element5->smallest
			&& head_ptr -> value != element5->secondsmallest
			&& head_ptr -> value != element5->secondlargest
			&& head_ptr -> value != element5->largest
		)
		{
			element5 ->middle = head_ptr->value;
		}
		head_ptr = head_ptr->next;
		i = i + 1;
	}
	element5->smallestpos = scan_num_pos(stack_a, element5->smallest);
	element5->secondsmallestpos = scan_num_pos(stack_a,
			element5->secondsmallest);
	element5->middlepos = scan_num_pos(stack_a, element5->middle);
	element5->secondlargestpos = scan_num_pos(stack_a, element5->secondlargest);
	element5->largestpos = scan_num_pos(stack_a, element5->largest);
}

// Function to find the smallest, 2nd smallest, middle,
// 2nd largest, and largest numbers in the linked list
void	find5_numbers(t_node *head, t_element5 *element5, t_stack *stack_a)
{
	struct s_node	*current;
	int				i;

	i = 0;
	current = head;
	while (ft_lstsize_modified(head) >= i)
	{
		if (current->value < element5->smallest)
		{
			element5->secondsmallest = element5->smallest;
			element5->smallest = current->value;
		}
		else if (current->value < element5->secondsmallest)
			element5->secondsmallest = current->value;
		if (current->value > element5->largest)
		{
			element5->secondlargest = element5->largest;
			element5->largest = current->value;
		}
		else if (current->value > element5->secondlargest)
			element5->secondlargest = current->value;
		current = current->next;
		i = i + 1;
	}
	find5_numbers_p2(head, element5, stack_a);
}

void	sort5(t_stack *stack_a, t_stack *stack_b, int *numberofop,
		t_element5 *element5)
{
	displaystack(stack_b);
	find5_numbers(stack_a->top, element5, stack_a);
	if (element5->largestpos == 0)
		sort5_case1(stack_a, numberofop, element5);
	else if (element5->largestpos == 1)
		sort5_case2(stack_a, numberofop, element5);
	else if (element5->largestpos == 2)
		sort5_case3(stack_a, numberofop, element5);
	else if (element5->largestpos == 3)
		sort5_case4(stack_a, numberofop, element5);
	else if (element5->largestpos == 4)
		sort5_case5(stack_a, numberofop, element5);
	printf("top of stack :%d\n", stack_a->top->value);
	sort_5_top3(element5, stack_a, numberofop);
}

/*
./push_swap "1 2 3 24394 2"
displaylinkedlist2(stack_a->top);
ft_lstsize2(stack_a->top);
// printf("stack_a->bot:%p | %d\n", stack_a->bot, stack_a->bot->value);
// printf("stack_a->top:%p | %d\n", stack_a->top, stack_a->top->value);
exit(1);

// printf("find 5 element\n");
// printf("Smallest: %d\n", element5->smallest);
// printf("Second Smallest: %d\n", element5->secondsmallest);
// printf("Middle: %d\n", element5->middle);
// printf("Second Largest: %d\n", element5->secondlargest);
// printf("Largest: %d\n\n", element5->largest);
// printf("end of find 5 element\n");
*/
