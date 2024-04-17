/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatingutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:19:50 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:19:51 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	lock_bothforkmutex(struct s_philo *philo)
{

	pthread_mutex_lock(philo->mutexs_i_readlock);

	if (philo->max - 1 == philo->id)
	{
		philo->mutexs_i[philo->id] = 1;
		philo->mutexs_i[0] = 1;

		// right is smaller
		pthread_mutex_lock(philo->r_mutex);
		// left is bigger
		pthread_mutex_lock(philo->l_mutex);

	}
	else
	{
		philo->mutexs_i[philo->id] = 1;
		philo->mutexs_i[philo->id + 1] = 1;

		// left is smaller
		pthread_mutex_lock(philo->l_mutex);
		// right is bigger
		pthread_mutex_lock(philo->r_mutex);
	}
	// pthread_mutex_unlock(philo->mutexs_i_readlock);

	pthread_mutex_lock(philo->printf_mutex);
	printf("%ld %d has taken a fork\n",
		philo->curr - philo->start, philo->id);
	printf("%ld %d has taken a fork\n",
		philo->curr - philo->start, philo->id);
	printf("%ld %d is eating\n",
		philo->curr - philo->start, philo->id);
	pthread_mutex_unlock(philo->printf_mutex);
}

void	unlock_bothforkmutex(struct s_philo *philo)
{
	if (philo->routinesemaphore[0] == 1)
		philo->routinesemaphore[0] = 0;
	else
		philo->routinesemaphore[3] = 0;

	philo->status = 1;
	philo->routinesemaphore[1] = 1;

	// pthread_mutex_lock(philo->mutexs_i_readlock);
	
	if (philo->max - 1 == philo->id)
	{
		philo->mutexs_i[philo->id] = 0;
		philo->mutexs_i[0] = 0;
		// reverse of it
		pthread_mutex_unlock(philo->l_mutex);
		pthread_mutex_unlock(philo->r_mutex);
	}
	else
	{
		philo->mutexs_i[philo->id] = 0;
		philo->mutexs_i[philo->id + 1] = 0;

		// reverse of it
		pthread_mutex_unlock(philo->r_mutex);
		pthread_mutex_unlock(philo->l_mutex);
	}
	pthread_mutex_unlock(philo->mutexs_i_readlock);

}
