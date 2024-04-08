#include "utils.h"

// void	checkmutex(struct s_philo ***philos, char **argv, pthread_mutex_t *mutexs)
// {
// 	struct	s_philo *philo;
// 	int		num;

// 	num = ft_atoi(argv[1]);
// 	*philos = (struct s_philo **)malloc(sizeof(struct s_philo *) * num);
// 	while (philos[num--])
// 	{

// 		if ((void *) &((philos[num])->l_mutex) == (void *) &((philos[num])->r_mutex))
// 		{
// 			printf("error\n");
// 		}
// 		else if ((void *)&mutexs[num] != (void *) &(philos[num])->l_mutex)
// 		{
// 			printf("error i think\n");
// 		}
// 	}
// }

int	setstruct(struct s_philo ***philos, int argc, char **argv, pthread_mutex_t *mutexs)
{
	int		num;
	struct	s_philo *philo;

	num = ft_atoi(argv[1]);
	*philos = (struct s_philo **)malloc(sizeof(struct s_philo *) * num);
	if (philos == NULL)
		return (-1);
	pthread_mutex_t *curr_mutex;

	// printf("num:%d\n", num);
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

		curr_mutex =  malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(curr_mutex, NULL);
		philo->curr_mutex = curr_mutex;
		philo->died = 0;
		philo->stop = 0;
		philo->num_of_time_eaten = 0;

		if (philo->max == num +1)
		{
			philo->r_mutex = &mutexs[0];
		}
		else
			philo->r_mutex = &mutexs[num +1];

		philo->l_mutex = &mutexs[num];
		pthread_mutex_init(philo->l_mutex, NULL);

		// if ((void *)philo->r_mutex == (void *)philo->l_mutex)
		// 	printf("got issue in mutex\n");

		if (argc == 6)
			philo->num_must_eat = ft_atoi(argv[5]);
		else
			philo->num_must_eat = -1;
		(*philos)[num] = philo;
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
	int			num4;

	philos = NULL;
	num = ft_atoi(argv[1]);
	pthread_t threads[num];
	pthread_mutex_t mutex[num];


	if (argc == 5 || argc == 6)
		setstruct(&philos, argc, argv, mutex);
	else
	 return (-1);

	// checkmutex(&philos, argv, mutex);
	// printf("philo id:%d\n", philos[0]->id);
	// printf("time before dying:%lu\n", philos[0]->time_to_die);
	// printf("time needed to eat:%lu\n", philos[0]->time_to_eat);
	// printf("time needed to sleep:%lu\n", philos[0]->time_to_sleep);
	// printf("status:%d\n\n", philos[0]->status);

	// break;
	num2 = ft_atoi(argv[1]);		
	while (num2--)
	{
		pthread_create(&threads[num2], NULL, thread_function, philos[num2]);
	}

	int alldie = 0;
	int	allend = 0;
	// int tobreakafter5 = 0;
	while (1)
	{
		alldie = 0;
		allend = 0;
		num4 = ft_atoi(argv[1]);
		
		// if (tobreakafter5 == 1000)
		// 	break ;
		// else
		// 	tobreakafter5 ++;

		while (num4 --)
		{
			// printf("check if anything died\n");
			// check if anything died. If so break
			// printf("philos died:%d\n", philos[num4]->died);
			if (philos[num4]->died == 1)
			{
				alldie = 1;
				break;
			}
		}
		//if a single thread even died
		if (alldie == 1)
		{
			alldie = 0;
			num4 = ft_atoi(argv[1]);
			while (num4 --)
			{
				alldie ++;
				philos[num4]->stop = 1;
			}
		}
		//otherwise check
		else
		{
			// printf("else statement\n");
			allend = 0;
			num4 = ft_atoi(argv[1]);
			while (num4 --)
			{
				if (philos[num4]->stop == 1)
					allend ++;
				else if (philos[num4]->num_must_eat == 0)
					allend ++;
			}
			// printf("all end?\n");
		}

		if (alldie == ft_atoi(argv[1])-1)
			break;
		else if (allend == ft_atoi(argv[1])-1)
			break;
	}
	// printf("all end:%d all died:%d\n", allend, alldie);


	num3 = ft_atoi(argv[1]);
	while (num3--)
	{
		pthread_join(threads[num3], NULL);
	}
	freestuff(philos, ft_atoi(argv[1]));
}
