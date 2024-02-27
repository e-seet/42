#include "./utils/utils.h"
#include "./utils/utils2.h"
// #include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"
#include "./sort/sort3.h"
#include "./sort/sort5.h"

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


void	setpos(t_stack *stack_a, int argc)
{
	int		i;
	int		smallest;
	t_node	*curr;

	i = 1;
	while (argc > i)
	{
		curr = stack_a ->top;
		while (curr->pos != 0)
		{
			curr = curr ->next;
		}
		smallest = curr->value;
		// find the smallest for every iteration
		while (curr ->next != stack_a->top)
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
	printf("set pos\n");
	displaylinkedlist2(stack_a->top);
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

void	radix_sort(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
	int		i;
	t_node	*head_a;
	t_node	*head_b;
	t_node	*tail_a;

	tail_a = stack_a->bot;
	i = 0;
	while (32 > i)
	{
		head_a = stack_a->top;
		tail_a = stack_a->bot;
		if (stack_is_sorted(stack_a) == 0 || stack_is_sorted2(stack_a) == 0)
		{
			break ;
		}
		while (head_a != tail_a)
		{
			if (stack_a ->top != NULL)
			{
				head_a = stack_a->top;
			}
			if (((head_a->pos >> i) & 1) == 0)
			{
				pb(stack_a, stack_b, numberofop);
			}
			else
			{
				rotate_stack(stack_a, numberofop);
			}
			head_a = stack_a->top;
		}
		if (((head_a->pos >> i) & 1) == 0)
		{
			pb(stack_a, stack_b, numberofop);
		}
		else
		{
			rotate_stack(stack_a, numberofop);
		}
		head_b = stack_b->top;
		if (head_b != NULL)
		{
			while (head_b != NULL)
			{
				pa(stack_a, stack_b, numberofop);
				head_b = stack_b->top;
			}
		}
		displaylinkedlist2(stack_a->top);
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


// should not work
//  should return "Error\n"
// ./push_swap 1 3 dog 35 80 -3 
// ./push_swap a

 //this need error? To check this test case
// ./push_swap 1 2 3 5 67b778 947
// .push_swap " 12 4 6 8 54fhd 4354"
// ./push_swap 1 --    45 32 


// The program should NOT work if it encounters a double number
// ./push_swap 1 3 58 9 3
// ./push_swap 3 03
// ./push_swap " 49 128     50 38   49"
// these examples should return "Error\n"

// ./push_swap "95 99 -9 10 9"
// this example should work because -9 & 9 are not equal

// The program should work with INT MAX & INT MIN
// ./push_swap 2147483647 2 4 7
// ./push_swap 99 -2147483648 23 545
// ./push_swap "2147483647 843 56544 24394"
// these examples should work and sort your list

// should not work since more than max
// ./push_swap 54867543867438 3
// ./push_swap -2147483647765 4 5
// ./push_swap "214748364748385 28 47 29"
// these examples should return "Error

// Nothing has been specified when strings and int are mixed. It's up to you what you want to do
// not done
// ./push_swap "1 2 4 3" 76 90 "348 05
