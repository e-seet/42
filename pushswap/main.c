// #include "./utils/utils.h"
#include "./utils/utils2.h"
#include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"

int stackissorted(t_stack *stack)
{
	t_node head ;
	head = *stack->top;
	int val = INT_MIN;


	while (head.next != NULL)
	{
		if (head.value > val)
			val = head.value;
		else
		{
			return 1;
		}
		head = *head.next;
	}
	return 0;
}

// /* original
/*
void sort5original(t_stack stack_a, t_stack stack_b)
{
	printf("top:%d, 2nd top:%d\n", (stack_a.top)->value, (stack_a.sec)->value );

	pb(&stack_a, &stack_b,&numberofop);
	pb(&stack_a, &stack_b,&numberofop);
	// printf( "a smallest:%d\n" , scanSmallestNum(&stack_a));
	// printf( "a 2nd smallest:%d\n" , scan2SmallestNum(&stack_a));

	// printf( "b smallest:%d\n" , scanSmallestNum(&stack_b));
	// printf( "b 2nd smallest:%d\n" , scan2SmallestNum(&stack_b));

	if ( (stack_a.bot)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.top)->value)
	{
		printf("case 1\n");

		// sorting only stack b. I can use any of the methods.
		if ( (stack_b.top)->value > stack_b.bot ->value)
			swap_top_two(&stack_b,&numberofop);
	}
	else if ((stack_a.bot)->value > (stack_a.top)->value && (stack_a.top)->value > (stack_a.sec)->value)
	{
		printf("case 3\n");

		if (stack_b.top->value > stack_b.bot->value)
			ss(&stack_a, &stack_b,&numberofop);
		else
			swap_top_two(&stack_a,&numberofop);
	}
	else if ( ((stack_a.sec)->value > (stack_a.top)->value) && (stack_a.top->value > (stack_a.bot)->value) )
	{
		printf("case 4\n");

		if ((stack_b.top)->value > stack_b.bot ->value)
			rrr(&stack_a, &stack_b,&numberofop);
		else
			reverse_rotate_stack(&stack_a,&numberofop);
	}
	// take note that all 3 of them need a rotate_stack first
	else 
	{
		if ((stack_a.top)->value > (stack_a.bot)->value &&  (stack_a.bot)->value > (stack_a.sec)->value)
		{
			printf("case 5\n");

			if (stack_b.bot->value < stack_b.top->value)
				rr(&stack_a, &stack_b,&numberofop);
			else
				rotate_stack(&stack_a,&numberofop);
		}
		// take note case 2 and 6 have 2 common operations [rotate stack, swap top two].
		else if ((stack_a.top)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.bot)->value)
		{
			printf("case 6\n");
			
			rotate_stack(&stack_a,&numberofop);

			if (stack_b.bot->value < stack_b.top->value)
				ss(&stack_a, &stack_b,&numberofop);
			else
				swap_top_two(&stack_a,&numberofop);

		}
		else
		{
			printf("case 2\n");

			// if (stack_b.bot->value < stack_b.top->value)
				// rr(&stack_a, &stack_b);
			// else
				rotate_stack(&stack_a,&numberofop);
			
			// if (stack_b.bot->value < stack_b.top->value)
				// ss(&stack_a, &stack_b);
			// else
				swap_top_two(&stack_a,&numberofop);
		
			// if (stack_b.bot->value < stack_b.top->value)
			// 	rrr(&stack_a, &stack_b);
			// else
				reverse_rotate_stack(&stack_a,&numberofop);
		}
	}

	// displaystack(&stack_a);
	// displaystack(&stack_b);


	while (stack_b.top != NULL)
	{
		if (stack_a.top->value > stack_b.top->value)
			pa(&stack_a, &stack_b);	
		else
			rotate_stack(&stack_a);
	}
	while(stack_a.top->value != scanSmallestNum(&stack_a))
	{
		reverse_rotate_stack(&stack_a);
	}




	// displaystack(&stack_a);
	if (stackissorted(&stack_a) == 0)
		printf("\n\nsorted\n");
	else
		printf("not sorted\n");
	displaystack(&stack_a);
}
*/

void sort3(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
		if ( (stack_a->bot)->value > (stack_a->sec)->value && (stack_a->sec)->value > (stack_a->top)->value)
	{
		printf("case 1\n");

		// sorting only stack b. I can use any of the methods.
		if ( (stack_b->top)->value > stack_b->bot ->value)
			swap_top_two(stack_b, numberofop);
	}
	else if ((stack_a->bot)->value > (stack_a->top)->value && (stack_a->top)->value > (stack_a->sec)->value)
	{
		printf("case 3\n");

		if (stack_b->top->value > stack_b->bot->value)
			ss(stack_a, stack_b,numberofop);
		else
			swap_top_two(stack_a, numberofop);
	}
	else if ( ((stack_a->sec)->value > (stack_a->top)->value) && (stack_a->top->value > (stack_a->bot)->value) )
	{
		printf("case 4\n");

		if ((stack_b->top)->value > stack_b->bot ->value)
			rrr(stack_a, stack_b, numberofop);
		else
			reverse_rotate_stack(stack_a, numberofop);
	}
	// take note that all 3 of them need a rotate_stack first
	else 
	{
		if ((stack_a->top)->value > (stack_a->bot)->value &&  (stack_a->bot)->value > (stack_a->sec)->value)
		{
			printf("case 5\n");

			if (stack_b->bot->value < stack_b->top->value)
				rr(stack_a, stack_b,numberofop);
			else
				rotate_stack(stack_a,numberofop);
		}
		// take note case 2 and 6 have 2 common operations [rotate stack, swap top two].
		else if ((stack_a->top)->value > (stack_a->sec)->value && (stack_a->sec)->value > (stack_a->bot)->value)
		{
			printf("case 6\n");
			
			rotate_stack(stack_a,numberofop);

			if (stack_b->bot->value < stack_b->top->value)
				ss(stack_a, stack_b,numberofop);
			else
				swap_top_two(stack_a,numberofop);

		}
		else
		{
			printf("case 2\n");

			// if (stack_b.bot->value < stack_b.top->value)
				// rr(&stack_a, &stack_b);
			// else
				rotate_stack(stack_a,numberofop);
			
			// if (stack_b.bot->value < stack_b.top->value)
				// ss(&stack_a, &stack_b);
			// else
				swap_top_two(stack_a,numberofop);
		
			// if (stack_b.bot->value < stack_b.top->value)
			// 	rrr(&stack_a, &stack_b);
			// else
				reverse_rotate_stack(stack_a,numberofop);
		}
	}
}


// Function to find the smallest, 2nd smallest, middle, 2nd largest, and largest numbers in the linked list
void findNumbers(t_node * head, s_element5 *element5)
{
    struct s_node *current = head;

    // Traverse the linked list
    while (current != NULL) {
        // Update smallest and second smallest
        if (current->value < element5->smallest) {
            element5->secondsmallest = element5->smallest;
            element5->smallest = current->value;
        } else if (current->value < element5->secondsmallest) {
            element5->secondsmallest = current->value;
        }

        // Update largest and second largest
        if (current->value > element5->largest) {
            element5->secondlargest = element5->largest;
            element5->largest = current->value;
        } else if (current->value > element5->secondlargest) {
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
	// printf("number of op %d\n", *numberofop);
	// printf("smallest element %d", element5->smallest);

	// Get all the numbers back from stack
	findNumbers(stack_a.top, element5);
	
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
		printf("case 1\n");
		// swap top 2 [at top: 4,5]
		if (element5->secondlargest == 1)
		{
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Swap top 2
		// Rotate top to bot [5,4]
		// Swap top 2 [At top: 4, 5]
		else if (element5->secondlargest == 2)
		{
			printf("problem\n");
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);			
			bringtobot(&stack_a, numberofop);
		}
		// Rotate bot to top
		// Swap top 2
		// Rotate top to bot [At bot: 4,5]
		else if (element5->secondlargest == 3)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
		}
		// Rotate top to bot [At bot: 4,5]
		else if (element5->secondlargest == 4)
		{
			rotate_stack(&stack_a, numberofop);
		}
	}
	// When the number 5 [largest number] is at the 2nd pos
	// x 5 x x x
	else if (element5->largestpos == 1)
	{
		// No action needed
		// at top [4,5]
		if (element5->secondlargest == 0)
		{
			printf("no action");
			bringtobot(&stack_a, numberofop);
		}
		// Rotate top to bot
		// Swap top 2 [At top:  4,5]
		else if (element5->secondlargest == 2)
		{
			rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Swap top two
		// Rotate bot to top
		// Swap top two
		// Rotate top to bot [At bot 4, 5]
		else if (element5->secondlargest == 3)
		{
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
		}
		// Swap top two
		// Rotate top to bot [At bot: 4, 5]
		else if (element5->secondlargest == 4)
		{
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
		}
	}
	// When the number 5 [largest number] is at the 3rd pos
	// x x 5 x x
	else if (element5->largestpos == 2)
	{
		// 	Swap top two
		// Rotate top to bot [At top: 4,5]
		if (element5->secondlargest == 0)
		{
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}	
		// Rotate top to bot [At top 4,5]
		else if (element5->secondlargest == 1)
		{
			rotate_stack(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Rotate top to bot
		// Rotate top to bot
		// Swap top two [At top: 4,5]
		else if (element5->secondlargest == 3)
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
		else if (element5->secondlargest == 4)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
	}
	// When the number 5 [largest number] is at the 4th pos
	// x x x 5 x
	else if (element5->largestpos == 3)
	{
		// Rotate bot to top
		// Swap top two
		// Rotate bot to top
		// Swap top two [At top: 4,5]
		if (element5->secondlargest == 0)
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
		else if (element5->secondlargest == 1)
		{
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Rotate bot to top [At bot: 4,5]
		else if (element5->secondlargest == 2)
		{
			reverse_rotate_stack(&stack_a, numberofop);
		}
		// 	Rotate bot to top
		// Rotate bot to top
		// Swap top two [At top: 4, 5]
		else if (element5->secondlargest == 4)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
	}
	// When the number 5 [largest number] is at the 5th pos
	// x x x x 5
	else if (element5->largestpos == 4)
	{
		// Rotate bot to top
		// Swap top two [At top: 4,5]
		if (element5->secondlargest == 0)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			bringtobot(&stack_a, numberofop);
		}
		// Swap top two
		// Rotate bot to top
		// Swap top two [At top: 4,5]
		else if (element5->secondlargest == 1)
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
		else if (element5->secondlargest == 2)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			reverse_rotate_stack(&stack_a, numberofop);
			swap_top_two(&stack_a, numberofop);
			rotate_stack(&stack_a, numberofop);
		}
		// No action
		else if (element5->secondlargest == 3)
		{
			// no action 
			printf("no action required");
		}
	}

	// Bring the number [4,5] at top of stack to bottom of stack
	// bringtobot(&stack_a, &numberofop);
}


// void sortNum(t_stack stack_a, t_stack stack_b, int *numberofop)
// {
	
	
// 	// printf("top:%d, 2nd top:%d bot:%d\n\n", (stack_a.top)->value, (stack_a.sec)->value,(stack_a.bot)->value );

// 	// printf( "a smallest:%d\n" , scanSmallestNum(&stack_a));
// 	// printf( "a 2nd smallest:%d\n" , scan2SmallestNum(&stack_a));

// 	// printf( "a 2nd biggest:%d\n" , scan2largestNum(&stack_a));
// 	// printf( "largest:%d\n" , scanlargestNum(&stack_a));

// 	// printf("\n\nfor fun %p\n", stack_b.top);

// 	// int firstvalue; 
// 	// int secondvalue; 

// 	//i think if it is at last, and next, still ok. We will test this out

// 	// case 1: 1 and 5
// 	// case 2: 1 and 2
// 	// case 3: 4 and 5

// 	// Moving stuff to stack b
// 	// case 1: 1 and 5 
// 	//  scanSmallestNum(&stack_a),
// 	//  scanlargestNum(&stack_a);
// 	printf( "The pos of smallest: %d \n ", scanNumPos(&stack_a ,scanSmallestNum(&stack_a)));
// 	printf( "The pos of largest %d \n\n ", scanNumPos(&stack_a, scanlargestNum(&stack_a))) ;

// 	// case 2: 1 and 2 
// 	//  scanSmallestNum(&stack_a),
// 	//  scan2SmallestNum(&stack_a))
// 	printf( "The pos of smallest: %d \n ", scanNumPos(&stack_a ,scanSmallestNum(&stack_a)));
// 	printf( "The pos of largest %d \n\n ", scanNumPos(&stack_a, scan2SmallestNum(&stack_a))) ;

// 	// case 3: 4 and 5 
// 	//  scan2largestNum(&stack_a)
// 	//  scanlargestNum(&stack_a));
// 	printf( "The pos of smallest: %d \n ", scanNumPos(&stack_a ,scan2largestNum(&stack_a)));
// 	printf( "The pos of largest %d \n \n", scanNumPos(&stack_a, scanlargestNum(&stack_a))) ;

// 	displaystack(&stack_a);

// 	// scan for running stack
// 	// Pull out non-running element
// 	int runPosDec = 1;
// 	int runPosAsc = 1;
// 	t_node *ranHead;
// 	ranHead = stack_a.top;


// 	while ( ranHead -> next != NULL)
// 	{
// 		//ranning in decreasing order
// 		if (ranHead->value > (ranHead->next)->value)
// 		{
// 			printf("curr value:%d, next value:%d\n", ranHead->value, (ranHead->next) -> value);
// 			printf("runnning %d, value:%d\n", runPosDec, ranHead->value);
// 			runPosDec ++;
// 		}
// 		else
// 		{
// 			break;
// 		}
// 		ranHead = ranHead -> next;
// 	}

// 	while ( ranHead -> next != NULL)
// 	{
// 		if (ranHead->value < (ranHead->next)->value)
// 		{
// 			// printf("curr value:%d, next value:%d\n", ranHead->value, (ranHead->next) -> value);
// 			printf("runnning %d, value:%d\n", runPosDec, ranHead->value);
// 			runPosAsc ++;
// 		}
// 		else
// 		{
// 			break;
// 		}
// 		ranHead = ranHead -> next;
// 	}

// 	printf("fianl value of ran [desc]: %d\n", runPosDec);
// 	printf("fianl value of ran [ASC]: %d\n\n", runPosAsc);


// 	printf("printing stuff for fun :%d, stack b too: %p", *numberofop, stack_b.top);

// 	// printf("After shifting to B:\n");
// 	// displaystack(&stack_b);

// 	// // sort3(&stack_a, &stack_b, numberofop);
// 	// displaystack(&stack_a);
// 	// displaystack(&stack_b);
// 	// printf("finished sorting a and b\n");

// 	// while (stack_b.top != NULL)
// 	// {
// 	// 	if (stack_a.top->value > stack_b.top->value)
// 	// 		pa(&stack_a, &stack_b, numberofop);	
// 	// 	else
// 	// 		rotate_stack(&stack_a, numberofop);
// 	// }
// 	// while(stack_a.top->value != scanSmallestNum(&stack_a))
// 	// {
// 	// 	reverse_rotate_stack(&stack_a, numberofop);
// 	// }
// 	// displaystack(&stack_a);
// 	// displaystack(&stack_b);
// 	// printf("Pushed back to stack a\n");
	
// 	// printf("moves: %d", *numberofop);

// 	/*Get the largest or smallest value first*/
// 	// scanSmallestNum(&stack_a)
// 	// scanlargestNum(&stack_a)

// 	// i will need a way to get it via compute



// 	// if the first number is 1 or 5
// 	// if 
// 	// ( 
// 	// 	(stack_a.top)->value == scanlargestNum(&stack_a) ||
// 	// 	(stack_a.top)->value == scanSmallestNum(&stack_a)
// 	// )
// 	// {

// 	// 	// grab it off from the stack	
// 	// 	firstvalue = (stack_a.top)->value;
// 	// 	printf("first value :%d", firstvalue);
// 	// 	pb(&stack_a, &stack_b);

// 	// 	// if the first number is 5, top of stack is 1 or 4
// 	// 	if 
// 	// 	(
// 	// 		(firstvalue == scanlargestNum(&stack_a) 
// 	// 		&&
// 	// 		(stack_a.top) -> value == scanSmallestNum(&stack_a))
// 	// 		||
// 	// 		(firstvalue == scanlargestNum(&stack_a) 
// 	// 		&&
// 	// 		(stack_a.top) -> value == scan2largestNum(&stack_a)
// 	// 		)
// 	// 	)
// 	// 	{
// 	// 		secondvalue = (stack_a.top)->value;
// 	// 		printf("second value :%d", secondvalue);
// 	// 		pb(&stack_a, &stack_b);
// 	// 	}
// 	// 	// if the first number is 1 and the top number of stack is 5 or 2
// 	// 	else if
// 	// 	(
// 	// 		(firstvalue == scanSmallestNum(&stack_a) 
// 	// 		&&
// 	// 		(stack_a.top) -> value == scanlargestNum(&stack_a))
// 	// 		||
// 	// 		(firstvalue == scanSmallestNum(&stack_a) 
// 	// 		&&
// 	// 		(stack_a.top) -> value == scan2SmallestNum(&stack_a)
// 	// 		)
// 	// 	)
// 	// 	{
// 	// 		secondvalue = (stack_a.top)->value;
// 	// 		printf("second value :%d", secondvalue);
// 	// 		pb(&stack_a, &stack_b);

// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		// need to do something
// 	// 		// what if the numbers are not 1 and 2
// 	// 		// what if the number is not 1 and 5
// 	// 		// what if the number is not 4 and 5

// 	// 		// 1 and 4 will be too much to grab.
// 	// 	}

// 	// }
// 	// else
// 	// {
// 	// 	// what if the number at top is not 1 or 5
// 	// }


	

// /* SORT 3
// 	// sorting 3 numbers in stack a
// 	if ( (stack_a.bot)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.top)->value)
// 	{
// 		printf("case 1\n");

// 		// sorting only stack b. I can use any of the methods.
// 		if ( (stack_b.top)->value > stack_b.bot ->value)
// 			swap_top_two(&stack_b);
// 	}
// 	else if ((stack_a.bot)->value > (stack_a.top)->value && (stack_a.top)->value > (stack_a.sec)->value)
// 	{
// 		printf("case 3\n");

// 		if (stack_b.top->value > stack_b.bot->value)
// 			ss(&stack_a, &stack_b);
// 		else
// 			swap_top_two(&stack_a);
// 	}
// 	else if ( ((stack_a.sec)->value > (stack_a.top)->value) && (stack_a.top->value > (stack_a.bot)->value) )
// 	{
// 		printf("case 4\n");

// 		if ((stack_b.top)->value > stack_b.bot ->value)
// 			rrr(&stack_a, &stack_b);
// 		else
// 			reverse_rotate_stack(&stack_a);
// 	}
// 	// take note that all 3 of them need a rotate_stack first
// 	else 
// 	{
// 		if ((stack_a.top)->value > (stack_a.bot)->value &&  (stack_a.bot)->value > (stack_a.sec)->value)
// 		{
// 			printf("case 5\n");

// 			if (stack_b.bot->value < stack_b.top->value)
// 				rr(&stack_a, &stack_b);
// 			else
// 				rotate_stack(&stack_a);
// 		}
// 		// take note case 2 and 6 have 2 common operations [rotate stack, swap top two].
// 		else if ((stack_a.top)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.bot)->value)
// 		{
// 			printf("case 6\n");
			
// 			rotate_stack(&stack_a);

// 			if (stack_b.bot->value < stack_b.top->value)
// 				ss(&stack_a, &stack_b);
// 			else
// 				swap_top_two(&stack_a);

// 		}
// 		else
// 		{
// 			printf("case 2\n");

// 			// if (stack_b.bot->value < stack_b.top->value)
// 				// rr(&stack_a, &stack_b);
// 			// else
// 				rotate_stack(&stack_a);
			
// 			// if (stack_b.bot->value < stack_b.top->value)
// 				// ss(&stack_a, &stack_b);
// 			// else
// 				swap_top_two(&stack_a);
		
// 			// if (stack_b.bot->value < stack_b.top->value)
// 			// 	rrr(&stack_a, &stack_b);
// 			// else
// 				reverse_rotate_stack(&stack_a);
// 		}
// 	}
// */
// 	// displaystack(&stack_a);
// 	// displaystack(&stack_b);


// /*
// 	Loop stack a and insert items from stack b
// 	while (stack_b.top != NULL)
// 	{
// 		if (stack_a.top->value > stack_b.top->value)
// 			pa(&stack_a, &stack_b);	
// 		else
// 			rotate_stack(&stack_a);
// 	}
// 	while(stack_a.top->value != scanSmallestNum(&stack_a))
// 	{
// 		reverse_rotate_stack(&stack_a);
// 	}
// */


// 	/*
// 	// check if it is sorted
// 	if (stackissorted(&stack_a) == 0)
// 		printf("\n\nsorted\n");
// 	else
// 		printf("not sorted\n");
// 	displaystack(&stack_a);
// 	*/
// }

void init5Element(s_element5 *element5)
{
	element5->smallest =  INT_MAX;
	element5->secondsmallest =  INT_MAX;
	element5->middle =  INT_MAX;
	element5->secondlargest = INT_MIN;
	element5->largest = INT_MIN;
}

int	main(int argc, char *argv[])
{

	int			i;
	t_stack		stack_a;
	t_stack		stack_b;
	int			numberofop;
	s_element5	element5;
	// s_datastore	stackdetails;

	printf("c argc:%d\n\n", argc);
	numberofop = 0;

	// printf("minrun:%d\n", calculate_minrun(argc-1));
	// stackdetails.stack_a_last = ft_atoi(argv[1]);
	// stackdetails.stack_a_top = ft_atoi(argv[argc-1]);

	// printf("top of stack: %d, bottom of stack:%d\n", stackdetails.stack_a_top, stackdetails.stack_a_last);


	i = 1;
	initstack(&stack_a);
	initstack(&stack_b);
	init5Element(&element5);
	// initdatastore(&stackdetails);

	while (argv[i])
	{
		// addtoback(&stack_a, ft_atoi(argv[i]));
		// push(&stack_a, ft_atoi(argv[i]), &stackdetails );
		push(&stack_a, ft_atoi(argv[i]) );
		i++;
	}

	// displaystack(&stack_a);

	// t_node *head = stack_a.top;
	// printf("count elements in stack%d\n", countElementsinStack(head) );
	// pb(&stack_a, &stack_b);
	// head = stack_a.top;
	// printf("count elements in stack%d\n", countElementsinStack(head) );

	// // To count min run first
	// int numofelements = countElementsinStack(head);
	// int minrun = calculate_minrun(numofelements);
	// // printf("minrun:%d\n", minrun);

	// int numofrun = (argc -1) / minrun;
	// printf("number of runs that will be created:%d \n", numofrun);

	// we sort 3 numbers
	// sort3(&stack_a, &stack_b);

	// displaystack(&stack_a);
	// printf("smalest 2nd:%d", scan2SmallestNum(&stack_a));

	sort5(stack_a, stack_b, &numberofop, &element5);
	// printf("after sorting\n");
	displaystack(&stack_a);

	/*
	if (argc == 4)
	{
		printf("top:%d, next:%d, bot:%d. \n\n", (stack_a.top)->value, (stack_a.sec)->value, (stack_a.bot)->value);

		if ( (stack_a.bot)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.top)->value)
			printf("case 1\n");
		else if ((stack_a.bot)->value > (stack_a.top)->value && (stack_a.top)->value > (stack_a.sec)->value)
		{
			printf("case 3\n");

			swap_top_two(&stack_a);
		}
		else if ( ((stack_a.sec)->value > (stack_a.top)->value) && (stack_a.top->value > (stack_a.bot)->value) )
		{
			printf("case 4\n");

			reverse_rotate_stack(&stack_a);
		}
		// take note that all 3 of them need a rotate_stack first
		else 
		{
			if ((stack_a.top)->value > (stack_a.bot)->value &&  (stack_a.bot)->value > (stack_a.sec)->value)
			{
				printf("case 5\n");

				rotate_stack(&stack_a);
			}
			// take note the latter 2 have a common swap_top_two
			else if ((stack_a.top)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.bot)->value)
			{
				printf("case 6\n");
				
				rotate_stack(&stack_a);

				swap_top_two(&stack_a);
			}
			else
			{
				printf("case 2\n");

				rotate_stack(&stack_a);
				swap_top_two(&stack_a);
				reverse_rotate_stack(&stack_a);
			}
		} 
		


		printf("top:%d, next:%d, bot:%d. \n\n", (stack_a.top)->value, (stack_a.sec)->value, (stack_a.bot)->value);
		displaystack(&stack_a);
	}
	*/


	// less than critical number of 64
	// if (numofrun == 1)
	// {

		// first operation
		// if (stackdetails.stack_a_top > stackdetails.stack_a_sec)
			// pb(&stack_a, &stack_b);
		// else
			// rr(&stack_a, &stack_b);


		// second operation
		// if (stackdetails.stack_a_top > stackdetails.stack_a_sec)
			// pb(&stack_a, &stack_b);
		// else
			// rr(&stack_a, &stack_b);
		


		// printf("\n");
		// displaystack(&stack_a);
		// displaystack(&stack_b);

	// }

	return (0);
}

// if (!isEmpty(&myStack)) {
//     printf("Popped: %d\n", pop(&myStack));
// }

// /* for stack*/

// #define MAX_SIZE 100

// // Define a stack structure
// struct Stack {
//     int items[MAX_SIZE];
//     int top;
// };

// // Initialize the stack
// void initialize(struct Stack *stack) {
//     stack->top = -1;
// }

// // Check if the stack is empty
// int isEmpty(struct Stack *stack) {
//     return stack->top == -1;
// }

// // Check if the stack is full
// int_fast16_t isFull(struct Stack *stack) {
//     return stack->top == MAX_SIZE - 1;
// }

// // Push an item onto the stack
// void push(struct Stack *stack, int value) {
//     if (isFull(stack)) {
//         printf("Stack overflow. Cannot push %d onto the stack.\n", value);
//     } else {
//         stack->items[++stack->top] = value;
//     }
// }

// // Pop an item from the stack
// int pop(struct Stack *stack) {
//     if (isEmpty(stack)) {
//         printf("Stack underflow. Cannot pop from an empty stack.\n");
//         return -1; // Error value
//     } else {
//         return stack->items[stack->top--];
//     }
// }

// // Peek at the top item of the stack without removing it
// int peek(struct Stack *stack) {
//     if (isEmpty(stack)) {
//         printf("Stack is empty. Cannot peek.\n");
//         return -1; // Error value
//     } else {
//         return stack->items[stack->top];
//     }
// }

// void print_binary(signed char num) {
//     for (int i = 7; i >= 0; i--) {
//         putchar((num & (1 << i)) ? '1' : '0');
//     }
// }

// int main(int argc, char *argv[])
// {
//     signed char 	number;
// 	int 			i;
// 	struct Stack	stack;

// 	i = 1;
//     initialize(&stack);

// 	while (argc > i)
// 	{
// 		number = ft_atoi(argv[i]);
// 		print_binary(number);
// 		push(&stack, number);
// 		printf("\n");

// 		i++;
// 	}

// 	while (!isEmpty(&stack))
// 	{
// 		number = pop(&stack);
// 		printf("num:%d\n", number);
// 	}

//     return 0;
// }
