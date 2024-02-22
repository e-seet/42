// #include "./utils/utils.h"
#include "./utils/utils2.h"
#include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./sort/sort3.h"
#include "./sort/sort5.h"

int getLastBit(int num) {
    // Get the last bit using bitwise AND with 1
    int lastBit = num & 1;
    return lastBit;
}

int getSecLastBit(int num) {
    // Get the last bit using bitwise AND with 1
    int lastBit = (num >> 1) & 1;
    return lastBit;
}

int getthirdLastBit(int num) {
    // Get the last bit using bitwise AND with 1
    int lastBit = (num >> 2) & 1;
    return lastBit;
}

int get4LastBit(int num) {
    // Get the last bit using bitwise AND with 1
    int lastBit = (num >> 3) & 1;
    return lastBit;
}

int get5LastBit(int num) {
    // Get the last bit using bitwise AND with 1
    int lastBit = (num >> 4) & 1;
    return lastBit;
}

// void loopbit(int num)
// {
// 	int i = 0;
// 	int bit;

// 	while (i < 32)
// 	{
// 	    bit = (num >> i) & 1;
// 		printf("i: %d, value:%d\n", i, bit);
// 		i = i + 1;
// 	}
// }

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
	// printf("radix sort\n");
	// printf("value:%d \n 5:%d\n 4:%d\n 3:%d\n 2:%d,  1:%d \n", -5,get5LastBit(-5) ,get4LastBit(-5) ,getthirdLastBit(-5),getSecLastBit(-5), getLastBit(-5));
	// printf("max int:%d", INT_MAX);
	// loopbit(INT_MAX); // 32 bits as // 0111
	// printf("\n\n"); 
	// printf("min int:%d", INT_MIN);
	// loopbit(INT_MIN); // 2s complement. Need 32 bits to store. 1000.... 

	//if it is 1/0, push to stack b? To find out
	int i = 0;
	t_node *headA;
	t_node *headB;
	
	t_node *tailA;
	// t_node *tailB;
	
	tailA = stack_a->bot;
	// tailB = stack_b->bot;
	
	printf("%p%d \n\n",numberofop, i);
	
	// /*
	while (4 > i)
	{
		// for the first time.
		headA = stack_a->top;

		if (stack_is_sorted(stack_a) == 0)
		{
			break;
		}

		// can do partitioning here to maximise efficiency 
		while (headA != tailA)
		{ 
			// check if top is null
			if (stack_a ->top != NULL)
			{
				headA = stack_a->top;
			}

			if (((headA->value >> i) & 1) == 1)
			{
				pb(stack_a,stack_b, numberofop);
			} 
			else
			{
				rotate_stack(stack_a, numberofop);
			}
				headA = stack_a->top;	
		}

		// had to use this to check the last one
		if (((headA->value >> i) & 1) == 1)
		{
			pb(stack_a,stack_b, numberofop);
		} 
		else
		{
			rotate_stack(stack_a, numberofop);
		}
		
		printf("after finish rotating A\n\n");
		// displaylinkedlist2(stack_a->top);
		// displaylinkedlist2(stack_b->top);

		headB = stack_b->top;
		if (headB != NULL)
		{
			// pushback to stack a
			while (headB != NULL)
			{
				pa(stack_a, stack_b, numberofop);
				// headB = headB->next;
				headB = stack_b->top;
			}
		}

		printf("\nthe %d from back\n",i);
		printf("after finish pushing back to B\n\n");
		// displaylinkedlist2(stack_a->top);
		// displaylinkedlist2(stack_b->top);
		i = i+1;
	}
	// */

	displaylinkedlist2(stack_a->top);

/*
	headA = stack_a->top;
	headB = stack_b->top;

	printf("head A:%p\n", headA);
	printf("head B%p\n", headB);
	// pa(stack_a, stack_b, numberofop);
	pb(stack_a, stack_b, numberofop);
	headA = stack_a->top;
	printf("head A:%p\n", headA);
*/
	// printf("\n\n");
	// displaylinkedlist2(stack_a->top);
	// displaylinkedlist2(stack_b->top);

}

int	main(int argc, char *argv[])
{

	int			i;
	t_stack		stack_a;
	t_stack		stack_b;
	int			numberofop;
	s_element5	element5;

	numberofop = 0;

	// printf("minrun:%d\n", calculate_minrun(argc-1));
	// stackdetails.stack_a_last = ft_atoi(argv[1]);
	// stackdetails.stack_a_top = ft_atoi(argv[argc-1]);
	// printf("top of stack: %d, bottom of stack:%d\n", stackdetails.stack_a_top, stackdetails.stack_a_last);

	i = 1;
	initstack(&stack_a);
	initstack(&stack_b);

	// addtoback(&stack_a, ft_atoi(argv[i]));
	while (argv[i])
	{
		
		addtoback(&stack_a, ft_atoi(argv[i]));
		// push(&stack_a, ft_atoi(argv[i]), &stackdetails );
		// push(&stack_a, ft_atoi(argv[i]) );
		i++;
	}

	// t_node *head = stack_a.top;
	// printf("count elements in stack%d\n", count_elements_in_stack(head) );
	// pb(&stack_a, &stack_b);
	// head = stack_a.top;
	// printf("count elements in stack%d\n", count_elements_in_stack(head) );

	// // To count min run first
	// int numofelements = count_elements_in_stack(head);
	// int minrun = calculate_minrun(numofelements);
	// // printf("minrun:%d\n", minrun);

	// int numofrun = (argc -1) / minrun;
	// printf("number of runs that will be created:%d \n", numofrun);

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
		radix_sort(&stack_a, &stack_b, &numberofop);
	}
	// printf("after sorting\n");
	// displaystack(&stack_a);

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


/*
1:	0000000000000001
2:	0000000000000010
3:	0000000000000011
4:	0000000000000100
8: 	0000000000001000
10:	0000000000001010
*/
