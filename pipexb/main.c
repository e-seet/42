#include "utils.h"

int	p3child(char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	pipexstruct.path = findprocesspath(pipexstruct);
	if (access(pipexstruct.path, F_OK) != 0)
	{
		perror("command not found");
		return (-1);
	}
	execveresult = execve(pipexstruct.path, pipexstruct.argvs3, envp);
	if (execveresult == -1)
		perror("smth wrong with executing. Terminate now");
	free(pipexstruct.path);
	return (0);
}

void	dup2child(struct s_pipex pipexstruct)
{
	if (pipexstruct.curr == 3)
	{
		printf("case == 3 \n");
		dup2(pipexstruct.p1fd, 0);
		dup2(pipexstruct.fdpipe1[1], 1);
	}
	else if (pipexstruct.argc - 2 == pipexstruct.curr)
	{
		printf("last part\n\n");
		if (pipexstruct.curr % 2 == 1)
			dup2(pipexstruct.fdpipe2[0], 0); //was there first
		else
			dup2(pipexstruct.fdpipe1[0], 0);
		dup2(pipexstruct.p2fd, 1);
	}
	else if (pipexstruct.curr % 2 == 0)
	{
		printf("case 0\n\n");
		dup2(pipexstruct.fdpipe1[0], 0);
		dup2(pipexstruct.fdpipe2[1], 1);
	}
	else if (pipexstruct.curr % 2 == 1)
	{
		printf("case 1\n");
		dup2(pipexstruct.fdpipe2[0], 0);
		dup2(pipexstruct.fdpipe1[1], 1);
	}
}

int	refactormain(struct s_pipex pipexstruct, char *envp[], char *argv[])
{
	pipexstruct.argvs3 = ft_split(argv[pipexstruct.curr], ' ');
	printf("check argvs3 %s\n", pipexstruct.argvs3[0]);
	pipexstruct.pid3 = fork();
	if (pipexstruct.pid3 == 0)
	{
		dup2child(pipexstruct);
		if (p3child(envp, pipexstruct) == -1)
			return (-1);
	}
	else
	{
		if (pipexstruct.curr % 2 == 1)
			close(pipexstruct.fdpipe1[1]);
		else if (pipexstruct.curr % 2 == 0)
			close(pipexstruct.fdpipe2[1]);
		else
			exit(1);
		waitpid(pipexstruct.pid3, NULL, 0);
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	struct s_pipex	pipexstruct;

	if (pipe(pipexstruct.fdpipe1) == -1 || pipe(pipexstruct.fdpipe2) == -1)
		return (1);
	setstructure(argc, argv, &pipexstruct, envp);
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		if (heredoccmd(&pipexstruct) == 0)
		{
			pipexstruct.curr =3 ;
			pipexstruct.heredocreadfd = open("heredoctemp.txt", O_RDONLY);
			if (pipexstruct.heredocreadfd == -1)
				perror("heredocreadfd opened with error\n");
		}
		else
			perror("heredoccmd failed. Nothing inside\n");
	}
	/*
	while (pipexstruct.argc - 1 > pipexstruct.curr)
	{
		
		if (refactormain(pipexstruct, envp, argv) == 1)
			return (1);
		pipexstruct.curr += 1;
	}
	 */
// /*
	printf("argc:%d\n\n", pipexstruct.argc);
	while (pipexstruct.argc - 1 > pipexstruct.curr)
	{
		printf("curr:%d\n", pipexstruct.curr);
		pipexstruct.argvs3 = ft_split(argv[pipexstruct.curr], ' ');
		printf("check argvs3 %s\n", argv[pipexstruct.curr]);

		if (pipexstruct.curr != 3 && pipexstruct.curr % 2 == 1)
		{
			if (pipe(pipexstruct.fdpipe1) == -1)
				return (1);
		}
		else if (pipexstruct.curr != 4 && pipexstruct.curr % 2 == 0)
		{
			if (pipe(pipexstruct.fdpipe2) == -1)
				return (1);
		}
		pipexstruct.pid3 = fork();
		if (pipexstruct.pid3 == 0)
		{
			dup2child(pipexstruct);
			if (p3child(envp, pipexstruct) == 1)
			{
				printf("error: 1, exiting\n");
				exit(1);
			}
		}
		else
		{
			if (pipexstruct.argc - 2 == pipexstruct.curr)
			{
				printf("close in main\n");
				// close(pipexstruct.fdpipe2[1]);
				// close(pipexstruct.fdpipe2[0]);

				// close(pipexstruct.fdpipe1[1]);
				// close(pipexstruct.fdpipe1[0]);

			}
			else if (pipexstruct.curr % 2 == 1)
				close(pipexstruct.fdpipe1[1]);
			else if (pipexstruct.curr % 2 == 0)
				close(pipexstruct.fdpipe2[1]);
			else
				exit(1);
			waitpid(pipexstruct.pid3, NULL, 0);
		}
		pipexstruct.curr = pipexstruct.curr +1;
	}
	// */
	return (0);
}


// to do. Check if i have a heredoc.
// if i have heredoc, curr = 3
// else curr = 2