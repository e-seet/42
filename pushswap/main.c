#include "./utils/utils.h"
#include "./utils/utils2.h"
// #include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./sort/sort3.h"
#include "./sort/sort5.h"
#include "./sort/radix_sort.h"

int	sort_wrapper(int argc, t_stack *stack_a, t_stack *stack_b)
{
	t_element3	element3;
	t_element5	element5;
	int			numberofop;

	printf("sort wrapper. argc:%d\n", argc);
	numberofop = 0;
	if (argc == 0)
	{
		printf("no arguments\n");
		return (1);
	}
	else if (argc == 1)
	{
		printf("only 1 item. Should be able to return right?");
		return (1);
	}
	else if (argc == 2)
	{
		printf("swap top 2 if required. TO do");
		return (1);
	}
	else if (argc == 3)
	{
		printf("argc ==3 \n");
		init3_element(&element3);
		find3_numbers(stack_a->top, &element3);
		find3_numbers_pos(stack_a, &element3);
		sort5elementstop3(stack_a, &numberofop, &element3);
		displaystack(stack_a);
		return (0);
	}
	else if (argc == 4)
	{
		printf("argc == 4. To do\n");
		displaylinkedlist2(stack_a->top);
		return (1);
	}
	else if (argc == 5)
	{
		printf("argc == 5\n");
		init5_element(&element5);
		sort5(stack_a, stack_b, &numberofop, &element5);
		displaylinkedlist2(stack_a->top);
		return (0);
	}
	else if (argc < 500)
	{
		printf("argc > 5\n");
		setpos(stack_a, argc);
		radix_sort(stack_a, stack_b, &numberofop);
		return (0);
	}
	else
	{
		printf("else other case scenario. idk just return -1 first\n");
		return (1);
	}
	printf("ops:%d\n", numberofop);
	return (0);
}

int readarguments(int argc,char **argv,int *i, t_stack *stack_a, int *err)
{
	printf("read arguments\n");

	if (argc == 2)
	{
		*i = 0;
	}
	
	while (argv[*i])
	{
		addtoback(stack_a, ft_atoi_modified(argv[*i], err));
		if (*err == 1)
		{
			printf("error\n");
			return (1);
		}
		*i = *i + 1;
	}

	// At the end
	if (argc != 2)
	{
		*i = *i -1;
	}

	/*
	if (argc != 2)
	{
		// take note
		// i = 1
		while (argv[*i])
		{
			addtoback(stack_a, ft_atoi_modified(argv[*i], err));

			if (*err == 1)
			{
				printf("error: err == 1\n");
				return (1);
			}
			*i = *i+1;
		}
		// take note
		*i = *i - 1;
	}

	else if (argc == 2)
	{
		// printf("argc == 2\n");
		*i = 0;
		while (argv[*i])
		{
			addtoback(stack_a, ft_atoi_modified(argv[*i], err));
			if (*err == 1)
			{
				printf("error\n");
				return (1);
			}
			*i = *i + 1;
		}
	}*/

	return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			err;
	t_stack		stack_a;
	t_stack		stack_b;
	// char		**args;

	err = -1;
	i = 1;
	initstack(&stack_a);
	initstack(&stack_b);

	if (argc != 2)
		readarguments(argc, argv, &i, &stack_a, &err);
	else
		readarguments(argc, ft_split(argv[1], ' '), &i, &stack_a, &err);
	
	if (err == 1)
	{
		printf("error in main. Return: err == 1\n");
		return (1);
	}

	/*
	if (argc != 2)
	{
		while (argv[i])
		{
			addtoback(&stack_a, ft_atoi_modified(argv[i], &err));
			if (err == 1)
			{
				printf("error: err == 1\n");
				return (1);
			}
			i++;
		}
		i = i - 1;
	}
	else if (argc == 2)
	{
		printf("only 1 element? Check if i can split\n");
		args = ft_split(argv[1], ' ');
		i = 0;
		while (args[i])
		{
			addtoback(&stack_a, ft_atoi_modified(args[i], &err));
			if (err == 1)
			{
				printf("error\n");
				return (1);
			}
			i++;
		}
	}*/

	if (hasDuplicate(stack_a.top))
	{
		printf("Linked list contains duplicate elements.\n");
		printf("error");
		return (1);
	}
	else
	{
		printf("Linked list does not contain duplicate elements.\n");
	}
	return (sort_wrapper(i, &stack_a, &stack_b));
}
