/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:19:31 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:19:32 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	stopall(int num, struct s_philo **philos, int *allend)
{
	while (num --)
	{
		philos[num]->stop = 1;
		*allend = *allend + 1;
	}
}

void	check_if_any_died(int num, struct s_philo **philos, int *allend)
{
	int	num2;

	num2 = num;
	while (num --)
	{
		if (philos[num]->died == 1)
		{
			stopall(num2, philos, allend);
			break ;
		}
	}
}

void	check_if_all_ate(int num, struct s_philo **philos, int *allend)
{
	int	allate;
	int	num2;

	allate = 0;
	num2 = num;
	while (num2 --)
	{
		if (philos[num2]->num_must_eat == 0)
			allate ++;
	}
	if (allate == num)
		stopall(num, philos, allend);
}
