#include "utils/utils.h"

void	createthreads(pthread_t *threads, int num, struct s_philo **philos)
{
	while (num--)
	{
		pthread_create(&threads[num], NULL, thread_function, philos[num]);
	}
}
// int num = ft_atoi(argv[1]);
// while (num--)
// {
// 	pthread_create(&threads[num], NULL, thread_function, philos[num]);
// }

void	jointhreads(pthread_t *threads, int num)
{
	while (num--)
	{
		pthread_join(threads[num], NULL);
	}
}
// num = ft_atoi(argv[1]);
// while (num--)
// {
// 	pthread_join(threads[num], NULL);
// }

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

int	main(int argc, char **argv)
{
	struct s_philo	**philos;
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
	duringthreads(argv, philos);
	jointhreads(threads, ft_atoi(argv[1]));
	freestuff(philos, ft_atoi(argv[1]));
}
