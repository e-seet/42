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

int	breakfunction(struct s_philo *philo, struct s_philo *philo2, int id)
{
	pthread_mutex_lock(philo->curr_routine_mutex);
	pthread_mutex_lock(philo2->extrastructlock);

	int temp;
	int max;
	int maxbackup;

	temp = 0;
	max = philo2->max;
	maxbackup = max;
	// printf("check max is working :%d\n", max);

	// So that the thread knows that the other philo have died and should stop
	if (philo2->died == 1)
	{
		// printf("c1\n");
		philo->stop = 1;
		philo2->stopped[id] = 1;

		while (max>=0)
		{
			if (philo2->stopped[max] == 1)
			{
				temp ++;
			}
			max = max -1;
		}
		pthread_mutex_unlock(philo2->extrastructlock);
		pthread_mutex_unlock(philo->curr_routine_mutex);
		if (temp == maxbackup)
			return 1;
		else
			return (0);
	}
	// The current philo died
	else if (philo->died == 1)
	{
		// printf("c2\n");
		pthread_mutex_lock(philo->printf_mutex);
		printf("%ld %d died\n", philo->time_of_death
			- philo->start, philo->id);
		pthread_mutex_unlock(philo->printf_mutex);

		philo2->stopped[id] = 1;
		// Set up the flag for memory address
		philo2->died = 1;


		while (max>=0)
		{
			if (philo2->stopped[max] == 1)
			{
				temp ++;
			}
			max = max - 1;
		}
		pthread_mutex_unlock(philo2->extrastructlock);
		pthread_mutex_unlock(philo->curr_routine_mutex);
		if (temp == maxbackup)
			return 1;
		else
			return (0);

	}
	// probably wont run this case
	else if (philo->stop == 1)
	{
		// printf("c3\n");

		pthread_mutex_lock(philo->printf_mutex);
		printf("%ld %d stopped\n", philo->curr - philo->start, philo->id);
		pthread_mutex_unlock(philo->printf_mutex);
		// increment the number of stop
		// philo2->stop = philo2->stop + 1;
		philo2->stopped[id] = 1;


		while (max>=0)
		{
			if (philo2->stopped[max] == 1)
			{
				temp ++;
			}
			max = max - 1;
		}
		pthread_mutex_unlock(philo2->extrastructlock);
		pthread_mutex_unlock(philo->curr_routine_mutex);
		if (temp == maxbackup)
			return 1;
		else
			return (0);
	}
	
	// when num_must_eat reaches 0, the eat file will change it to done = 1
	else if (philo->done == 1)
	{
		// printf("c4\n");
		philo2->stopped[id] = 1;
		// pthread_mutex_unlock(philo2->extrastructlock);
		// pthread_mutex_unlock(philo->curr_routine_mutex);
		
		while (max>=0)
		{
			// printf("id :%d, value :%d\n", max, philo2->stopped[max]);
			if (philo2->stopped[max] == 1)
			{
				temp ++;
			}
			max = max - 1;
		}
		pthread_mutex_unlock(philo2->extrastructlock);
		pthread_mutex_unlock(philo->curr_routine_mutex);

		if (temp == philo2->max)
			return 1;
		else
			return (0);
	}

	else
	{

		// printf("c5\n");
		while (max>=0)
		{
			if (philo2->stopped[max] == 1)
			{
				temp ++;
			}
			max = max - 1;
		}
		pthread_mutex_unlock(philo2->extrastructlock);
		pthread_mutex_unlock(philo->curr_routine_mutex);
		if (temp == maxbackup)
			return 1;
		else
			return (0);
	}
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

	// philo = (struct s_philo *) arg;
	
	struct thread_args *args = (struct thread_args *) arg;
	philo = args->philo1;
    struct s_philo *philo2 = args->philo2;

	//here may have read issues. To check 
	int id; 
	id = philo->id;
	

	while (1)
	{
		update_current_time_now(philo);
		breakval = breakfunction(philo, philo2, id);
		if (breakval == 1)
			break ;
		routine(philo);
	}
	return (NULL);
}
