// #include "./utils/utils.h"
#include "./utils/utils2.h"
#include "./utils/timsort.h"
#include "./utils/operations.h"
#include "./utils/operations2.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	printf("number of argc:%d\n\n", argc);

	// printf("minrun:%d\n", calculate_minrun(argc-1));


	i = 1;
	initstack(&stack_a);
	initstack(&stack_b);

	while (argv[i])
	{
		addtoback(&stack_a, ft_atoi(argv[i]));
		i++;
	}

	t_node *head = stack_a.top;
	// printf("count elements in stack%d\n", countElementsinStack(head) );
	// pb(&stack_a, &stack_b);
	// head = stack_a.top;
	// printf("count elements in stack%d\n", countElementsinStack(head) );

	// To count min run first
	int numofelements = countElementsinStack(head);
	int minrun = calculate_minrun(numofelements);
	printf("minrun:%d\n", minrun);

	int numofrun = (argc -1) / minrun;
	printf("number of runs that will be created:%d \n", numofrun);

	// less than critical number of 64
	if (numofrun == 1)
	{

	}

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
