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

// u_int64_t	get_current_time(void)
// {
// 	struct timeval	tv;
// 	if (gettimeofday(&tv, NULL) == -1)
// 		write(2, "gettimeofday() error\n", 22);
// 	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
// }

// int	ft_usleep(useconds_t time)
// {
// 	u_int64_t	start;
// 	start = get_current_time();
// 	while ((get_current_time() - start) < time)
// 		usleep(time / 10);
// 	return(0);
// }

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// int	ft_usleep(useconds_t time)
// {
// 	u_int64_t	start;
// 	start = get_current_time();
// 	while ((get_current_time() - start) < time)
// 		usleep(time / 10);
// 	return(get_current_time()-start);
// }

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
	while (num --)
	{
		pthread_mutex_destroy(philos[num]->curr_mutex);
		pthread_mutex_destroy(philos[num]->curr_routine_mutex);
		pthread_mutex_destroy(philos[num]->l_mutex);
		pthread_mutex_destroy(&mutexs[num]);

		// issue freeing threads
		free(&threads[num]); 
		
		free(&mutexs[num]); // is this mutex or int array. To find out
		free(philos[num]->curr_mutex);
		free(philos[num]->curr_routine_mutex);
		free(philos[num]->l_mutex);

		free(philos[num]);
	}
	free(philos);

}

void	update_current_time_now(struct s_philo *philo)
{
	pthread_mutex_lock(philo->curr_mutex);
	if (philo->start == 0)
		philo->start = get_current_time();
	philo->curr = (get_current_time());
	pthread_mutex_unlock(philo->curr_mutex);
}

void	update_current_time(struct s_philo *philo)
{
	pthread_mutex_lock(philo->curr_mutex);
	philo->curr = get_current_time();
	pthread_mutex_unlock(philo->curr_mutex);
}

// void	check_death_condition(struct s_philo *philo)
// {
// 	if ((philo->last_meal_time > 0) && (((philo->curr) - philo->last_meal_time)
// 			> philo->time_to_die))
// 	{
// 		philo->time_of_death = get_current_time();
// 		// printf("id%d\ntime of death:%lu.\nHow long since it passed:%lu\n",
// 			// philo->id, philo->time_of_death,
// 			// philo->curr - philo->last_meal_time);
// 	}
// }

// void	check_finished_eating(struct s_philo *philo)
// {
// 	if (philo->num_must_eat == 0)
// 	{
//		// printf("philo%d|Curr:%ld\n: finished eating.",
//		// 	philo->id, philo->curr);
// 	}
// }
