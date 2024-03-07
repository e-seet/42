/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:21:28 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:21:29 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_H
# define UTILS2_H

# include "utils.h"
# include "utils3.h"

// int	count_elements_in_stack(t_node *head);
int	stack_is_sorted(t_stack *stack);
int	stack_is_sorted2(t_stack *stack);
int	ft_atoi_modified(const char *str, int *err);
int	has_duplicate(t_node *head);
int	ft_lstsize_modified(t_node *head);

#endif
