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

	//condition to break it
	while (1)
	{
		// pthread_mutex_lock(&philo->curr_mutex);
		// philo->curr = get_current_time();
		// printf("\n\npid:%d|updated time curr:%lu\n", philo->id, philo->curr);
		// pthread_mutex_unlock(&philo->curr_mutex);
		update_current_time_now(philo);

		//break cases. We keep them first
		// break case 1: unlikely to use
		// if ((philo->last_meal_time > 0) && ((philo->curr - philo->last_meal_time) > philo->time_to_die))
		// {
			// philo->time_of_death = get_current_time();
		// 	printf("id%d\ntime of death:%lu.\nHow long since it passed:%lu\n", philo->id, philo->time_of_death, philo->curr - philo->last_meal_time);
		// 	break;
		// }
		// break case 2: using now to break
		if (philo->num_must_eat == 0)
		{
			printf("philo%d|Curr:%ld\n: finished eating.", philo->id, philo->curr);
			break;
		}


		// Odd number of philo. Split to 3 groups
		if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 1))
		{
			printf("handle odd eating\n");
			handle_odd_philo_eating(philo);
		}
		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 0))
		{
			printf("handle odd sleeping\n");
			handle_odd_philo_sleeping(philo);
		}
		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id == philo->max))
		{
			printf("handle odd thinking\n");
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
			// pthread_mutex_lock(&philo->sleeping_mutex);
			// printf("%ld %d is sleeping | for %d time %lu\n", philo->curr, philo->id, philo->time_to_sleep, get_current_time());
			// if ((philo->curr - philo->last_meal_time) + philo->time_to_sleep > philo->time_to_die)
			// {
			// 	ft_usleep((philo->time_to_die) - (philo->curr - philo->last_meal_time));
			// 	philo->time_of_death = get_current_time();
			// 	philo->died = 1;
			// 	break;
			// }
			// else
			// 	ft_usleep(philo->time_to_sleep);
			// philo->status = 2;
			// pthread_mutex_unlock(&philo->sleeping_mutex);
		}
		else if (philo->status == 2)
		{
			handle_philo_thinking(philo);
		}
		else if (philo->status == 3)
		{
			handle_philo_eating(philo);
			// pthread_mutex_lock(philo->l_mutex);
			// printf("%ld %d has taken a fork | %lu\n", philo->curr, philo->id, get_current_time());
			// pthread_mutex_lock(philo->r_mutex);
			// printf("%ld %d has taken a fork | %lu\n", philo->curr, philo->id, get_current_time());
			// pthread_mutex_lock(&philo->eating_mutex);
			// if ((philo->curr - philo->last_meal_time) + philo->time_to_eat > philo->time_to_die)			
			// {
			// 	printf("eating got issue!!!\n");
			// 	printf("curr:%lu\n", philo->curr);
			// 	printf("lastm:%lu\n", philo->last_meal_time);
			// 	printf("tte:%d\n", philo->time_to_eat);
			// 	printf("ttd:%lu\n", philo->time_to_die);
			// 	ft_usleep(1);
			// 	philo->time_of_death = get_current_time();
			// 	philo->died = 1;
			// 	// i can continue with the process here if required.
			// 	break;
			// }
			// else
			// {
			// 	printf("%ld %d is eating | for %d time %lu\n", philo->curr, philo->id, philo->time_to_eat, get_current_time());
			// 	ft_usleep(philo->time_to_eat);
			// 	philo->last_meal_time = get_current_time();
			// }
			// philo->status = 1;
			// if (philo->num_must_eat > 0)
			// 	philo->num_must_eat = philo->num_must_eat - 1;
			// philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
			// pthread_mutex_unlock(&philo->eating_mutex);
			// pthread_mutex_unlock(philo->l_mutex);
			// pthread_mutex_unlock(philo->r_mutex);
		}
		if (philo->died == 1)
		{
			printf("philo %d died. Died at:%ld", philo->id, philo->time_of_death);
			break;
		}
	
		// if (philo->num_of_time_eaten == 1)
			// break;
	}

	// end of the while loop
	printf("\nid:%d, num_must_eat:%d, numoftimeeaten:%d\n", philo->id, philo->num_must_eat, philo->num_of_time_eaten);
	printf("Expected 1 if died:%d\n\n", philo->died);
    return NULL;
}

void *thread_function_original(void *arg)
{

	struct s_philo *philo;
	philo = (struct s_philo *) arg;

	//condition to break it
	while (1)
	{

		pthread_mutex_lock(philo->curr_mutex);
		// ft_usleep(1);
		philo->curr = get_current_time();
		printf("\n\npid:%d|updated time curr:%lu\n", philo->id, philo->curr);
		pthread_mutex_unlock(philo->curr_mutex);

		// cases to break
		// if (philo->died == 1)
		// {
		// 	break;
		// }
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


		// Odd number of philo. Split to 3 groups
		if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 1))
		{
			pthread_mutex_lock(philo->l_mutex);
			pthread_mutex_lock(philo->r_mutex);
			pthread_mutex_lock(&philo->eating_mutex);
			philo->last_meal_time = get_current_time();
			// printf("last meal time:%lu\n", philo->last_meal_time);
			// printf("id:%d is eating at %lu\n", philo->id, philo->curr);
			philo->status = 1;
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
			pthread_mutex_unlock(&philo->eating_mutex);
			pthread_mutex_unlock(philo->l_mutex);
			pthread_mutex_unlock(philo->r_mutex);
		}
		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 0))
		{
			pthread_mutex_lock(&philo->sleeping_mutex);
			// printf("id:%d is sleeping for :%d\n", philo->id, philo->time_to_sleep);
			ft_usleep(philo->time_to_sleep);
			philo->status = 2;
			philo->last_meal_time = philo->curr;
			pthread_mutex_unlock(&philo->sleeping_mutex);
		}
		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id == philo->max))
		{
			// printf("id:%d is thinking\n", philo->id);
			pthread_mutex_lock(&philo->thinking_mutex);
			philo->status = 3;
			philo->last_meal_time = philo->curr;
			pthread_mutex_unlock(&philo->thinking_mutex);
		}

		// even number of philo
		else if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id %2 == 0))
		{
			// printf("curr:%lu\n", philo->curr);
			// printf("last meal time:%lu\n", philo->last_meal_time);
			// eat
			pthread_mutex_lock(philo->l_mutex);
			pthread_mutex_lock(philo->r_mutex);
			pthread_mutex_lock(&philo->eating_mutex);
			philo->last_meal_time = get_current_time();
			// printf("id:%d is eating\n", philo->id);
			philo->status = 1;
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
			pthread_mutex_unlock(&philo->eating_mutex);
			pthread_mutex_unlock(philo->l_mutex);
			pthread_mutex_unlock(philo->r_mutex);
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

		// otherwise we check the previous status and do stuff
		else if (philo->status == 1)
		{
			// printf("\ncase status 1\n");

			//sleep
			pthread_mutex_lock(&philo->sleeping_mutex);
			// printf("id:%d|curr:%ld is sleeping:+%d\n", philo->id, philo->curr, philo->time_to_sleep);
			printf("%ld %d is sleeping | for %lu time %lu\n", philo->curr, philo->id, philo->time_to_sleep, get_current_time());
			if ((philo->curr - philo->last_meal_time) + philo->time_to_sleep > philo->time_to_die)
			{
				ft_usleep((philo->time_to_die) - (philo->curr - philo->last_meal_time));
				philo->time_of_death = get_current_time();
				philo->died = 1;
				// can continue with the process here if required
				break;
			}
			else
				ft_usleep(philo->time_to_sleep);
			philo->status = 2;
			pthread_mutex_unlock(&philo->sleeping_mutex);
			//set to think for status
		}
		else if (philo->status == 2)
		{
			// printf("\ncase status 2\n");
			// printf("id:%d|curr:%ld is thinking:+%d\n", philo->id, philo->curr, 1);
			pthread_mutex_lock(&philo->thinking_mutex);
			printf("%ld %d is thinking | for %d time %lu\n", philo->curr, philo->id, 1, get_current_time());
			printf("Thinking is set to 1 ms\n");
			ft_usleep(1);
			philo->status = 3;
			pthread_mutex_unlock(&philo->thinking_mutex);

		}
		else if (philo->status == 3)
		{
			// printf("pid:%d curr:%lu\n", philo->id ,philo->curr);
			printf("id:%d|curr:%ld last meal time:%lu\n", philo->id, philo->curr, philo->last_meal_time);
			// update to next staus: 1
			pthread_mutex_lock(philo->l_mutex);
			printf("%ld %d has taken a fork | %lu\n", philo->curr, philo->id, get_current_time());
			pthread_mutex_lock(philo->r_mutex);
			printf("%ld %d has taken a fork | %lu\n", philo->curr, philo->id, get_current_time());
			pthread_mutex_lock(&philo->eating_mutex);

			if ((philo->curr - philo->last_meal_time) + philo->time_to_eat > philo->time_to_die)			
			{
				printf("eating got issue!!!\n");
				printf("curr:%lu\n", philo->curr);
				printf("lastm:%lu\n", philo->last_meal_time);
				printf("tte:%lu\n", philo->time_to_eat);
				printf("ttd:%lu\n", philo->time_to_die);
				
				// ft_usleep(philo->time_to_die - (philo->curr - philo->last_meal_time));
				ft_usleep(1);
				philo->time_of_death = get_current_time();
				philo->died = 1;
				// i can continue with the process here if required.
				break;
			}
			else
			{
				printf("%ld %d is eating | for %lu time %lu\n", philo->curr, philo->id, philo->time_to_eat, get_current_time());
				ft_usleep(philo->time_to_eat);
				philo->last_meal_time = get_current_time();

			}
			
			// printf("id:%d|curr:%ld lastmealtime:%lu just finished eating\n", philo->id, philo->curr, philo->last_meal_time);
			if (philo->last_meal_time > philo->curr)
				printf("id:%d|curr:%ld vs last meal: %ld\n", philo->id, philo->curr, philo->last_meal_time);
			philo->status = 1;
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
			pthread_mutex_unlock(&philo->eating_mutex);
			pthread_mutex_unlock(philo->l_mutex);
			pthread_mutex_unlock(philo->r_mutex);
		}

	}

	// end of the while loop
	printf("\nEnd PHILO! id:%d, num_must_eat:%d, numoftimeeaten:%d\n", philo->id, philo->num_must_eat, philo->num_of_time_eaten);
	printf("Expected 1 if died:%d\n\n", philo->died);
    return NULL;
}
