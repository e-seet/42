#include "utils.h"

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
			printf("%ld %d died\n", philo->time_of_death - philo->start, philo->id);
			break;
		}
		else if (philo->stop == 1)
		{
			break;
		}
		else if (philo->curr - philo->start == 180000)
		{
			printf("3min\n");
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
