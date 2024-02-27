#include "./utils/utils.h"
#include "./utils/utils2.h"
// #include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./sort/sort3.h"
#include "./sort/sort5.h"
#include "./sort/radix_sort.h"

// Function to check for duplicates in a circular linked list
int hasDuplicate(t_node *head)
{
    if (head == NULL || head->next == head)
	{
        return 0; // No duplicates in an empty list or a single-node list
    }

    t_node *current = head->next; // Start from the second node
    t_node *compare;

    while (current != head)
	{
        compare = head;

        // Compare the current node's data with all previous nodes
        while (compare != current)
		{
            if (current->value == compare->value)
			{
                return 1; // Duplicate found
            }
            compare = compare->next;
        }

        current = current->next;
    }

    return 0; // No duplicates found
}

int	ft_atoi_modified(const char *str, int *err)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	// check if spaces
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' 
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	// check the signs
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = str[i] - 48 + num * 10;
		i++;
	}
	printf("str:%s\n", str);
	printf("num:%ld\n\n", num*sign);
	// printf("i value:%d\n", i);
	if (i == 0 || str[i] != '\0' || num * sign > INT_MAX || num * sign < INT_MIN)
		*err = 1;
	else
		*err = 0;


	return (num * sign);
}


void	loopbit(int num)
{
	int	i;
	int	bit;

	i = 0;
	// Iterate through all 32 bits
	while (i < 32)
	{
		bit = (num >> i) & 1;
		printf("%d", bit);
		i = i + 1;
	}
}



int	main(int argc, char *argv[])
{
	int			i;
	int			err;
	t_stack		stack_a;
	t_stack		stack_b;
	int			numberofop;
	t_element3	element3;
	t_element5	element5;

	err = -1;
	numberofop = 0;
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

	// check for duplicate	
	if (hasDuplicate(stack_a.top)) {
        printf("Linked list contains duplicate elements.\n");
		printf("error");
		return (-1);
		// break;
    } else {
        printf("Linked list does not contain duplicate elements.\n");
    }


	if (argc == 1)
	{
		printf("no arguments\n");

		return -1;
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

		return 0;
	}
	else if (argc == 3)
	{
		printf("swap top 2 if required");
		return -1;
	}
	else if (argc == 4)
	{
		printf("argc ==4 \n");
		init3_element(&element3);
		find3_numbers(stack_a.top, &element3);
		find3_numbers_pos(&stack_a, &element3);
		sort5elementstop3(&stack_a, &numberofop, &element3);
		displaystack(&stack_a);
		return -0;
	}
	else if (argc == 5)
	{
		printf("argc ==5\n");
		displaylinkedlist2(stack_a.top);		
		return -1;
	}
	if (argc == 6)
	{
		printf("argc == 6\n");
		init5_element(&element5);
		sort5(stack_a, stack_b, &numberofop, &element5);
	}
	else if (argc < 500)
	{
		printf("argc <500\n");
		setpos(&stack_a, argc);
		radix_sort(&stack_a, &stack_b, &numberofop);
	}
	else
	{
		printf("else \n");
		return -1;
	}
	displaystack(&stack_a);
	printf("ops:%d\n", numberofop);
	return (0);
}
