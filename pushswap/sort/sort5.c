
#include "sort5.h"

int	sort5wrapper(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
	t_element5	element5;

	init5_element(&element5);
	sort5(stack_a, stack_b, numberofop, &element5);
	return (0);
}

void	init5_element(t_element5 *element5)
{
	element5->smallest = INT_MAX;
	element5->secondsmallest = INT_MAX;
	element5->middle = INT_MAX;
	element5->secondlargest = INT_MIN;
	element5->largest = INT_MIN;
}

// Function to find the smallest, 2nd smallest, middle,
// 2nd largest, and largest numbers in the linked list
void	find5_numbers(t_node *head, t_element5 *element5)
{
	printf("find 5 numbers\n");
	struct s_node	*current;
	struct s_node	*head_ptr;
	int 			size;
	int				i;

	i = 0;
	size = ft_lstsize_modified(head);
	printf("size:%d\n",size);
	current = head;
	// Traverse the linked list
	while (size >= i)
	{
		// Update smallest and second smallest
		if (current->value < element5->smallest)
		{
			element5->secondsmallest = element5->smallest;
			element5->smallest = current->value;
		}
		else if (current->value < element5->secondsmallest)
		{
			element5->secondsmallest = current->value;
		}
		// Update largest and second largest
		if (current->value > element5->largest)
		{
			element5->secondlargest = element5->largest;
			element5->largest = current->value;
		}
		else if (current->value > element5->secondlargest)
		{
			element5->secondlargest = current->value;
		}
		// Move to the next node
		current = current->next;
		// printf("what is the value now! :%d\n", current->value);
		i = i + 1;
	}

	i = 0;
	// another function
	head_ptr = head;
	while ( size >= i)
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
		// printf("what is the value now :%d\n", head_ptr->value);
		head_ptr = head_ptr->next;
		i = i+1;
	}


	// Print the results
	printf("find 5 element\n");
	printf("Smallest: %d\n", element5->smallest);
	printf("Second Smallest: %d\n", element5->secondsmallest);
	printf("Middle: %d\n", element5->middle);
	printf("Second Largest: %d\n", element5->secondlargest);
	printf("Largest: %d\n\n", element5->largest);
	printf("end of find 5 element\n");
}

void sort5(t_stack *stack_a, t_stack *stack_b, int *numberofop, t_element5 *element5)
{
	printf("sort 5\n");
	t_element3	element3;

	displaystack(stack_a);
	displaystack(stack_b);
	// Get all the numbers back from stack
	find5_numbers(stack_a->top, element5);

	// get all the position of the numbers in the stack
	element5->smallestpos = scan_num_pos(stack_a, element5->smallest);
	element5->secondsmallestpos = scan_num_pos(stack_a, element5->secondsmallest);
	element5->middlepos = scan_num_pos(stack_a, element5->middle);
	element5->secondlargestpos = scan_num_pos(stack_a, element5->secondlargest);
	element5->largestpos = scan_num_pos(stack_a, element5->largest);
	
	printf("\npositions\n");
	printf("Smallest position: %d\n", element5->smallestpos);
	printf("Second Smallest  position: %d\n", element5->secondsmallestpos);
	printf("Middle  position: %d\n", element5->middlepos);
	printf("Second Largest  position: %d\n", element5->secondlargestpos);
	printf("!!Largest position: %d\n\n", element5->largestpos);
	// When the number 5 [largest number] is at the top
	// 5 x x x x
	if (element5->largestpos == 0)
	{
		// swap top 2 [at top: 4,5]
		if (element5->secondlargestpos == 1)
		{
			printf("\n1\n");
			swap_top_two(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		// Swap top 2
		// Rotate top to bot [5,4]
		// Swap top 2 [At top: 4, 5]
		else if (element5->secondlargestpos == 2)
		{
			printf("problem 2\n");
			swap_top_two(stack_a, numberofop);
			rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		// Rotate bot to top
		// Swap top 2
		// Rotate top to bot [At bot: 4,5]
		else if (element5->secondlargestpos == 3)
		{
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			rotate_stack(stack_a, numberofop);
		}
		// Rotate top to bot [At bot: 4,5]
		else if (element5->secondlargestpos == 4)
		{
			rotate_stack(stack_a, numberofop);
		}
		printf("end of op 1\n");
		displaystack(stack_a);
		// printf("problem where\n");
	}
	// When the number 5 [largest number] is at the 2nd pos
	// x 5 x x x
	else if (element5->largestpos == 1)
	{
		// No action needed
		// at top [4,5]
		if (element5->secondlargestpos == 0)
		{
			printf("no action");
			bringtobot(stack_a, numberofop);
		}
		// Rotate top to bot
		// Swap top 2 [At top:  4,5]
		else if (element5->secondlargestpos == 2)
		{
			rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		// Swap top two
		// Rotate bot to top
		// Swap top two
		// Rotate top to bot [At bot 4, 5]
		else if (element5->secondlargestpos == 3)
		{
			swap_top_two(stack_a, numberofop);
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			rotate_stack(stack_a, numberofop);
		}
		// Swap top two
		// Rotate top to bot [At bot: 4, 5]
		else if (element5->secondlargestpos == 4)
		{
			swap_top_two(stack_a, numberofop);
			reverse_rotate_stack(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		printf("end of op2\n");
		displaystack(stack_a);
	}
	// When the number 5 [largest number] is at the 3rd pos
	// x x 5 x x
	else if (element5->largestpos == 2)
	{
		// 	Swap top two
		// Rotate top to bot [At top: 4,5]
		if (element5->secondlargestpos == 0)
		{
			swap_top_two(stack_a, numberofop);
			rotate_stack(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		// Rotate top to bot [At top 4,5]
		else if (element5->secondlargestpos == 1)
		{
			rotate_stack(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		// Rotate top to bot
		// Rotate top to bot
		// Swap top two [At top: 4,5]
		else if (element5->secondlargestpos == 3)
		{
			rotate_stack(stack_a, numberofop);
			rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		// Rotate bot to top
		// Rotate bot to top
		// Swap top two
		// Rotate bot to top
		// Swap top two [at top: 4, 5]
		else if (element5->secondlargestpos == 4)
		{
			reverse_rotate_stack(stack_a, numberofop);
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		printf("end of op3\n");
		displaystack(stack_a);
	}
	/*When the number 5 [largest number] is at the 4th pos
	x x x 5 x*/
	else if (element5->largestpos == 3)
	{
		/*Rotate bot to top
		Swap top two
		Rotate bot to top
		Swap top two [At top: 4,5]*/
		if (element5->secondlargestpos == 0)
		{
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		/*Swap top two
		Rotate bot to top
		Swap top two
		Rotate bot to top
		Swap top two [At top: 4,5]*/
		else if (element5->secondlargestpos == 1)
		{
			swap_top_two(stack_a, numberofop);
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		/*Rotate bot to top [At bot: 4,5]*/
		else if (element5->secondlargestpos == 2)
		{
			reverse_rotate_stack(stack_a, numberofop);
		}
		/*Rotate bot to top
		Rotate bot to top
		Swap top two [At top: 4, 5]*/
		else if (element5->secondlargestpos == 4)
		{
			reverse_rotate_stack(stack_a, numberofop);
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		printf("end of op4\n");
		displaystack(stack_a);
	}
	// When the number 5 [largest number] is at the 5th pos
	// x x x x 5
	else if (element5->largestpos == 4)
	{
		/*Rotate bot to top
		Swap top two [At top: 4,5]*/
		if (element5->secondlargestpos == 0)
		{
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			bringtobot(stack_a, numberofop);
		}
		/*Swap top two
		Rotate bot to top
		Swap top two [At top: 4,5]*/
		else if (element5->secondlargestpos == 1)
		{
			printf("this runs\n");
			swap_top_two(stack_a, numberofop); //impt
			reverse_rotate_stack(stack_a, numberofop); //impt. This may be wrong.
			swap_top_two(stack_a, numberofop); //impt. This may be wrong.
			bringtobot(stack_a, numberofop); //impt
		}
		/*Rotate bot to top
		Rotate bot to top
		Swap top two
		Rotate top to bot [At bot: 4,5]*/
		else if (element5->secondlargestpos == 2)
		{
			reverse_rotate_stack(stack_a, numberofop);
			reverse_rotate_stack(stack_a, numberofop);
			swap_top_two(stack_a, numberofop);
			rotate_stack(stack_a, numberofop);
		}
		/* No action*/
		else if (element5->secondlargestpos == 3)
		{
			printf("no action required");
		}
		printf("end of op5\n");
		// displaystack(stack_a);
		// displaylinkedlist2(stack_a->top);
	}


	// displaylinkedlist2(stack_a->top);


	printf("top of stack :%d\n" , stack_a->top->value);
	// printf("init 3 element\n");
	init3_element(&element3);
	// printf("get the values from the 5 elements\n");
	element3.smallest = element5->smallest;
	element3.middle = element5->secondsmallest;
	element3.largest = element5->middle;

	element3.smallestpos = scan_num_pos(stack_a, element5->smallest);
	element3.middlepos = scan_num_pos(stack_a, element5->secondsmallest);
	element3.largestpos = scan_num_pos(stack_a, element5->middle);


	// printf("e5:%d \n", element5->middle);
	// printf("e3.1: %d\n", element3.smallestpos);
	// printf("e3.2: %d\n", element3.middlepos);
	// printf("e3.3: %d\n", element3.largestpos);

	// displaylinkedlist2(stack_a->top);

	printf("\nsort the top 3 numbers\n");
	sort5elementstop3(stack_a, numberofop, &element3);

	printf("end of sort 5\n\n");
	// displaylinkedlist2(stack_a->top);
	// displaylinkedlist2(stack_b->top);
}

//./push_swap "1 2 3 24394 2"

// displaylinkedlist2(stack_a->top);
// ft_lstsize2(stack_a->top);
// // printf("stack_a->bot:%p | %d\n", stack_a->bot, stack_a->bot->value);
// // printf("stack_a->top:%p | %d\n", stack_a->top, stack_a->top->value);
// exit(1);

