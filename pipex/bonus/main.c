#include <stdio.h>
#include "utils.h"


// to check setstructure since it is for bonus
char	*findprocesspath(char *path, char *paths[],
struct s_pipex pipexstruct, int processnum)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (processnum == 1)
			path = ft_strjoin(path, pipexstruct.argvs1[0]);
		else if (processnum == 2)
			path = ft_strjoin(path, pipexstruct.argvs2[0]); 
		else //for heredoc
			
		if (access(path, F_OK) == 0)
			break ;
		free (path);
		path = NULL;
		i++;
	}
	if (access(path, F_OK) == 0)
		return (path);
	else
		return (NULL);
}
// //Change from stdout(1) to fd[1] so that the data that 
//supposed to go stdout will go to pipe instead
// // then it will write into pipe. That's why fd[1]
// dup2(pipexstruct.fdpipe[1], 1);
// //close the pipe for reading
// close(pipexstruct.fdpipe[0]);
// //Change the stdin(0) to read the file's fd 
//so that it will read from the file of interest
// dup2(pipexstruct.p1fd, 0);
//path: "/bin/ls"
//arg:  ["ls", "-l"]

int	p1child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	path = findprocesspath(path, paths, pipexstruct, 1);
	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}
	dup2(pipexstruct.fdpipe[1], 1);
	close(pipexstruct.fdpipe[0]);
	dup2(pipexstruct.p1fd, 0);
	execveresult = execve(path, pipexstruct.argvs1, envp);
	if (execveresult == -1)
		perror("Execve failed in P1child. Terminating Now");
	free(path);
	return (0);
}

//path: "/bin/ls"
//arg:  ["ls", "-l"]
// change from stdin(0)  to listen to fd[0]

int	p2child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	path = findprocesspath(path, paths, pipexstruct, 2);
	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}
	dup2(pipexstruct.fdpipe[0], 0);
	close(pipexstruct.fdpipe[1]);
	dup2(pipexstruct.p2fd, 1);
	execveresult = execve(path, pipexstruct.argvs2, envp);
	if (execveresult == -1)
		perror("smth wrong with executing. Terminate now");
	free(path);
	return (0);
}

char	*findpath(char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			path = envp[i];
			break ;
		}
		i++;
	}
	if (ft_strncmp("PATH=", path, 5) == 0)
		return (path);
	else
		return (NULL);
}




int	main(int argc, char *argv[], char *envp[])
{
	struct s_pipex	pipexstruct;
	char			*path;
	char			**paths;

	// printf("argc: %d\n", argc);
	// if (argc < 3)
	// 	printf("argc is less than 5\n");
	// else
	// 	printf("argc is more than 5\n");

	// // original pipex code
	setstructure(argv, &pipexstruct);
	path = findpath(envp);
	paths = ft_split(path + 5, ':');

	printf("happy birthday first");

	// int temp;
	// temp = heredoccmd(&pipexstruct);
	// if (temp == 0)
	// 	printf("heredoccmd success\n");
	// else
	// 	printf("heredoccmd failed\n");

	

	pipexstruct.p1fd = 0;
	printf("\n\nto ignore\n%s, %s, %d, %d\n.", paths[0],argv[0], pipexstruct.p1fd, argc);


	// if (pipe(pipexstruct.fdpipe) == -1)
	// 	return (1);
	// setstructure(argv, &pipexstruct);
	// if (pipexstruct.pid1 != 0)
	// 	wait(NULL);
	// pipexstruct.pid1 = fork();
	// if (pipexstruct.pid1 == 0)
	// 	if (p1child(paths, path, envp, pipexstruct) == 1)
	// 		exit(1);
	// pipexstruct.pid2 = fork();
	// if (pipexstruct.pid2 == 0)
	// 	if (p2child(paths, path, envp, pipexstruct) == 1)
	// 		exit(1);
	// closepipes(&pipexstruct);
	// waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0);
	// waitpid(pipexstruct.pid2, &pipexstruct.pid2status, 0);
	return (0);
}

// For now
// ./pipex_bonus "here_doc" "wow"


// Do heredoc
//HEREDOC argv[1]
//Delimiter:END argv[2]
// Use get next line for the delimiter.
// IF it is END, ENDD, ENDDD all doesn't work.
// onlu END	

// ./pipex "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file"
// argc: at least: 
// argv[0]: ./pipex
// argv[1]: here_doc
// argv[2]: END
// argv[3]: tr a b
// argv[4]: tr b c
// argv[5]: tr c d
// argv[6]: output_file

// gcc -o main main.c utils.c

// pipex original code
// ./main  infile "grep this" "wc -w" outfile

// Basic stuff
//stdin: 0
//stdout: 1
//pipe fd[0]: read
//pipe fd[1]: write