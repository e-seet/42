#ifndef LIBFTFILES_H
# define LIBFTFILES_H


#include <stdio.h>
#include <unistd.h>

//for read write, permission with files, creating files
#include <fcntl.h>
//for unix processes
#include <sys/wait.h>

//struct to store whatever i need for now
struct pipeStructure {
    int pid1;
	int pid1status;
	int p1fd;

    int pid2;
	int pid2status;
	int p2fd;
};


size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	numofwords(const char *s, char c);
char	*copycontent(const char *s, char c);
void	*list_free(char **strs, int i);
char	**ft_split(char const *s, char c);

char	*ft_strjoin(char const *s1, char const *s2);

#endif