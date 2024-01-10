
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
	int		p1fd; //infile
	char	**argvs1;

	// convert this into a single process orientaed
	int		pid2;
	int		pid2status;
	char	**argvs2;
	int		p2fd; //outfile

	int		pid3;
	int		pid3status;
	int		p3fd; //infile
	char	**argvs3;

	int		fdpipe1[2];
	int		fdpipe2[2];
	int		curr;
	int		argc;
};

void	setstructure(int argc, char *argv[], struct s_pipex *pipexstruct);
void	closepipes(struct s_pipex *pipexstruct);

char	*findprocesspath(char *path, char *paths[],
			struct s_pipex pipexstruct, int processnum);
int		p1child(char *paths[], char *path, char *envp[],
			struct s_pipex pipexstruct);

int		p2child(char *paths[], char *path, char *envp[],
			struct s_pipex pipexstruct);

char	*findpath(char *envp[]);

#endif