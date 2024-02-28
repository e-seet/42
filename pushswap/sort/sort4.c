#include "sort4.h"

int	sort4wrapper(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
	printf("wrapper\n");
	t_element4	element4;

	init4_element(&element4);
	printf("%p, %p, %p", stack_a->top, stack_b->top, numberofop);
	sort4_al(stack_a, stack_b, numberofop, &element4);
	return (0);
}

void	init4_element(t_element4 *element4)
{
	element4->smallest = INT_MAX;
	element4->secondsmallest = INT_MAX;
	element4->secondlargest = INT_MIN;
	element4->largest = INT_MIN;
}

// Function to find the smallest, 2nd smallest, middle,
// 2nd largest, and largest numbers in the linked list
void	find4_numbers(t_node *head, t_element4 *element4)
{
	printf("find 4 numbers\n");
	struct s_node	*current;
	// struct s_node	*head_ptr;
	int 			size;
	int				i;

	i = 0;
	size = ft_lstsize_modified(head);
	printf("size:%d\n",size);
	current = head;
	// Traverse the linked list
	while (size >= i)
	{
		if (current->value < element4->smallest)
		{
			element4->secondsmallest = element4->smallest;
			element4->smallest = current->value;
		}
		else if (current->value < element4->secondsmallest)
		{
			element4->secondsmallest = current->value;
		}
		if (current->value > element4->largest)
		{
			element4->secondlargest = element4->largest;
			element4->largest = current->value;
		}
		else if (current->value > element4->secondlargest)
		{
			element4->secondlargest = current->value;
		}
		current = current->next;
		i = i + 1;
	}
	// Print the results
	printf("Smallest: %d\n", element4->smallest);
	printf("Second Smallest: %d\n", element4->secondsmallest);
	printf("Second Largest: %d\n", element4->secondlargest);
	printf("Largest: %d\n\n", element4->largest);
}

void sort4_al(t_stack *stack_a, t_stack *stack_b, int *numberofop, t_element4 *element4)
{
	printf("sort 4\n");
	t_element3	element3;

	// displaystack(stack_a);
	displaystack(stack_b);
	// Get all the numbers back from stack
	find4_numbers(stack_a->top, element4); //no issues

	// get all the position of the numbers in the stack
	element4->smallestpos = scan_num_pos(stack_a, element4->smallest);
	element4->secondsmallestpos = scan_num_pos(stack_a, element4->secondsmallest);
	element4->secondlargestpos = scan_num_pos(stack_a, element4->secondlargest);
	element4->largestpos = scan_num_pos(stack_a, element4->largest);

	printf("num of op: %p", numberofop);

	// printf("\npositions\n");
	// printf("Smallest position: %d\n", element4->smallestpos);
	// printf("Second Smallest  position: %d\n", element4->secondsmallestpos);
	// // printf("Middle  position: %d\n", element4->middlepos);
	// printf("Second Largest  position: %d\n", element4->secondlargestpos);
	// printf("!!Largest position: %d\n\n", element4->largestpos);
	
	// When the number 4 [largest number] is at the top
	// 4 x x x
	if (element4->largestpos == 0)
	{
		rotate_stack(stack_a, numberofop);
	}
	// x 4 x x
	else if (element4->largestpos == 1)
	{
		swap_top_two(stack_a, numberofop);
	}
	// x x 4 x
	else if (element4->largestpos == 2)
	{
		// case 3
		reverse_rotate_stack(stack_a, numberofop);
	}
	/*When the number 4 [largest number] is at the 4th pos
	x x x  4 */
	else if (element4->largestpos == 3)
	{
		// case 4
		// no action. Just do 3 element sort.
	}


	// printf("top of stack :%d\n" , stack_a->top->value);
	// // printf("init 3 element\n");
	init3_element(&element3);
	element3.smallest = element4->smallest;
	element3.middle = element4->secondsmallest;
	element3.largest = element4->secondlargest;

	element3.smallestpos = scan_num_pos(stack_a, element4->smallest);
	element3.middlepos = scan_num_pos(stack_a, element4->secondsmallest);
	element3.largestpos = scan_num_pos(stack_a, element4->secondlargest);
	sort5elementstop3(stack_a, numberofop, &element3);
	displaylinkedlist2(stack_a->top);
}