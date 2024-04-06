#include "utils.h"

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
		printf("\n\npid:%d|updated time curr:%lu\n", philo->id, philo->curr);
		pthread_mutex_unlock(&philo->curr_mutex);

		if ((philo->last_meal_time > 0) && ((philo->curr - philo->last_meal_time) > philo->time_to_die))
		{
			philo->time_of_death = get_current_time();
			printf("id%d\ntime of death:%lu.\nHow long since it passed:%lu\n", philo->id, philo->time_of_death, philo->curr - philo->last_meal_time);
			break;
		}
		if (philo->num_must_eat == 0)
		{
			printf("philo%d|Curr:%ld\n: finished eating.", philo->id, philo->curr);
			break;
		}


		if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 1))
		{
			pthread_mutex_lock(&philo->l_mutex);
			pthread_mutex_lock(&philo->r_mutex);
			pthread_mutex_lock(&philo->eating_mutex);
			philo->last_meal_time = get_current_time();
			// printf("last meal time:%lu\n", philo->last_meal_time);
			// printf("id:%d is eating at %lu\n", philo->id, philo->curr);
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
			// printf("id:%d is sleeping for :%d\n", philo->id, philo->time_to_sleep);
			ft_usleep(philo->time_to_sleep);
			philo->status = 2;
			pthread_mutex_unlock(&philo->sleeping_mutex);
		}
		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id == philo->max))
		{
			// printf("id:%d is thinking\n", philo->id);
			pthread_mutex_lock(&philo->thinking_mutex);
			philo->status = 3;
			pthread_mutex_unlock(&philo->thinking_mutex);
		}
		// for the first time
		// check max is event and id is even
		else if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id %2 == 0))
		{
			// printf("curr:%lu\n", philo->curr);
			// printf("last meal time:%lu\n", philo->last_meal_time);
			// eat
			pthread_mutex_lock(&philo->l_mutex);
			pthread_mutex_lock(&philo->r_mutex);
			pthread_mutex_lock(&philo->eating_mutex);
			philo->last_meal_time = get_current_time();
			// printf("id:%d is eating\n", philo->id);
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
			// printf("id:%d is sleeping\n", philo->id);
			ft_usleep(philo->time_to_sleep);
			philo->status = 2;
			pthread_mutex_unlock(&philo->sleeping_mutex);
			//set to think for status
		}
		// for the above, we are trying to split into the various grouping

		// otherwise we check the previous status and do stuff
		else if (philo->status == 1)
		{
			// printf("\ncase status 1\n");

			//sleep
			pthread_mutex_lock(&philo->sleeping_mutex);
			printf("id:%d|curr:%ld is sleeping:+%d\n", philo->id, philo->curr, philo->time_to_sleep);
			ft_usleep(philo->time_to_sleep);
			philo->status = 2;
			pthread_mutex_unlock(&philo->sleeping_mutex);
			//set to think for status
		}
		else if (philo->status == 2)
		{
			// printf("\ncase status 2\n");
			printf("id:%d|curr:%ld is thinking:+%d\n", philo->id, philo->curr, 1);
			pthread_mutex_lock(&philo->thinking_mutex);
			ft_usleep(1);
			philo->status = 3;
			pthread_mutex_unlock(&philo->thinking_mutex);

		}
		else if (philo->status == 3)
		{
			// printf("pid:%d curr:%lu\n", philo->id ,philo->curr);
			printf("id:%d|curr:%ld last meal time:%lu\n", philo->id, philo->curr, philo->last_meal_time);
			// update to next staus: 1
			pthread_mutex_lock(&philo->l_mutex);
			pthread_mutex_lock(&philo->r_mutex);
			pthread_mutex_lock(&philo->eating_mutex);
			ft_usleep(philo->time_to_eat);
			philo->last_meal_time = get_current_time();
			printf("id:%d|curr:%ld lastmealtime:%lu just finished eating\n", philo->id, philo->curr, philo->last_meal_time);
			if (philo->last_meal_time > philo->curr)
				printf("id:%d|curr:%ld vs last meal: %ld\n", philo->id, philo->curr, philo->last_meal_time);
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
