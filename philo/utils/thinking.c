/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:19:55 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:19:56 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// There is the issue in which someone who have been thinking for a long time did not break out
// instead someone who have just started thinking break out and go to eat.
// This is an issue and should be resolved.
int	sleeproutine(struct s_philo *philo)
{
	// last fella
	if (philo->max - 1 == philo->id)
	{
		pthread_mutex_lock(philo->mutexs_i_readlock);
		// i can move on to the next stage.
		if (philo->mutexs_i[philo->id] == 0 && philo->mutexs_i[0] == 0)
		{

			pthread_mutex_unlock(philo->mutexs_i_readlock);
			return (1);
		}
		// continue waiting
		else
		{
			pthread_mutex_unlock(philo->mutexs_i_readlock);
			ft_usleep(1);
			update_current_time_now(philo); //inside here data race
		}
	}


	// every other fella
	else
	{

		pthread_mutex_lock(philo->mutexs_i_readlock);
		// i can move on to the next stage.
		if (philo->mutexs_i[philo->id] == 0
			&& philo->mutexs_i[philo->id + 1] == 0)
			{
				pthread_mutex_unlock(philo->mutexs_i_readlock);
				return (1);
			}
		// continue waiting
		else
		{
			pthread_mutex_unlock(philo->mutexs_i_readlock);
			ft_usleep(1);
			update_current_time_now(philo);//inside here data race
		}
	}
	return (0);
}

void	handle_odd_philo_thinking(struct s_philo *philo)
{
	int	breakval;

	// pthread_mutex_lock(philo->curr_routine_mutex);
	if (philo->status == 0 && philo->routinesemaphore[0] == 1
		&& (philo->max % 2 == 1) && (philo->id == philo->max))
	{
		philo->last_meal_time = (philo->curr);
		pthread_mutex_lock(philo->printf_mutex);
		printf("%ld %d is thinking\n", (philo->curr - philo->start), philo->id);
		pthread_mutex_unlock(philo->printf_mutex);
		philo->status = 3;
		philo->routinesemaphore[0] = 0;
		philo->routinesemaphore[3] = 1;
		while (1)
		{
			breakval = sleeproutine(philo);
			if (breakval == 1)
				break ;
		}
	}
	// pthread_mutex_unlock(philo->curr_routine_mutex);

}

void	change_thinking_semaphore(struct s_philo *philo)
{
	philo->status = 3;
	philo->routinesemaphore[2] = 0;
	philo->routinesemaphore[3] = 1;
}

void	handle_philo_thinking(struct s_philo *philo)
{
	// pthread_mutex_lock(philo->curr_routine_mutex);
	if (philo->status == 2 && philo->routinesemaphore[2] == 1
	)
	{
		pthread_mutex_lock(philo->printf_mutex);
		printf("%ld %d is thinking\n", (philo->curr - philo->start), philo->id);
		pthread_mutex_unlock(philo->printf_mutex);
		
		while (1)
		{
			if ((philo->curr) - philo->last_meal_time > philo->time_to_die)
			{
				philo->time_of_death = (philo->curr);
				philo->died = 1;
				break ;
			}
			else
			{
				if (sleeproutine(philo) == 1) 
					break ;
			}
		}
		change_thinking_semaphore(philo);
	}
	// pthread_mutex_unlock(philo->curr_routine_mutex);
}
