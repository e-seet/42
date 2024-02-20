#include "timsort.h"

void insertSort()
{
	printf("insert sort\n");
	
	// 

}

void mergeSort2()
{

}

// go up
// stop when curr is smaller than prev.
int precompute1(t_node *head)
{
	int		i;
	int		c;
	int		value;
	// t_node	*prev;
	t_node	*curr;
	// t_node	*next;
	
	printf("precomp\n");
	i = 0;
	c = 0;
	value = head->value;
	curr = head -> prev;

	while (curr->value > value)
	{
		curr = curr ->prev;
		i = i +2;
		c = c + 1;
	}
	i = i + c ; // to move it back to original spot
	printf("rotate up to right place, need:%d moves\n", i);
	return (i);
}

// go down. May not need it
// stop when next node is bigger than current value
int precompute2(t_node	*head)
{
	int		i;
	int		limit;
	int		c;
	int		value;
	t_node	*curr;
	// t_node	*next;
	
	printf("precomp\n");
	i = 0;
	c = 0;
	limit = 10;
	value = head->value;
	curr = head -> next;

	while (value > curr -> value)
	{
		curr = curr ->next;
		i = i +2;
		c = c + 1;
		if (i + c > limit)
			break;
	}
	i = i + c ; // to move it back to original spot?
	printf("rotate up to right place, need:%d moves. If >10 over limit\n", i);
	return (i);
}

// sorting to the bottom half of the stack
// given the node at the bottom of th estack
// smallest is at the bottom of the stack
// int precompute3(t_node *head)
// {
// 	int i;
// 	int value;

// 	i = 1; //sort once
// 	t_node	*curr;
	
// 	i = 1;
// 	if (head != NULL)
// 		curr = head;
// 	else
// 		return (i);
// 	value = curr ->value;

// 	// while ()
// 	// {
// 	// 	i++;
// 	// 	curr = curr -> prev;
// 	// }
// 	printf("rotate down to the right place, need:%d moves\n", i);
// 	return (i);
// }

// sorting to the top half of the stack
int precompute4(t_node *head)
{
	int		i;
	int		value;
	t_node	*prev;
	t_node	*curr;
	
	i = 1;
	if (head != NULL)
		curr = head;
	else
		return (i);
	value = curr -> value;
	prev = head -> prev;
	while (value > prev -> value && curr -> value > value)
	{
		i++;
		curr = curr -> prev;
		prev = prev -> prev;
	}
	printf("rotate down to the right place, need:%d moves", i);
	return (i);
}

// algo to calculate the miin run
int calculate_minrun(int n)
{
    int r = 0;
	// int iter = 0;

    while (n >= 64)
	{
		// printf("iter: %d\n", iter);
        // printf("n value:%d \n", n);
		r = r | (n & 1);
		// printf("r value:%d\n", r);
        n >>= 1;
        // printf("n value:%d \n\n", n);
		// iter ++;
    }
	// printf("final n:%d, final r: %d\n\n", n, r );
    return n + r;
}



void tim_sort(t_stack *stack_a, t_stack *stack_b, int *numberofop)
{
	int minrun;
	int timeout; //temp variable for now

	timeout = 0;
	minrun = calculate_minrun(count_elements_in_stack((stack_a->top)));
	
	// number of stacks theoretically creating

	printf("printing stuff for fun now: %p, %p, %p %d\n\n", stack_a->top, stack_b->top, numberofop, minrun);


	// check that it is empty
	while (stack_is_sorted(stack_a) != 0 && timeout < 1)
	{
		//pre-compute1: top of stack to top
		precompute1(stack_a->top);
		precompute2(stack_a->top); // no need to go down if it is 0.
		// precompute3(stack_b->top);
		// precompute4(stack_b->top);
		// precomputer2: pb + Put at top half of stack
		//precomputer3: pb + Put at bottom half of stack

		timeout = timeout+ 1;
	}



}

// run = consecutive increasing or decrasing
// 1.If the run is less than a chosen "minrun" size, TimSort uses InsertionSort to bulk it up to minrun elements.

//
// 2.The value of minrun is calculated such that, where n is the size of an array, n/minrun is a power of two or slightly less than a power of two, thus ensuring balanced merges on random data.

// Example
// Insertion sort:
// If the run is 33 [33 items consecutively increasing / decreasing] and minrun is 50,
// we use insertion sort and grab another (50 - 33 = 17) 17 elements to add in.

// Get sorted runs and merge them together.
// if 7 numbers are consecutive from run b, it looks for first element in run a and try to find it in run b. Everything between .. and .. can be copied over.

// Rules for merging
// 1.A > B + C
// 2.B > C

// Last run < Second to last run
// Last run + Second to last run < Third to last run
