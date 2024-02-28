#include "./utils/utils.h"
#include "./utils/utils2.h"
// #include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./sort/sort3.h"
#include "./sort/sort5.h"
#include "./sort/radix_sort.h"

int sort_wrapper(int argc, t_stack *stack_a, t_stack *stack_b)
{
	printf("sort wrapper. argc:%d\n", argc);
	t_element3	element3;
	t_element5	element5;
	int			numberofop;
	// int			i;
	// int			err;

	// err = -1;
	// i = 1;
	numberofop = 0;
	if (argc == 0)
	{
		printf("no arguments\n");

		return -1;
	}
	else if (argc == 1)
	{
		printf("only 1 item");
	}
	// {
	// 	printf("only 1 element? Check if i can split\n");
		
	// 	char **args = ft_split(argv[1], ' ');
	// 	i = 0;
	// 	while (args[i])
	// 	{

	// 		addtoback(&stack_a, ft_atoi_modified(args[i], &err));
	// 		if (err == 1)
	// 		{
	// 			printf("error\n");
	// 			return -1;
	// 		}
	// 		i++;
	// 	}
	// 	// to check and then sort accordingly.
	// 	// ./push_swap "3 4 6 8 9 74 -56 +495"

	// 	return 0;
	// }
	else if (argc == 2 )
	{
		printf("swap top 2 if required");
		return -1;
	}
	else if (argc == 3)
	{
		printf("argc ==3 \n");
		init3_element(&element3);
		find3_numbers(stack_a->top, &element3);
		find3_numbers_pos(stack_a, &element3);
		sort5elementstop3(stack_a, &numberofop, &element3);
		displaystack(stack_a);
		return -0;
	}
	else if (argc ==4)
	{
		printf("argc ==4\n");
		displaylinkedlist2(stack_a->top);
		return -1;
	}
	else if (argc == 5)
	{
		printf("argc == 5\n");
		init5_element(&element5);
		sort5(stack_a, stack_b, &numberofop, &element5);
	}
	else if (argc < 500)
	{
		printf("argc <500\n");
		setpos(stack_a, argc);
		radix_sort(stack_a, stack_b, &numberofop);
	}
	else
	{
		printf("else \n");
		return -1;
	}

	// displaystack(stack_a);
	printf("ops:%d\n", numberofop);
	return (0);	
}

int	main(int argc, char *argv[])
{
	int			i;
	int			err;
	t_stack		stack_a;
	t_stack		stack_b;
	
	err = -1;
	i = 1;
	initstack(&stack_a);
	initstack(&stack_b);
	if (argc != 2)
	{
		while (argv[i])
		{
			addtoback(&stack_a, ft_atoi_modified(argv[i], &err));
			if (err == 1)
			{
				printf("error: err == 1\n");
				return -1;
			}
			i++;
		}
	}
	else if (argc == 2)
	{
		printf("only 1 element? Check if i can split\n");
		
		char **args = ft_split(argv[1], ' ');
		i = 0;
		while (args[i])
		{

			addtoback(&stack_a, ft_atoi_modified(args[i], &err));
			if (err == 1)
			{
				printf("error\n");
				return -1;
			}
			i++;
		}
		// to check and then sort accordingly.
		// ./push_swap "3 4 6 8 9 74 -56 +495"

		// return 0;
	}

	// check for duplicate	
	if (hasDuplicate(stack_a.top))
	{
        printf("Linked list contains duplicate elements.\n");
		printf("error");
		return (-1);
    }
	else
	{
        printf("Linked list does not contain duplicate elements.\n");
    }

	return sort_wrapper(i, &stack_a, &stack_b);
	
}
