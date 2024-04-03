
#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

// need something like a global time.

struct s_philo {
	int		id;
	int		time_to_die;

	int		time_to_eat;
	int		time_to_sleep;

	int		num_must_eat;
	int		died;

	//mutex fork. 
	// The one fork that he should have
};

#endif
