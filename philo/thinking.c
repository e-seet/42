#include "utils.h"

void	handle_odd_philo_thinking(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->thinking_mutex);
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id == philo->max))
	{
		philo->last_meal_time = (philo->curr);
		printf("%ld %d is thinking\n", (philo->curr - philo->start), philo->id);
		philo->status = 3;

		while (1)
		{
			if (philo->max - 1 == philo->id)
			{
				if (philo->mutexs_i[philo->id] == 0 && philo->mutexs_i[0] == 0)
					break;
				else
				{
					ft_usleep(1);
					update_current_time_now(philo);
				}
			}
			else
			{
				if (philo->mutexs_i[philo->id] == 0 && philo->mutexs_i[philo->id + 1] == 0)
					break;
				else
				{
					ft_usleep(1);
					update_current_time_now(philo);
				}
			}
		}
		pthread_mutex_unlock(&philo->thinking_mutex);
	}
}

void	handle_philo_thinking(struct s_philo *philo)
{
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
				break;
			}
			else if (philo->max - 1 == philo->id)
			{
				if (philo->mutexs_i[philo->id] == 0 && philo->mutexs_i[0] == 0)
					break;
				else
				{
					ft_usleep(1);
					update_current_time_now(philo);
				}
			}
			else
			{
				if (philo->mutexs_i[philo->id] == 0 && philo->mutexs_i[philo->id + 1] == 0)
					break;
				else
				{
					ft_usleep(1);
					update_current_time_now(philo);
				}
			}

		}
		philo->status = 3;
	}
	pthread_mutex_unlock(&philo->thinking_mutex);
}

