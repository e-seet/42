#include "utils.h"

char	*findprocesspath(char *path, char *paths[],
struct s_pipex pipexstruct, int processnum)
{
	int	i;

	printf("findprocesspath\n");
	// printf("joined this:%s\n", pipexstruct.argvs1[0]);

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (processnum == 1)
			path = ft_strjoin(path, pipexstruct.argvs1[0]);
		else
			path = ft_strjoin(path, pipexstruct.argvs2[0]);
		
		if (access(path, F_OK) == 0)
		{
			printf("found path\n");
			break ;
		}
		free (path);
		path = NULL;
		i++;
	}
	if (access(path, F_OK) == 0)
		return (path);
	else
		return (NULL);
}

int	p1child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	printf("\n\np1child: %d\n", pipexstruct.curr);
	path = findprocesspath(path, paths, pipexstruct, 1);
	printf("the path1 to use: %s\n\n", path);
	if (access(path, F_OK) != 0)
	{ 
		perror("command not found");
		return (1);
	}

	// first, read from fd
	if (pipexstruct.curr == 3)
	{
		// read from file:
		printf("p1: if: read file fd and start the process");
		dup2(pipexstruct.fdpipe[1], 1);
		close(pipexstruct.fdpipe[0]);
		dup2(pipexstruct.p1fd, 0);
	}
	// supposed to write output to p1fd.
	else if (pipexstruct.curr +3 == pipexstruct.argc)
	{
		printf("p1: else if: write output to p1fd");
		dup2(pipexstruct.fdpipe[0], 0);
		close(pipexstruct.fdpipe[1]);
		dup2(pipexstruct.p1fd, 1);
	}
	else
	{
		printf("p1: else\n");
		printf("p1child to do something \n");
		
		// dup2(pipexstruct.fdpipe[0], 0);
		// dup2(pipexstruct.fdpipe[1], 1);

	}

	execveresult = execve(path, pipexstruct.argvs1, envp);
	if (execveresult == -1)
		perror("Execve failed in P1child. Terminating Now");
	free(path);
	return (0);
}

//path: "/bin/ls"
//arg:  ["ls", "-l"]
// change from stdin(0)  to listen to fd[0]

// modified
int	p2child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	printf("\n\np2child: %d\n", pipexstruct.curr+1);
	path = findprocesspath(path, paths, pipexstruct, 2);
	printf("the path2 to use: %s\n\n", path);
	
	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}


	// End at the current P2 
	if (pipexstruct.argc - 3 == pipexstruct.curr)
	{
		dup2(pipexstruct.fdpipe[0], 0);
		close(pipexstruct.fdpipe[1]);
		dup2(pipexstruct.p2fd, 1);
	}
	else
	{
		printf("p2child to do. Else\n");
		
		dup2(pipexstruct.fdpipe[1], 1);
		// close(pipexstruct.fdpipe[]);
		dup2(pipexstruct.fdpipe[0], 0);
	}
	// Curr:p2. End at P1 
	// else if (pipexstruct.argc -3 == pipexstruct.curr)
	// {
	// 	printf("p2child to do. else if\n");
	// }
	// // continue to pipe to p1
	// else
	// {
	// 	printf("p2child to do. Else\n");

	// }

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
	// int				curr;

	// if (argc != 5)
		// return (1);

	path = findpath(envp);
	paths = ft_split(path + 5, ':');
	if (pipe(pipexstruct.fdpipe) == -1)
		return (1);

	// looping 
	setstructure(argc, argv, &pipexstruct);

	printf("basic testing of variables: argc:%d\n", argc);


	while (argc - 2 >= pipexstruct.curr)
	{
		// printf("\ncurr value: %d\n", pipexstruct.curr);
		// printf("argc value:%d\n", argc);

		pipexstruct.argvs1 = ft_split(argv[pipexstruct.curr], ' ');
		pipexstruct.argvs2 = ft_split(argv[pipexstruct.curr+1], ' ');

		// this will allow us to check if it is the last process
		if (argc == pipexstruct.curr + 3)
		{
			// ends with p2 process
			if (pipexstruct.curr %2 == 1)
			{
				printf("Ends with p2 process\n");
				pipexstruct.p2fd = open(argv[pipexstruct.curr+2], O_TRUNC | O_CREAT | O_RDWR, 0644);
				if (pipexstruct.p2fd == -1 )
					printf("error2 opening file fd2:%d\n", pipexstruct.p2fd);
			}
			// ends with p1 process
			else
			{
				printf("Ends with p1 process\n");
				pipexstruct.p1fd = open(argv[pipexstruct.curr+2], O_TRUNC | O_CREAT | O_RDWR, 0644);
				if (pipexstruct.p1fd == -1 )
					printf("error1 opening file fd1:%d\n", pipexstruct.p1fd);
			}
		}
		// else if (argc == curr + 3)
		// {
		// 	printf("case3 struct: %s \n", argv[curr+3]);
		// 	pipexstruct.p2fd = open(argv[curr+3], O_TRUNC | O_CREAT | O_RDWR, 0644);
		// 	printf("opened? %d\n", pipexstruct.p2fd);
		// }

		if (pipexstruct.pid1 != 0)
			wait(NULL);

		pipexstruct.pid1 = fork();
		if (pipexstruct.pid1 == 0)
			if (p1child(paths, path, envp, pipexstruct) == 1)
				exit(1);


		pipexstruct.pid2 = fork();
		if (pipexstruct.pid2 == 0)
			if (p2child(paths, path, envp, pipexstruct) == 1)
				exit(1);

		closepipes(&pipexstruct);

		// waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0); // this will end
		waitpid(pipexstruct.pid1, &pipexstruct.pid1status, WNOHANG); // this will end
		// printf("status 2: %d\n", pipexstruct.pid2status);
		// waitpid(pipexstruct.pid2, &pipexstruct.pid2status, 0);
		waitpid(pipexstruct.pid2, &pipexstruct.pid2status, WNOHANG);

		// pid_t terminated_pid  = waitpid(pipexstruct.pid2, &pipexstruct.pid2status, WNOHANG);
		// printf("terminated_pid:%d\n", terminated_pid);
		// if (terminated_pid == -1) {
            // perror("waitpid");
        //     exit(EXIT_FAILURE);
        // } 
		// else if (terminated_pid == 0)
		// {
        // //     // Child process is still running (not terminated yet)
        //     printf("Child process is running.\n");
		// }
		// } else {
        //     // Child process has terminated
        //     if (WIFEXITED(pipexstruct.pid2status)) {
        //         printf("Child process %d terminated with exit status %d.\n", terminated_pid, WEXITSTATUS(pipexstruct.pid2status));
        //     } else {
        //         printf("Child process %d terminated abnormally.\n", terminated_pid);
        //     }
        // }


		pipexstruct.curr +=2;
	}
	
	return (0);
}
// bonus test 1:
// working
//   ./pipexs "infile" "END" "tr a b" "tr b e"  "output.txt"

// to implement
// ./pipexs "infile" "END" "tr a b" "tr b c" "tr b d"  "output.txt"
// ./pipexs "infile" "END" "tr a b" "tr b c" "tr b d" "tr d e" "output.txt"


// current:
//  ./pipexs "infile" "END" "tr a b" "tr b c" "output.txt"
//0  file to run: ./pipexs 
//1  heredoc file: "infile" 
//2  command to end heredoc: "END" 
//>3  first process: "tr a b" 
//4  second process: "tr b c" 
//5  outfile: "output.txt"
// argc = 6

//  ./pipexs "infile" "END" "tr a b" "tr b c"  "tr c d" "output.txt"
//0  file to run: ./pipexs 
//1  heredoc file: "infile" 
//2  command to end heredoc: "END" 
//>3  first process: "tr a b" 
//4  second process: "tr b c" 
//5  third process: "tr c d" 
//6  outfile: "output.txt"
// argc = 7



//compile 
// gcc -o main main.c libftfiles.c

// run
// ./main infile "ls -l" "wc -l" output.txt
// comamnd
// ls -l | wc -l > output.txt


// ./main  infile "grep this" "wc -w" output.txt

// ./pipex infile "grep file" "wc -l" output.txt


//0:./main
//1:infile
//2:"ls -l"
//3:"wc -l"
//4:output.txt

// ./main infile "ls -l" "wc -l" output.txt
