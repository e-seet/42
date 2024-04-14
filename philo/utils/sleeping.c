/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:19:04 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:19:05 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	unlock_mutex_sleeping(struct s_philo *philo)
{
	pthread_mutex_unlock(&philo->sleeping_mutex);
	pthread_mutex_unlock(philo->curr_routine_mutex);
}

void	lock_mutex_sleeping(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->sleeping_mutex);
	pthread_mutex_lock(philo->curr_routine_mutex);
}

void	handle_odd_philo_sleeping(struct s_philo *philo)
{
	lock_mutex_sleeping(philo);
	if (philo->status == 0 && philo->routinesemaphore[0] == 1
		&& (philo->max % 2 == 1) && (philo->id != philo->max)
		&& (philo->id % 2 == 0))
	{
		philo->last_meal_time = (philo->curr);
		printf("%ld %d is sleeping\n", philo->curr, philo->id);
		if (philo->time_to_sleep > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
			ft_usleep(philo->time_to_sleep);
		philo->status = 2;
		philo->routinesemaphore[0] = 0;
		philo->routinesemaphore[2] = 1;
	}
	unlock_mutex_sleeping(philo);
}

void	handle_even_philo_sleeping(struct s_philo *philo)
{
	lock_mutex_sleeping(philo);
	if (philo->status == 0 && philo->routinesemaphore[0] == 1
		&& (philo->max % 2 == 0) && (philo->id % 2 == 1))
	{
		printf("%ld %d is sleeping\n", philo->curr - philo->start, philo->id);
		philo->last_meal_time = (philo->curr);
		if (philo->time_to_sleep > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
			ft_usleep(philo->time_to_sleep);
		philo->status = 2;
		philo->routinesemaphore[0] = 0;
		philo->routinesemaphore[2] = 1;
	}
	unlock_mutex_sleeping(philo);
}

void	handle_philo_sleeping(struct s_philo *philo)
{
	int	elapsed;

	lock_mutex_sleeping(philo);
	if (philo->status == 1 && philo->routinesemaphore[1] == 1
	)
	{
		printf("%ld %d is sleeping\n", (philo->curr - philo->start), philo->id);
		if (((philo->curr) - philo->last_meal_time)
			+ philo->time_to_sleep > philo->time_to_die)
		{
			ft_usleep((philo->time_to_die)
				- ((philo->curr) - philo->last_meal_time));
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			elapsed = ft_usleep(philo->time_to_sleep);
			printf("%d sleep elapsed:%d\n", philo->id, elapsed);
		}
		philo->status = 2;
		philo->routinesemaphore[0] = 0;
		philo->routinesemaphore[2] = 1;
	}
	unlock_mutex_sleeping(philo);
}
