/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:18:53 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:18:53 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;
	size_t	elapsed;

	start = get_current_time();
	while (1)
	{
		elapsed = get_current_time() - start;
		if (elapsed >= milliseconds)
		{
			return (elapsed);
			break ;
		}
		usleep(1000);
	}
	return (0);
}

void	freestuff(struct s_philo **philos, int num, pthread_mutex_t *mutexs, pthread_t *threads)
{

	// only a single mutex
	pthread_mutex_destroy(philos[0]->mutexs_i_readlock);
	pthread_mutex_destroy(philos[0]->printf_mutex);

	//multiple mutex
	while (num --)
	{
		pthread_mutex_destroy(philos[num]->curr_mutex);
		pthread_mutex_destroy(philos[num]->curr_routine_mutex);
		pthread_mutex_destroy(&mutexs[num]);

		// issue freeing threads
		free(&threads[num]); 
		
		free(&mutexs[num]); // is this mutex or int array. To find out
		free(philos[num]->curr_mutex);
		free(philos[num]->curr_routine_mutex);

		free(philos[num]);
	}
	free(philos);
}

void	update_current_time_now(struct s_philo *philo)
{
	// pthread_mutex_lock(philo->curr_routine_mutex);
	// pthread_mutex_lock(philo->curr_mutex);
	if (philo->start == 0)
		philo->start = get_current_time();
	philo->curr = (get_current_time());
	// pthread_mutex_unlock(philo->curr_mutex);
	// pthread_mutex_unlock(philo->curr_routine_mutex);
}

