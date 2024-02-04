
#ifndef UTILS_H
# define UTILS_H

# include <sys/wait.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
//for read write, permission with files, creating files
# include <fcntl.h>

struct s_pipex {
	int		pid1;
	int		pid1status;
	int		p1fd;
	char	**argvs1;

	int		pid2;
	int		pid2status;
	int		p2fd;
	char	**argvs2;

	int		fdpipe[2];
};

void	setstructure(char *argv[], struct s_pipex *pipexstruct);
void	closepipes(struct s_pipex *pipexstruct);

char	*findprocesspath(char *path, char *paths[],
			struct s_pipex pipexstruct, int processnum);
int		p1child(char *paths[], char *path, char *envp[],
			struct s_pipex pipexstruct);

int		p2child(char *paths[], char *path, char *envp[],
			struct s_pipex pipexstruct);

char	*findpath(char *envp[]);

#endif