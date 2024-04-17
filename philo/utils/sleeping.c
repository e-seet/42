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

void	handle_odd_philo_sleeping(struct s_philo *philo)
{
	// pthread_mutex_lock(philo->curr_routine_mutex);
	if (philo->status == 0 && philo->routinesemaphore[0] == 1
		&& (philo->max % 2 == 1) && (philo->id != philo->max)
		&& (philo->id % 2 == 0))
	{
		philo->last_meal_time = (philo->curr);
		pthread_mutex_lock(philo->printf_mutex);
		printf("%ld %d is sleeping\n", philo->curr, philo->id);
		pthread_mutex_unlock(philo->printf_mutex);
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
	// pthread_mutex_unlock(philo->curr_routine_mutex);

}

void	handle_even_philo_sleeping(struct s_philo *philo)
{
	// pthread_mutex_lock(philo->curr_routine_mutex);
	if (philo->status == 0 && philo->routinesemaphore[0] == 1
		&& (philo->max % 2 == 0) && (philo->id % 2 == 1))
	{
		pthread_mutex_lock(philo->printf_mutex);
		printf("%ld %d is sleeping\n", philo->curr - philo->start, philo->id);
		pthread_mutex_unlock(philo->printf_mutex);
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
	// pthread_mutex_unlock(philo->curr_routine_mutex);
}

void	handle_philo_sleeping(struct s_philo *philo)
{
	int	elapsed;

	// pthread_mutex_lock(philo->curr_routine_mutex);
	if (philo->status == 1 && philo->routinesemaphore[1] == 1
	)
	{
		pthread_mutex_lock(philo->printf_mutex);
		printf("%ld %d is sleeping\n", (philo->curr - philo->start), philo->id);
		pthread_mutex_unlock(philo->printf_mutex);
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
			pthread_mutex_lock(philo->printf_mutex);
			printf("%d sleep elapsed:%d\n", philo->id, elapsed);
			pthread_mutex_unlock(philo->printf_mutex);
		}
		philo->status = 2;
		philo->routinesemaphore[0] = 0;
		philo->routinesemaphore[2] = 1;
	}
	// pthread_mutex_lock(philo->curr_routine_mutex);
}
