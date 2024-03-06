
void sort5(t_stack stack_a, t_stack stack_b)
{
	printf("top:%d, 2nd top:%d\n", (stack_a.top)->value, (stack_a.sec)->value );

	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	// printf( "a smallest:%d\n" , scanSmallestNum(&stack_a));
	// printf( "a 2nd smallest:%d\n" , scan2SmallestNum(&stack_a));

	// printf( "b smallest:%d\n" , scanSmallestNum(&stack_b));
	// printf( "b 2nd smallest:%d\n" , scan2SmallestNum(&stack_b));

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

			// if (stack_b.bot->value < stack_b.top->value)
				// rr(&stack_a, &stack_b);
			// else
				rotate_stack(&stack_a);
			
			// if (stack_b.bot->value < stack_b.top->value)
				// ss(&stack_a, &stack_b);
			// else
				swap_top_two(&stack_a);
		
			// if (stack_b.bot->value < stack_b.top->value)
			// 	rrr(&stack_a, &stack_b);
			// else
				reverse_rotate_stack(&stack_a);
		}
	}

	// displaystack(&stack_a);
	// displaystack(&stack_b);


	while (stack_b.top != NULL)
	{
		if (stack_a.top->value > stack_b.top->value)
			pa(&stack_a, &stack_b);	
		else
			rotate_stack(&stack_a);
	}
	while(stack_a.top->value != scanSmallestNum(&stack_a))
	{
		reverse_rotate_stack(&stack_a);
	}




	// displaystack(&stack_a);
	if (stackissorted(&stack_a) == 0)
		printf("\n\nsorted\n");
	else
		printf("not sorted\n");
	displaystack(&stack_a);
}


/* original
void sort5(t_stack stack_a, t_stack stack_b)
{
	printf("top:%d, 2nd top:%d\n", (stack_a.top)->value, (stack_a.sec)->value );

	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	// printf( "a smallest:%d\n" , scanSmallestNum(&stack_a));
	// printf( "a 2nd smallest:%d\n" , scan2SmallestNum(&stack_a));

	// printf( "b smallest:%d\n" , scanSmallestNum(&stack_b));
	// printf( "b 2nd smallest:%d\n" , scan2SmallestNum(&stack_b));

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

			// if (stack_b.bot->value < stack_b.top->value)
				// rr(&stack_a, &stack_b);
			// else
				rotate_stack(&stack_a);
			
			// if (stack_b.bot->value < stack_b.top->value)
				// ss(&stack_a, &stack_b);
			// else
				swap_top_two(&stack_a);
		
			// if (stack_b.bot->value < stack_b.top->value)
			// 	rrr(&stack_a, &stack_b);
			// else
				reverse_rotate_stack(&stack_a);
		}
	}

	// displaystack(&stack_a);
	// displaystack(&stack_b);


	while (stack_b.top != NULL)
	{
		if (stack_a.top->value > stack_b.top->value)
			pa(&stack_a, &stack_b);	
		else
			rotate_stack(&stack_a);
	}
	while(stack_a.top->value != scanSmallestNum(&stack_a))
	{
		reverse_rotate_stack(&stack_a);
	}




	// displaystack(&stack_a);
	if (stackissorted(&stack_a) == 0)
		printf("\n\nsorted\n");
	else
		printf("not sorted\n");
	displaystack(&stack_a);
}
*/


// the one below is somewhat broken. 12345 breaks
// 25134 works with 12 ops, taking 3 and 2.
// the logic is taking the smallest twice given i only see top, next, bot

/*
The algo: 
1. Scan the 3 items: top, sec, bot
2. Push the smallest item and rotate accordingly if required
3. Re-scan the 3 items again
4. Push the smallest item and rotate accordinly if required
5. Use sort 3 to sort both stacks
6. Push back to stack a

Issue: 
1. 25134
Takes 12 steps to finish sorting
2. There may be issue with 1 2345
*/
void sort5(t_stack stack_a, t_stack stack_b, int *numberofop)
{
	
	// printf("top:%d, 2nd top:%d bot:%d\n\n", (stack_a.top)->value, (stack_a.sec)->value,(stack_a.bot)->value );

	// printf( "a smallest:%d\n" , scanSmallestNum(&stack_a));
	// printf( "a 2nd smallest:%d\n" , scan2SmallestNum(&stack_a));

	// printf( "a 2nd biggest:%d\n" , scan2largestNum(&stack_a));
	// printf( "largest:%d\n" , scanlargestNum(&stack_a));

	// printf("\n\nfor fun %p\n", stack_b.top);

	// int firstvalue; 
	// int secondvalue; 

	//i think if it is at last, and next, still ok. We will test this out

	// case 1: 1 and 5
	// case 2: 1 and 2
	// case 3: 4 and 5


	// Moving stuff to stack b
	// try grabbing the smallest value for both times
	// top is the smallest out of the 3
	if 
	((stack_a.top)->value < (stack_a.sec)->value && (stack_a.top)->value < (stack_a.bot)->value)
	{
		pb(&stack_a, &stack_b, numberofop);

		// top is the smallest out of the 3
		if 
		((stack_a.top)->value < (stack_a.sec)->value && (stack_a.top)->value < (stack_a.bot)->value)
		{
			pb(&stack_a, &stack_b, numberofop);
		}
		// second element is the smallest
		else if
		((stack_a.sec)->value < (stack_a.top)->value && (stack_a.sec)->value < (stack_a.bot)->value)
		{
			rotate_stack(&stack_a, numberofop);
			pb(&stack_a, &stack_b, numberofop);
		}
		// bot is the smallest
		else if
		((stack_a.bot)->value < (stack_a.top)->value && (stack_a.bot)->value < (stack_a.sec)->value)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			pb(&stack_a, &stack_b,numberofop);
		}
	}
	// second element is the smallest
	else if
	((stack_a.sec)->value < (stack_a.top)->value && (stack_a.sec)->value < (stack_a.bot)->value)
	{
		rotate_stack(&stack_a, numberofop);
		pb(&stack_a, &stack_b, numberofop);

		// top is the smallest out of the 3
		if 
		((stack_a.top)->value < (stack_a.sec)->value && (stack_a.top)->value < (stack_a.bot)->value)
		{
			pb(&stack_a, &stack_b, numberofop);
		}
		// second element is the smallest
		else if
		((stack_a.sec)->value < (stack_a.top)->value && (stack_a.sec)->value < (stack_a.bot)->value)
		{
			rotate_stack(&stack_a, numberofop);
			pb(&stack_a, &stack_b, numberofop);
		}
		// bot is the smallest
		else if
		((stack_a.bot)->value < (stack_a.top)->value && (stack_a.bot)->value < (stack_a.sec)->value)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			pb(&stack_a, &stack_b, numberofop);
		}

	}
	// bot is the smallest
	else if
	((stack_a.bot)->value < (stack_a.top)->value && (stack_a.bot)->value < (stack_a.sec)->value)
	{
		reverse_rotate_stack(&stack_a, numberofop);
		pb(&stack_a, &stack_b, numberofop);

		if 
		((stack_a.top)->value < (stack_a.sec)->value && (stack_a.top)->value < (stack_a.bot)->value)
		{
			pb(&stack_a, &stack_b, numberofop);
		}
		// second element is the smallest
		else if
		((stack_a.sec)->value < (stack_a.top)->value && (stack_a.sec)->value < (stack_a.bot)->value)
		{
			rotate_stack(&stack_a, numberofop);
			pb(&stack_a, &stack_b, numberofop);
		}
		// bot is the smallest
		else if
		((stack_a.bot)->value < (stack_a.top)->value && (stack_a.bot)->value < (stack_a.sec)->value)
		{
			reverse_rotate_stack(&stack_a, numberofop);
			pb(&stack_a, &stack_b, numberofop);
		}
	}
	printf("After shifting to B:\n");
	displaystack(&stack_b);

	sort3(&stack_a, &stack_b, numberofop);
	displaystack(&stack_a);
	displaystack(&stack_b);
	printf("finished sorting a and b\n");

	while (stack_b.top != NULL)
	{
		if (stack_a.top->value > stack_b.top->value)
			pa(&stack_a, &stack_b, numberofop);	
		else
			rotate_stack(&stack_a, numberofop);
	}
	while(stack_a.top->value != scanSmallestNum(&stack_a))
	{
		reverse_rotate_stack(&stack_a, numberofop);
	}
	displaystack(&stack_a);
	displaystack(&stack_b);
	printf("Pushed back to stack a\n");
	
	printf("moves: %d", *numberofop);

	/*Get the largest or smallest value first*/
	// scanSmallestNum(&stack_a)
	// scanlargestNum(&stack_a)

	// i will need a way to get it via compute



	// if the first number is 1 or 5
	// if 
	// ( 
	// 	(stack_a.top)->value == scanlargestNum(&stack_a) ||
	// 	(stack_a.top)->value == scanSmallestNum(&stack_a)
	// )
	// {

	// 	// grab it off from the stack	
	// 	firstvalue = (stack_a.top)->value;
	// 	printf("first value :%d", firstvalue);
	// 	pb(&stack_a, &stack_b);

	// 	// if the first number is 5, top of stack is 1 or 4
	// 	if 
	// 	(
	// 		(firstvalue == scanlargestNum(&stack_a) 
	// 		&&
	// 		(stack_a.top) -> value == scanSmallestNum(&stack_a))
	// 		||
	// 		(firstvalue == scanlargestNum(&stack_a) 
	// 		&&
	// 		(stack_a.top) -> value == scan2largestNum(&stack_a)
	// 		)
	// 	)
	// 	{
	// 		secondvalue = (stack_a.top)->value;
	// 		printf("second value :%d", secondvalue);
	// 		pb(&stack_a, &stack_b);
	// 	}
	// 	// if the first number is 1 and the top number of stack is 5 or 2
	// 	else if
	// 	(
	// 		(firstvalue == scanSmallestNum(&stack_a) 
	// 		&&
	// 		(stack_a.top) -> value == scanlargestNum(&stack_a))
	// 		||
	// 		(firstvalue == scanSmallestNum(&stack_a) 
	// 		&&
	// 		(stack_a.top) -> value == scan2SmallestNum(&stack_a)
	// 		)
	// 	)
	// 	{
	// 		secondvalue = (stack_a.top)->value;
	// 		printf("second value :%d", secondvalue);
	// 		pb(&stack_a, &stack_b);

	// 	}
	// 	else
	// 	{
	// 		// need to do something
	// 		// what if the numbers are not 1 and 2
	// 		// what if the number is not 1 and 5
	// 		// what if the number is not 4 and 5

	// 		// 1 and 4 will be too much to grab.
	// 	}

	// }
	// else
	// {
	// 	// what if the number at top is not 1 or 5
	// }


	

/* SORT 3
	// sorting 3 numbers in stack a
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

			// if (stack_b.bot->value < stack_b.top->value)
				// rr(&stack_a, &stack_b);
			// else
				rotate_stack(&stack_a);
			
			// if (stack_b.bot->value < stack_b.top->value)
				// ss(&stack_a, &stack_b);
			// else
				swap_top_two(&stack_a);
		
			// if (stack_b.bot->value < stack_b.top->value)
			// 	rrr(&stack_a, &stack_b);
			// else
				reverse_rotate_stack(&stack_a);
		}
	}
*/
	// displaystack(&stack_a);
	// displaystack(&stack_b);


/*
	Loop stack a and insert items from stack b
	while (stack_b.top != NULL)
	{
		if (stack_a.top->value > stack_b.top->value)
			pa(&stack_a, &stack_b);	
		else
			rotate_stack(&stack_a);
	}
	while(stack_a.top->value != scanSmallestNum(&stack_a))
	{
		reverse_rotate_stack(&stack_a);
	}
*/


	/*
	// check if it is sorted
	if (stackissorted(&stack_a) == 0)
		printf("\n\nsorted\n");
	else
		printf("not sorted\n");
	displaystack(&stack_a);
	*/
}
