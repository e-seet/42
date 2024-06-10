/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:19:00 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:19:01 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	lastfella(struct s_philo *philo)
{
	// printf("last fella eats\n");
	int	elapsed;

	elapsed = 0;
	lock_bothforkmutex(philo);
	if (philo->mutexs_i[philo->id] == 1 && (philo->mutexs_i[0] == 1)
		&& (philo->routinesemaphore[3] == 1)
	)
	{
		if ((philo->curr - philo->last_meal_time)
			+ philo->time_to_eat > philo->time_to_die)
		{
			if (philo->curr - philo->last_meal_time
				> philo->time_to_die)
			{
				// printf("weird chmap eating and dying\n");
			ft_usleep(philo->time_to_die - (philo->curr - philo->last_meal_time));
			}
				
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			elapsed = ft_usleep(philo->time_to_eat);
			pthread_mutex_lock(philo->printf_mutex);
			printf("%d eating elapsed: %d\n", philo->id, elapsed);
			pthread_mutex_unlock(philo->printf_mutex);
			philo->last_meal_time = get_current_time();
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			if (philo->num_must_eat == 0)
				philo->done = 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		}
	}
	else
	{
		printf("ah what?? Error!\n");
	
	}
	unlock_bothforkmutex(philo);
}

void	normalfella(struct s_philo *philo)
{	
	// printf("normal fella eats\n");

	int	elapsed;

	elapsed = 0;
	lock_bothforkmutex(philo);
	if (philo->mutexs_i[philo->id] == 1
		&& (philo->mutexs_i[philo->id + 1] == 1))
	{
		if ((philo->curr - philo->last_meal_time)
			+ philo->time_to_eat > philo->time_to_die)
		{
			if (philo->curr - philo->last_meal_time
				> philo->time_to_die)
				ft_usleep(philo->time_to_die
					- (philo->curr - philo->last_meal_time));
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			elapsed = ft_usleep(philo->time_to_eat);
			pthread_mutex_lock(philo->printf_mutex);
			printf("%d eating elapsed: %d\n", philo->id, elapsed);
			pthread_mutex_unlock(philo->printf_mutex);
			philo->last_meal_time = get_current_time();
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			if (philo->num_must_eat == 0)
				philo->done = 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		}
	}
	unlock_bothforkmutex(philo);

}

void	handle_odd_philo_eating(struct s_philo *philo)
{
	// pthread_mutex_lock(philo->curr_routine_mutex);
	lock_bothforkmutex(philo);
	if (philo->status == 0 && philo->routinesemaphore[0] == 1
		&& (philo->max % 2 == 1) && (philo->id != philo->max)
		&& (philo->id % 2 == 1))
	{
		if (philo->time_to_eat > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			ft_usleep(philo->time_to_eat);
			philo->last_meal_time = get_current_time();
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			if (philo->num_must_eat == 0)
				philo->done = 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		}
	}
	unlock_bothforkmutex(philo);
	// pthread_mutex_unlock(philo->curr_routine_mutex);
}

void	handle_even_philo_eating(struct s_philo *philo)
{
	// pthread_mutex_lock(philo->curr_routine_mutex);
	lock_bothforkmutex(philo);
	if (philo->status == 0 && philo->routinesemaphore[0] == 1
		&& (philo->max % 2 == 0) && (philo->id % 2 == 0))
	{
		if (philo->time_to_eat > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			ft_usleep(philo->time_to_eat);
			philo->last_meal_time = get_current_time();
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			if (philo->num_must_eat == 0)
				philo->done = 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		}
	}
	unlock_bothforkmutex(philo); //inside here data race
	// pthread_mutex_unlock(philo->curr_routine_mutex);
}

void	handle_philo_eating(struct s_philo *philo)
{
	// pthread_mutex_lock(philo->curr_routine_mutex);
	if (philo->status == 3)
	{
		if (philo->max - 1 == philo->id)
		{
			lastfella(philo);

		}
		else
		{
			normalfella(philo);
		}
	}
}
