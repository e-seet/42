// #include "./utils/utils.h"
#include "./utils/utils2.h"
#include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./sort/sort3.h"
#include "./sort/sort5.h"

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

	while (argv[i])
	{
		addtoback(&stack_a, ft_atoi(argv[i]));
		// push(&stack_a, ft_atoi(argv[i]), &stackdetails );
		// push(&stack_a, ft_atoi(argv[i]) );
		i++;
	}

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

	if (argc == 4)
	{
		s_element3	element3;
		init3Element(&element3);
		find3Numbers(stack_a.top, &element3);
		find3NumbersPos(&stack_a, &element3);
		sort5elementstop3(&stack_a, &numberofop, &element3);
		displaystack(&stack_a);
	}
	if (argc == 6)
	{
		init5Element(&element5);
		sort5(stack_a, stack_b, &numberofop, &element5);
		displaystack(&stack_a);
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

