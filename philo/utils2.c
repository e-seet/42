#include "utils.h"

void	handle_odd_philo_sleeping(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id != philo->max) && (philo->id % 2 == 0))
	{
		pthread_mutex_lock(&philo->sleeping_mutex);
		philo->last_meal_time = (philo->curr - philo->start);
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
		pthread_mutex_unlock(&philo->sleeping_mutex);
	}
}

void	handle_odd_philo_thinking(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id == philo->max))
	{
		// pthread_mutex_lock(&philo->thinking_mutex);
		philo->last_meal_time = (philo->curr - philo->start);
		printf("%ld %d is thinking\n", (philo->curr), philo->id);
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

		// while (1)

		// pthread_mutex_unlock(&philo->thinking_mutex);
	}
}

void	handle_even_philo_sleeping(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id % 2 == 1))
	{
		pthread_mutex_lock(&philo->sleeping_mutex);
		printf("%ld %d is sleeping\n", philo->curr, philo->id);
		philo->last_meal_time = (philo->curr - philo->start);
		if (philo->time_to_sleep > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
			ft_usleep(philo->time_to_sleep);
		philo->status = 2;
		pthread_mutex_unlock(&philo->sleeping_mutex);
	}
}

void	handle_philo_sleeping(struct s_philo *philo)
{
	if (philo->status == 1)
	{
		pthread_mutex_lock(&philo->sleeping_mutex);
		printf("%ld %d is sleeping\n", (philo->curr), philo->id);

		// printf("%ld %d is sleeping | for %lu time %lu\n",
			// (philo->curr - philo->start), philo->id, philo->time_to_sleep, get_current_time());
		if (((philo->curr - philo->start) - philo->last_meal_time)
			+ philo->time_to_sleep > philo->time_to_die)
		{
			ft_usleep((philo->time_to_die)
				- ((philo->curr - philo->start) - philo->last_meal_time));
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			ft_usleep(philo->time_to_sleep);
		}
		philo->status = 2;
		pthread_mutex_unlock(&philo->sleeping_mutex);
	}
}

void	handle_philo_thinking(struct s_philo *philo)
{
	if (philo->status == 2)
	{
		printf("%ld %d is thinking\n", (philo->curr), philo->id);
		while (1)
		{

			if ((philo->curr - philo->start) - philo->last_meal_time > philo->time_to_die)
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
}

