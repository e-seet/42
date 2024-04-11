#include "utils.h"

void	lock_bothforkmutex(struct s_philo *philo)
{
	pthread_mutex_lock(philo->l_mutex);
	pthread_mutex_lock(philo->r_mutex);
	printf("%ld %d has taken a fork\n",
		philo->curr - philo->start, philo->id);
	printf("%ld %d has taken a fork\n",
		philo->curr - philo->start, philo->id);
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
	printf("%ld %d is eating\n",
		philo->curr - philo->start, philo->id);
}

void	unlock_bothforkmutex(struct s_philo *philo)
{
	philo->status = 1;
	pthread_mutex_unlock(&philo->eating_mutex);
	pthread_mutex_unlock(philo->l_mutex);
	pthread_mutex_unlock(philo->r_mutex);
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
}
