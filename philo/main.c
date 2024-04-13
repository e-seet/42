#include "utils/utils.h"

void	init_philo_mutexs(struct s_philo *philo, int *mutexs_i,
	pthread_mutex_t *mutexs, char **argv)
{
	pthread_mutex_t	*curr_mutex;
	int				num;
	int				num2;

	num = ft_atoi(argv[1]);
	curr_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(curr_mutex, NULL);
	philo->curr_mutex = curr_mutex;
	philo->mutexs_i = mutexs_i;
	philo->l_mutex = &mutexs[num];
	pthread_mutex_init(philo->l_mutex, NULL);
	if (philo->max - 1 == num)
		philo->r_mutex = &mutexs[0];
	else
		philo->r_mutex = &mutexs[num + 1];
	philo->routinesemaphore = (int *)malloc(sizeof(int) * 4);
	num2 = 4;
	while (--num2)
	{
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
		init_philo_mutexs(philo, mutexs_i, mutexs, argv);
		init_philo(philo, argv, argc, num);
		(*philos)[num] = philo;
	}
	return (0);
}

void	stopall(int num, struct s_philo **philos, int *allend)
{
	while (num --)
	{
		philos[num]->stop = 1;
		*allend = *allend + 1;
	}
}

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

void	check_if_any_died(int num, struct s_philo **philos, int *allend)
{
	int	num2;

	num2 = num;
	while (num --)
	{
		if (philos[num]->died == 1)
		{
			stopall(num2, philos, allend);
			break ;
		}
	}
}

void	check_if_all_ate(int num, struct s_philo **philos, int *allend)
{
	int	allate;
	int	num2;

	allate = 0;
	num2 = num;
	while (num2 --)
	{
		if (philos[num2]->num_must_eat == 0)
			allate ++;
	}
	if (allate == num)
		stopall(num, philos, allend);
}

void	duringthreads(char **argv, struct s_philo **philos)
{
	int	allend;

	while (1)
	{
		allend = 0;
		check_if_any_died(ft_atoi(argv[1]), philos, &allend);
		if (allend == ft_atoi(argv[1]))
			break ;
		allend = 0;
		check_if_all_ate(ft_atoi(argv[1]), philos, &allend);
		if (allend == ft_atoi(argv[1]))
			break ;
		else
			ft_usleep(1);
	}
}

int	main(int argc, char **argv)
{
	struct s_philo	**philos;
	// int				allend;
	pthread_mutex_t	*mutexs;
	pthread_t		*threads;

	philos = NULL;
	threads = malloc(ft_atoi(argv[1]) * sizeof(pthread_t));
	mutexs = malloc(ft_atoi(argv[1]) * sizeof(pthread_mutex_t));
	init_fork_mutex(mutexs, ft_atoi(argv[1]));
	if (argc == 5 || argc == 6)
		setstruct(&philos, argc, argv, mutexs);
	else
		return (-1);
	createthreads(threads, ft_atoi(argv[1]), philos);
	// int num = ft_atoi(argv[1]);
	// while (num--)
	// {
	// 	pthread_create(&threads[num], NULL, thread_function, philos[num]);
	// }
	duringthreads(argv, philos);
	// while (1)
	// {
	// 	allend = 0;
	// 	check_if_any_died(ft_atoi(argv[1]), philos, &allend);
	// 	if (allend == ft_atoi(argv[1]))
	// 		break ;
	// 	allend = 0;
	// 	check_if_all_ate(ft_atoi(argv[1]), philos, &allend);
	// 	if (allend == ft_atoi(argv[1]))
	// 		break ;
	// 	else
	// 		ft_usleep(1);
	// }
	jointhreads(threads, ft_atoi(argv[1]));
	// num = ft_atoi(argv[1]);
	// while (num--)
	// {
	// 	pthread_join(threads[num], NULL);
	// }
	freestuff(philos, ft_atoi(argv[1]));
}
