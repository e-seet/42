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

int	p1child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct,  
// int (*arrayoffd)[2], 
int fdpipe[])
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
	

	if (pipexstruct.curr == 3)
	{
		printf("case 1:\n");
		
		// dup2(arrayoffd[pipexstruct.curr][1], 1);  // write to pipe instead of stdout
		// close(arrayoffd[pipexstruct.curr][0]); // close read pipe
		dup2(fdpipe[1], 1);  // write to pipe instead of stdout
		close(fdpipe[0]); // close read pipe
		dup2(pipexstruct.heredocreadfd, 0); // read from infile instead of stdin
	}
	else if ( pipexstruct.curr == pipexstruct.end)
	{
		printf("case 2: last process To check my pipes H\n");

		dup2(fdpipe[0], 0); 
		close(fdpipe[1]); // close write //this is where is says bad fd
		dup2(pipexstruct.outfilefd, 1);	// to write to file


		// char buffer[1024];  // Allocate a buffer for the read operation
		// int bytes_read = 0; 
		// here is the bad file descriptor
		// while ((bytes_read = read(fdpipe[0], buffer, 1024)) > 0) // failed
		// {
		// 	write(1, buffer, bytes_read);
		// }

		// // Check if the read operation finished because of an error or end-of-file
		// if (bytes_read == -1) {
		// 	// An error occurred, handle it here
		// 	perror("read failed");
		// } 
		


		// dup2(arrayoffd[pipexstruct.curr][0], 0); 
		// close((arrayoffd[pipexstruct.curr][1])); // close write
		// The following line is correct

		// char buffer[1024];  // Allocate a buffer for the read operation
		// int bytes_read = 0; 
		// while ((bytes_read = read(fdpipe[1], buffer, 1024)) > 0) // failed
		// {
		// 	write(1, buffer, bytes_read);
		// }



		// char buffer[1024];  // Allocate a buffer for the read operation
		// int bytes_read = 0; 
		//here is the bad file descriptor
		// while ((bytes_read = read(arrayoffd[pipexstruct.curr][1], buffer, 1024)) > 0) // failed
		// {
		// 	write(1, buffer, bytes_read);
		// }

		// // Check if the read operation finished because of an error or end-of-file
		// if (bytes_read == -1) {
		// 	// An error occurred, handle it here
		// 	perror("read failed");
		// } 
		

	}

	execveresult = execve(path, pipexstruct.argvs, envp);
	if (execveresult == -1)
		perror("Execve failed in Process. Terminating Now\n");
	else
		printf("p1 executed\n");
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
	

	int temp;
	temp = heredoccmd(&pipexstruct);
	if (temp == 0)
	{
			// char buffer[1024];  // Allocate a buffer for the read operation
			// int bytes_read; 
			pipexstruct.heredocreadfd = open("heredoctemp.txt", O_RDONLY);
			if (pipexstruct.heredocreadfd == - 1)
				printf("heredocreadfd opened with error")
			else
				printf("no error")
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

	int		fdpipe[2];

	//setting up for processors
	int start = 3;
	pipexstruct.end = argc - 2; // to check
	// int arrayoffd[argc][2];

	pipexstruct.outfilefd = open(argv[argc-1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	printf("check fd:%d | outfile name:%s", pipexstruct.outfilefd, argv[argc-1]);

	// printf("where we stop?:%d\n", argc-1);
	while ((argc-1) > start)
	{
		pipexstruct.curr = start;
		pipexstruct.argvs = ft_split(argv[start], ' ');

		// pipe(arrayoffd[pipexstruct.curr]);

		if (pipexstruct.pid1 != 0)
			wait(NULL);
		pipexstruct.pid1 = fork();

		if (pipexstruct.pid1 == 0)
		{
			if (p1child(paths, path, envp, pipexstruct, fdpipe) == 1)
				exit(1);
		}
			
		waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0);
		start++;
	}

	printf("end of all my processes\n");

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
