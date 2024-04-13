#include "utils.h"

void	lastfella(struct s_philo *philo, int *elapsed)
{
	if (philo->mutexs_i[philo->id] == 0 && (philo->mutexs_i[0] == 0))
	{
		lock_bothforkmutex(philo);
		if ((philo->curr - philo->last_meal_time)
			+ philo->time_to_eat > philo->time_to_die)
		{
			if (philo->curr - philo->last_meal_time
				> philo->time_to_die)
				ft_usleep(philo->time_to_die
					- (philo->curr - philo->last_meal_time));
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			*elapsed = ft_usleep(philo->time_to_eat);
			printf("%d eating elapsed: %d\n", philo->id, *elapsed);
			philo->last_meal_time = get_current_time();
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		}
		unlock_bothforkmutex(philo);
	}
}

void	normalfella(struct s_philo *philo, int *elapsed)
{
	if (philo->mutexs_i[philo->id] == 0
		&& (philo->mutexs_i[philo->id + 1] == 0))
	{
		lock_bothforkmutex(philo);
		if ((philo->curr - philo->last_meal_time)
			+ philo->time_to_eat > philo->time_to_die)
		{
			if (philo->curr - philo->last_meal_time
				> philo->time_to_die)
				ft_usleep(philo->time_to_die
					- (philo->curr - philo->last_meal_time));
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			*elapsed = ft_usleep(philo->time_to_eat);
			printf("%d eating elapsed: %d\n", philo->id, *elapsed);
			philo->last_meal_time = get_current_time();
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		}
		unlock_bothforkmutex(philo);
	}
}

void	handle_odd_philo_eating(struct s_philo *philo)
{
	if (philo->status == 0 && philo->routinesemaphore[0] == 1
		&& (philo->max % 2 == 1) && (philo->id != philo->max)
		&& (philo->id % 2 == 1))
	{
		lock_bothforkmutex(philo);
		if (philo->time_to_eat > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			ft_usleep(philo->time_to_eat);
			philo->last_meal_time = get_current_time();
			philo->status = 1;
			philo->routinesemaphore[0] = 0;
			philo->routinesemaphore[1] = 1;
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		}
		unlock_bothforkmutex(philo);
	}
}

void	handle_even_philo_eating(struct s_philo *philo)
{
	if (philo->status == 0 && philo->routinesemaphore[0] == 1
		&& (philo->max % 2 == 0) && (philo->id % 2 == 0))
	{
		lock_bothforkmutex(philo);
		if (philo->time_to_eat > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			ft_usleep(philo->time_to_eat);
			philo->last_meal_time = get_current_time();
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		}
		unlock_bothforkmutex(philo);
	}
}

void	handle_philo_eating(struct s_philo *philo)
{
	int	elapsed;

	elapsed = 0;
	if (philo->status == 3 && philo->routinesemaphore[3] == 1)
	{
		if (philo->max - 1 == philo->id)
		{
			lastfella(philo, &elapsed);
		}
		else
		{
			normalfella(philo, &elapsed);
		}
	}
}
