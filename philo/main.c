#include "string.h" // may need to comment out for memset
#include "stdio.h" // to remove for printf

#include "stdlib.h"
#include "unistd.h"
#include "sys/time.h"
#include "pthread.h"

#include "philosopher.h"
# include "../libft/libft.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

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

		printf("check value of num:%d\n", num);
		if (philo->max == num +1)
		{
			philo->r_mutex = mutex[0];
			printf("right = 0\n");
		}
		else
		{
			philo->r_mutex = mutex[num +1];
			printf("right = %d\n", num+1);
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
			printf("left = %d\n", num);
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


void *thread_function(void *arg)
{

	struct s_philo *philo;
	philo = (struct s_philo *) arg;

	//condition to break it
	while (1)
	{

		pthread_mutex_lock(&philo->curr_mutex);
		// ft_usleep(1);
		philo->curr = get_current_time();
		printf("\n\nupdated time\npid:%d, curr:%lu\n", philo->id, philo->curr);
		pthread_mutex_unlock(&philo->curr_mutex);

		if ((philo->last_meal_time > 0) && ((philo->curr - philo->last_meal_time) > philo->time_to_die))
		{
			philo->time_of_death = get_current_time();
			printf("pid%d\ntime of death:%lu.\nHow long since it passed:%lu\n", philo->id, philo->time_of_death, philo->curr - philo->last_meal_time);
			break;
		}
		if (philo->num_must_eat == 0)
		{
			printf("philo %d: finished eating\n", philo->id);
			break;
		}

		if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 1))
		{
			printf("curr:%lu\n", philo->curr);
			printf("last meal time:%lu\n", philo->last_meal_time);
			pthread_mutex_lock(&philo->l_mutex);
			pthread_mutex_lock(&philo->r_mutex);
			pthread_mutex_lock(&philo->eating_mutex);
			philo->last_meal_time = get_current_time();
			printf("id:%d is eating at %lu\n", philo->id, philo->curr);
			philo->status = 1;
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			pthread_mutex_unlock(&philo->eating_mutex);
			pthread_mutex_unlock(&philo->l_mutex);
			pthread_mutex_unlock(&philo->r_mutex);
		}
		
		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 0))
		{
			pthread_mutex_lock(&philo->sleeping_mutex);
			printf("id:%d is sleeping\n", philo->id);
			ft_usleep(philo->time_to_sleep);
			philo->status = 2;
			pthread_mutex_unlock(&philo->sleeping_mutex);
		}
		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id == philo->max))
		{
			printf("id:%d is thinking\n", philo->id);
			pthread_mutex_lock(&philo->thinking_mutex);
			philo->status = 3;
			pthread_mutex_unlock(&philo->thinking_mutex);
		}
		// for the first time
		// check max is event and id is even
		else if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id %2 == 0))
		{
			printf("curr:%lu\n", philo->curr);
			printf("last meal time:%lu\n", philo->last_meal_time);
			// eat
			pthread_mutex_lock(&philo->l_mutex);
			pthread_mutex_lock(&philo->r_mutex);
			pthread_mutex_lock(&philo->eating_mutex);
			philo->last_meal_time = get_current_time();
			printf("id:%d is eating\n", philo->id);
			philo->status = 1;
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			pthread_mutex_unlock(&philo->eating_mutex);
			pthread_mutex_unlock(&philo->l_mutex);
			pthread_mutex_unlock(&philo->r_mutex);
		}
		else if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id %2 == 1))
		{
			//sleep
			pthread_mutex_lock(&philo->sleeping_mutex);
			printf("id:%d is sleeping\n", philo->id);
			ft_usleep(philo->time_to_sleep);
			philo->status = 2;
			pthread_mutex_unlock(&philo->sleeping_mutex);
			//set to think for status
		}
		// for the above, we are trying to split into the various grouping

		// otherwise we check the previous status and do stuff
		else if (philo->status == 1)
		{
			//sleep
			pthread_mutex_lock(&philo->sleeping_mutex);
			printf("id:%d is sleeping\n", philo->id);
			ft_usleep(philo->time_to_sleep);
			philo->status = 2;
			pthread_mutex_unlock(&philo->sleeping_mutex);
			//set to think for status
		}
		else if (philo->status == 2)
		{
			printf("id:%d is thinking\n", philo->id);
			pthread_mutex_lock(&philo->thinking_mutex);
			philo->status = 3;
			pthread_mutex_unlock(&philo->thinking_mutex);

		}
		else if (philo->status == 3)
		{
			// printf("pid:%d curr:%lu\n", philo->id ,philo->curr);
			printf("pid:%d last meal time:%lu\n", philo->id, philo->last_meal_time);
			// update to next staus: 1
			pthread_mutex_lock(&philo->l_mutex);
			pthread_mutex_lock(&philo->r_mutex);
			pthread_mutex_lock(&philo->eating_mutex);
			philo->last_meal_time = get_current_time();
			printf("id:%d is eating\n", philo->id);
			philo->status = 1;
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			pthread_mutex_unlock(&philo->eating_mutex);
			pthread_mutex_unlock(&philo->l_mutex);
			pthread_mutex_unlock(&philo->r_mutex);
		}
	}

    return NULL;
}

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