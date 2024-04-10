#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define NUM_FORKS NUM_PHILOSOPHERS

pthread_mutex_t forks[NUM_FORKS];

void* philosopher(void* arg) {
    int id = *((int*)arg);
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking.\n", id);

        // Acquire left fork
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d picked up left fork %d.\n", id, left_fork);

        // Acquire right fork
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d picked up right fork %d.\n", id, right_fork);

        // Eat (perform a task)
        printf("Philosopher %d is eating.\n", id);
        sleep(1); // Simulate time taken to eat

        // Put down right fork
        pthread_mutex_unlock(&forks[right_fork]);
        printf("Philosopher %d put down right fork %d.\n", id, right_fork);

        // Put down left fork
        pthread_mutex_unlock(&forks[left_fork]);
        printf("Philosopher %d put down left fork %d.\n", id, left_fork);

        // Think (perform another task)
        sleep(1); // Simulate time taken to think
    }

    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];

    // Initialize the mutexes
    for (int i = 0; i < NUM_FORKS; ++i) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Wait for philosopher threads to finish (they never will in this example)
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_join(philosophers[i], NULL);
    }

    // Clean up mutexes
    for (int i = 0; i < NUM_FORKS; ++i) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}


// void *thread_function_original(void *arg)
// {

// 	struct s_philo *philo;
// 	philo = (struct s_philo *) arg;

// 	//condition to break it
// 	while (1)
// 	{

// 		pthread_mutex_lock(philo->curr_mutex);
// 		// ft_usleep(1);
// 		philo->curr = get_current_time();
// 		// printf("\n\npid:%d|updated time curr:%lu\n", philo->id, philo->curr);
// 		pthread_mutex_unlock(philo->curr_mutex);

// 		// cases to break
// 		// if (philo->died == 1)
// 		// {
// 		// 	break;
// 		// }
// 		if ((philo->last_meal_time > 0) && ((philo->curr - philo->last_meal_time) > philo->time_to_die))
// 		{
// 			philo->time_of_death = get_current_time();
// 			// printf("id%d\ntime of death:%lu.\nHow long since it passed:%lu\n", philo->id, philo->time_of_death, philo->curr - philo->last_meal_time);
// 			break;
// 		}
// 		if (philo->num_must_eat == 0)
// 		{
// 			// printf("philo%d|Curr:%ld\n: finished eating.", philo->id, philo->curr);
// 			break;
// 		}


// 		// Odd number of philo. Split to 3 groups
// 		if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 1))
// 		{
// 			pthread_mutex_lock(philo->l_mutex);
// 			pthread_mutex_lock(philo->r_mutex);
// 			pthread_mutex_lock(&philo->eating_mutex);
// 			philo->last_meal_time = get_current_time();
// 			// printf("last meal time:%lu\n", philo->last_meal_time);
// 			// printf("id:%d is eating at %lu\n", philo->id, philo->curr);
// 			philo->status = 1;
// 			if (philo->num_must_eat > 0)
// 				philo->num_must_eat = philo->num_must_eat - 1;
// 			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
// 			pthread_mutex_unlock(&philo->eating_mutex);
// 			pthread_mutex_unlock(philo->l_mutex);
// 			pthread_mutex_unlock(philo->r_mutex);
// 		}
// 		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id != philo->max) && (philo->id %2 == 0))
// 		{
// 			pthread_mutex_lock(&philo->sleeping_mutex);
// 			// printf("id:%d is sleeping for :%d\n", philo->id, philo->time_to_sleep);
// 			ft_usleep(philo->time_to_sleep);
// 			philo->status = 2;
// 			philo->last_meal_time = philo->curr;
// 			pthread_mutex_unlock(&philo->sleeping_mutex);
// 		}
// 		else if (philo->status == 0 && (philo->max % 2 == 1) && (philo->id == philo->max))
// 		{
// 			// printf("id:%d is thinking\n", philo->id);
// 			pthread_mutex_lock(&philo->thinking_mutex);
// 			philo->status = 3;
// 			philo->last_meal_time = philo->curr;
// 			pthread_mutex_unlock(&philo->thinking_mutex);
// 		}

// 		// even number of philo
// 		else if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id %2 == 0))
// 		{
// 			// printf("curr:%lu\n", philo->curr);
// 			// printf("last meal time:%lu\n", philo->last_meal_time);
// 			// eat
// 			pthread_mutex_lock(philo->l_mutex);
// 			pthread_mutex_lock(philo->r_mutex);
// 			pthread_mutex_lock(&philo->eating_mutex);
// 			philo->last_meal_time = get_current_time();
// 			// printf("id:%d is eating\n", philo->id);
// 			philo->status = 1;
// 			if (philo->num_must_eat > 0)
// 				philo->num_must_eat = philo->num_must_eat - 1;
// 			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
// 			pthread_mutex_unlock(&philo->eating_mutex);
// 			pthread_mutex_unlock(philo->l_mutex);
// 			pthread_mutex_unlock(philo->r_mutex);
// 		}
// 		else if (philo->status == 0 && (philo->max % 2 == 0) && (philo->id %2 == 1))
// 		{
// 			//sleep
// 			pthread_mutex_lock(&philo->sleeping_mutex);
// 			// printf("id:%d is sleeping\n", philo->id);
// 			ft_usleep(philo->time_to_sleep);
// 			philo->status = 2;
// 			pthread_mutex_unlock(&philo->sleeping_mutex);
// 			//set to think for status
// 		}

// 		// otherwise we check the previous status and do stuff
// 		else if (philo->status == 1)
// 		{
// 			// printf("\ncase status 1\n");

// 			//sleep
// 			pthread_mutex_lock(&philo->sleeping_mutex);
// 			// printf("id:%d|curr:%ld is sleeping:+%d\n", philo->id, philo->curr, philo->time_to_sleep);
// 			printf("%ld %d is sleeping | for %lu time %lu\n", philo->curr, philo->id, philo->time_to_sleep, get_current_time());
// 			if ((philo->curr - philo->last_meal_time) + philo->time_to_sleep > philo->time_to_die)
// 			{
// 				ft_usleep((philo->time_to_die) - (philo->curr - philo->last_meal_time));
// 				philo->time_of_death = get_current_time();
// 				philo->died = 1;
// 				// can continue with the process here if required
// 				break;
// 			}
// 			else
// 				ft_usleep(philo->time_to_sleep);
// 			philo->status = 2;
// 			pthread_mutex_unlock(&philo->sleeping_mutex);
// 			//set to think for status
// 		}
// 		else if (philo->status == 2)
// 		{
// 			// printf("\ncase status 2\n");
// 			// printf("id:%d|curr:%ld is thinking:+%d\n", philo->id, philo->curr, 1);
// 			pthread_mutex_lock(&philo->thinking_mutex);
// 			// printf("%ld %d is thinking | for %d time %lu\n", philo->curr, philo->id, 1, get_current_time());
// 			// printf("Thinking is set to 1 ms\n");
// 			ft_usleep(1);
// 			philo->status = 3;
// 			pthread_mutex_unlock(&philo->thinking_mutex);

// 		}
// 		else if (philo->status == 3)
// 		{
// 			// printf("pid:%d curr:%lu\n", philo->id ,philo->curr);
// 			printf("id:%d|curr:%ld last meal time:%lu\n", philo->id, philo->curr, philo->last_meal_time);
// 			// update to next staus: 1
// 			pthread_mutex_lock(philo->l_mutex);
// 			printf("%ld %d has taken a fork | %lu\n", philo->curr, philo->id, get_current_time());
// 			pthread_mutex_lock(philo->r_mutex);
// 			printf("%ld %d has taken a fork | %lu\n", philo->curr, philo->id, get_current_time());
// 			pthread_mutex_lock(&philo->eating_mutex);

// 			if ((philo->curr - philo->last_meal_time) + philo->time_to_eat > philo->time_to_die)			
// 			{
// 				// printf("eating got issue!!!\n");
// 				// printf("curr:%lu\n", philo->curr);
// 				// printf("lastm:%lu\n", philo->last_meal_time);
// 				// printf("tte:%lu\n", philo->time_to_eat);
// 				// printf("ttd:%lu\n", philo->time_to_die);
				
// 				// ft_usleep(philo->time_to_die - (philo->curr - philo->last_meal_time));
// 				ft_usleep(1);
// 				philo->time_of_death = get_current_time();
// 				philo->died = 1;
// 				// i can continue with the process here if required.
// 				break;
// 			}
// 			else
// 			{
// 				// printf("%ld %d is eating | for %lu time %lu\n", philo->curr, philo->id, philo->time_to_eat, get_current_time());
// 				ft_usleep(philo->time_to_eat);
// 				philo->last_meal_time = get_current_time();

// 			}
			
// 			// printf("id:%d|curr:%ld lastmealtime:%lu just finished eating\n", philo->id, philo->curr, philo->last_meal_time);
// 			if (philo->last_meal_time > philo->curr)
// 				// printf("id:%d|curr:%ld vs last meal: %ld\n", philo->id, philo->curr, philo->last_meal_time);
// 			philo->status = 1;
// 			if (philo->num_must_eat > 0)
// 				philo->num_must_eat = philo->num_must_eat - 1;
// 			philo->num_of_time_eaten = philo->num_of_time_eaten + 1;
// 			pthread_mutex_unlock(&philo->eating_mutex);
// 			pthread_mutex_unlock(philo->l_mutex);
// 			pthread_mutex_unlock(philo->r_mutex);
// 		}

// 	}

// 	// end of the while loop
// 	// printf("\nEnd PHILO! id:%d, num_must_eat:%d, numoftimeeaten:%d\n", philo->id, philo->num_must_eat, philo->num_of_time_eaten);
// 	// printf("Expected 1 if died:%d\n\n", philo->died);
//     return NULL;
// }

// Later
// void	*thread_function_backup(void *arg)
// {
// 	struct s_philo	*philo;

// 	philo = (struct s_philo *) arg;
// 	while (1)
// 	{
// 		update_current_time(philo);
// 		check_death_condition(philo);
// 		check_finished_eating(philo);
// 		handle_odd_philo_eating(philo);
// 		handle_odd_philo_sleeping(philo);
// 		handle_odd_philo_thinking(philo);
// 		handle_even_philo_eating(philo);
// 		handle_even_philo_sleeping(philo);
// 		handle_philo_sleeping(philo);
// 		handle_philo_thinking(philo);
// 		handle_philo_eating(philo);
// 		if (philo->died == 1)
// 			break ;
// 		if (philo->num_must_eat == 0)
// 			break ;
// 	}
// 	return (NULL);
// }
