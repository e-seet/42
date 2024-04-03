/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5c.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:22:52 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:22:53 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT5C_H
# define SORT5C_H

# include "../utils/operations.h"
# include "../utils/operations2.h"
# include "../utils/utils.h"
# include "../utils/utils2.h"
# include "../utils/utils4.h"
# include "./sort3.h"

void	sort5_case1(t_stack *stack_a, int *numberofop, t_element5 *element5);
void	sort5_case2(t_stack *stack_a, int *numberofop, t_element5 *element5);
void	sort5_case3(t_stack *stack_a, int *numberofop, t_element5 *element5);
void	sort5_case4(t_stack *stack_a, int *numberofop, t_element5 *element5);
void	sort5_case5(t_stack *stack_a, int *numberofop, t_element5 *element5);

#endif
