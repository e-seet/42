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
