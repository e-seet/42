/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:22:35 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:22:35 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT3_H
# define SORT3_H

# include "../utils/operations.h"
# include "../utils/operations2.h"
# include "../utils/utils.h"
# include "../utils/utils4.h"
# include "../utils/exit.h"

void	find3_numbers(t_node *head, t_element3 *element3);
void	sort5elementstop3(t_stack *stack_a, int *numberofop,
			t_element3 *element3);
void	sort5elementstop3_2(t_stack *stack_a, int *numberofop,
			t_element3 *element3);

void	sort5elementstop3v1(t_stack *stack_a, int *numberofop,
			t_element3 *element3);

// int		sort3wrapper(t_stack *stack_a, t_stack *stack_b, int *numberofop);
int		sort3wrapper(t_stack *stack_a, t_stack *stack_b,
			int *numberofop, int sorttype);

#endif
