#include "utils.h"

void	setstructure(char *argv[], struct s_pipex *pipexstruct)
{
	// pipexstruct->p2fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	// if (pipexstruct->p2fd < 0)
	// 	perror("Error in opening file. Terminating now1");
	// pipexstruct->p1fd = open(argv[1], O_RDONLY);
	// if (pipexstruct->p1fd < 0)
	// 	perror("Error in opening file. Terminating now2");
	// pipexstruct->argvs1 = ft_split(argv[3], ' ');
	// pipexstruct->argvs2 = ft_split(argv[4], ' ');

	// delimiter
	pipexstruct->delimiter = argv[2];
	// Get FD to open file and write

	pipexstruct->heredocwritefd = open("heredoctemp.txt", O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipexstruct->heredocwritefd == - 1)
		printf("opening heredoctempt for writing failed");


}

//check if the last character is a \n and subtract accordingly
int linechecker(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;

	// go to the position before \0 and check if it is a \n
	if (str[i - 1] == '\n')
		return 1;
	else
		return 0;
}

// read from stdin.
// write to pipe
int heredoccmd(struct s_pipex *pipexstruct)
{
	char	*line;

	while (1)
	{
		write(1,"heredoc>", 8);
		// Get line by line 
		line = get_next_line(0);

		// found the delimiter.
		// Make sure delimiter is same length as line
		// There will be a extra \n for line, that's why need to subtract by 1. 
		if ( (ft_strncmp(line, pipexstruct->delimiter, ft_strlen(pipexstruct->delimiter)) == 0) 
		&& (ft_strlen(line) - linechecker(line)) == ft_strlen(pipexstruct->delimiter))
			break ;

		// write to file
		write(pipexstruct->heredocwritefd, line, ft_strlen(line));
		// write(1,line, ft_strlen(line));
		// write(1, "\n", 1);

		line = NULL;
	}
	printf("end\n\n ");
	return (0);
}

// void	closepipes(struct s_pipex *pipexstruct)
// {
// 	close(pipexstruct->fdpipe[0]);
// 	close(pipexstruct->fdpipe[1]);
// }
