/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:22:48 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:22:48 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT5_H
# define SORT5_H

# include "../utils/operations.h"
# include "../utils/operations2.h"
# include "../utils/utils.h"
# include "../utils/utils2.h"
# include "../utils/utils3.h"
# include "../utils/utils4.h"
# include "./sort3.h"
# include "./sort5c.h"
# include "../utils/exit.h"

void	sort_5_top3(t_element5 *element5, t_stack *stack_a, int *numberofop);
// int		sort5wrapper(t_stack *stack_a, t_stack *stack_b, int *numberofop);
int		sort5wrapper(t_stack *stack_a, t_stack *stack_b, int *numberofop);
void	find5_numbers(t_node *head, t_element5 *element5, t_stack *stack_a);
void	find5_numbers_p2(t_node *head, t_element5 *element5, t_stack *stack_a);

// void	sort5(t_stack *stack_a, t_stack *stack_b, int *numberofop,
// 			t_element5 *element5);
void	sort5(t_stack *stack_a, int *numberofop,
			t_element5 *element5);
// void	init5_element(t_element5 *element5);
// int		ft_lstsize_modified(t_node *head);
#endif
