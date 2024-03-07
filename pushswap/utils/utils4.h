/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:21:14 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:21:15 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS4_H
# define UTILS4_H

# include "utils.h"
# include "operations.h"
# include "operations2.h"
# include "operations3.h"

void	initstack(t_stack *stack, int num);
void	bringtobot(t_stack *stack, int *numberofop);
void	init3_element(t_element3 *element3);

#endif
