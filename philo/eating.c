#include "utils.h"

void	handle_odd_philo_eating(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 1)
		&& (philo->id != philo->max) && (philo->id % 2 == 1))
	{
		// if ((void *)philo->r_mutex == (void *)philo->l_mutex)
		// {
		// 	pthread_mutex_lock(philo->l_mutex);
		// 	printf("%ld %d has taken a fork\n",philo->curr, philo->id);
		// 	philo->locked_l = 1;
		// 	ft_usleep(philo->time_to_die);
		// 	philo->time_of_death = get_current_time();
		// 	philo->died = 1;
		// 	philo->locked_l = 1;
		// 	pthread_mutex_unlock(philo->l_mutex);
		// }
		// else
		// {
			pthread_mutex_lock(philo->l_mutex);
			pthread_mutex_lock(philo->r_mutex);
			printf("%ld %d has taken a fork\n",philo->curr, philo->id);
			printf("%ld %d has taken a fork\n",philo->curr, philo->id);
			
			if (philo->max - 1 == philo->id)
			{
				philo->mutexs_i[philo->id] = 1;
				philo->mutexs_i[0] = 1;
			}
			else
			{
				philo->mutexs_i[philo->id] = 1;
				philo->mutexs_i[philo->id + 1] = 1;
			}
			pthread_mutex_lock(&philo->eating_mutex);

			printf("%ld %d is eating\n", philo->curr, philo->id);
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

		
			if (philo->max - 1 == philo->id)
			{
				philo->mutexs_i[philo->id] = 0;
				philo->mutexs_i[0] = 0;
			}
			else
			{
				philo->mutexs_i[philo->id] = 0;
				philo->mutexs_i[philo->id + 1] = 0;
			}

			// printf("%ld %d has release a fork\n",philo->curr, philo->id);
			// printf("%ld %d has release a fork\n",philo->curr, philo->id);
			pthread_mutex_unlock(philo->l_mutex);
			pthread_mutex_unlock(philo->r_mutex);

		// }
	}
}

void	handle_even_philo_eating(struct s_philo *philo)
{
	if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id % 2 == 0))
	{
		pthread_mutex_lock(philo->l_mutex);
		pthread_mutex_lock(philo->r_mutex);
		printf("%ld %d has taken a fork\n",philo->curr, philo->id);
		printf("%ld %d has taken a fork\n",philo->curr, philo->id);

		if (philo->max - 1 == philo-> id)
		{
			philo->mutexs_i[0] = 1;
			philo->mutexs_i[philo->id] = 1;
		}
		else
		{
			philo->mutexs_i[philo->id] = 1;
			philo->mutexs_i[philo->id + 1] = 1;
		}

		// pthread_mutex_lock(&philo->eating_mutex);
		printf("%ld %d is eating\n", philo->curr, philo->id);
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
		// pthread_mutex_unlock(&philo->eating_mutex);

		if (philo->max - 1 == philo-> id)
		{
			philo->mutexs_i[0] = 0;
			philo->mutexs_i[philo->id] = 0;
		}
		else
		{
			philo->mutexs_i[philo->id] = 0;
			philo->mutexs_i[philo->id + 1] = 0;
		}

		// printf("%ld %d has release a fork\n",philo->curr, philo->id);
		// printf("%ld %d has release a fork\n",philo->curr, philo->id);

		pthread_mutex_unlock(philo->l_mutex);
		pthread_mutex_unlock(philo->r_mutex);
		// printf("%ld %d has return a fork\n",philo->curr, philo->id);
		// printf("%ld %d has return a fork\n",philo->curr, philo->id);
	}
}

void	handle_philo_eating(struct s_philo *philo)
{
	if (philo->status == 3)
	{
		if ((void *)philo->r_mutex == (void *)philo->l_mutex)
		{
			pthread_mutex_lock(philo->l_mutex);
			// philo->locked_l = 1;
			if (philo->max - 1 == philo-> id)
			{
				philo->mutexs_i[philo->id] = 1;
			}
			else
			{
				philo->mutexs_i[philo->id] = 1;
			}

			printf("%ld %d has taken a fork\n",philo->curr, philo->id);
			if ((philo->curr - philo->last_meal_time)
				+ philo->time_to_eat > philo->time_to_die)
			ft_usleep(philo->time_to_die
					- (philo->curr - philo->last_meal_time));
			philo->time_of_death = get_current_time();
			philo->died = 1;
			philo->status = 1;

			if (philo->max - 1 == philo-> id)
			{
				philo->mutexs_i[philo->id] = 0;
			}
			else
			{
				philo->mutexs_i[philo->id] = 0;
			}
			// printf("%ld %d has release a fork\n",philo->curr, philo->id);
			pthread_mutex_unlock(philo->l_mutex);
		}
		else
		{
			pthread_mutex_lock(philo->l_mutex);
			pthread_mutex_lock(philo->r_mutex);
			if (philo->max - 1 == philo-> id)
			{
				philo->mutexs_i[0] = 1;
				philo->mutexs_i[philo->id] = 1;
			}
			else
			{
				philo->mutexs_i[philo->id] = 1;
				philo->mutexs_i[philo->id + 1] = 1;
			}
			
			printf("%ld %d has taken a fork\n",
				philo->curr, philo->id);
			printf("%ld %d has taken a fork\n",
				philo->curr, philo->id);

			// printf("checking left mutex:%p\n",  (void *) &philo->l_mutex);
			// printf("checking right mutex:%p\n",  (void *) &philo->r_mutex);

			// pthread_mutex_lock(&philo->eating_mutex);
			printf("%ld %d is eating\n", philo->curr, philo->id);
			if ((philo->curr - philo->last_meal_time)
				+ philo->time_to_eat > philo->time_to_die)
			{
				// printf("eating got issue!!!\n");
				// printf("check last meal time:%lu\n", philo->last_meal_time);
				// printf("value:%lu\n", (philo->curr - philo->last_meal_time)
					// + philo->time_to_eat);
				ft_usleep(philo->time_to_die
					- (philo->curr - philo->last_meal_time));
				philo->time_of_death = get_current_time();
				philo->died = 1;
			}
			else
			{
				// printf("%ld %d is eating | for %lu time %lu\n",
					// philo->curr, philo->id, philo->time_to_eat, get_current_time());
				ft_usleep(philo->time_to_eat);
				philo->last_meal_time = get_current_time();
				if (philo->num_must_eat > 0)
					philo->num_must_eat = philo->num_must_eat - 1;
				philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
			}
			philo->status = 1;
			// pthread_mutex_unlock(&philo->eating_mutex);

			if (philo->max - 1 == philo-> id)
			{
				philo->mutexs_i[0] = 0;
				philo->mutexs_i[philo->id] = 0;
			}
			else
			{
				philo->mutexs_i[philo->id] = 0;
				philo->mutexs_i[philo->id + 1] = 0;
			}

			// printf("%ld %d has release a fork\n",philo->curr, philo->id);
			// printf("%ld %d has release a fork\n",philo->curr, philo->id);
			pthread_mutex_unlock(philo->l_mutex);
			pthread_mutex_unlock(philo->r_mutex);
		}
	}
}
