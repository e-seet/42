#include "utilsbonus.h"


// to check setstructure since it is for bonus
char	*findprocesspath(char *path, char *paths[],
struct s_pipex pipexstruct, int processnum)
{
	int	i;
	// int	j;

	i = 0;
	printf("process number:%d\n", processnum);
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, pipexstruct.argvs[0]);

		if (access(path, F_OK) == 0)
		{
			// printf("check the paths:%s\n", path);
			// printf("broke \n\n");
			break ;
		}
		free (path);
		path = NULL;
		i++;
	}
	
	if (access(path, F_OK) == 0)
	{
		// printf("found path:%s \n\n", path);
		return (path);

	}
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

int	p1child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct, int (*arrayoffd)[2])
{
	// printf("Running process\n");


	int		execveresult = 0;

	path = findprocesspath(path, paths, pipexstruct, pipexstruct.currpos);
	printf("p1child path:%s\n", path);

	printf("curr pos number:%d\n", pipexstruct.currpos);
	printf("las pos number:%d\n", pipexstruct.lastpos);

	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}

	// pipe(arrayoffd[pipexstruct.currpos]);

	// for first pipe when we open the file
	// read the file written by heredoc
	if (pipexstruct.currpos == 3)
	{	
		// original 
		// dup2(pipexstruct.fdpipe[1], 1);
		// close(pipexstruct.fdpipe[0]);
		// dup2(pipexstruct.p1fd, 0); // reading the file

		printf("\n\ncase 1: Read file\n");
		dup2(arrayoffd[pipexstruct.currpos][1], 1); // write to pipe instead of stdout
		close(arrayoffd[pipexstruct.currpos][0]); // close unused read pipe
		dup2(pipexstruct.infilefd, 0); // Read from file instead stdin
		write(1,"help la", 20);

	}
	// end
	else if (pipexstruct.currpos == pipexstruct.lastpos)
	{
		// original
		// dup2(pipexstruct.fdpipe[0], 0); // read file from pipe
		// close(pipexstruct.fdpipe[1]); // write file to pipe
		// dup2(pipexstruct.outfilefd, 1);
		
		printf("\n\ncase 2: Write to outfile\n");

		// new
		dup2(arrayoffd[pipexstruct.currpos-1][0], 0); // read from previous pipe
		close(arrayoffd[pipexstruct.currpos][1]); // close unused write pipe
		dup2(pipexstruct.outfilefd, 0); // from the reading of file
		printf("this run");

	}
	else if ( pipexstruct.currpos > 3)
	{
		printf("case 3. Continue\n");

		dup2(arrayoffd[pipexstruct.currpos-1][0], 0); // Read from previous pipe
		dup2(arrayoffd[pipexstruct.currpos][1], 1); // write to current pipe
	}

	printf("execve result");
	execveresult = execve(path, pipexstruct.argvs, envp);
	if (execveresult == -1)
		perror("Execve failed in P1child. Terminating Now");
	free(path);
	return (0);
}



//path: "/bin/ls"
//arg:  ["ls", "-l"]
// change from stdin(0)  to listen to fd[0]
int	p2child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct, int (*arrayoffd)[2])
{
	int		execveresult;

	path = findprocesspath(path, paths, pipexstruct, pipexstruct.currpos);
	printf("p2child path:%s\n", path);
	
	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}

	// else if 
	
	if (pipexstruct.currpos == pipexstruct.lastpos)
	{
		dup2(arrayoffd[pipexstruct.currpos][0], 0); 	//read from pipe
		close(arrayoffd[pipexstruct.currpos][1]); 	// close unused
		dup2(pipexstruct.p2fd, 1); 						// for writing to the outfile
	}
	//check this
	else
	{
		dup2(arrayoffd[pipexstruct.currpos][1], 1); 	// write to pipe
		dup2(arrayoffd[pipexstruct.currpos-1][0], 0); 	// Read from pipe
	}

	execveresult = execve(path, pipexstruct.argvs, envp);
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

	// if (argc < 5)
	// 	perror("  Too little arguments. :( Argue more ");

	// setting the array of pipes
	// n-1: n refers to the number of process executed
	// 2 refers to the in and output
	// arrayoffd[n-1][2]
	
	// Remove first 3 for running the program and heredoc
	// last one for fd
	// int numberofprocess = argc - 3 - 1;
	// int arrayoffd[numberofprocess][2]; 
	// for process piping
	int arrayoffd[argc][2]; 


	path = findpath(envp);
	paths = ft_split(path + 5, ':');

	int temp;
	temp = heredoccmd(&pipexstruct, argv);
	if (temp == 0)
	{
		// pipexstruct.heredocreadfd = open("heredoctemp.txt", O_RDONLY);
		// if(pipexstruct.heredocreadfd < 0)
		// 	perror("Error in opening the file to read. Terminating heredoc read now");
		
		// if (pipe(pipexstruct.fdpipe) == -1)
			// return (1);

		// pipexstruct.infilefd = open("heredoctemp.txt", O_TRUNC | O_CREAT | O_RDWR, 0644);
		// if(pipexstruct.infilefd< 0)
		// 	perror("Error in opening file. Terminating now2");
	
		setstructure(argv,argc, &pipexstruct);
	}
	else
		perror("heredoc failed and there may be issues with the writing of file. Terminating now");


	int start;
	start = 3;

	pipexstruct.lastpos = argc-2;

	while (argc -1 > start)
	{
		pipexstruct.currpos = start;
		pipexstruct.argvs = ft_split(argv[start], ' ');


		if (pipexstruct.pid1 != 0)
			wait(NULL);
		pipexstruct.pid1 = fork();
		if (pipexstruct.pid1 == 0)
			// need to change the pipes here
			if (p1child(paths, path, envp, pipexstruct, arrayoffd) == 1)
				exit(1);
		

		// pipexstruct.pid2 = fork();
		// if (pipexstruct.pid2 == 0)
		// 	if (p2child(paths, path, envp, pipexstruct, arrayoffd) == 1)
		// 		exit(1);

		// need to close the right pipes
		// closepipes(&pipexstruct); 

		waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0);
		start ++;

	}
	printf("end");

	
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

//example 2
// ./pipex "here_doc" "END" "grep a" "grep b" "wc -w" "output_file"

// example 3
// ./pipex "here_doc" "END" "ls -l"  "wc -w" "output_file"
// argv[0]: ./pipex
// argv[1]: "here_doc" 
// argv[2]: "END" 
// argv[3]: "ls -l"  
// argv[4]: "wc -w" 
// argv[5]: "output_file"


// gcc -o main main.c utils.c

// pipex original code
// ./main  infile "grep this" "wc -w" outfile
// argv[0]: ./main
// argv[1]: infile
// argv[2]: grep this
// argv[3]: wc -w
// argv[4]: outfile

// Basic stuff
//stdin: 0
//stdout: 1
//pipe fd[0]: read
//pipe fd[1]: write