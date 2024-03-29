/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:21:18 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:21:19 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils4.h"

void	initstack(t_stack *stack, int num)
{
	stack->top = NULL;
	stack->bot = NULL;
	stack->numofelements = 0;
	stack->alpha = num;
}

void	bringtobot(t_stack *stack, int *numberofop)
{
	rotate_stack(stack, numberofop, 0);
	rotate_stack(stack, numberofop, 0);
}

void	init3_element(t_element3 *element3)
{
	element3->smallest = INT_MAX;
	element3->middle = INT_MAX;
	element3->largest = INT_MIN;
	element3->smallestpos = -1;
	element3->middlepos = -1;
	element3->largestpos = -1;
}
