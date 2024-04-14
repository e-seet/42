/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:19:46 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:19:47 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_fork_mutex(pthread_mutex_t *mutexs, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&mutexs[i], NULL);
		i++;
	}
}

void	init_philo_mutexs(struct s_philo *philo, int *mutexs_i,
int num, pthread_mutex_t *mutexs)
{
	pthread_mutex_t	*curr_mutex;
	pthread_mutex_t	*curr_routine_mutex;
	int				num2;

	num2 = 5;
	philo->mutexs_i = mutexs_i;
	curr_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	curr_routine_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(curr_mutex, NULL);
	philo->curr_mutex = curr_mutex;
	pthread_mutex_init(curr_routine_mutex, NULL);
	philo->curr_routine_mutex = curr_routine_mutex;
	philo->l_mutex = &mutexs[num];
	pthread_mutex_init(philo->l_mutex, NULL);
	if (philo->max - 1 == num)
		philo->r_mutex = &mutexs[0];
	else
		philo->r_mutex = &mutexs[num + 1];
	philo->routinesemaphore = (int *)malloc(sizeof(int) * 4);
	while (num2-- > 0)
	{
		printf("num2:%d\n", num2);
		philo->routinesemaphore[num2] = 0;
	}
	philo->routinesemaphore[0] = 1;
}

void	init_philo(struct s_philo *philo, char **argv, int argc, int id)
{
	philo->id = id;
	philo->status = 0;
	philo->max = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->last_meal_time = 0;
	philo->died = 0;
	philo->start = 0;
	philo->stop = 0;
	philo->num_of_time_eaten = 0;
	if (argc == 6)
		philo->num_must_eat = ft_atoi(argv[5]);
	else
		philo->num_must_eat = -1;
}

int	setstruct(struct s_philo ***philos, int argc,
	char **argv, pthread_mutex_t *mutexs)
{
	int				num;
	struct s_philo	*philo;
	int				*mutexs_i;

	num = ft_atoi(argv[1]);
	*philos = (struct s_philo **)malloc(sizeof(struct s_philo *) * num);
	if (philos == NULL)
		return (-1);
	mutexs_i = malloc(num * sizeof(int));
	while (num--)
	{
		mutexs_i[num] = 0;
	}
	num = ft_atoi(argv[1]);
	while (num--)
	{
		philo = (struct s_philo *) malloc (sizeof(struct s_philo));
		if (philo == NULL)
			return (-1);
		init_philo(philo, argv, argc, num);
		init_philo_mutexs(philo, mutexs_i, num, mutexs);
		philo->mutexs_i = mutexs_i;
		(*philos)[num] = philo;
	}
	return (0);
}
