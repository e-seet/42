/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:22:07 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:22:07 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations2.h"

// break off the last node
// set the 2nd last node's next to null [when 1]
// Else, return the last node.
// t_node	*ft_rralastnode(t_node *head, int tonull, t_Stack *stack)
t_node	*ft_rralastnode(t_node *head, t_stack *stack)
{
	t_node	*prev;
	t_node	*curr;

	curr = head;
	while (curr->next != head)
	{
		prev = curr;
		curr = curr->next;
	}
	stack->bot = prev;
	stack->top = curr;
	return (curr);
}

// Shift down all elements of stack by 1
void	reverse_rotate_stack(t_stack *stack, int *numberofop, int print)
{
	t_node	*head;
	t_node	*lastnode;

	if (stack -> alpha == 0 && print == 0)
		write(1, "rra\n", 4);
	else if (stack -> alpha == 1 && print == 0)
		write(1, "rrb\n", 4);
	head = stack->top;
	lastnode = ft_rralastnode(head, stack);
	lastnode -> next = head;
	stack->top = lastnode;
	*numberofop = *numberofop + 1;
}

// rra and rrb at the same time
void	rrr(t_stack *a, t_stack *b, int *numberofop)
{
	write(1, "rrr\n", 4);
	reverse_rotate_stack(a, numberofop, 1);
	reverse_rotate_stack(b, numberofop, 1);
	*numberofop = *numberofop - 1;
}

// Shift down all elements of stack a by 1
// void rra(t_stack *a)
// {
// 	t_node	*head;
// 	t_node	*lastnode;

// 	head = a->top;
// 	lastnode = ft_rralastnode(head, 1);
// 	printf("check my lastnode:%d\n", lastnode->value);
// 	lastnode -> next = head;
// 	head = lastnode;
// 	a->top = head;
// 	lastnode = ft_rralastnode(head, 0);
// }

// Shift down all elements of stack b by 1
// void rrb(t_stack *b)
// {
// 	t_node	*head;
// 	t_node	*lastnode;

// 	head = b->top;
// 	lastnode = ft_rralastnode(head, 1);
// 	printf("check my lastnode:%d\n", lastnode->value);
// 	lastnode -> next = head;
// 	head = lastnode;
// 	b->top = head;
// 	lastnode = ft_rralastnode(head, 0);
// }
