#include "./utils/utils.h"
#include "./utils/utils2.h"
// #include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./sort/sort3.h"
#include "./sort/sort4.h"
#include "./sort/sort5.h"
#include "./sort/radix_sort.h"

int	errormsg(void)
{
	perror("Error\n");
	return (1);
}

int	sort1n2(int argc, int *numberofop, t_stack *stack_a)
{
	if (argc == 1)
	{
		printf("nothing to sort.");
		printf("ops:%d", *numberofop);
		return (0);
	}
	else
	{
		printf("swap top 2 if required. TO do");
		if (stack_is_sorted(stack_a) == 0 || stack_is_sorted2(stack_a) == 0)
			printf("sorted.");
		else
			swap_top_two(stack_a, numberofop);
		return (0);
	}
}

int	sort_wrapper(int argc, t_stack *stack_a, t_stack *stack_b)
{
	int			numberofop;

	numberofop = 0;
	if (argc == 0)
		errormsg();
	else if (argc == 1 || argc == 2)
		return (sort1n2(argc, &numberofop, stack_a));
	else if (argc == 3)
		return (sort3wrapper(stack_a, &numberofop));
	else if (argc == 4)
		return (sort4wrapper(stack_a, stack_b, &numberofop));
	else if (argc == 5)
		return (sort5wrapper(stack_a, stack_b, &numberofop));
	else if (argc <= 500)
		return (radix_sort_wrapper(argc, stack_a, stack_b, &numberofop));
	else
		errormsg();
	printf("ops:%d\n", numberofop);
	return (0);
}

int	readarguments(int argc, char **argv, int *i, t_stack *stack_a)
{
	int	err;

	if (argc == 2)
	{
		*i = 0;
	}
	while (argv[*i])
	{
		addtoback(stack_a, ft_atoi_modified(argv[*i], &err));
		if (err == 1)
		{
			printf("error\n");
			return (1);
		}
		*i = *i + 1;
	}
	if (argc != 2)
	{
		*i = *i -1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			err;
	t_stack		stack_a;
	t_stack		stack_b;

	i = 1;
	initstack(&stack_a);
	initstack(&stack_b);
	if (argc != 2)
		err = readarguments(argc, argv, &i, &stack_a);
	else
		err = readarguments(argc, ft_split(argv[1], ' '), &i, &stack_a);
	if (err == 1)
	{
		printf("error in main. Return: err == 1\n");
		return (1);
	}
	if (hasDuplicate(stack_a.top))
	{
		printf("Linked list contains duplicate elements.\n");
		printf("error");
		return (1);
	}
	return (sort_wrapper(i, &stack_a, &stack_b));
}
