// To do: find out what happen if file is missing. To test

// quick reference
// stdin 0
// stdout 1
// stderr 2
//creating the pipe
//fd[0] - read
//fd[1] - write	

// #include "libftfiles.h"
#include <sys/wait.h>
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>
//for read write, permission with files, creating files
#include <fcntl.h>

//struct to store whatever i need for now
struct pipeStructure {
    int pid1;
	int pid1status;
	int p1fd;

    int pid2;
	int pid2status;
	int p2fd;

	// int fdpipe[];
};

// P1 write to pipe
void P1child(char *argv[], char *paths[], char *path, char *envp[], struct pipeStructure pipexStruct, int fd[])
{
		int		i;
		char	**argvs;

		i = 0;
		argvs = ft_split(argv[2], ' ');
		// loop through the various
		while (paths[i])
		{
			path = ft_strjoin(paths[i], "/");
			path = ft_strjoin(path, argvs[0]);
			//check the path+file exists
			if (access(path, F_OK) == 0)
				break;
			free(path);
			path = NULL;
			i++;
		}
		//check that at the end (when break out or end of loop)
		if (access(path, F_OK) != 0)
			return perror("access error");


		pipexStruct.p1fd = open(argv[1], O_RDONLY);
		if (pipexStruct.p1fd < 0)
			perror("Error in opening file. Terminating now");

		//Change from stdout(1) to fd[1] so that the data that supposed to go stdout will go to pipe instead
		// then it will write into pipe. That's why fd[1]
		dup2(fd[1], 1);
		//close the pipe for reading
		close(fd[0]);
		//Change the stdin(0) to read the file's fd so that it will read from the file of interest
		dup2(pipexStruct.p1fd, 0);

		int execveResult;
		//path: "/bin/ls"
		//arg:  ["ls", "-l"]
		execveResult =  execve(path, argvs, envp);
		
		if (execveResult == -1)
			perror("Execve failed in P1child. Terminating Now");
		free(path);
		free(argvs);
		//end of process code
}

// read from pipe and write
void P2child(char *argv[], char *paths[], char *path, char *envp[], struct pipeStructure pipexStruct, int fd[])
{
		int i;
		char **argvs;

		i = 0;
		argvs = ft_split(argv[2], ' ');
		while (paths[i])
		{
			path = ft_strjoin(paths[i], "/");
			path = ft_strjoin(path, argvs[0]);
			//check the path+file exists
			if (access(path, F_OK) == 0)
				break;
			free(path);
			path = NULL;
			i++;
		}

		if (access(path, F_OK) != 0)
			return perror("access error");

		// Open a file for writing (create if it doesn't exist or truncate if it does)
		// int writefd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		pipexStruct.p2fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);

		if (pipexStruct.p2fd < 0)
			perror("Error in opening file. Terminating now");

		// change from stdin(0)  to listen to fd[0]
		dup2(fd[0], 0);
		// Close the pipe for writing as we not sending any data over
		close(fd[1]);
		// change the output to writefd
		dup2(pipexStruct.p2fd, 1);

		int execveResult;
		//path: "/bin/ls"
		//arg:  ["ls", "-l"]
		execveResult =  execve(path, argvs, envp);
		if (execveResult == -1)
			perror("smth wrong with executing. Terminate now");
		//end of process code
		free(path);
		free(argvs);

}

// void freemem()
// {

// }

//pipex, file1, cmd1, cmd2, file2
int main(int argc, char *argv[], char *envp[])
{
	struct pipeStructure pipexStruct;
	char *path;
	char **paths;

	path = NULL;
	//correct number of parameters
	if (argc != 5)
		return -1;

	int i = 0;
	//Get the string:"PATH="
	while (envp[i])
	{
		if (ft_strncmp("PATH=",envp[i], 5) == 0)
		{
			path = envp[i];
			break;
		}
		i++;
	}

	//Split the path string into various paths
	paths = ft_split(path + 5, ':');
	i = 0;

	// int array for pipe 
	int fd[2]; 
	if(pipe(fd) == -1)
		printf("Error in creating pipe\n");

	pipexStruct.pid1 = fork();
	if (pipexStruct.pid1 == 0)
		P1child(argv, paths, path,envp, pipexStruct, fd);

	pipexStruct.pid2 = fork();
	if (pipexStruct.pid2 == 0)
		P2child(argv, paths, path,envp, pipexStruct, fd);

	//! to do: close both pipes
	close(fd[0]);
	close(fd[1]);

	//The third argument, which is 0 in this case, represents
	// the "options" argument. It specifies various options
	// that control the behavior of the waitpid function. 
	//When you pass 0 as the options, you are indicating that
	// you want the waitpid function to operate in its default
	// blocking mode and wait for a child process to change state.
	waitpid(pipexStruct.pid1, &pipexStruct.pid1status, 0);
	waitpid(pipexStruct.pid2, &pipexStruct.pid2status, 0);

	
	// the 2 if statements are just extra and should be removed 
	// if (WIFEXITED(pipexStruct.pid1status)) {
	//     printf("Child process (PID %d) exited with status %d\n", pipexStruct.pid1, WEXITSTATUS(pipexStruct.pid1status));
	// } else if (WIFSIGNALED(pipexStruct.pid1status)) {
	//     printf("Child process (PID %d) terminated by signal %d\n", pipexStruct.pid1, WTERMSIG(pipexStruct.pid1status));
	// }
	// if (WIFEXITED(pipexStruct.pid2status)) {
	//     printf("Child process (PID %d) exited with status %d\n", pipexStruct.pid2, WEXITSTATUS(pipexStruct.pid2status));
	// } else if (WIFSIGNALED(pipexStruct.pid2status)) {
	//     printf("Child process (PID %d) terminated by signal %d\n", pipexStruct.pid2, WTERMSIG(pipexStruct.pid2status));
	// }
	// to do:free alls the memory
	// freemem();
	return 0;
}

// ./main  infile "grep this" "wc -w" outfile

//compile 
// gcc -o main main.c libftfiles.c

// run
// ./main infile "ls -l" "wc -l" outfile

//0:./main
//1:infile
//2:"ls -l"
//3:"wc -l"
//4:outfile