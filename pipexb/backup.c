//https://github.com/cclaude42/pipex/blob/master/bonus.c#L15

// #include "utils.h"

// char	*findprocesspath(char *path, char *paths[],
// struct s_pipex pipexstruct, int processnum)
// {
// 	int	i;

// 	// printf("findprocesspath\n");
// 	// printf("joined this:%s\n", pipexstruct.argvs1[0]);

// 	i = 0;
// 	while (paths[i])
// 	{
// 		path = ft_strjoin(paths[i], "/");
// 		if (processnum == 1)
// 			path = ft_strjoin(path, pipexstruct.argvs1[0]);
// 		else if (processnum == 2)
// 			path = ft_strjoin(path, pipexstruct.argvs2[0]);
// 		else
// 			path = ft_strjoin(path, pipexstruct.argvs3[0]);

// 		if (access(path, F_OK) == 0)
// 		{
// 			// printf("found path\n");
// 			break ;
// 		}
// 		free (path);
// 		path = NULL;
// 		i++;
// 	}
// 	if (access(path, F_OK) == 0)
// 		return (path);
// 	else
// 		return (NULL);
// }
// /*
// int	p1child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
// {
// 	int		execveresult;

// 	printf("\n\np1child: %d\n", pipexstruct.curr);
// 	// printf("argc:%d\n", pipexstruct.argc);

// 	path = findprocesspath(path, paths, pipexstruct, 1);
// 	printf("the path1 to use: %s\n", path);
// 	if (access(path, F_OK) != 0)
// 	{ 
// 		perror("command not found");
// 		return (1);
// 	}

// 	// first, read from fd
// 	if (pipexstruct.curr == 3)
// 	{
// 		// read from file:
// 		printf("p1: if: read file fd and start the process");
// 		dup2(pipexstruct.fdpipe[1], 1);
// 		close(pipexstruct.fdpipe[0]);
// 		dup2(pipexstruct.p1fd, 0);
// 	}
// 	// supposed to write output to p1fd.
// 	else if (pipexstruct.curr + 3 == pipexstruct.argc)
// 	{
// 		printf("p1: else if: write output to p1fd");

// 		// printf("check p1fd:%d", pipexstruct.p1fd);
// 		dup2(pipexstruct.fdpipe[0], 0);
// 		// close(pipexstruct.fdpipe[1]);
// 		dup2(pipexstruct.p1fd, 1);
// 	}
// 	// else if (pipexstruct.curr == 5)
// 	// {
// 	// 	printf("huh");
// 	// }
// 	else
// 	{
// 		printf("p1: else\n");
// 		printf("p1child to do something \n");

// 		// printf("curr value: %d\n", pipexstruct.curr);
// 		// printf("argc value:%d\n", pipexstruct.argc);
// 		printf("check p1fd:%d\n", pipexstruct.p1fd);
// 		printf("check p2fd:%d\n", pipexstruct.p2fd);

// 		int i = 0;
// 		// printf("\n");
// 		while (pipexstruct.argvs1[i])
// 		{
// 			printf("argvs %d, %s\n", i, pipexstruct.argvs1[i]);
// 			i ++;
// 		}
	
// 		// printf("Write to fd here\n");
// 		// dup2(0,pipexstruct.fdpipe[0]);
// 		// dup2(1,pipexstruct.fdpipe[1]);


// 		// dup2(pipexstruct.fdpipe[0], 0);
// 		// dup2(pipexstruct.fdpipe[1], 1);
// 		// dup2(pipexstruct.p1fd,1);

// 		// close(pipexstruct.fdpipe[1]);
// 		// close(pipexstruct.fdpipe[0]);
// 		// dup2(pipexstruct.fdpipe[1], 1);
// 		// dup2(pipexstruct.p2fd, 1); 
		

// 		// char buffer[1024];
// 		// int bytes_read;

// 		// bytes_read = read(pipexstruct.fdpipe[0], buffer, sizeof(buffer));
// 		// if (bytes_read < 0) {
// 		// 	perror("Error reading from the pipe");
// 		// } else {
// 		// 	// Process the data in the 'buffer' here
// 		// 	printf("there is content");
// 		// 	printf("%d", bytes_read);
// 		// }


// 		// dup2(pipexstruct.fdpipe[0], 0);
// 		// dup2(pipexstruct.fdpipe[1], 1);
// 		// return 0;
// 	}

// 	execveresult = execve(path, pipexstruct.argvs1, envp);
// 	if (execveresult == -1)
// 		perror("Execve failed in P1child. Terminating Now");
// 	free(path);
// 	return (0);
// }*/

// //path: "/bin/ls"
// //arg:  ["ls", "-l"]
// // change from stdin(0)  to listen to fd[0]

// // modified
// /*int	p2child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
// {
// 	int		execveresult;

// 	printf("\n\np2child: %d\n", pipexstruct.curr+1);
// 	path = findprocesspath(path, paths, pipexstruct, 2);
// 	printf("the path2 to use: %s\n\n", path);
	
// 	if (access(path, F_OK) != 0)
// 	{
// 		perror("command not found");
// 		return (1);
// 	}


// 	// End at the current P2 
// 	if (pipexstruct.argc - 3 == pipexstruct.curr)
// 	{
// 		printf("p2child: %d. if\n", pipexstruct.curr);
// 		printf("check fd:%d", pipexstruct.p2fd);
// 		dup2(pipexstruct.fdpipe[0], 0);
// 		close(pipexstruct.fdpipe[1]);
// 		dup2(pipexstruct.p2fd, 1);
// 	}  
// 	else
// 	{
// 		printf("p2child: %d. Else\n", pipexstruct.curr);
// 		dup2(pipexstruct.fdpipe[0], 0);
// 		// added this line and it stop appearing at the end of p4
// 		dup2(pipexstruct.fdpipe[1], 1); 

// 	}
// 	// Curr:p2. End at P1 
// 	// else if (pipexstruct.argc -3 == pipexstruct.curr)
// 	// {
// 	// 	printf("p2child to do. else if\n");
// 	// }
// 	// // continue to pipe to p1
// 	// else
// 	// {
// 	// 	printf("p2child to do. Else\n");

// 	// }

// 	execveresult = execve(path, pipexstruct.argvs2, envp);
// 	if (execveresult == -1)
// 		perror("smth wrong with executing. Terminate now");
// 	free(path);
// 	return (0);
// }*/

// int	p3child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
// {
// 	int		execveresult;

// 	// printf("\n\np3child: %d\n", pipexstruct.curr);
// 	path = findprocesspath(path, paths, pipexstruct, 3);
// 	int	 i = 0;
// 	while (pipexstruct.argvs3[i])
// 	{
// 		printf("argvs %d, %s ", i, pipexstruct.argvs3[i]);
// 		i ++;
// 	}
	
// 	if (access(path, F_OK) != 0)
// 	{
// 		perror("command not found");
// 		return (1);
// 	}

// 	// read from file:
// 	if (pipexstruct.curr == 3)
// 	{
// 		printf("p3child:%d if: read file fd and start the process\n", pipexstruct.curr);

// 		dup2(pipexstruct.fdpipe[1], 1);
// 		close(pipexstruct.fdpipe[0]);
// 		dup2(pipexstruct.p1fd, 0); // fixed 
// 	}
// 	// End at the current P2 
// 	else if (pipexstruct.argc - 2 == pipexstruct.curr)
// 	{
// 		printf("p3child: %d. else if\n", pipexstruct.curr);
// 		printf("check fd:%d", pipexstruct.p2fd);
// 		dup2(pipexstruct.fdpipe[0], 0);
// 		close(pipexstruct.fdpipe[1]);
// 		dup2(pipexstruct.p2fd, 1);
// 		printf("hi");
// 	}  
// 	else
// 	{
// 		printf("p3child: %d. Else: just pipe 0 and 1\n", pipexstruct.curr);
// 		// close(pipexstruct.fdpipe[0]);
// 		dup2(pipexstruct.fdpipe[0], 0);
// 		// dup2(pipexstruct.fdpipe[1], 1); 
// 		dup2(pipexstruct.p2fd, 1);

// 	}
// 	// else if (pipexstruct.argc -3 == pipexstruct.curr)
// 	// {
// 	// 	printf("p2child to do. else if\n");
// 	// }
// 	// // continue to pipe to p1
// 	// else
// 	// {
// 	// 	printf("p2child to do. Else\n");

// 	// }

// 	execveresult = execve(path, pipexstruct.argvs3, envp);
// 	if (execveresult == -1)
// 		perror("smth wrong with executing. Terminate now");
// 	free(path);
// 	return (0);
// }

// char	*findpath(char *envp[])
// {
// 	int		i;
// 	char	*path;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (ft_strncmp("PATH=", envp[i], 5) == 0)
// 		{
// 			path = envp[i];
// 			break ;
// 		}
// 		i++;
// 	}
// 	if (ft_strncmp("PATH=", path, 5) == 0)
// 		return (path);
// 	else
// 		return (NULL);
// }

// // int	main(int argc, char *argv[], char *envp[])
// // {
// // 	struct s_pipex	pipexstruct;
// // 	char			*path;
// // 	char			**paths;
// // 	// int				curr;

// // 	// if (argc != 5)
// // 		// return (1);

// // 	path = findpath(envp);
// // 	paths = ft_split(path + 5, ':');
// // 	if (pipe(pipexstruct.fdpipe) == -1)
// // 		return (1);

// // 	// looping 
// // 	setstructure(argc, argv, &pipexstruct);

// // 	// printf("basic testing of variables: argc:%d\n", argc);


// // 	while (argc - 2 >= pipexstruct.curr)
// // 	{
// // 		/*
// // 		printf("\ncurr value: %d\n", pipexstruct.curr);
// // 		printf("argc value:%d\n", pipexstruct.argc);
// // 		*/

// // 		pipexstruct.argvs1 = ft_split(argv[pipexstruct.curr], ' ');
// // 		pipexstruct.argvs2 = ft_split(argv[pipexstruct.curr+1], ' ');

// // 		// this will allow us to check if it is the last process
// // 		if (argc == pipexstruct.curr + 3)
// // 		{
// // 			// ends with p2 process
// // 			if (pipexstruct.curr %2 == 1)
// // 			{
// // 				// printf("Ends with p2 process\n");
// // 				pipexstruct.p2fd = open(argv[pipexstruct.curr+2], O_TRUNC | O_CREAT | O_RDWR, 0644);
// // 				if (pipexstruct.p2fd == -1 )
// // 					printf("error2 opening file fd2:%d\n", pipexstruct.p2fd);
// // 			}
// // 			// ends with p1 process
// // 			else
// // 			{
// // 				printf("Ends with p1 process\n");
// // 				pipexstruct.p1fd = open(argv[pipexstruct.curr+2], O_TRUNC | O_CREAT | O_RDWR, 0644);
// // 				if (pipexstruct.p1fd == -1 )
// // 					printf("error1 opening file fd1:%d\n", pipexstruct.p1fd);
// // 			}
// // 		}
// // 		// else if (argc == curr + 3)
// // 		// {
// // 		// 	printf("case3 struct: %s \n", argv[curr+3]);
// // 		// 	pipexstruct.p2fd = open(argv[curr+3], O_TRUNC | O_CREAT | O_RDWR, 0644);
// // 		// 	printf("opened? %d\n", pipexstruct.p2fd);
// // 		// }

// // 		if (pipexstruct.pid1 != 0)
// // 			wait(NULL);

// // 		pipexstruct.pid1 = fork();
// // 		if (pipexstruct.pid1 == 0)
// // 			if (p1child(paths, path, envp, pipexstruct) == 1)
// // 				exit(1);


// // 		if (pipexstruct.curr + 2 != pipexstruct.argc)
// // 		{
		
// // 			pipexstruct.pid2 = fork();
// // 			if (pipexstruct.pid2 == 0)
// // 				if (p2child(paths, path, envp, pipexstruct) == 1)
// // 					exit(1);
// // 		}

// // 		// closepipes(&pipexstruct);

// // 		// waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0); // this will end
// // 		waitpid(pipexstruct.pid1, &pipexstruct.pid1status, WNOHANG); // this will end
// // 		// printf("status 2: %d\n", pipexstruct.pid2status);
// // 		// waitpid(pipexstruct.pid2, &pipexstruct.pid2status, 0);
// // 		waitpid(pipexstruct.pid2, &pipexstruct.pid2status, WNOHANG);

// // 		// pid_t terminated_pid  = waitpid(pipexstruct.pid2, &pipexstruct.pid2status, WNOHANG);
// // 		// printf("terminated_pid:%d\n", terminated_pid);
// // 		// if (terminated_pid == -1) {
// //             // perror("waitpid");
// //         //     exit(EXIT_FAILURE);
// //         // } 
// // 		// else if (terminated_pid == 0)
// // 		// {
// //         // //     // Child process is still running (not terminated yet)
// //         //     printf("Child process is running.\n");
// // 		// }
// // 		// } else {
// //         //     // Child process has terminated
// //         //     if (WIFEXITED(pipexstruct.pid2status)) {
// //         //         printf("Child process %d terminated with exit status %d.\n", terminated_pid, WEXITSTATUS(pipexstruct.pid2status));
// //         //     } else {
// //         //         printf("Child process %d terminated abnormally.\n", terminated_pid);
// //         //     }
// //         // }


// // 		pipexstruct.curr +=2;
// // 	}
	
// // 	return (0);
// // }


// int	main(int argc, char *argv[], char *envp[])
// {
// 	struct s_pipex	pipexstruct;
// 	char			*path;
// 	char			**paths;

// 	path = findpath(envp);
// 	paths = ft_split(path + 5, ':');
// 	if (pipe(pipexstruct.fdpipe) == -1)
// 		return (1);

// 	// looping 
// 	setstructure(argc, argv, &pipexstruct);
// 	printf("check fdof p2:%d\n", pipexstruct.p2fd);
// 	while (pipexstruct.argc - 2 >= pipexstruct.curr)
// 	{
// 		/*
// 		printf("runs here");
// 		printf("argc value:%d\n", pipexstruct.argc);
// 		printf("\ncurr value: %d\n", pipexstruct.curr);
// 		*/

// 		pipexstruct.argvs3 = ft_split(argv[pipexstruct.curr], ' ');

// 		// this will allow us to check if it is the last process
// 		// if (argc == pipexstruct.curr + 3)
// 		// {
// 		// 	// ends with p2 process
// 		// 	if (pipexstruct.curr %2 == 1)
// 		// 	{
// 		// 		// printf("Ends with p2 process\n");
// 		// 		pipexstruct.p2fd = open(argv[pipexstruct.curr+2], O_TRUNC | O_CREAT | O_RDWR, 0644);
// 		// 		if (pipexstruct.p2fd == -1 )
// 		// 			printf("error2 opening file fd2:%d\n", pipexstruct.p2fd);
// 		// 	}
// 		// 	// ends with p1 process
// 		// 	else
// 		// 	{
// 		// 		printf("Ends with p1 process\n");
// 		// 		pipexstruct.p1fd = open(argv[pipexstruct.curr+2], O_TRUNC | O_CREAT | O_RDWR, 0644);
// 		// 		if (pipexstruct.p1fd == -1 )
// 		// 			printf("error1 opening file fd1:%d\n", pipexstruct.p1fd);
// 		// 	}
// 		// }
// 		// if (pipexstruct.pid1 != 0)
// 		// 	wait(NULL);

// 		pipexstruct.pid3 = fork();
		
// 		if (pipexstruct.pid3 == 0)
// 			if (p3child(paths, path, envp, pipexstruct) == 1)
// 				exit(1);

// 		waitpid(pipexstruct.pid3, &pipexstruct.pid3status, WNOHANG); // this will end
// 		// waitpid(pipexstruct.pid3, &pipexstruct.pid3status, 0); // this will end
// 		pipexstruct.curr +=1;
// 	}
	
// 	return (0);
// }

// // bonus test 1:
// // working
// //   ./pipexs "infile" "END" "tr a b" "tr b e"  "output.txt"

// // to implement
// // ./pipexs "infile" "END" "tr a b" "tr b c" "tr b d"  "output.txt"
// // ./pipexs "infile" "END" "tr a b" "tr b c" "tr b d" "tr d e" "output.txt"


// // current:
// //  ./pipexs "infile" "END" "tr a b" "tr b c" "output.txt"
// //0  file to run: ./pipexs 
// //1  heredoc file: "infile" 
// //2  command to end heredoc: "END" 
// //>3  first process: "tr a b" 
// //4  second process: "tr b c" 
// //5  outfile: "output.txt"
// // argc = 6

// //  ./pipexs "infile" "END" "tr a b" "tr b c"  "tr c d" "output.txt"
// //0  file to run: ./pipexs 
// //1  heredoc file: "infile" 
// //2  command to end heredoc: "END" 
// //>3  first process: "tr a b" 
// //4  second process: "tr b c" 
// //5  third process: "tr c d" 
// //6  outfile: "output.txt"
// // argc = 7



// //compile 
// // gcc -o main main.c libftfiles.c

// // run
// // ./main infile "ls -l" "wc -l" output.txt
// // comamnd
// // ls -l | wc -l > output.txt


// // ./main  infile "grep this" "wc -w" output.txt

// // ./pipex infile "grep file" "wc -l" output.txt


// //0:./main
// //1:infile
// //2:"ls -l"
// //3:"wc -l"
// //4:output.txt

// // ./main infile "ls -l" "wc -l" output.txt




































































































#include "utils.h"

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
		else
			path = ft_strjoin(path, pipexstruct.argvs3[0]);

		if (access(path, F_OK) == 0)
		{
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

int	p3child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	path = findprocesspath(path, paths, pipexstruct, 3);
	
	// check access
	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}

	execveresult = execve(path, pipexstruct.argvs3, envp);
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

	path = findpath(envp);
	paths = ft_split(path + 5, ':');

	if (pipe(pipexstruct.fdpipe1) == -1)
		return (1);

	if (pipe(pipexstruct.fdpipe2) == -1)
		return (1);

	// looping 
	setstructure(argc, argv, &pipexstruct);
	// printf("argc:%d, curr:%d", pipexstruct.argc, pipexstruct.curr);
	printf("argc:%d\n", pipexstruct.argc);

	while (pipexstruct.argc - 1 > pipexstruct.curr)
	{
		pipexstruct.argvs3 = ft_split(argv[pipexstruct.curr], ' ');
		
		if (pipexstruct.curr != 3 && pipexstruct.curr % 2 == 1)
		{
			if (pipe(pipexstruct.fdpipe1) == -1)
				return (1);
		}
			
		if (pipexstruct.curr != 4 && pipexstruct.curr % 2 == 0)
		{
			if (pipe(pipexstruct.fdpipe2) == -1)
				return (1);
		}

		pipexstruct.pid3 = fork();


		// /*
		//child process 
		if (pipexstruct.pid3 == 0)
		{
			printf("child:%d dups\n", pipexstruct.curr);

			if (pipexstruct.curr == 3)
			{
				dup2(pipexstruct.p1fd, 0);		// read from p1fd instead of stdin
				dup2(pipexstruct.fdpipe1[1], 1); 			// write to pipefd instead of stdout
			}
			else if (pipexstruct.argc - 2 == pipexstruct.curr)
			{
				dup2(pipexstruct.fdpipe2[0], 0);
				dup2(pipexstruct.p2fd, 1);
			}
			else if (pipexstruct.curr % 2 == 0)
			{
				dup2(pipexstruct.fdpipe1[0], 0);				// read from pipe instead of stdin
				dup2(pipexstruct.fdpipe2[1], 1); // write to fdpipe instead of stdout
			}
			else if (pipexstruct.curr % 2 == 1)
			{
				dup2(pipexstruct.fdpipe2[0], 0);	// read from fdpipe instead of stdout
				dup2(pipexstruct.fdpipe1[1], 1); 			
			}
			else
			{
				printf("quit from child\n");
				exit(1);
			}
			int result = p3child(paths, path, envp, pipexstruct);
			if (result == 1)
			{
				printf("error: 1, exiting\n");
				exit(1);
			}
		}
		// */

		// child process
		/*
		if (pipexstruct.pid3 == 0)
		{
			printf("child:%d dups\n", pipexstruct.curr);
			if (pipexstruct.curr == 3)
			{
				dup2(pipexstruct.p1fd, 0);		// read from p1fd instead of stdin
				dup2(pipexstruct.fdpipe1[1], 1); 			// write to pipefd instead of stdout
				int result = p3child(paths, path, envp, pipexstruct);
				if (result == 1)
				{
					printf("error: 1, exiting\n");
					exit(1);
				}
			}
			else if (pipexstruct.curr == 4)
			{
				dup2(pipexstruct.fdpipe1[0], 0);				// read from pipe instead of stdin
				dup2(pipexstruct.fdpipe2[1], 1); // write to fdpipe instead of stdout
				int result = p3child(paths, path, envp, pipexstruct);
				if (result == 1)
				{
					printf("error: 1, exiting\n");
					exit(1);
				}
			}
			else if (pipexstruct.curr == 5)
			{
				dup2(pipexstruct.fdpipe2[0], 0);	// read from fdpipe instead of stdout
				dup2(pipexstruct.fdpipe1[1], 1); 			
				int result = p3child(paths, path, envp, pipexstruct);
				if (result == 1)
				{
					printf("error: 1, exiting\n");
					exit(1);
				}
			}
			else if (pipexstruct.curr == 6)
			{
				dup2(pipexstruct.fdpipe1[0], 0);
				dup2(pipexstruct.fdpipe2[1], 1); // this not working
				int result = p3child(paths, path, envp, pipexstruct);
				if (result == 1)
				{
					printf("error: 1, exiting\n");
					exit(1);
				}
			}
			else if (pipexstruct.curr == 7)
			{
				dup2(pipexstruct.fdpipe2[0], 0);
				dup2(pipexstruct.p2fd, 1);
				int result = p3child(paths, path, envp, pipexstruct);
				if (result == 1)
				{
					printf("error: 1, exiting\n");
					exit(1);
				}
			}
			else
			{
				exit(1);
			}
		}
		// */

		// parent process
		else
		{
			if (pipexstruct.curr == 3)
			{
				close(pipexstruct.fdpipe1[1]);
				waitpid(pipexstruct.pid3, NULL, 0); // modified 
			}
			else if (pipexstruct.curr == 4)
			{
				close(pipexstruct.fdpipe2[1]);
				waitpid(pipexstruct.pid3, NULL, 0); // modified 
		
			}
			else if (pipexstruct.curr == 5)
			{
				close(pipexstruct.fdpipe1[1]);
				waitpid(pipexstruct.pid3, NULL, 0); // modified 
			}
			else if (pipexstruct.curr == 6)
			{
				close(pipexstruct.fdpipe2[1]);
				waitpid(pipexstruct.pid3, NULL, 0); // modified 
			}
			else if (pipexstruct.curr == 7)
			{
				close(pipexstruct.fdpipe1[1]);
				waitpid(pipexstruct.pid3, NULL, 0); // modified 
			}
			else
			{
				exit(1);
			}
		}

		
		pipexstruct.curr +=1;
	}
	
	return (0);
}

