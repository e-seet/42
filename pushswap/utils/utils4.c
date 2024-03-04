#include "utils4.h"

void	initstack(t_stack *stack, int num)
{
	stack->top = NULL;
	stack->bot = NULL;
	stack->numofelements = -1;
	stack->alpha = num;
}

void	bringtobot(t_stack *stack, int *numberofop)
{
	rotate_stack(stack, numberofop);
	rotate_stack(stack, numberofop);
}
