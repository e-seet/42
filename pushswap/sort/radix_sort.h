/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:22:27 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:22:28 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_SORT_H
# define RADIX_SORT_H

# include "../utils/operations.h"
# include "../utils/operations2.h"
# include "../utils/operations3.h"
# include "../utils/utils.h"
# include "../utils/utils2.h"
# include "../utils/utils3.h"
# include "../utils/exit.h"
// # include "../utils/utils4.h"

int		radix_sort_wrapper(t_stack *stack_a,
			t_stack *stack_b, int *numberofop);
void	setpos(t_stack *stack_a, int i);
void	radix_sort(t_stack *stack_a, t_stack *stack_b, int *numberofop);

#endif
