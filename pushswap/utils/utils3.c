#include "utils3.h"

// Function to display the elements in the linked list
// void	displaylinkedlist(t_node *head)
// {
// 	t_node	*current;
// 	int		i;
// 	int		size;

// 	i = 0;
// 	size = ft_lstsize2(head);
// 	current = head;
// 	printf("Linked List: ");
// 	while (size > i)
// 	{
// 		printf("\n%d  ", current->value);
// 		current = current->next;
// 		i ++;
// 	}
// 	printf("\nthe i number:%d\n", i);
// 	printf ("size of linked list:%d\n", ft_lstsize2(head));
// 	printf("\n\n");
// }

void	displaylinkedlist(t_node *head)
{
	t_node	*current;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize2(head);
	current = head;
	while (size > i)
	{
		current = current->next;
		i ++;
	}
}

// // Function to display the elements in the linked list
// void	displaylinkedlist2(t_node *head)
// {
// 	t_node	*current;
// 	int		i;
// 	int		size;

// 	size = ft_lstsize2(head);
// 	current = head;
// 	i = 0;
// 	if (current == NULL)
// 	{
// 		return ;
// 	}
// 	printf("Linked List2: ");
// 	while (size > i)
// 	{
// 		printf("\n%d  ", current->value);
// 		printf("+pos:%d  ", current->pos);
// 		printf("\nprev:%p  ", current->prev);
// 		printf("\ncurr:%p  ", current);
// 		printf("\nnext:%p  ", current->next);
// 		if (current == current->next || i > 8)
// 		{
// 			printf("con to breka\n");
// 			printf("curr == curr->Next or i > 6\n");
// 			break ;
// 		}
// 		current = current->next;
// 		i ++;
// 	}
// }

// Function to display the elements in the linked list
void	displaylinkedlist2(t_node *head)
{
	t_node	*current;
	int		i;
	int		size;

	size = ft_lstsize2(head);
	current = head;
	i = 0;
	if (current == NULL)
	{
		return ;
	}
	while (size > i)
	{
		if (current == current->next)
			break ;
		current = current->next;
		i ++;
	}
}

// // Function to display the elements in the linked list
// void	displaylinkedlist3(t_node *head)
// {
// 	t_node	*current;
// 	t_node	*prev;
// 	t_node	*next;
// 	int		i;
// 	int		size;

// 	printf("LL3\n");
// 	size = ft_lstsize2(head);
// 	current = head;
// 	prev = head->prev;
// 	next = current ->next;
// 	i = 0;
// 	if (current == NULL)
// 	{
// 		return ;
// 	}
// 	printf("Linked List: ");
// 	while (size > i)
// 	{
// 		if (current->prev == prev && current ->next == next)
// 			printf("all ok\n");
// 		else
// 		{
// 			printf("error\n");
// 			printf("curr%p | value: %d\n", current, current->value);
// 			if (current->prev != prev)
// 			{
// 				printf("prev:%p | value:%d\n", prev, prev->value);
// 				printf("curr ->prev %p | value:%d\n", current->prev,
// 					current->value);
// 			}
// 			if (current->next != next)
// 			{
// 				printf("curr ->next %p\n", current->next);
// 				printf("next: %p\n", next);
// 			}
// 			break ;
// 		}
// 		current = current->next;
// 		prev = prev->next;
// 		next = next->next;
// 		i ++;
// 	}
// 	printf("size:%d\n", size);
// 	printf("i:%d\n", i);
// }

//f
//f
// Function to display the elements in the linked list
void	displaylinkedlist3(t_node *head)
{
	t_node	*current;
	t_node	*prev;
	t_node	*next;
	int		i;

	current = head;
	prev = head->prev;
	next = current ->next;
	i = 0;
	if (current == NULL)
		return ;
	while (ft_lstsize2(head) > i)
	{
		if (current->prev == prev && current ->next == next)
			printf("all ok\n");
		else
		{
			perror("curr prev != prev or curr next != next");
			break ;
		}
		current = current->next;
		prev = prev->next;
		next = next->next;
		i ++;
	}
}

// Function to display the elements in the stack (linked list)
void	displaystack(t_stack *stack)
{
	printf("display linked list:\n");
	if (stack->top != NULL)
		displaylinkedlist(stack->top);
}
