#ifndef UTILS_H
# define UTILS_H

# include <sys/wait.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
//for read write, permission with files, creating files
# include <fcntl.h>


struct s_pipex {
	int		p1fd;
	int		p2fd;

	int		pid3;
	char	**argvs3;
	int		fdpipe1[2];
	int		fdpipe2[2];
	int		curr;
	int		argc;
	char	*delimiter;
	int		heredocwritefd;
	int		heredocreadfd;
	char	*path;
	char	**paths;
};

void	setstructure(int argc, char *argv[], struct s_pipex *pipexstruct,
			char *envp[]);

int		linechecker(char *str);

void	closepipes(struct s_pipex *pipexstruct);

int		heredoccmd(struct s_pipex *pipexstruct);

char	*findprocesspath(struct s_pipex pipexstruct);

char	*findpath(char *envp[]);

#endif