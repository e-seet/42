/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:22:13 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:22:14 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS3_H
# define OPERATIONS3_H

# include "utils.h"

void	pb_c2(t_stack *b, t_node	*topnode_a, t_node	*topnode_b);

void	pb(t_stack *a, t_stack *b, int *numberofop);

void	pa_c1(t_stack *b, t_node *topnode_a, t_node	*topnode_b);

void	pa(t_stack *a, t_stack *b, int *numberofop);

#endif
