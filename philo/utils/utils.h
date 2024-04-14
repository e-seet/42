#ifndef UTILS_H
# define UTILS_H

# include "string.h" // may need to comment out for memset
# include "stdio.h" // to remove for printf

# include "stdlib.h"
# include "unistd.h"
# include "sys/time.h"
# include "pthread.h"

# include "philosopher.h"
# include "../../libft/libft.h"

size_t	get_current_time(void);
// int		ft_usleep(size_t milliseconds);
int		ft_usleep(size_t milliseconds);
// int	ft_usleep(useconds_t time);

// u_int64_t	get_current_time(void);
// int	ft_usleep(useconds_t time);

void	freestuff(struct s_philo **philos, int num);
void	update_current_time_now(struct s_philo *philo);
void	check_death_condition(struct s_philo *philo);
void	check_finished_eating(struct s_philo *philo);

void	check_death_condition(struct s_philo *philo);
void	check_finished_eating(struct s_philo *philo);

// starting is odd
void	handle_odd_philo_eating(struct s_philo *philo);
void	handle_odd_philo_sleeping(struct s_philo *philo);
void	handle_odd_philo_thinking(struct s_philo *philo);

// starting is even
void	handle_even_philo_eating(struct s_philo *philo);
void	handle_even_philo_sleeping(struct s_philo *philo);

void	handle_philo_sleeping(struct s_philo *philo);
void	handle_philo_thinking(struct s_philo *philo);
void	handle_philo_eating(struct s_philo *philo);

void	*thread_function(void *arg);

void	lock_bothforkmutex(struct s_philo *philo);
void	unlock_bothforkmutex(struct s_philo *philo);

//setup
void	init_philo_mutexs(struct s_philo *philo, int *mutexs_i,
int num, pthread_mutex_t *mutexs);

void	init_philo(struct s_philo *philo, char **argv, int argc, int id);

int		setstruct(struct s_philo ***philos, int argc,
			char **argv, pthread_mutex_t *mutexs);

void	init_fork_mutex(pthread_mutex_t *mutexs, int num);


// checkers
void	check_if_all_ate(int num, struct s_philo **philos, int *allend);
void	check_if_any_died(int num, struct s_philo **philos, int *allend);
void	stopall(int num, struct s_philo **philos, int *allend);

#endif