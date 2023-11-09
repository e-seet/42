
#include <sys/wait.h>
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>
//for read write, permission with files, creating files
#include <fcntl.h>

//struct to store whatever i need
struct pipestructure {
	int	pid1;
	int	pid1status;
	int	p1fd;

	int	pid2;
	int	pid2status;
	int	p2fd;

	int	fdpipe[2];
};

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
int	P1child(char *argv[], char *paths[], char *path, char *envp[], struct pipestructure pipexstruct)
{
	int		i;
	char	**argvs;
	int		execveresult;

	i = 0;
	argvs = ft_split(argv[2], ' ');
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, argvs[0]);
		if (access(path, F_OK) == 0)
			break ;
		free (path);
		path = NULL;
		i++;
	}
	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}
	pipexstruct.p1fd = open(argv[1], O_RDONLY);
	if (pipexstruct.p1fd < 0)
		perror("Error in opening file. Terminating now");
	i = 0;
	while (argvs[i])
	{
		printf("argv:%s \n", argvs[i]);
		i ++;
	}
	dup2(pipexstruct.fdpipe[1], 1);
	close(pipexstruct.fdpipe[0]);
	dup2(pipexstruct.p1fd, 0);
	execveresult = execve(path, argvs, envp);
	if (execveresult == -1)
		perror("Execve failed in P1child. Terminating Now");
	free(path);
	free(argvs);
	return (0);
}

//path: "/bin/ls"
//arg:  ["ls", "-l"]
// change from stdin(0)  to listen to fd[0]

int	P2child(char *argv[], char *paths[], char *path, char *envp[], struct pipestructure pipexstruct)
{
	int		i;
	char	**argvs;
	int		execveresult;

	i = 0;
	argvs = ft_split(argv[3], ' ');
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, argvs[0]);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}
	dup2(pipexstruct.fdpipe[0], 0);
	close(pipexstruct.fdpipe[1]);
	i = 0;
	while (argvs[i])
	{
		printf("argv2:%s \n", argvs[i]);
		i ++;
	}
	dup2(pipexstruct.p2fd, 1);
	execveresult = execve(path, argvs, envp);
	if (execveresult == -1)
		perror("smth wrong with executing. Terminate now");
	free(path);
	free(argvs);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	struct pipestructure	pipexstruct;
	char					*path;
	char					**paths;
	int						i;

	path = NULL;
	if (argc != 5)
		return (1);
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
	paths = ft_split(path + 5, ':');
	i = 0;
	if (pipe(pipexstruct.fdpipe) == -1)
		printf("Error in creating pipe\n");
	if (pipexstruct.pid1 != 0)
		wait(NULL);
	pipexstruct.pid1 = fork();
	if (pipexstruct.pid1 == 0)
		if (P1child(argv, paths, path, envp, pipexstruct) == 1)
			exit(1);
	pipexstruct.p2fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipexstruct.p2fd < 0)
		perror("Error in opening file. Terminating now");
	pipexstruct.pid2 = fork();
	if (pipexstruct.pid2 == 0)
		if (P2child(argv, paths, path, envp, pipexstruct) == 1)
			exit(1);
	close(pipexstruct.fdpipe[0]);
	close(pipexstruct.fdpipe[1]);
	waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0);
	waitpid(pipexstruct.pid2, &pipexstruct.pid2status, 0);
	return (0);
}

//pipex, file1, cmd1, cmd2, file2

// ./main  infile "grep this" "wc -w" outfile

//compile 
// gcc -o main main.c libftfiles.c

// run
// ./main infile "ls -l" "wc -l" outfile

// issue with this: #16
// ./main infile2 "cat" "hostname" outfile
// my first process is written in. But 
//not the second. therefore missing hostname inside there

// #18
// ./main  "infile2" "grep Now" "head -2" outfile

//0:./main
//1:infile
//2:"ls -l"
//3:"wc -l"
//4:outfile