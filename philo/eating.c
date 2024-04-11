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
			printf("%ld %d has taken a fork\n",philo->curr - philo->start, philo->id);
			printf("%ld %d has taken a fork\n",philo->curr - philo->start, philo->id);
			
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

			printf("%ld %d is eating\n", philo->curr - philo->start, philo->id);
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
			{
				printf("%d num must eat before -1 :%d\n", philo->id, philo->num_must_eat);
				philo->num_must_eat = philo->num_must_eat - 1;
				printf("%d num must eat after -1:%d\n", philo->id, philo->num_must_eat);
			}
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

			// printf("%ld %d has release a fork\n",philo->curr - philo->start, philo->id);
			// printf("%ld %d has release a fork\n",philo->curr - philo->start, philo->id);
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
		printf("%ld %d has taken a fork\n",philo->curr - philo->start, philo->id);
		printf("%ld %d has taken a fork\n",philo->curr - philo->start, philo->id);

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
		printf("%ld %d is eating\n", philo->curr - philo->start, philo->id);
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
		{
			printf("%d num must eat before -1 :%d\n", philo->id, philo->num_must_eat);
			philo->num_must_eat = philo->num_must_eat - 1;
			printf("%d num must eat after -1:%d\n", philo->id, philo->num_must_eat);

		}
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

		pthread_mutex_unlock(philo->l_mutex);
		pthread_mutex_unlock(philo->r_mutex);

	}
}

void	handle_philo_eating(struct s_philo *philo)
{
	int elapsed = 0;
	if (philo->status == 3)
	{
		printf("normal eat\n");
		if (philo->max - 1 == philo->id)
		{
			// if (philo->mutexs_i[philo->id] == 0)
			// {
			// 	pthread_mutex_lock(philo->l_mutex);
			// 	philo->mutexs_i[philo->id] = 1;
			// 	printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);
			// 	check ++;
			// }
			// if (philo->mutexs_i[0] == 0)
			// {
			// 	pthread_mutex_lock(philo->r_mutex);
			// 	philo->mutexs_i[0] = 1;
			// 	printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);
			// 	check ++;
			// }
			// if (check == 2)

			if (philo->mutexs_i[philo->id] == 0 && (philo->mutexs_i[0] == 0))
			{
				pthread_mutex_lock(philo->l_mutex);
				philo->mutexs_i[philo->id] = 1;
				printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);

				pthread_mutex_lock(philo->r_mutex);
				philo->mutexs_i[0] = 1;
				printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);

				// lock it and do my usual stuff
				// pthread_mutex_lock(&philo->eating_mutex);
				if ((philo->curr - philo->last_meal_time)
					+ philo->time_to_eat > philo->time_to_die)
				{
					if(philo->curr - philo->last_meal_time > philo->time_to_die)
					{
						printf("%ld %d is eating\n", philo->curr - philo->start, philo->id);
						printf("otw to die\n");
						ft_usleep(philo->time_to_die
							- (philo->curr - philo->last_meal_time));
					}
					
					philo->time_of_death = get_current_time();
					philo->died = 1;
				}
				else
				{
					printf("%ld %d is eating\n", philo->curr - philo->start, philo->id);
					printf("eat normal1: %lu\n", philo->time_to_eat);
					elapsed = ft_usleep(philo->time_to_eat);
					printf("eating elapsed: %d\n", elapsed);
					philo->last_meal_time = get_current_time();
					if (philo->num_must_eat > 0)
					{
						printf("%d num must eat before -1 :%d\n", philo->id, philo->num_must_eat);
						philo->num_must_eat = philo->num_must_eat - 1;
						printf("%d num must eat after -1:%d\n", philo->id, philo->num_must_eat);
					}
					philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
				}
				philo->status = 1;
				// pthread_mutex_unlock(&philo->eating_mutex);

				pthread_mutex_unlock(philo->l_mutex);
				philo->mutexs_i[philo->id] = 0;
				// printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);

				pthread_mutex_unlock(philo->r_mutex);
				philo->mutexs_i[0] = 0;
				// printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);

			}
		}
		// for the other set of test case
		else
		{
			// if (philo->mutexs_i[philo->id] == 0)
			// {
			// 	pthread_mutex_lock(philo->l_mutex);
			// 	philo->mutexs_i[philo->id] = 1;
			// 	printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);
			// }
			// if (philo->mutexs_i[philo->id + 1] == 0)
			// {
			// 	pthread_mutex_lock(philo->r_mutex);
			// 	philo->mutexs_i[philo->id + 1] = 1;
			// 	printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);
			// }
			// if (check == 2)

			if (philo->mutexs_i[philo->id] == 0 && (philo->mutexs_i[philo->id + 1] == 0))
			{

				pthread_mutex_lock(philo->l_mutex);
				philo->mutexs_i[philo->id] = 1;
				printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);

				pthread_mutex_lock(philo->r_mutex);
				philo->mutexs_i[philo->id + 1] = 1;
				printf("%ld %d has taken a fork\n", philo->curr - philo->start, philo->id);

				// pthread_mutex_lock(&philo->eating_mutex);
				if ((philo->curr - philo->last_meal_time)
					+ philo->time_to_eat > philo->time_to_die)
				{
					if(philo->curr - philo->last_meal_time > philo->time_to_die)
					{
						printf("%ld %d is eating\n", philo->curr - philo->start, philo->id);
						printf("otw to die\n");
						ft_usleep(philo->time_to_die
							- (philo->curr - philo->last_meal_time));
					}
					
					philo->time_of_death = get_current_time();
					philo->died = 1;
				}
				else
				{
					printf("%ld %d is eating\n", philo->curr - philo->start, philo->id);
					printf("eat normal2: %lu\n", philo->time_to_eat);
					elapsed = ft_usleep(philo->time_to_eat);
					printf("eating elapsed: %d\n", elapsed);
					philo->last_meal_time = get_current_time();
					if (philo->num_must_eat > 0)
					{
						printf("%d num must eat before -1 :%d\n", philo->id, philo->num_must_eat);
						philo->num_must_eat = philo->num_must_eat - 1;
						printf("%d num must eat after -1:%d\n", philo->id, philo->num_must_eat);
					}
					philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
				}
				philo->status = 1;
				// pthread_mutex_unlock(&philo->eating_mutex);

				pthread_mutex_unlock(philo->l_mutex);
				philo->mutexs_i[philo->id] = 0;

				pthread_mutex_unlock(philo->r_mutex);
				philo->mutexs_i[philo->id + 1] = 0;
			}
		}

		//ending
		// if (philo->max - 1 == philo-> id)
		// {
		// 	philo->mutexs_i[0] = 0;
		// 	philo->mutexs_i[philo->id] = 0;
		// }
		// else
		// {
		// 	philo->mutexs_i[philo->id] = 0;
		// 	philo->mutexs_i[philo->id + 1] = 0;
		// }

			// printf("%ld %d has release a fork\n",philo->curr - philo->start, philo->id);
			// printf("%ld %d has release a fork\n",philo->curr - philo->start, philo->id);
			// pthread_mutex_unlock(philo->l_mutex);
			// pthread_mutex_unlock(philo->r_mutex);
		// }
	}
}
