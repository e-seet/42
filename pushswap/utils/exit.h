/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:23:08 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:23:08 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H
# include "../utils/utils.h"

void	exitsafe(t_stack *stack_a, t_stack *stack_b);
void	freestrs(char **strs, int internal);

#endif
