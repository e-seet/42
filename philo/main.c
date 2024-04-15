/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:18:35 by eseet             #+#    #+#             */
/*   Updated: 2024/04/14 15:18:36 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	createthreads(pthread_t *threads, int num, struct s_philo **philos)
{
	while (num--)
	{
		pthread_create(&threads[num], NULL, thread_function, philos[num]);
	}
}

void	jointhreads(pthread_t *threads, int num)
{
	while (num--)
	{
		pthread_join(threads[num], NULL);
	}
}

void *thread_observe(void *arg)
{
    struct s_philo **philos = (struct s_philo **)arg;

	int	allend;

	while (1)
	{
		allend = 0;
		check_if_any_died(philos[0]->max, philos, &allend);
		if (allend == philos[0]->max)
			break ;
		allend = 0;
		check_if_all_ate(philos[0]->max, philos, &allend);
		if (allend == philos[0]->max)
			break ;
		else
			ft_usleep(1);
	}

	return (NULL);
}

// void	singlethread(struct s_philo **philos)
// {
	
// }

// void	duringthreads(char **argv, struct s_philo **philos)
// {
// 	ft_usleep(6000);
// 	singlethread(philos);
// 	printf("argv:%p", argv);


// 	// int	allend;

// 	// while (1)
// 	// {
// 	// 	allend = 0;
// 	// 	check_if_any_died(ft_atoi(argv[1]), philos, &allend);
// 	// 	if (allend == ft_atoi(argv[1]))
// 	// 		break ;
// 	// 	allend = 0;
// 	// 	check_if_all_ate(ft_atoi(argv[1]), philos, &allend);
// 	// 	if (allend == ft_atoi(argv[1]))
// 	// 		break ;
// 	// 	else
// 	// 		ft_usleep(1);
// 	// }
// }

int	main(int argc, char **argv)
{
	struct s_philo	**philos;
	int				num;
	pthread_mutex_t	*mutexs;
	pthread_t		*threads;

	pthread_t	thread1;
	philos = NULL;
	num = ft_atoi(argv[1]);
	// threads = malloc(num * sizeof(pthread_t));
	threads = ft_calloc(num, sizeof(pthread_t));
	mutexs = ft_calloc(num, sizeof(pthread_mutex_t));
	// init_fork_mutex(mutexs, num);
	if (argc == 5 || argc == 6)
		setstruct(&philos, argc, argv, mutexs);
	else
		return (-1);

	//extra thread
    pthread_create(&thread1, NULL, thread_observe, philos);

	// my bulk of philos	
	createthreads(threads, ft_atoi(argv[1]), philos);
	// duringthreads(argv, philos);
	jointhreads(threads, ft_atoi(argv[1]));

	pthread_join(thread1, NULL);

	freestuff(philos, ft_atoi(argv[1]), mutexs, threads);
}
