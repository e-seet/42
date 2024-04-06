#include "utils.h"


int setstruct(struct s_philo ***philos, int argc, char **argv, pthread_mutex_t *mutex)
{
	int	num;
	struct s_philo *philo;

	num = ft_atoi(argv[1]);
	*philos = (struct s_philo **)malloc(sizeof(struct s_philo *) * num);
	if (philos == NULL)
		return (-1);

	pthread_mutex_t curr_mutex;
	pthread_mutex_init(&curr_mutex, NULL);

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
		philo->curr_mutex = curr_mutex;

		// printf("check value of max:%d\n\n", philo->max);
		// 5

		// printf("check value of num:%d\n", num);
		if (philo->max == num +1)
		{
			philo->r_mutex = mutex[0];
			// printf("right = 0\n");
		}
		else
		{
			philo->r_mutex = mutex[num +1];
			// printf("right = %d\n", num+1);
		}

		// if (philo->id == 0)
		// {
		// 	// philo->l_mutex = mutex[ ft_atoi(argv[1]) - 1];
		// 	// printf("left0 = %d\n", ft_atoi(argv[1]) - 1);
		// 	philo->l_mutex = mutex[num];
		// 	printf("left0 = %d\n", 0);
		// }
		// else
		// {
			philo->l_mutex = mutex[num];
			// printf("left = %d\n", num);
		// }
		
		pthread_mutex_init(&philo->l_mutex, NULL);
		

		if (argc == 6)
			philo->num_must_eat = ft_atoi(argv[5]);
		else
			philo->num_must_eat = -1;
		(*philos)[num] = philo;

		printf("\n");
	}
	// int	i = ft_atoi(argv[1]);
	// while(i--)
	// {
	// 	printf("philo id:%d\n", (*philos)[i]->id);
	// 	printf("philo id:%d\n",(*philos)[i]->time_to_die);
	// 	printf("philo id:%d\n", (*philos)[i]->time_to_eat);
	// 	printf("philo id:%d\n\n", (*philos)[i]->time_to_sleep);
	// }
	return (0);
}

void eat_routine()
{


}

void routine()
{
	// check left right
	// eat
	// sleep
	// think
}

// pthread_mutex_t mutex;
// int shared = 0;


int main(int argc, char **argv)
{
	struct s_philo **philos;
	// int		timer;
	// int		died;
	int			num;
	int			num2;
	int			num3;
	// struct 	thread_arg threadarg;

	philos = NULL;
	// died = 0;

	num = ft_atoi(argv[1]);
	pthread_t threads[num];
	pthread_mutex_t mutex[num];


	if (argc == 5 || argc == 6)
		setstruct(&philos, argc, argv, mutex);
	else
	 return (-1);

	printf("philo id:%d\n", philos[0]->id);
	printf("time before dying:%lu\n", philos[0]->time_to_die);
	printf("time needed to eat:%d\n", philos[0]->time_to_eat);
	printf("time needed to sleep:%d\n", philos[0]->time_to_sleep);
	printf("status:%d\n\n", philos[0]->status);


	while (1)
	{
		num2 = ft_atoi(argv[1]);		
		while(num2--)
		{
			// i send in each philo but as it is shared data structure
			// there will be race condition
			pthread_create(&threads[num2], NULL, thread_function, philos[num2]);
		}

		num3 = ft_atoi(argv[1]);
		while(num3--)
		{
			pthread_join(threads[num3], NULL);
		}
		
		break;
	}

}