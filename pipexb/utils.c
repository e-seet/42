#include "utils.h"

void	setstructure(int argc, 	char *argv[], struct s_pipex *pipexstruct)
{

	// outfile
	pipexstruct->p2fd = open(argv[argc-1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipexstruct->p2fd < 0)
		perror("Error in opening file. Terminating now");
	
	pipexstruct->p1fd = open(argv[1], O_RDONLY);
	if (pipexstruct->p1fd < 0)
		perror("Error in opening file. Terminating now");

	pipexstruct->curr = 3;
	pipexstruct->argc = argc;
	// the following 2 will be variable
	// pipexstruct->argvs1 = ft_split(argv[3], ' ');
	// pipexstruct->argvs2 = ft_split(argv[3], ' ');
	// printf("argv1:%s", pipexstruct->argvs1);
	// printf("argv2:%s", pipexstruct->argvs2);
}

void	closepipes(struct s_pipex *pipexstruct)
{
	close(pipexstruct->fdpipe[0]);
	close(pipexstruct->fdpipe[1]);

	close(pipexstruct->fdpipe_next[0]);
	close(pipexstruct->fdpipe_next[1]);
}
