# Things to know

1. 1 or more philosopher
2. Either Eat / Think / Sleep
3. As many fork as philosopher
4. 1 philosopher needs 2 fork to eat
5. Finish eating -> Put fork back -> Sleep -> Think after awake
6. Simulation Stops when die of starvation
7.

Every philosopher needs to eat and should never starve.
• Philosophers don’t speak with each other.
• Philosophers don’t know if another philosopher is about to die.
• No need to say that philosophers should avoid dying!

Arguments:

1. number_of_philosophers
2. time_to_die [ms]
3. time_to_eat [ms]
4. time_to_sleep [ms]
5. number_of_times_each_philosopher_must_eat [optional]

◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

Requirements:
Arrangement of philo: 1 2 3 4 5 6 -> 1

Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died

Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.

A displayed state message should not be mixed up with another message.

• A message announcing a philosopher died should be displayed no more than 10 ms
after the actual death of the philosopher.

## Others

printf: Prototype int printf(const char *format, ...). It prints formatted output to the standard output stream (stdout).

malloc: Prototype void *malloc(size_t size). It dynamically allocates memory of size bytes and returns a pointer to the allocated memory.

free: Prototype void free(void *ptr). It deallocates the memory previously allocated by malloc, calloc, or realloc.

write: Prototype ssize_t write(int fd, const void *buf, size_t count). It writes up to count bytes from the buffer pointed to by buf to the file descriptor fd.

memset: Prototype void *memset(void* ptr, int value, size_t num). It fills the first num bytes of the memory area pointed to by ptr with the constant byte value.

usleep: Prototype int usleep(useconds_t microseconds). It suspends the execution of the calling thread for microseconds microseconds.

gettimeofday: Prototype int gettimeofday(struct timeval *tv, struct timezone* tz). It gets the current time of day and timezone information and stores it in the timeval structure pointed to by tv.

pthread_create: Prototype int pthread_create(pthread_t *thread, const pthread_attr_t* attr, void *(*start_routine) (void *), void* arg). It creates a new thread with attributes specified by attr and starts the execution of the function start_routine with the argument arg.

pthread_detach: Prototype int pthread_detach(pthread_t thread). It marks the thread identified by thread as detached, allowing the resources associated with the thread to be automatically released when the thread exits.

pthread_join: Prototype int pthread_join(pthread_t thread, void **retval). It waits for the thread specified by thread to terminate and retrieves the exit status of the thread, storing it in the location pointed to by retval.

pthread_mutex_init: Prototype int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t* attr). It initializes a mutex object with attributes specified by attr.

pthread_mutex_destroy: Prototype int pthread_mutex_destroy(pthread_mutex_t *mutex). It destroys the mutex object specified by mutex, releasing any resources associated with it.

pthread_mutex_lock: Prototype int pthread_mutex_lock(pthread_mutex_t *mutex). It locks the mutex specified by mutex, blocking the calling thread if the mutex is already locked by another thread.

pthread_mutex_unlock: Prototype int pthread_mutex_unlock(pthread_mutex_t *mutex). It unlocks the mutex specified by mutex, allowing other threads to lock it.

## Concept

This is a cycle:

1. almost half of the philosopher can be eating at the same time [max number]
2. Sleep
3. Think

Sample command

5 philo
800 time_to_die
200 eat time
200 sleep time
7 number of time each philo need to eat
./Philo 5 800 200 200 7

## Questions

How can we ran the routine if we do not know how many philosophers are there?
How are we determining the fork left and right? The algo? Why need 3 state?
C1:|1|2
1: Takes 1 and 2.
2: Takes 1 and 2.

C2:|1|2|3|4|5
Round 1:
>1< 2 >3< 4|5
1: Takes 1 and 2
2: Waits
3: Takes 3 and 4
4: Waits
5: Waits [Not enough spoon]

Round 2:
|1 >2 < |3 >4< 5
1: Waits [Eaten R1]
2: Take 2 and 3
3: Waits [Eaten R1]
4: Takes 4 and 5
5: Waits [Not enough spoon]

Round 3:
<1|2|3|4>5
1: Waits [Eaten R1]
2: Waits [Eaten R2]
3: Waits [Eaten R1]
4: Waits [Eaten R2]
5: Takes 1 and 5

C3:|1|2|3|4|5|6

Round 1:
>1< 2 >3< 4>5<6
1: Takes 1 and 2
2: Waits
3: Takes 3 and 4
4: Waits
5: Takes 5 and 6
6: Waits

Round 2:
>1< 2 >3< 4>5<6
1: Waits [Eaten R1]
2: Takes 2 and 3
3: Waits [Eaten R1]
4: Takes 4 and 5
5: Waits [Eaten R1]
6: Takes 6 and 1

How does 1 philo eats?
C0:|1