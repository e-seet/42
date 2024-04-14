/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:19:15 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:19:15 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

//	how long before i will die if i dont eat
// unsigned long		time_to_die;

// how long i take to eat
// unsigned long			time_to_eat;

// how long i sleep
// unsigned long			time_to_sleep;

struct s_philo {
	int					id;
	int					max;

	unsigned long		last_meal_time;

	unsigned long		time_to_die;

	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;

	int					num_must_eat;
	int					num_of_time_eaten;
	int					died;
	unsigned long		time_of_death;
	int					stop;

	unsigned long		start;
	unsigned long		curr;
	int					status;

	pthread_mutex_t		*l_mutex;
	pthread_mutex_t		*r_mutex;

	int					*mutexs_i;
	int					*routinesemaphore;

	pthread_mutex_t		*curr_routine_mutex;
	pthread_mutex_t		eating_mutex;
	pthread_mutex_t		sleeping_mutex;
	pthread_mutex_t		thinking_mutex;

	pthread_mutex_t		*curr_mutex;
};

//statuus 1 = sleeping
// status 2 = thinking
// status 3  = eating

// i may something like array of forks for mutex.

// struct thread_arg
// {
// 	struct s_philo **philos;
// 	int				num;
// };

#endif
