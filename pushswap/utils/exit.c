/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:23:06 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:23:06 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	exitsafe(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*prev;
	t_node	*curr;
	int		i;
	int		size;

	size = ft_lstsize2(stack_a->top);
	i = 0;
	curr = stack_a->top;
	while (size > i)
	{
		prev = curr;
		curr = curr ->next;
		free(prev);
		i ++;
	}
	size = ft_lstsize2(stack_b->top);
	i = 0;
	curr = stack_b->top;
	while (size > i)
	{
		prev = curr;
		curr = curr ->next;
		free(prev);
		i ++;
	}
}
