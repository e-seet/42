#include "utils.h"

int	sleeproutine(struct s_philo *philo)
{
	if (philo->max - 1 == philo->id)
	{
		if (philo->mutexs_i[philo->id] == 0 && philo->mutexs_i[0] == 0)
			return (1);
		else
		{
			ft_usleep(1);
			update_current_time_now(philo);
		}
	}
	else
	{
		if (philo->mutexs_i[philo->id] == 0
			&& philo->mutexs_i[philo->id + 1] == 0)
			return (1);
		else
		{
			ft_usleep(1);
			update_current_time_now(philo);
		}
	}
	return (0);
}

void	handle_odd_philo_thinking(struct s_philo *philo)
{
	int	breakval;

	pthread_mutex_lock(&philo->thinking_mutex);
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id == philo->max))
	{
		philo->last_meal_time = (philo->curr);
		printf("%ld %d is thinking\n", (philo->curr - philo->start), philo->id);
		philo->status = 3;
		while (1)
		{
			breakval = sleeproutine(philo);
			if (breakval == 1)
				break ;
		}
		pthread_mutex_unlock(&philo->thinking_mutex);
	}
}

void	handle_philo_thinking(struct s_philo *philo)
{
	int	breakval;

	pthread_mutex_lock(&philo->thinking_mutex);
	if (philo->status == 2)
	{
		printf("%ld %d is thinking\n", (philo->curr - philo->start), philo->id);
		while (1)
		{
			if ((philo->curr) - philo->last_meal_time > philo->time_to_die)
			{
				philo->time_of_death = (philo->curr);
				philo->died = 1;
				break ;
			}
			else
			{
				breakval = sleeproutine(philo);
				if (breakval == 1)
					break ;
			}
		}
		philo->status = 3;
	}
	pthread_mutex_unlock(&philo->thinking_mutex);
}
