#include "utils.h"
#include <stdio.h>

/* for stack*/

#define MAX_SIZE 100

// Define a stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
int_fast16_t isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an item onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push %d onto the stack.\n", value);
    } else {
        stack->items[++stack->top] = value;
    }
}

// Pop an item from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1; // Error value
    } else {
        return stack->items[stack->top--];
    }
}

// Peek at the top item of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Error value
    } else {
        return stack->items[stack->top];
    }
}

void print_binary(signed char num) {
    for (int i = 7; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
}

int main(int argc, char *argv[])
{
    signed char 	number;
	int 			i;
	struct Stack	stack;

	i = 1;
    initialize(&stack);

	while (argc > i)
	{
		number = ft_atoi(argv[i]);
		print_binary(number);
		push(&stack, number);
		printf("\n");
		
		i++;
	}

	while (!isEmpty(&stack))
	{
		number = pop(&stack);
		printf("num:%d\n", number);
	}



    return 0;
}

// gcc -o main main.c  utils.c
// 2 6 7 11 3
// 22 5 1 4 20
// >./main 2 1 3 6 5 8