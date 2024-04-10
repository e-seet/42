#include "utils.h"

void	handle_odd_philo_sleeping(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->sleeping_mutex);
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id != philo->max) && (philo->id % 2 == 0))
	{
		philo->last_meal_time = (philo->curr);
		printf("%ld %d is sleeping\n", philo->curr, philo->id);
		if (philo->time_to_sleep > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
			ft_usleep(philo->time_to_sleep);
		philo->status = 2;
	}
	pthread_mutex_unlock(&philo->sleeping_mutex);
}

void	handle_even_philo_sleeping(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->sleeping_mutex);
	if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id % 2 == 1))
	{
		printf("%ld %d is sleeping\n", philo->curr - philo->start, philo->id);
		philo->last_meal_time = (philo->curr);
		if (philo->time_to_sleep > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
			ft_usleep(philo->time_to_sleep);
		philo->status = 2;
	}
	pthread_mutex_unlock(&philo->sleeping_mutex);

}

void	handle_philo_sleeping(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->sleeping_mutex);
	int elapsed;
	printf("normal sleep\n");
	if (philo->status == 1)
	{
		printf("%ld %d is sleeping\n", (philo->curr - philo->start), philo->id);

		// printf("%ld %d is sleeping | for %lu time %lu\n",
			// (philo->curr - philo->start), philo->id, philo->time_to_sleep, get_current_time());
		if (((philo->curr) - philo->last_meal_time) + philo->time_to_sleep > philo->time_to_die)
		{
			ft_usleep((philo->time_to_die) - ((philo->curr) - philo->last_meal_time));
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			elapsed = ft_usleep(philo->time_to_sleep);
			printf("sleep elapsed:%d\n", elapsed);
		}
		philo->status = 2;
	}
	pthread_mutex_unlock(&philo->sleeping_mutex);
}
