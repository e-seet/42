#include "string.h" // may need to comment out for memset
#include "stdio.h" // to remove for printf

#include "stdlib.h"
#include "unistd.h"
#include "sys/time.h"
#include "pthread.h"


#include "philosopher.h"
# include "../libft/libft.h"

int setstruct(struct s_philo **philos, int argc, char **argv)
{
	int	num;
	struct s_philo *philo;

	num = ft_atoi(argv[1]);
	philos = (struct s_philo **) malloc (sizeof(struct s_philo *) * num);
	if (philos == NULL)
		return (-1);

	while (num--)
	{
		philo = (struct s_philo *) malloc (sizeof(struct s_philo));
		if (philo == NULL)
			return (-1);
		philo->id = num;
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo->num_must_eat = ft_atoi(argv[5]);
		philos[num] = philo;
	}
	// int	i = ft_atoi(argv[1]);
	// while(i--)
	// {
	// 	printf("philo id:%d\n", philos[i]->id);
	// 	printf("philo id:%d\n", philos[i]->time_to_die);
	// 	printf("philo id:%d\n", philos[i]->time_to_eat);
	// 	printf("philo id:%d\n\n", philos[i]->time_to_sleep);
	// }
	return (0);
}

void routine()
{
	// check left right
	// eat
	// sleep
	// think
}

int main(int argc, char **argv)
{
	struct s_philo **philos;
	int		timer;
	int		died;

	philos = NULL;
	died = 0;
	timer = 0;	
	if (argc == 5 || argc == 6)
	{
		setstruct(philos, argc, argv);
	}
	else
	 return (-1);

	while (1)
	{
		// if (died == 1 || philos)

		// pthreads allows us to ran in parallel. For eating / sleeping / thinking
		
		// the question is on how do we make all of the philo ran at the same time?
		// since we do not know how many philo are there


	}

}