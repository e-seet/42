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

void * thread_function(void *arg)
{

	struct s_philo *philo;
	philo = (struct s_philo *) arg;

	while (1)
	{
		update_current_time_now(philo);

		if (philo->num_must_eat == 0)
		{
			break;
		}

		if (philo->died == 1)
		{
			printf("%ld %d died\n", philo->time_of_death, philo->id);
			break;
		}
		else if (philo->stop == 1)
		{
			break;
		}


		// Odd number of philo. Split to 3 groups
		if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 1))
		{
			// printf("handle odd eating\n");
			handle_odd_philo_eating(philo);
		}
		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 0))
		{
			// printf("handle odd sleeping\n");
			handle_odd_philo_sleeping(philo);
		}
		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id == philo->max))
		{
			// printf("handle odd thinking\n");
			handle_odd_philo_thinking(philo);
		}

		// even number of philo
		else if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id %2 == 0))
		{
			handle_even_philo_eating(philo);
		}
		else if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id %2 == 1))
		{
			handle_even_philo_sleeping(philo);
		}
		else if (philo->status == 1)
		{
			handle_philo_sleeping(philo);
		}
		else if (philo->status == 2)
		{
			handle_philo_thinking(philo);
		}
		else if (philo->status == 3)
		{
			handle_philo_eating(philo);
		}
	}
    return NULL;
}
