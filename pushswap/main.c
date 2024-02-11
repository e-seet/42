// #include "./utils/utils.h"
#include "./utils/utils2.h"
#include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"

/*
void sort3(t_stack stack_a)
{
	printf("top:%d, next:%d, bot:%d. \n\n", (stack_a.top)->value, (stack_a.sec)->value, (stack_a.bot)->value);

	if ( (stack_a.bot)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.top)->value)
	{
		printf("case 1\n");
	}
	else if ((stack_a.bot)->value > (stack_a.top)->value && (stack_a.top)->value > (stack_a.sec)->value)
	{
		printf("case 3\n");

		swap_top_two(&stack_a);
	}
	else if ( ((stack_a.sec)->value > (stack_a.top)->value) && (stack_a.top->value > (stack_a.bot)->value) )
	{
		printf("case 4\n");

		reverse_rotate_stack(&stack_a);
	}
	// take note that all 3 of them need a rotate_stack first
	else 
	{
		if ((stack_a.top)->value > (stack_a.bot)->value &&  (stack_a.bot)->value > (stack_a.sec)->value)
		{
			printf("case 5\n");

			rotate_stack(&stack_a);
		}
		// take note the latter 2 have a common swap_top_two
		else if ((stack_a.top)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.bot)->value)
		{
			printf("case 6\n");
			
			rotate_stack(&stack_a);

			swap_top_two(&stack_a);
		}
		else
		{
			printf("case 2\n");

			rotate_stack(&stack_a);
			swap_top_two(&stack_a);
			reverse_rotate_stack(&stack_a);
		}
	} 
}
*/

void sort5(t_stack stack_a, t_stack stack_b)
{
	printf("top:%d, 2nd top:%d", (stack_a.top)->value, (stack_a.sec)->value );
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	// displaystack(&stack_a);
	// displaystack(&stack_b);

	// printf( "a smallest:%d\n" , scanSmallestNum(&stack_a));
	// printf( "a 2nd smallest:%d\n" , scan2SmallestNum(&stack_a));


	// printf( "b smallest:%d\n" , scanSmallestNum(&stack_b));
	// printf( "b 2nd smallest:%d\n" , scan2SmallestNum(&stack_b));
	/*
	printf("stack a:\n");
	printf("top:%d\n", (stack_a.top)->value);
	printf("next:%d\n", (stack_a.sec)->value);
	printf("bot:%d\n\n", (stack_a.bot)->value);
	
	printf("stack b:\n");
	if ((stack_b.top) != NULL)
		printf("top:%d\n", (stack_b.top)->value);
	if ((stack_b.sec) != NULL)
		printf("next:%d\n", (stack_b.sec)->value);
	if ((stack_b.bot) != NULL)
		printf("bot:%d\n\n", (stack_b.bot)->value);

	printf("stack b\n");
	displaystack(&stack_b);
	printf("\n");
	*/

	if ( (stack_a.bot)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.top)->value)
	{
		printf("case 1\n");

		// sorting only stack b. I can use any of the methods.
		if ( (stack_b.top)->value > stack_b.bot ->value)
			swap_top_two(&stack_b);
	}
	else if ((stack_a.bot)->value > (stack_a.top)->value && (stack_a.top)->value > (stack_a.sec)->value)
	{
		printf("case 3\n");

		if (stack_b.top->value > stack_b.bot->value)
			ss(&stack_a, &stack_b);
		else
			swap_top_two(&stack_a);
	}
	else if ( ((stack_a.sec)->value > (stack_a.top)->value) && (stack_a.top->value > (stack_a.bot)->value) )
	{
		printf("case 4\n");

		if ((stack_b.top)->value > stack_b.bot ->value)
			rrr(&stack_a, &stack_b);
		else
			reverse_rotate_stack(&stack_a);
	}
	// take note that all 3 of them need a rotate_stack first
	else 
	{
		if ((stack_a.top)->value > (stack_a.bot)->value &&  (stack_a.bot)->value > (stack_a.sec)->value)
		{
			printf("case 5\n");

			if (stack_b.bot->value < stack_b.top->value)
				rr(&stack_a, &stack_b);
			else
				rotate_stack(&stack_a);
		}
		// take note case 2 and 6 have 2 common operations [rotate stack, swap top two].
		else if ((stack_a.top)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.bot)->value)
		{
			printf("case 6\n");
			
			rotate_stack(&stack_a);

			if (stack_b.bot->value < stack_b.top->value)
				ss(&stack_a, &stack_b);
			else
				swap_top_two(&stack_a);

		}
		else
		{
			printf("case 2\n");

			if (stack_b.bot->value < stack_b.top->value)
				rr(&stack_a, &stack_b);
			else
				rotate_stack(&stack_a);
			
			if (stack_b.bot->value < stack_b.top->value)
				ss(&stack_a, &stack_b);
			else
				swap_top_two(&stack_a);
		
			// if (stack_b.bot->value < stack_b.top->value)
			// 	rrr(&stack_a, &stack_b);
			// else
				reverse_rotate_stack(&stack_a);
		}
	}

	// By now: Stack a is sorted [smallest on top]. Stack B is sorted [smallest on top]


	// merging from stake b into stake a. 
	// We try if this works. IF not we need to find some algo
	
	while (stack_b.top != NULL)
	{
		if (stack_a.top->value > stack_b.top->value)
			pa(&stack_a, &stack_b);	
		else
			rotate_stack(&stack_a);
	}
	// displaystack(&stack_a);
	// displaystack(&stack_b);

	while(stack_a.top->value != scanSmallestNum(&stack_a))
	{
		reverse_rotate_stack(&stack_a);
	}

	displaystack(&stack_a);
	// displaystack(&stack_b);

	// pa(&stack_a, &stack_b);	
	// printf("stack b:\n");
	// if ((stack_b.top) != NULL)
	// 	printf("top:%d\n", (stack_b.top)->value);
	// else
	// 	printf("stack b top is null\n");
	// if ((stack_b.sec) != NULL)
	// 	printf("next:%d\n", (stack_b.sec)->value);
	// else
	// 	printf("stack b sec is null\n");
	// if ((stack_b.bot) != NULL)
	// 	printf("bot:%d\n\n", (stack_b.bot)->value);
	// else
	// 	printf("stack b bot is null\n");
	
}

int	main(int argc, char *argv[])
{
	int			i;
	t_stack		stack_a;
	t_stack		stack_b;
	// s_datastore	stackdetails;

	printf("c argc:%d\n\n", argc);

	// printf("minrun:%d\n", calculate_minrun(argc-1));
	// stackdetails.stack_a_last = ft_atoi(argv[1]);
	// stackdetails.stack_a_top = ft_atoi(argv[argc-1]);

	// printf("top of stack: %d, bottom of stack:%d\n", stackdetails.stack_a_top, stackdetails.stack_a_last);


	i = 1;
	initstack(&stack_a);
	initstack(&stack_b);
	// initdatastore(&stackdetails);

	while (argv[i])
	{
		// addtoback(&stack_a, ft_atoi(argv[i]));
		// push(&stack_a, ft_atoi(argv[i]), &stackdetails );
		push(&stack_a, ft_atoi(argv[i]) );
		i++;
	}

	// displaystack(&stack_a);

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

	// we sort 3 numbers
	// sort3(stack_a);

	// displaystack(&stack_a);
	// printf("smalest 2nd:%d", scan2SmallestNum(&stack_a));

	sort5(stack_a, stack_b);
	// printf("after sorting\n");
	// displaystack(&stack_a);

	/*
	if (argc == 4)
	{
		printf("top:%d, next:%d, bot:%d. \n\n", (stack_a.top)->value, (stack_a.sec)->value, (stack_a.bot)->value);

		if ( (stack_a.bot)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.top)->value)
			printf("case 1\n");
		else if ((stack_a.bot)->value > (stack_a.top)->value && (stack_a.top)->value > (stack_a.sec)->value)
		{
			printf("case 3\n");

			swap_top_two(&stack_a);
		}
		else if ( ((stack_a.sec)->value > (stack_a.top)->value) && (stack_a.top->value > (stack_a.bot)->value) )
		{
			printf("case 4\n");

			reverse_rotate_stack(&stack_a);
		}
		// take note that all 3 of them need a rotate_stack first
		else 
		{
			if ((stack_a.top)->value > (stack_a.bot)->value &&  (stack_a.bot)->value > (stack_a.sec)->value)
			{
				printf("case 5\n");

				rotate_stack(&stack_a);
			}
			// take note the latter 2 have a common swap_top_two
			else if ((stack_a.top)->value > (stack_a.sec)->value && (stack_a.sec)->value > (stack_a.bot)->value)
			{
				printf("case 6\n");
				
				rotate_stack(&stack_a);

				swap_top_two(&stack_a);
			}
			else
			{
				printf("case 2\n");

				rotate_stack(&stack_a);
				swap_top_two(&stack_a);
				reverse_rotate_stack(&stack_a);
			}
		} 
		


		printf("top:%d, next:%d, bot:%d. \n\n", (stack_a.top)->value, (stack_a.sec)->value, (stack_a.bot)->value);
		displaystack(&stack_a);
	}
	*/


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

// if (!isEmpty(&myStack)) {
//     printf("Popped: %d\n", pop(&myStack));
// }

// /* for stack*/

// #define MAX_SIZE 100

// // Define a stack structure
// struct Stack {
//     int items[MAX_SIZE];
//     int top;
// };

// // Initialize the stack
// void initialize(struct Stack *stack) {
//     stack->top = -1;
// }

// // Check if the stack is empty
// int isEmpty(struct Stack *stack) {
//     return stack->top == -1;
// }

// // Check if the stack is full
// int_fast16_t isFull(struct Stack *stack) {
//     return stack->top == MAX_SIZE - 1;
// }

// // Push an item onto the stack
// void push(struct Stack *stack, int value) {
//     if (isFull(stack)) {
//         printf("Stack overflow. Cannot push %d onto the stack.\n", value);
//     } else {
//         stack->items[++stack->top] = value;
//     }
// }

// // Pop an item from the stack
// int pop(struct Stack *stack) {
//     if (isEmpty(stack)) {
//         printf("Stack underflow. Cannot pop from an empty stack.\n");
//         return -1; // Error value
//     } else {
//         return stack->items[stack->top--];
//     }
// }

// // Peek at the top item of the stack without removing it
// int peek(struct Stack *stack) {
//     if (isEmpty(stack)) {
//         printf("Stack is empty. Cannot peek.\n");
//         return -1; // Error value
//     } else {
//         return stack->items[stack->top];
//     }
// }

// void print_binary(signed char num) {
//     for (int i = 7; i >= 0; i--) {
//         putchar((num & (1 << i)) ? '1' : '0');
//     }
// }

// int main(int argc, char *argv[])
// {
//     signed char 	number;
// 	int 			i;
// 	struct Stack	stack;

// 	i = 1;
//     initialize(&stack);

// 	while (argc > i)
// 	{
// 		number = ft_atoi(argv[i]);
// 		print_binary(number);
// 		push(&stack, number);
// 		printf("\n");

// 		i++;
// 	}

// 	while (!isEmpty(&stack))
// 	{
// 		number = pop(&stack);
// 		printf("num:%d\n", number);
// 	}

//     return 0;
// }
