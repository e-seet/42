#include "utils.h"

void	freestuff(struct s_philo **philos, int num)
{
	while (num --)
	{
		pthread_mutex_destroy(philos[num]->curr_mutex);
		free(philos[num]->curr_mutex);
		free(philos[num]);
	}
}

void	update_current_time_now(struct s_philo *philo)
{
	pthread_mutex_lock(philo->curr_mutex);
	philo->curr = get_current_time();
	// printf("\n\npid:%d|updated time curr:%lu\n", philo->id, philo->curr);
	pthread_mutex_unlock(philo->curr_mutex);
}

void	update_current_time(struct s_philo *philo)
{
	pthread_mutex_lock(philo->curr_mutex);
	philo->curr = get_current_time();
	// printf("\n\npid:%d|updated time curr:%lu\n", philo->id, philo->curr);
	pthread_mutex_unlock(philo->curr_mutex);
}

void	check_death_condition(struct s_philo *philo)
{
	if ((philo->last_meal_time > 0) && ((philo->curr - philo->last_meal_time)
			> philo->time_to_die))
	{
		philo->time_of_death = get_current_time();
		// printf("id%d\ntime of death:%lu.\nHow long since it passed:%lu\n",
			// philo->id, philo->time_of_death,
			// philo->curr - philo->last_meal_time);
	}
}

void	check_finished_eating(struct s_philo *philo)
{
	if (philo->num_must_eat == 0)
	{
		// printf("philo%d|Curr:%ld\n: finished eating.", philo->id, philo->curr);
	}
}

void	handle_odd_philo_sleeping(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id != philo->max) && (philo->id % 2 == 0))
	{
		pthread_mutex_lock(&philo->sleeping_mutex);
		philo->last_meal_time = philo->curr;
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
		philo->last_meal_time = philo->curr;
		printf("%ld %d is thinking\n", philo->curr, philo->id);
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
		philo->last_meal_time = philo->curr;
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
		printf("%ld %d is sleeping\n", philo->curr, philo->id);

		// printf("%ld %d is sleeping | for %lu time %lu\n",
			// philo->curr, philo->id, philo->time_to_sleep, get_current_time());
		if ((philo->curr - philo->last_meal_time)
			+ philo->time_to_sleep > philo->time_to_die)
		{
			ft_usleep((philo->time_to_die)
				- (philo->curr - philo->last_meal_time));
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
		printf("%ld %d is thinking\n", philo->curr, philo->id);
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
		philo->status = 3;
	}
}

