#include "utils/utils.h"

int	setstruct(struct s_philo ***philos, int argc, char **argv, pthread_mutex_t *mutexs)
{
	int		num;
	struct	s_philo *philo;

	num = ft_atoi(argv[1]);
	*philos = (struct s_philo **)malloc(sizeof(struct s_philo *) * num);
	if (philos == NULL)
		return (-1);
	pthread_mutex_t *curr_mutex;

	int *mutexs_i = malloc(num * sizeof(int));
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
		philo->id = num;
		philo->status = 0;
		philo->max = ft_atoi(argv[1]);
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		philo->last_meal_time = 0;
		philo->mutexs_i = mutexs_i;
		curr_mutex =  malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(curr_mutex, NULL);
		philo->curr_mutex = curr_mutex;
		philo->died = 0;
		philo->start = 0;
		philo->stop = 0;
		philo->num_of_time_eaten = 0;

		philo->l_mutex = &mutexs[num];
		pthread_mutex_init(philo->l_mutex, NULL);
		if (philo->max - 1 == num)
			philo->r_mutex = &mutexs[0];
		else
			philo->r_mutex = &mutexs[num + 1];

		if (argc == 6)
			philo->num_must_eat = ft_atoi(argv[5]);
		else
			philo->num_must_eat = -1;
		(*philos)[num] = philo;
	}
	return (0);
}

int main(int argc, char **argv)
{
	struct s_philo **philos;
	int			num;
	int			num2;
	int			num3;

	philos = NULL;
	num = ft_atoi(argv[1]);
	pthread_t threads[num];
	pthread_mutex_t *mutexs = malloc(num * sizeof(pthread_mutex_t));
	
	for (int i = 0; i < num; i++) {
		pthread_mutex_init(&mutexs[i], NULL);
	}

	if (argc == 5 || argc == 6)
		setstruct(&philos, argc, argv, mutexs);
	else
	 return (-1);

	num2 = ft_atoi(argv[1]);		
	while (num2--)
	{
		pthread_create(&threads[num2], NULL, thread_function, philos[num2]);
	}
	int			num4;
	int alldie = 0;
	int	allend = 0;
	while (1)
	{
		alldie = 0;
		allend = 0;
		// this segment check if anything died. If so, we go through and stop them all
		num4 = ft_atoi(argv[1]);
		while (num4 --)
		{
			if (philos[num4]->died == 1)
			{
				alldie = 1;
				alldie = 0;
				num4 = ft_atoi(argv[1]);
				while (num4 --)
				{
					alldie ++;
					philos[num4]->stop = 1;
				}
				break;
			}
		}

		// this segment check if all the philo ended, if so then i break out.
		// for now i conmmnent out
		// int num5;
		// allend = 0;
		// num5 = ft_atoi(argv[1]);
		// while (num5 --)
		// {
		// 	if (philos[num5]->stop == 1)
		// 		allend ++;
		// }

		// Go through every philo and check whether 
		// they have eaten the required amount
		int num6;
		allend = 0;
		num6 = ft_atoi(argv[1]);
		while (num6 --)
		{
			if (philos[num6]->num_must_eat == 0)
				allend ++;
		}
		// if eaten the required amount, then stop all
		if (allend == ft_atoi(argv[1]))
		{
			num6 = ft_atoi(argv[1]);
			while (num6 --)
			{
				philos[num6]->stop = 1;
			}	
		}

		// do i need a final check? To be
		// allend = 0;
		// num6 = ft_atoi(argv[1]);
		// while (num5 --)
		// {
		// 	if (philos[num5]->stop == 1)
		// 		allend ++;
		// }
		// while loop to check this.


		if (alldie == ft_atoi(argv[1]) )
		{
			break;
		}
		else if (allend == ft_atoi(argv[1]) )
		{
			break;
		}
		else
			ft_usleep(1);

	}
	num3 = ft_atoi(argv[1]);
	while (num3--)
	{
		pthread_join(threads[num3], NULL);
	}
	freestuff(philos, ft_atoi(argv[1]));
}
