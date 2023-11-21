// pipe then fork
#include "utils.h"

// to check setstructure since it is for bonus
char	*findprocesspath(char *path, char *paths[], struct s_pipex pipexstruct)
{
	int	i;

	i = 0;
	
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, pipexstruct.argvs[0]);
		if (access(path, F_OK) == 0)
		{
			printf("break\n");
			break ;

		}
		free(path);
		path = NULL;
		i++;
	}
	if (access(path, F_OK) == 0)
	{
		return (path);
	}
	else
	{
		return (NULL);
	}
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

int	p1child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct,  int (*arrayoffd)[2])
{
	int		execveresult;
	// printf("\n\nprocess child execution??\n");
	printf("\n\np1 child's curr: %d\n",pipexstruct.curr);

	path = findprocesspath(path, paths, pipexstruct);
	printf("the path:%s\n", path);

	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}
	
	pipe(arrayoffd[pipexstruct.curr]);

	if (pipexstruct.curr == 3)
	{
		printf("case 1:\n");
		
		
		//original	
		// dup2(pipexstruct.fdpipe[1], 1);
		// close(pipexstruct.fdpipe[0]);
		// dup2(pipexstruct.p1fd, 0);

		// testing
		dup2(arrayoffd[pipexstruct.curr][1], 1);  // write to pipe instead of stdout
		// dup2(arrayoffd[pipexstruct.curr+1][1], 1);  // if i used +1, the result will fly to stdout (1)
		
		close(arrayoffd[pipexstruct.curr][0]); // close read pipe
		dup2(pipexstruct.heredocreadfd, 0); // read from infile instead of stdin


	}
	else if ( pipexstruct.curr == pipexstruct.end)
	{
		printf("case 2: last process\n");
		// original
		// dup2(pipexstruct.fdpipe[0], 0);
		// close(pipexstruct.fdpipe[1]);
		// dup2(pipexstruct.p2fd, 1);		


		// to experiment with this.
		 //read from previous pipe?
		// dup2(arrayoffd[pipexstruct.curr-1][0], 0);

		//read from current pipe? Shouldnt work? but worked
		dup2(arrayoffd[pipexstruct.curr][0], 0); 
		close((arrayoffd[pipexstruct.curr][1])); // close write

		// The following line is correct
		dup2(pipexstruct.outfilefd, 1);	// to write to file
		
		// dup2(pipexstruct.outfilefd, arrayoffd[pipexstruct.curr][1]);	// to write to file
		// dup2(pipexstruct.outfilefd, arrayoffd[pipexstruct.curr][0]);	// to write to file
		// dup2(pipexstruct.outfilefd, 1);	// to write to file
		// dup2(arrayoffd[pipexstruct.curr+1][1], 1);  // if i used +1, the result will fly to stdout (1)
		

			// while ((bytes_read = read(arrayoffd[pipexstruct.curr-1][0], buffer, 1024)) > 0) // bad fd
			// while ((bytes_read = read(arrayoffd[pipexstruct.curr][1], buffer, 1024)) > 0) // bad fd


			char buffer[1024];  // Allocate a buffer for the read operation
			int bytes_read = 0; 

			// printf("trying to read from pipe\n");
			// write(1,"write from pipe\n", 16);
			//	no difference and no output..
			// while ((bytes_read = read(arrayoffd[pipexstruct.curr-1][1], buffer, 1024)) > 0)
			while ((bytes_read = read(arrayoffd[pipexstruct.curr][0], buffer, 1024)) > 0)
		
			// while ((bytes_read = read(arrayoffd[pipexstruct.curr-1][0], buffer, 1024)) > 0) // fail
			// while ((bytes_read = read(arrayoffd[pipexstruct.curr][1], buffer, 1024)) > 0) // failed
			{
				write(1, buffer, bytes_read);
			}

			// Check if the read operation finished because of an error or end-of-file
			if (bytes_read == -1) {
				// An error occurred, handle it here
				perror("read failed");
			} 
			
		// this gets written to the output file.	
		// write(1, "end\n", 3);

	}
	// else
	// {
	// 	printf("case 3: middle process \n");
	// 	dup2(arrayoffd[pipexstruct.curr-1][0], 0); //read from previous pipe
	// 	close(arrayoffd[pipexstruct.curr-1][1]); //read from previous pipe
	// 	dup2(arrayoffd[pipexstruct.curr][1], 1); //write to next pipe
	// }
	// dup2(pipexstruct.fdpipe[1], 1);
	// close(pipexstruct.fdpipe[0]);
	// dup2(pipexstruct.p1fd, 0);

	
	// printf("check args:\n");
	// int z = 0;
	// while(pipexstruct.argvs[z])
	// {
	// 	printf("%s\n", pipexstruct.argvs[z]);
	// 	z ++;
	// }
	
	execveresult = execve(path, pipexstruct.argvs, envp);
	if (execveresult == -1)
		perror("Execve failed in Process. Terminating Now\n");
	else
		printf("p1 executed\n");
	free(path);

	return (0);
}

//path: "/bin/ls"
//arg:  ["ls", "-l"]
// change from stdin(0)  to listen to fd[0]

// int	p2child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
// {
// 	int		execveresult;

// 	path = findprocesspath(path, paths, pipexstruct, 2);
// 	if (access(path, F_OK) != 0)
// 	{
// 		perror("command not found");
// 		return (1);
// 	}
// 	dup2(pipexstruct.fdpipe[0], 0);
// 	close(pipexstruct.fdpipe[1]);
// 	dup2(pipexstruct.p2fd, 1);
// 	execveresult = execve(path, pipexstruct.argvs2, envp);
// 	if (execveresult == -1)
// 		perror("smth wrong with executing. Terminate now");
// 	free(path);
// 	return (0);
// }

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
	

	int temp;
	temp = heredoccmd(&pipexstruct);
	if (temp == 0)
	{
			// char buffer[1024];  // Allocate a buffer for the read operation
			// int bytes_read; 
			pipexstruct.heredocreadfd = open("heredoctemp.txt", O_RDONLY);
			// // Perform the read operation in a loop until there's nothing left to read
			// while ((bytes_read = read(pipexstruct.heredocreadfd, buffer, 1024)) > 0)
			// {
			// 	// Process the bytes read
			// 	write(1, buffer, bytes_read);
			// }

			// // Check if the read operation finished because of an error or end-of-file
			// if (bytes_read == -1) {
			// 	// An error occurred, handle it here
			// 	perror("read failed");
			// } else {
			// 	// End of file reached, all data has been read
			// }

	}
	else
		perror("heredoccmd failed");


	pipexstruct.p1fd = 0;


	//setting up for processors
	int start = 3;
	pipexstruct.end = argc - 2; // to check
	int arrayoffd[argc][2];



	// printf("\nend of heredoc\n\n");
	// printf("\n\nto ignore\n%s, %s, %d, %d %d\n.", paths[0],argv[0], pipexstruct.p1fd, argc, start); 

	pipexstruct.outfilefd = open(argv[argc-1], O_TRUNC | O_CREAT | O_RDWR, 0644);

	// printf("where we stop?:%d\n", argc-1);
	while ((argc-1) > start)
	{
		// printf("start:%d\n", start);
		pipexstruct.curr = start;
		// printf("pipex curr: %d\n",pipexstruct.curr);
		pipexstruct.argvs = ft_split(argv[start], ' ');

		if (pipexstruct.pid1 != 0)
			wait(NULL);
		pipexstruct.pid1 = fork();

		if (pipexstruct.pid1 == 0)
		{
			if (p1child(paths, path, envp, pipexstruct, arrayoffd) == 1)
				exit(1);
		}
			
		waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0);
		start++;
	}

	printf("end of all my processes\n");

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



// find . -name "*.c" | entr make bonus
