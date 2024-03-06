#include "utils.h"

void	setstructure(char *argv[], struct s_pipex *pipexstruct)
{
	char	**strs;
	int		size;

	strs = ft_split(argv[4], '/');
	size = ft_strlen(argv[4]);
	if (ft_strncmp(strs[0], argv[4], size) != 0)
		mkdir(strs[0], 0777);
	pipexstruct->p2fd = open(argv[4], O_APPEND | O_CREAT | O_RDWR, 0644);
	if (pipexstruct->p2fd < 0)
		perror("Error in opening file. Terminating now");
	pipexstruct->p1fd = open(argv[1], O_RDONLY);
	if (pipexstruct->p1fd < 0)
		perror("Error in opening file. Terminating now");
	pipexstruct->argvs1 = ft_split(argv[2], ' ');
	pipexstruct->argvs2 = ft_split(argv[3], ' ');
}

void	closepipes(struct s_pipex *pipexstruct)
{
	close(pipexstruct->fdpipe[0]);
	close(pipexstruct->fdpipe[1]);
}
