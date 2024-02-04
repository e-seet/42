#include "utils.h"

void initStack(t_stack *stack)
{
    stack->top = NULL; // Set the top to NULL indicating the stack is empty
}

int isEmpty(t_stack *stack)
{
    return stack->top == NULL;
}

void push(t_stack *stack, int value)
{
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    if (newNode == NULL)
	{
        printf("Failed to allocate memory.\n");
        return;
    }
    newNode->value = value;
    newNode->next = stack->top; // New node points to the current top
    stack->top = newNode;       // Stack top now points to the new node
}

int pop(t_stack *stack)
{
    if (isEmpty(stack))
	{
        printf("Stack is empty.\n");
        return -1; // Assuming -1 is not a valid data, indicating error
    }
    t_node *temp = stack->top;  // Temp pointer to top node
    int poppedValue = temp->value;
    stack->top = temp->next;    // Update top to next node
    free(temp);                 // Free the popped node
    return poppedValue;
}


// void sa(t_stack *a); // Swap the first 2 elements at the top of stack a
// void sb(t_stack *b); // Swap the first 2 elements at the top of stack b
// void ss(t_stack *a, t_stack *b); // sa and sb at the same time

// void pa(t_stack *a, t_stack *b); // Take the first element at the top of b and put it at the top of a
// void pb(t_stack *a, t_stack *b); // Take the first element at the top of a and put it at the top of b

// void ra(t_stack *a); // Shift up all elements of stack a by 1
// void rb(t_stack *b); // Shift up all elements of stack b by 1
// void rr(t_stack *a, t_stack *b); // ra and rb at the same time

// void rra(t_stack *a); // Shift down all elements of stack a by 1
// void rrb(t_stack *b); // Shift down all elements of stack b by 1
// void rrr(t_stack *a, t_stack *b); // rra and rrb at the same time
