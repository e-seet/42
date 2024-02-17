# include "sort5.h"

void init5Element(s_element5 *element5)
{
	element5->smallest =  INT_MAX;
	element5->secondsmallest =  INT_MAX;
	element5->middle =  INT_MAX;
	element5->secondlargest = INT_MIN;
	element5->largest = INT_MIN;
}

// Function to find the smallest, 2nd smallest, middle, 2nd largest, and largest numbers in the linked list
void find5Numbers(t_node * head, s_element5 *element5)
{
    struct s_node *current = head;

    // Traverse the linked list
    while (current != NULL) {
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
    }

	// another function
    struct s_node *headPtr = head;
	 while (headPtr != NULL)
	 {
		if (
			headPtr -> value != element5->smallest &&
			headPtr -> value != element5->secondsmallest &&
			headPtr -> value != element5->secondlargest &&
			headPtr -> value != element5->largest
			)
		{
			element5 ->middle = headPtr->value;
		}
        headPtr = headPtr->next;
    }

    // Print the results
    printf("Smallest: %d\n", element5->smallest);
    printf("Second Smallest: %d\n", element5->secondsmallest);
    printf("Middle: %d\n", element5->middle);
    printf("Second Largest: %d\n", element5->secondlargest);
    printf("Largest: %d\n\n", element5->largest);
}

void sort5(t_stack stack_a, t_stack stack_b, int *numberofop, s_element5 *element5)
{
	displaystack(&stack_a);
	displaystack(&stack_b);

	// Get all the numbers back from stack
	find5Numbers(stack_a.top, element5);
	
	// get all the position of the numbers in the stack
	element5->smallestpos  = scanNumPos(&stack_a, element5->smallest);
	element5->secondsmallestpos  = scanNumPos(&stack_a, element5->secondsmallest);
	element5->middlepos  = scanNumPos(&stack_a, element5->middle);
	element5->secondlargestpos  = scanNumPos(&stack_a, element5->secondlargest);
	element5->largestpos  = scanNumPos(&stack_a, element5->largest);

	// printf("\npositions\n");
    // printf("Smallest position: %d\n", element5->smallestpos);
    // printf("Second Smallest  position: %d\n", element5->secondsmallestpos);
    // printf("Middle  position: %d\n", element5->middlepos);
    // printf("Second Largest  position: %d\n", element5->secondlargestpos);
    // printf("Largest position: %d\n", element5->largestpos);

	// When the number 5 [largest number] is at the top
	// 5 x x x x
	if (element5->largestpos == 0)
	{
		// swap top 2 [at top: 4,5]
		if (element5->secondlargestpos == 1)
		{
			printf("\n1\n");
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Swap top 2
		// Rotate top to bot [5,4]
		// Swap top 2 [At top: 4, 5]
		else if (element5->secondlargestpos == 2)
		{
			printf("problem 2\n");
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);			
			bringtobot(&stack_a, numberofop);
		}
		// Rotate bot to top
		// Swap top 2
		// Rotate top to bot [At bot: 4,5]
		else if (element5->secondlargestpos == 3)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
		}
		// Rotate top to bot [At bot: 4,5]
		else if (element5->secondlargestpos == 4)
		{
			rotate_stack(&stack_a, numberofop);
		}

		printf("end of op\n");
		displaystack(&stack_a);
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
			bringtobot(&stack_a, numberofop);
		}
		// Rotate top to bot
		// Swap top 2 [At top:  4,5]
		else if (element5->secondlargestpos == 2)
		{
			rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Swap top two
		// Rotate bot to top
		// Swap top two
		// Rotate top to bot [At bot 4, 5]
		else if (element5->secondlargestpos == 3)
		{
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
		}
		// Swap top two
		// Rotate top to bot [At bot: 4, 5]
		else if (element5->secondlargestpos == 4)
		{
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}

		printf("end of op\n");
		displaystack(&stack_a);

	}
	// When the number 5 [largest number] is at the 3rd pos
	// x x 5 x x
	else if (element5->largestpos == 2)
	{
		// 	Swap top two
		// Rotate top to bot [At top: 4,5]
		if (element5->secondlargestpos == 0)
		{
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}	
		// Rotate top to bot [At top 4,5]
		else if (element5->secondlargestpos == 1)
		{
			rotate_stack(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Rotate top to bot
		// Rotate top to bot
		// Swap top two [At top: 4,5]
		else if (element5->secondlargestpos == 3)
		{
			rotate_stack(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Rotate bot to top
		// Rotate bot to top
		// Swap top two
		// Rotate bot to top
		// Swap top two [at top: 4, 5]
		else if (element5->secondlargestpos == 4)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}

		printf("end of op\n");
		displaystack(&stack_a);

	}
	// When the number 5 [largest number] is at the 4th pos
	// x x x 5 x
	else if (element5->largestpos == 3)
	{
		// Rotate bot to top
		// Swap top two
		// Rotate bot to top
		// Swap top two [At top: 4,5]
		if (element5->secondlargestpos == 0)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Swap top two
		// Rotate bot to top
		// Swap top two
		// Rotate bot to top
		// Swap top two [At top: 4,5]
		else if (element5->secondlargestpos == 1)
		{
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Rotate bot to top [At bot: 4,5]
		else if (element5->secondlargestpos == 2)
		{
			reverse_rotate_stack(&stack_a, numberofop);
		}
		// 	Rotate bot to top
		// Rotate bot to top
		// Swap top two [At top: 4, 5]
		else if (element5->secondlargestpos == 4)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}

		printf("end of op\n");
		displaystack(&stack_a);
	}
	// When the number 5 [largest number] is at the 5th pos
	// x x x x 5
	else if (element5->largestpos == 4)
	{
		// Rotate bot to top
		// Swap top two [At top: 4,5]
		if (element5->secondlargestpos == 0)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Swap top two
		// Rotate bot to top
		// Swap top two [At top: 4,5]
		else if (element5->secondlargestpos == 1)
		{
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Rotate bot to top
		// Rotate bot to top
		// Swap top two
		// Rotate top to bot [At bot: 4,5]
		else if (element5->secondlargestpos == 2)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
		}
		// No action
		else if (element5->secondlargestpos == 3)
		{
			// no action 
			printf("no action required");
		}

		printf("end of op\n");
		displaystack(&stack_a);
	}

	s_element3	element3;
	init3Element(&element3);

	element3.smallest  = element5->smallest;
	element3.middle  = element5->secondsmallest;
	element3.largest  = element5->middle;

	element3.smallestpos  = scanNumPos(&stack_a, element5->smallest);
	element3.middlepos  = scanNumPos(&stack_a, element5->secondsmallest);
	element3.largestpos  = scanNumPos(&stack_a, element5->middle);;
	
	// sort the top 3 numbers
	sort5elementstop3(&stack_a, numberofop, &element3);
}
