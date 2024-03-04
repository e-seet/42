#include "./utils/utils.h"
#include "./utils/utils2.h"
#include "./utils/utils3.h"
#include "./utils/utils4.h"
// #include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./utils/exit.h"
#include "./sort/sort3.h"
#include "./sort/sort4.h"
#include "./sort/sort5.h"
#include "./sort/radix_sort.h"
// #include <errno.h>

int	errormsg(t_stack *stack_a, t_stack *stack_b)
{
	exitsafe(stack_a, stack_b);
	write(2, "Error\n", 6);
	return (1);
}

// int	sort1n2(int argc, int *numberofop, t_stack *stack_a, t_stack *stack_b)
// int	sort1n2(int argc, t_stack *stack_a, t_stack *stack_b, int *numberofop)
int	sort1n2(int argc, t_stack *stack_a, t_stack *stack_b)
{
	// printf("sort1n2 argc:%d\n", argc);
	if (argc == 2)
	{
		return errormsg(stack_a, stack_b);
		// return (0);
	}
	else
	{
		return errormsg(stack_a, stack_b);

		// printf("sort 1 n 2\n");
		// if (stack_is_sorted(stack_a) == 0 || stack_is_sorted2(stack_a) == 0)
		// {
		// }
		// else
			// swap_top_two(stack_a, numberofop, 0);
		// write(2, "Error\n", 6);
		// exitsafe(stack_a, stack_b);
		// return (0);
	}
}

int	sort_wrapper(int argc, t_stack *stack_a, t_stack *stack_b)
{
	int			numberofop;

	// printf("sort wraper argc:%d\n", argc);
	numberofop = 0;
	if (argc == 0 || argc == 1)
		return errormsg(stack_a, stack_b);
	else if (argc == 3 || argc == 2)
		return (sort1n2(argc, stack_a, stack_b));
		// return (sort1n2(argc, stack_a, stack_b, &numberofop));
		// return (sort1n2(argc, &numberofop, stack_a, stack_b));
	else if (argc == 4)
		return (sort3wrapper(stack_a, stack_b, &numberofop));
	else if (argc == 5)
		return (sort4wrapper(stack_a, stack_b, &numberofop));
	else if (argc == 6)
		return (sort5wrapper(stack_a, stack_b, &numberofop));
	else if (argc > 6)
		return (radix_sort_wrapper(argc, stack_a, stack_b, &numberofop));
	else
		return errormsg(stack_a, stack_b);
	return (0);
}

int	readarguments(int argc, char **argv, int *i, t_stack *stack_a)
{
	int		err;
	int		internal;
	char	**strs;

	while (argc > *i)
	{
		internal = 0;
		strs = ft_split(argv[*i], ' ');

		while (strs[internal])
		{
			// printf("read arg\n");
			addtoback(stack_a, ft_atoi_modified(strs[internal], &err));
			internal = internal + 1;
		}
		if (err == 1)
		{
			return (1);
		}
		*i = *i + 1;
	}
	return (0);
}


// int	readarguments(int argc, char **argv, int *i, t_stack *stack_a)
// {
// 	int	err;

// 	// if (argc == 2)
// 	// {
// 	// 	*i = 0;
// 	// }
// 	while (argv[*i])
// 	{
// 		addtoback(stack_a, ft_atoi_modified(argv[*i], &err));
// 		if (err == 1)
// 		{
// 			return (1);
// 		}
// 		*i = *i + 1;
// 	}
// 	// if (argc != 2)
// 	// {
// 	// 	*i = *i -1;
// 	// }
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	int			i;
	int			err;
	t_stack		stack_a;
	t_stack		stack_b;

	i = 1;
	initstack(&stack_a, 0);
	initstack(&stack_b, 1);

	if (argc == 1)
	{
		return errormsg(&stack_a, &stack_b);
	}
	// else if (argc != 2)
		// err = readarguments(argc, argv, &i, &stack_a);
	else
	{
		// printf("main\n");
		err = readarguments(argc, argv, &i, &stack_a);
	}
		// err = readarguments(argc, ft_split(argv[1], ' '), &i, &stack_a);	
	if (err == 1)
	{
		return errormsg(&stack_a, &stack_b);
	}
	if (has_duplicate(stack_a.top))
	{
		return errormsg(&stack_a, &stack_b);
	}
	return (sort_wrapper(i, &stack_a, &stack_b));
}
