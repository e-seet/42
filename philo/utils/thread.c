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
		pthread_mutex_lock(philo->printf_mutex);
		printf("%ld %d died\n", philo->time_of_death
			- philo->start, philo->id);
		pthread_mutex_unlock(philo->printf_mutex);
		return (1);
	}
	else if (philo->stop == 1)
	{
		pthread_mutex_lock(philo->printf_mutex);
		printf("%ld %d stopped\n", philo->curr - philo->start, philo->id);
		pthread_mutex_unlock(philo->printf_mutex);
		return (1);
	}
	else
		return (0);
}

void	routine(struct s_philo *philo)
{
	pthread_mutex_lock(philo->curr_routine_mutex);
	if (philo->status == 1)
	{
		// printf("\n philo sleeping\n");
		handle_philo_sleeping(philo);
	}
	else if (philo->status == 2)
	{
		// printf("\n philo thinking\n");
		handle_philo_thinking(philo);
	}
	else if (philo->status == 3)
	{
		// printf("\n philo eating\n");
		handle_philo_eating(philo);
	}
	else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id % 2 == 1))
	{
		// printf("\nodd philo eating\n");
		handle_odd_philo_eating(philo);
	}
	else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id % 2 == 0))
	{
		// printf("\nodd philo sleeping\n");
		handle_odd_philo_sleeping(philo);
	}
	else if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id == philo->max))
	{
		// printf("\nodd philo thinking\n");
		handle_odd_philo_thinking(philo);
	}
	else if (philo->status == 0 && (philo->max % 2 == 0)
		&& (philo->id % 2 == 0))
	{
		// printf("\neven philo eating\n");
		handle_even_philo_eating(philo);
	}
	else if (philo->status == 0 && (philo->max % 2 == 0)
		&& (philo->id % 2 == 1))
	{
		// printf("\neven philo sleeping\n");
		handle_even_philo_sleeping(philo);
	}
	ft_usleep(1);
	pthread_mutex_unlock(philo->curr_routine_mutex);
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
