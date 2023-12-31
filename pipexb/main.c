#include "utils.h"

char	*findprocesspath(char *path, char *paths[],
struct s_pipex pipexstruct, int processnum)
{
	int	i;

	printf("findprocesspath\n");
	printf("joined this:%s\n", pipexstruct.argvs1[0]);

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

	printf("\n\np1child\n");
	path = findprocesspath(path, paths, pipexstruct, 1);
	printf("the path to use: %s\n\n", path);
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

// modified
int	p2child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	printf("\n\np2child\n");
	path = findprocesspath(path, paths, pipexstruct, 2);
	printf("the path to use: %s\n\n", path);
	
	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}

	// original code
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
	int				curr;

	// if (argc != 5)
		// return (1);

	path = findpath(envp);
	paths = ft_split(path + 5, ':');
	if (pipe(pipexstruct.fdpipe) == -1)
		return (1);

	// looping 
	setstructure(argc, argv, &pipexstruct);

	curr = 3;

	printf("basic testing of variables: argc:%d\n\n", argc);


	while (argc - 3 >= curr)
	{
		pipexstruct.argvs1 = ft_split(argv[curr], ' ');

		printf("\n\ncurr value: %d\n", curr);
		printf("argc value:%d\n", argc);


		if (argc == curr + 3)
		{

			pipexstruct.p2fd = open(argv[curr+2], O_TRUNC | O_CREAT | O_RDWR, 0644);
			//lazy method
			if (curr != 3)
			{
				pipexstruct.p1fd = open(argv[curr+2], O_TRUNC | O_CREAT | O_RDWR, 0644);
			}

			if (pipexstruct.p2fd == -1 ||pipexstruct.p1fd == -1 )
			{
				printf("error opening file fd1:%d, fd2:%d\n", pipexstruct.p1fd, pipexstruct.p2fd);
			}
			else
				printf("error opening file fd1:%d, fd2:%d\n", pipexstruct.p1fd, pipexstruct.p2fd);
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


		printf("argv::%s\n",argv[curr+1]);
		
		pipexstruct.argvs2 = ft_split(argv[curr+1], ' ');
		pipexstruct.pid2 = fork();
		if (pipexstruct.pid2 == 0)
			if (p2child(paths, path, envp, pipexstruct) == 1)
				exit(1);

		closepipes(&pipexstruct);
		printf("status 2: %d\n", pipexstruct.pid2status);

		waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0); // this will end
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


		curr +=2;
	}
	
	return (0);
}

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
