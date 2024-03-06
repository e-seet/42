#include "./utils/utils.h"
#include "./utils/utils2.h"
#include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./sort/sort3.h"
#include "./sort/sort5.h"

void setpos(t_stack *stack_a, int argc)
{
	int i;
	int smallest;
	t_node *curr;

	i = 1;
	while (argc > i)
	{
		// initial setting of smalelst value
		curr = stack_a ->top;
		while (curr->pos != 0)
		{
			curr = curr ->next;
		}
		smallest = curr->value;

		// find the smallest for every iteration
		while(curr ->next != stack_a->top)
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
	stack_a ->originalnumber = argc -1;
}

/*
void loopbit(int num)
{
    int i = 0;
    int bit;

    while (i < 32) // Iterate through all 32 bits
    {
        bit = (num >> i) & 1;
        printf("%d", bit);
        // printf("i: %d, value: %d\n", i, bit);
        i = i + 1;
    }
}*/

int number_of_binary_digits(int num) {
    int count = 0;

    // Handle negative numbers (return -1 for error)
    if (num < 0) {
        return -1;
    }

    // Handle the case of 0, which requires only 1 binary digit
    if (num == 0) {
        return 1;
    }

    // Efficiently find the number of digits using bitwise shift
    while (num != 0) {
        num >>= 1;  // Right shift by 1 to remove the least significant bit
        count++;     // Increment the count for each non-zero bit
    }

    return count;
}

void radix_sort(t_stack *stack_a, t_stack *stack_b, int *numberofop, int binarydigit)
{
	//if it is 1/0, push to stack b? To find out
	int i = 0;
	t_node *headA;
	t_node *headB;
	t_node *tailA;
	// t_node *tailB;
	
	tailA = stack_a->bot;
	
	while (binarydigit-2 >= i)
	{
		printf("\n\nvalue of i :%d\n", i);
		displaylinkedlist2(stack_a->top);
		displaylinkedlist2(stack_b->top);
		printf("\n\n");
		// for the first time.
		headA = stack_a->top;
		tailA = stack_a->bot;

		printf("original number:%d\n",  stack_a->originalnumber);
		printf("count element in a:%d\n", count_elements_in_stack(stack_a->top));

		if ( (stack_is_sorted2(stack_a) == 0 && (stack_a->originalnumber == count_elements_in_stack(stack_a->top))))
		{
			break;
		}

		// can do partitioning here to maximise efficiency 
		while (headA != tailA)
		{ 
			// printf("first while loop\n");
			// displaylinkedlist2(stack_a->top);

			// check if top is null
			if (stack_a ->top != NULL)
			{
				headA = stack_a->top;
			}

			// dont rotate after pushing
			if (((headA->pos >> i) & 1) == 0)
			{
					pb(stack_a,stack_b, numberofop);
			}
			// rotate down
			else if (((headA->pos >> (i+1)) & 1) == 0)
			{
				pb(stack_a,stack_b, numberofop);
				rotate_stack(stack_b, numberofop);
			}
			else
			{
				rotate_stack(stack_a, numberofop);
 			}
			headA = stack_a->top;	
		}

		// check last node
		if (headA != NULL)
		{
			// dont rotate after pushing
			if (((headA->pos >> i) & 1) == 0)
			{
					pb(stack_a,stack_b, numberofop);
			}
			// rotate down
			else if (((headA->pos >> (i+1)) & 1) == 0)
			{
				pb(stack_a,stack_b, numberofop);
				rotate_stack(stack_b, numberofop);
			}
			
			else
			{
				rotate_stack(stack_a, numberofop);
 			}
		}
		// end of pushing to b

		printf("end of Pushing to B\n");
		printf("a\n");
 		displaylinkedlist2(stack_a->top);
 		printf("b\n");
		displaylinkedlist2(stack_b->top);

		
		t_node *tailB;
		
		// push back to A
		headB = stack_b->top;
		tailB = stack_b->bot;
		// tailB = stack_b->bot;
		int breaknum = 0;

		if (headB != NULL)
		{
			printf("second while loop\n");
			// pushback to stack a
			while (headB != tailB)
			{
				
				// check that stack b is sorted or ready to push back to a. [unlikely]
				if 
				(
					(stack_is_rev_sorted(stack_b) == 0 && (stack_a->originalnumber == count_elements_in_stack(stack_b->top))) ||
					(stack_is_sorted2(stack_b) == 0 && (stack_a->originalnumber == count_elements_in_stack(stack_b->top)))
				)
				{
					printf("psuh all back to A\n");
					while (headB != NULL)
					{
						pa(stack_a, stack_b, numberofop);
						headB = stack_b->top;
					}
					break;
				
				}
				else if (((headB->pos >> (i)) & 1) == 0 )
				{
					while ((((headB->pos >> (i)) & 1) == 0))
					{
						pa(stack_a, stack_b, numberofop);
						headB = stack_b->top;
					}
				

				}
				// else if (((headB->pos >> (i)) & 1) == 0 && (((headB->pos >> (i+1)) & 1) != 0))
				// {
				// 	// last digit is 0, and 2nd last is 1, push back to a
				// 	while (((headB->pos >> (i)) & 1) == 0 && (((headB->pos >> (i+1)) & 1) != 0))
				// 	{
				// 		pa(stack_a, stack_b, numberofop);
				// 		headB = stack_b->top;
				// 		// printf("value :%d \n", headB->value);
				// 		// printf("lsb: %d\n", (headB->pos >> (i)) & 1);
				// 		// printf("2 lsb: %d\n", (headB->pos >> (i+1)) & 1);
				// 	}

					// when i am done with lsb = 0 and msb = 1. 
					// Need to reverse rotate back so that the head becomes the tail? or tail becoems the head?
					// basically everything should be retotated until it is done
					
					/*
					tailB = stack_b ->bot;
					headB = stack_b->top;
					int breaknum2 = 0;
					while (headB != stack_b->bot)
					{
						printf("Reverse rotate rotate back\n");
						// reverse_rotate_stack(stack_b, numberofop);
						if (breaknum2 == 7)
							break;
						// tailB = stack_b->bot;
						breaknum2 = breaknum2 + 1;

					}
					printf("end of rotating: %d\n", tailB->value);*/
				// }

				// else if (((headB->pos >> (i)) & 1) == 0 && (((headB->pos >> (i+1)) & 1) != 0))
				// else if ( (((headB->pos >> (i+1)) & 1) != 1))
				// {
				// 	printf("back back from stack b to stack a\n");
				// 	pa(stack_a, stack_b, numberofop);
				// }
				// else if (((headB->pos >> (i+1)) & 1) == 0)
				// {
				// 	headB = stack_b->top;
				// 	while (headB != tailB)
				// 	{
				// 		reverse_rotate_stack(stack_b, numberofop);
				// 		headB = stack_b->top;
				// 	}
				// 	if (headB == tailB)
				// 		break;
				// }
				else if (breaknum == 10)
				{
					break;
				}
				else
				{
					rotate_stack(stack_b, numberofop);

				}
				headB = stack_b->top;
				breaknum = breaknum + 1;
			}
		}

		// printf("i:%d\n", i);
		printf("end of pushing back to a| value of i:%d\n", i);
		printf("a\n");
		displaylinkedlist2(stack_a->top);
		printf("b\n");
		displaylinkedlist2(stack_b->top);
		// printf("\n\n");
		i = i+1;
	}


	headB = stack_b->top;
	if (headB != NULL)
	{
		while (headB != NULL)
		{
			pa(stack_a, stack_b, numberofop);
			headB = stack_b->top;
		}
	}

	// */
	displaylinkedlist2(stack_a->top);


}

int	main(int argc, char *argv[])
{

	int			i;
	t_stack		stack_a;
	t_stack		stack_b;
	int			numberofop;
	s_element5	element5;

	numberofop = 0;

	i = 1;
	initstack(&stack_a);
	initstack(&stack_b);

	while (argv[i])
	{
		addtoback(&stack_a, ft_atoi(argv[i]));
		i++;
	}

	// sort 3
	if (argc == 4)
	{
		s_element3	element3;
		init3Element(&element3);
		find3Numbers(stack_a.top, &element3);
		find3NumbersPos(&stack_a, &element3);
		sort5elementstop3(&stack_a, &numberofop, &element3);
		displaystack(&stack_a);
	
	}
	// sort 4
	else if (argc ==5)
	{
		// to do. Lazy to do now.
	}
	// sort 5
	if (argc == 6)
	{
		init5Element(&element5);
		sort5(stack_a, stack_b, &numberofop, &element5);
		// displaystack(&stack_a);
	}
	else 
	{
	// 	// try to do timsort
		// tim_sort(&stack_a, &stack_b, &numberofop);
		setpos(&stack_a, argc);
		int binarydigit = number_of_binary_digits(argc);
		radix_sort(&stack_a, &stack_b, &numberofop, binarydigit);
	}

	printf("after sorting\n");
	// printf("a\n");
	displaylinkedlist2(stack_a.top);
	// printf("b\n");
	// displaylinkedlist2(stack_b.top);

	// displaystack(&stack_a);
	// displaystack(&stack_b);

	printf("ops:%d\n", numberofop);
	return (0);
}


/*
1:	0000000000000001
2:	0000000000000010
3:	0000000000000011
4:	0000000000000100
8: 	0000000000001000
10:	0000000000001010
*/

/*
1:	0000000000000001
2:	0000000000000010
3:	0000000000000011
4:	0000000000000100
5:	0000000000000101
6:	0000000000000110
7:	0000000000000111
*/