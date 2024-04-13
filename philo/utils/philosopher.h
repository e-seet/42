
#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

// id: philo id
// max: max number of philo
// last_meal_time: time that philo last had its meal

//	how long before i will die if i dont eat
// unsigned long		time_to_die;

// how long i take to eat
// unsigned long			time_to_eat;

// how long i sleep
// unsigned long			time_to_sleep;

// num_must_eat: MIN number of time i need to eat.
// num_of_time_eaten: to calculate the number of time eaten
//died: check if philo have died
// time_of_death: time that the philo died
// stop: to stop the philo from continuing so as to end
// start: philo starting time
// curr: current time

//status: store previous state
// initial: 0 eat:1 sleep:2 think:3

// l_mutex: left fork [own's id]
// r_mutex: right fork [id + 1; if (id+1 == max): 0]
// mutexs_i: acts as a semaphore to check if fork is avail
// routine semaphore: acts as a semaphore for each philo's routines

// eating_mutex, sleeping_mutex and thinking_mutexs are irreleveant here
// curr_mutex: to lock each rountine and ensure each thread runs 1 at a time

//whichroutine[4]
// 0 = started
// 1 = eat
// 2 = sleep
// 3 = think

struct s_philo {
	int					id;
	int					max;

	unsigned long		last_meal_time;

	unsigned long		time_to_die;

	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;

	int					num_must_eat;
	int					num_of_time_eaten;
	int					died;
	unsigned long		time_of_death;
	int					stop;

	unsigned long		start;
	unsigned long		curr;
	int					status;

	pthread_mutex_t		*l_mutex;
	pthread_mutex_t		*r_mutex;

	int					*mutexs_i;
	int					*routinesemaphore;

	pthread_mutex_t		eating_mutex;
	pthread_mutex_t		sleeping_mutex;
	pthread_mutex_t		thinking_mutex;

	pthread_mutex_t		*curr_mutex;
};

#endif
