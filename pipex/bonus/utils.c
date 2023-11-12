#include "utils.h"

void	setstructure(char *argv[], struct s_pipex *pipexstruct)
{
	pipexstruct->p2fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipexstruct->p2fd < 0)
		perror("Error in opening file. Terminating now");
	pipexstruct->p1fd = open(argv[1], O_RDONLY);
	if (pipexstruct->p1fd < 0)
		perror("Error in opening file. Terminating now");
	pipexstruct->argvs1 = ft_split(argv[3], ' ');
	pipexstruct->argvs2 = ft_split(argv[4], ' ');

	// delimiter
	pipexstruct->delimiter = argv[2];
	// Get FD to open file and write
	pipexstruct->heredocfd = open("heredoctemp.txt", O_TRUNC | O_CREAT | O_RDWR, 0644);
}

// read from stdin.
// write to pipe
int heredoccmd(struct s_pipex *pipexstruct)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		write(1,"heredoc>", 8);
		// end of file. Break and nth to write
		if (get_next_line(0, &line) == 0)
			break ;
		// found the delimiter, nothing to write 
		if (ft_strncmp(line, pipexstruct->delimiter, ft_strlen(pipexstruct->delimiter)) == 0)
			break ;
		printf("%s\n", line);
		// write to file
		write(pipexstruct->heredocfd, line, ft_strlen(line));
		free(line);
		line = NULL;
	}
	return (0);
}

void	closepipes(struct s_pipex *pipexstruct)
{
	close(pipexstruct->fdpipe[0]);
	close(pipexstruct->fdpipe[1]);
}
