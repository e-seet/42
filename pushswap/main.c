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
	// printf("\n\n");
	displaylinkedlist2(stack_a->top);
}

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
}

void radix_sort(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
	//if it is 1/0, push to stack b? To find out
	int i = 0;
	t_node *headA;
	t_node *headB;
	t_node *tailA;
	
	tailA = stack_a->bot;
	
	while (32 > i)
	{
		printf("value of i :%d\n", i);
		// for the first time.
		headA = stack_a->top;
		tailA = stack_a->bot;

		if (stack_is_sorted(stack_a) == 0 || stack_is_sorted2(stack_a) == 0)
		{
			break;
		}

		// can do partitioning here to maximise efficiency 
		while (headA != tailA)
		{ 
			printf("first while loop\n");
			// check if top is null
			if (stack_a ->top != NULL)
			{
				headA = stack_a->top;
			}



			if (((headA->pos >> i) & 1) == 0)
			{
				printf("what is this? %d", (headA->pos >> i) & 1);
				pb(stack_a,stack_b, numberofop);
			}
			else
			{
				rotate_stack(stack_a, numberofop);
 			}
			headA = stack_a->top;	
		}
		// printf("check A:\n");
		// displaylinkedlist2(stack_a->top);

		// had to use this to check the last one
		if (((headA->pos >> i) & 1) == 0)
		{
			pb(stack_a,stack_b, numberofop);
		} 
		else
		{
			rotate_stack(stack_a, numberofop);
		}
		displaylinkedlist2(stack_a->top);

		headB = stack_b->top;
		if (headB != NULL)
		{
			// pushback to stack a
			while (headB != NULL)
			{
				printf("second while loop\n");
				pa(stack_a, stack_b, numberofop);
				// headB = headB->next;
				headB = stack_b->top;
			}
		}
		printf("i:%d\n", i);
		displaylinkedlist2(stack_a->top);
		printf("\n\n");
		i = i+1;
	}
	// */


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
		radix_sort(&stack_a, &stack_b, &numberofop);
	}
	printf("after sorting\n");
	displaystack(&stack_a);

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