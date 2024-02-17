# include <limits.h>
# include "sort3.h"
// # include "../utils/utils.h"

void init3Element(s_element3 *element3)
{
	element3->smallest =  INT_MAX;
	element3->middle =  INT_MAX;
	element3->largest = INT_MIN;

	element3->smallestpos  =  -1;
	element3->middlepos  = -1;
	element3->largestpos  = -1;
}

void find3Numbers(t_node *head, s_element3 *element3)
{
	int temp;

	element3->smallest = head->value;
	element3->middle = head->next->value;
	element3->largest = head->next->next->value;

	if (element3->smallest > element3->middle)
	{
		temp = element3->smallest;
		element3->smallest = element3->middle;
		element3->middle = temp;
	}
	if (element3->smallest > element3->largest)
	{
		temp = element3->smallest;
		element3->smallest = element3->largest;
		element3->largest = temp;
	}
	if (element3->middle > element3->largest)
	{
		temp = element3->middle;
		element3->middle = element3->largest;
		element3->largest = temp;
	}
}

void find3NumbersPos(t_stack *stack_a, s_element3 *element3)
{
	element3->smallestpos = scanNumPos(stack_a, element3->smallest);
	element3->middlepos = scanNumPos(stack_a, element3->middle);
	element3->largestpos = scanNumPos(stack_a, element3->largest);
}


void sort5elementstop3(t_stack *stack_a, int *numberofop, s_element3 *element3)
{
	// c1
	if (element3->smallestpos == 0 && element3->largestpos == 2)
	{
	}
	//c2
	else if (element3->smallestpos == 0 && element3->largestpos == 1)
	{
		rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
	}
	// c3
	else if (element3->smallestpos == 1 && element3->largestpos == 2)
	{
		swap_top_two(stack_a, numberofop);
	}
	// c4
	// remove top, swap top two, return my top, swap top two
	else if (element3->smallestpos == 2 && element3->largestpos == 1)
	{
		rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
	}
	// c5
	else if (element3->smallestpos == 1 && element3->largestpos == 0)
	{
		swap_top_two(stack_a, numberofop);
		rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
	}
	// c6
	else if (element3->smallestpos == 2 && element3->largestpos == 0)
	{
		swap_top_two(stack_a, numberofop);
		rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
		reverse_rotate_stack(stack_a, numberofop);
		swap_top_two(stack_a, numberofop);
	}

	printf("final number of ops:%d\n", *numberofop);
}