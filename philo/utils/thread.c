/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:19:21 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:19:22 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	breakfunction(struct s_philo *philo)
{
	if (philo->died == 1)
	{
		printf("%ld %d died\n", philo->time_of_death
			- philo->start, philo->id);
		return (1);
	}
	else if (philo->stop == 1)
	{
		printf("%ld %d stopped\n", philo->curr - philo->start, philo->id);
		return (1);
	}
	else
		return (0);
}

void	routine(struct s_philo *philo)
{
	if (philo->status == 1)
		handle_philo_sleeping(philo);
	else if (philo->status == 2)
		handle_philo_thinking(philo);
	else if (philo->status == 3)
		handle_philo_eating(philo);
	else if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id != philo->max) && (philo->id % 2 == 1))
		handle_odd_philo_eating(philo);
	else if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id != philo->max) && (philo->id % 2 == 0))
		handle_odd_philo_sleeping(philo);
	else if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id == philo->max))
		handle_odd_philo_thinking(philo);
	else if (philo->status == 0 && (philo->max % 2 == 0)
		&& (philo->id % 2 == 0))
		handle_even_philo_eating(philo);
	else if (philo->status == 0 && (philo->max % 2 == 0)
		&& (philo->id % 2 == 1))
		handle_even_philo_sleeping(philo);
}

void	*thread_function(void *arg)
{
	struct s_philo	*philo;
	int				breakval;

	philo = (struct s_philo *) arg;
	while (1)
	{
		update_current_time_now(philo);
		breakval = breakfunction(philo);
		if (breakval == 1)
			break ;
		routine(philo);
	}
	return (NULL);
}
