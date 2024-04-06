#ifndef UTILS_H
# define UTILS_H

#include "string.h" // may need to comment out for memset
#include "stdio.h" // to remove for printf

#include "stdlib.h"
#include "unistd.h"
#include "sys/time.h"
#include "pthread.h"

#include "philosopher.h"
# include "../libft/libft.h"

size_t	get_current_time(void);
int	ft_usleep(size_t milliseconds);
void *thread_function(void *arg);

#endif