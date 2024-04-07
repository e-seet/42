#include "utils.h"

void	update_current_time_now(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->curr_mutex);
	philo->curr = get_current_time();
	printf("\n\npid:%d|updated time curr:%lu\n", philo->id, philo->curr);
	pthread_mutex_unlock(&philo->curr_mutex);
}

void	update_current_time(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->curr_mutex);
	philo->curr = get_current_time();
	printf("\n\npid:%d|updated time curr:%lu\n", philo->id, philo->curr);
	pthread_mutex_unlock(&philo->curr_mutex);
}

void	check_death_condition(struct s_philo *philo)
{
	if ((philo->last_meal_time > 0) && ((philo->curr - philo->last_meal_time)
			> philo->time_to_die))
	{
		philo->time_of_death = get_current_time();
		printf("id%d\ntime of death:%lu.\nHow long since it passed:%lu\n",
			philo->id, philo->time_of_death,
			philo->curr - philo->last_meal_time);
	}
}

void	check_finished_eating(struct s_philo *philo)
{
	if (philo->num_must_eat == 0)
	{
		printf("philo%d|Curr:%ld\n: finished eating.", philo->id, philo->curr);
	}
}

// Checked the function below
void	handle_odd_philo_eating(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id != philo->max) && (philo->id % 2 == 1))
	{
		pthread_mutex_lock(&philo->l_mutex);
		pthread_mutex_lock(&philo->r_mutex);
		pthread_mutex_lock(&philo->eating_mutex);
		if (philo->time_to_eat > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
			ft_usleep(philo->time_to_eat);
		philo->last_meal_time = get_current_time();
		philo->status = 1;
		if (philo->num_must_eat > 0)
			philo->num_must_eat = philo->num_must_eat - 1;
		philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		pthread_mutex_unlock(&philo->eating_mutex);
		pthread_mutex_unlock(&philo->l_mutex);
		pthread_mutex_unlock(&philo->r_mutex);
	}
}

// Checked the function below
void	handle_odd_philo_sleeping(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id != philo->max) && (philo->id % 2 == 0))
	{
		pthread_mutex_lock(&philo->sleeping_mutex);
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

// Checked the function below
void	handle_odd_philo_thinking(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id == philo->max))
	{
		pthread_mutex_lock(&philo->thinking_mutex);
		philo->last_meal_time = philo->curr;
		printf("think for 1 ms TEMP AT THE START\n");
		if (1 > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
			ft_usleep(1);
		philo->status = 3;
		pthread_mutex_unlock(&philo->thinking_mutex);
	}
}

// Checked the function below
void	handle_even_philo_eating(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id % 2 == 0))
	{
		pthread_mutex_lock(&philo->l_mutex);
		pthread_mutex_lock(&philo->r_mutex);
		pthread_mutex_lock(&philo->eating_mutex);
		if (philo->time_to_eat > philo->time_to_die)
		{
			ft_usleep(philo->time_to_die);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
			ft_usleep(philo->time_to_eat);
		philo->last_meal_time = get_current_time();
		philo->status = 1;
		if (philo->num_must_eat > 0)
			philo->num_must_eat = philo->num_must_eat - 1;
		philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		pthread_mutex_unlock(&philo->eating_mutex);
		pthread_mutex_unlock(&philo->l_mutex);
		pthread_mutex_unlock(&philo->r_mutex);
	}
}

// Checked and handled death
void	handle_even_philo_sleeping(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id % 2 == 1))
	{
		pthread_mutex_lock(&philo->sleeping_mutex);
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

// Checked and handled died
void	handle_philo_sleeping(struct s_philo *philo)
{
	if (philo->status == 1)
	{
		pthread_mutex_lock(&philo->sleeping_mutex);
		printf("%ld %d is sleeping | for %lu time %lu\n",
			philo->curr, philo->id, philo->time_to_sleep, get_current_time());
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

// Checked and handle died
void	handle_philo_thinking(struct s_philo *philo)
{
	if (philo->status == 2)
	{
		pthread_mutex_lock(&philo->thinking_mutex);
		printf("%ld %d is thinking | for %d time %lu\n",
			philo->curr, philo->id, 1, get_current_time());
		printf("Thinking is set to 1 ms\n");
		if ((philo->curr - philo->last_meal_time) + 1 > philo->time_to_die)
		{
			ft_usleep(1);
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
			ft_usleep(1);
		philo->status = 3;
		pthread_mutex_unlock(&philo->thinking_mutex);
	}
}

// Checked and handled Died
void	handle_philo_eating(struct s_philo *philo)
{
	if (philo->status == 3)
	{
		pthread_mutex_lock(&philo->l_mutex);
		printf("%ld %d has taken a fork | %lu\n",
			philo->curr, philo->id, get_current_time());
		pthread_mutex_lock(&philo->r_mutex);
		printf("%ld %d has taken a fork | %lu\n",
			philo->curr, philo->id, get_current_time());
		pthread_mutex_lock(&philo->eating_mutex);
		if ((philo->curr - philo->last_meal_time)
			+ philo->time_to_eat > philo->time_to_die)
		{
			printf("eating got issue!!!\n");
			printf("check last meal time:%lu\n", philo->last_meal_time);
			printf("value:%lu\n", (philo->curr - philo->last_meal_time)
				+ philo->time_to_eat);
			ft_usleep(philo->time_to_die
				- (philo->curr - philo->last_meal_time));
			philo->time_of_death = get_current_time();
			philo->died = 1;
		}
		else
		{
			printf("%ld %d is eating | for %lu time %lu\n",
				philo->curr, philo->id, philo->time_to_eat, get_current_time());
			ft_usleep(philo->time_to_eat);
			philo->last_meal_time = get_current_time();
			if (philo->num_must_eat > 0)
				philo->num_must_eat = philo->num_must_eat - 1;
			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
		}
		philo->status = 1;
		pthread_mutex_unlock(&philo->eating_mutex);
		pthread_mutex_unlock(&philo->l_mutex);
		pthread_mutex_unlock(&philo->r_mutex);
	}
}

// Later
void	*thread_function_backup(void *arg)
{
	struct s_philo	*philo;

	philo = (struct s_philo *) arg;
	while (1)
	{
		update_current_time(philo);
		check_death_condition(philo);
		check_finished_eating(philo);
		handle_odd_philo_eating(philo);
		handle_odd_philo_sleeping(philo);
		handle_odd_philo_thinking(philo);
		handle_even_philo_eating(philo);
		handle_even_philo_sleeping(philo);
		handle_philo_sleeping(philo);
		handle_philo_thinking(philo);
		handle_philo_eating(philo);
		if (philo->died == 1)
			break ;
		if (philo->num_must_eat == 0)
			break ;
	}
	printf("\nENDED PHILO id:%d, num_must_eat:%d, numoftimeeaten:%d\n",
		philo->id, philo->num_must_eat, philo->num_of_time_eaten);
	printf("Expected 1 if died:%d\n\n", philo->died);
	return (NULL);
}
