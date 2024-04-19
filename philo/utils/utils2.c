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

// routinesemaphore 1 2 3 for the thread's process
// curr_routine_mutex is the mutex for the thread's routine.
// at where  do what

// for forks under: philo->l_mutex, r_mutex
// mutexs[0]...

// mutexs_i is array storing which forks are taken; 
// to check which for available without mutex


// void	stopall(int num, struct s_philo **philos, int *allend)
// {
// 	while (num --)
// 	{
// 		pthread_mutex_unlock(philos[num]->curr_routine_mutex);
// 		if (philos[num]->status == 3)
// 		{
// 			pthread_mutex_unlock(philos[num]->l_mutex);
// 			pthread_mutex_unlock(philos[num]->r_mutex);
// 		}
// 		pthread_mutex_lock(philos[num]->curr_routine_mutex);
// 		philos[num]->stop = 1;
// 		pthread_mutex_unlock(philos[num]->curr_routine_mutex);
// 		*allend = *allend + 1;
// 	}
// }

// void	stopall(int num, struct s_philo **philos, int *allend)
// {
// 	while (num --)
// 	{
// 		pthread_mutex_unlock(philos[num]->curr_routine_mutex);
// 		if (philos[num]->status == 3)
// 		{
// 			pthread_mutex_unlock(philos[num]->l_mutex);
// 			pthread_mutex_unlock(philos[num]->r_mutex);
// 		}
// 		pthread_mutex_lock(philos[num]->curr_routine_mutex);
// 		philos[num]->stop = 1;
// 		pthread_mutex_unlock(philos[num]->curr_routine_mutex);
// 		*allend = *allend + 1;
// 	}
// }


void	check_if_any_died(int num, struct s_philo **philos)
{
	// int	num2;

	// num2 = num;
	while (num --)
	{
		if (philos[num]->died == 1)
		{
			// stopall(num2, philos); // need to change this
			break ;
		}
	}
}

void	check_if_all_ate(int num, struct s_philo **philos)
{
	// int	num2;
	int	max;
	int	allate;


	max = 0;
	allate = 0;
	// num2 = num;
	
	pthread_mutex_lock(philos[max]->extrastructlock);
	max = philos[max]->max;

	while (num --)
	{
		if (philos[max]->num_must_eat == 0)
			allate ++;
	}
	pthread_mutex_unlock(philos[max]->extrastructlock);
	printf("print the number of all ate:%d\n", allate);
	// if (allate == num)
		// stopall(num, philos, allend); // need to change this
}
