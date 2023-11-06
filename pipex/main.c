// To do: find out what happen if file is missing. To test
//note stdin0 stdout1 stderr2	
// fd[0] read, fd[1] write
#include "libftfiles.h"

#include <sys/wait.h>

//do stuff to p1 child.
// P1 is the read process
void P1child(char *argv[], char *paths[], char *path, char *envp[], struct pipeStructure pipexStruct, int fd[])
{
		int i;
		char **argvs;

		argvs = ft_split(argv[2], ' ');
		i = 0;
		//argvs[0] is the command. Eg "ls"
		// while(argvs[i])
		// {
		// 	printf("%s\n", argvs[i]);
		// 	i++;
		// }
		
		//re-assiging the path pointer
		i = 0;
		//loop through the paths and check whether it is valid
		while (paths[i])
		{
			
			path = ft_strjoin(paths[i], "/");
			path = ft_strjoin(path, argvs[0]);
			//check file exists
			if (access(path, F_OK) == 0)
			{
				break;
			}
			i++;
		}

		int readfd = open(argv[1], O_RDONLY);

		dup2(fd[1], 1);
		close(fd[0]); //close pipe for reading
		dup2(readfd, 0);

		//path: "/bin/ls"
		//arg:  ["ls", "-l"]
		int execveResult;
		printf("execve of p1child");
		execveResult =  execve(path, argvs, envp);
		
		if (execveResult == -1)
		{
			perror("smth wrong with executing. Terminate now");
		}
		else
		{
			printf("end of p1child");
		}
		//end of process code
}

//do stuff to p2 child

void P2child(char *argv[], char *paths[], char *path, char *envp[], struct pipeStructure pipexStruct, int fd[])
{
		int i;
		char **argvs;

		argvs = ft_split(argv[2], ' ');
		i = 0;
		//argvs[0] is the command. Eg "ls"
		// while(argvs[i])
		// {
		// 	printf("%s\n", argvs[i]);
		// 	i++;
		// }
		
		//re-assiging the path pointer
		i = 0;
		//loop through the paths and check whether it is valid
		while (paths[i])
		{
			
			path = ft_strjoin(paths[i], "/");
			path = ft_strjoin(path, argvs[0]);
			//check file exists
			if (access(path, F_OK) == 0)
			{
				break;
			}
			i++;
		}


		//!! settle the fd
		// Open a file for writing (create if it doesn't exist or truncate if it does)
		int writefd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);

		
		dup2(fd[0], 0);
		close(fd[1]); //close pipe for reading
		dup2(writefd, 1);

		//path: "/bin/ls"
		//arg:  ["ls", "-l"]
		int execveResult;
		execveResult =  execve(path, argvs, envp);
		printf("end of p2child");
		
		if (execveResult == -1)
		{
			perror("smth wrong with executing. Terminate now");
		}
		//end of process code
		else
		{
			printf("end of p2child");
		}
}


//pipex, file1, cmd1, cmd2, file2
int main(int argc, char *argv[], char *envp[])
{
	struct pipeStructure pipexStruct;
	char *path;
	char **paths;
	// char **argvs;

	//correct number of parameters
	if (argc == 5)
	{
		//Find env + arg
		int i = 0;
		//Get the path string
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
		// while(paths[i])
		// {
		// 	printf("%s\n", paths[i]);
		// 	i++;
		// }
		// printf("\n");


		//creating the pipe
		//fd[0] - read
		//fd[1] - write	
		int fd[2];
		if(pipe(fd) == -1)
		{
			printf("Error in creating pipe\n");
		}

		pipexStruct.pid1 = fork();
		if (pipexStruct.pid1 == 0)
			P1child(argv, paths, path,envp, pipexStruct, fd);

		pipexStruct.pid2 = fork();
		if (pipexStruct.pid2 == 0)
			P2child(argv, paths, path,envp, pipexStruct, fd);

		//The third argument, which is 0 in this case, represents
		// the "options" argument. It specifies various options
		// that control the behavior of the waitpid function. 
		//When you pass 0 as the options, you are indicating that
		// you want the waitpid function to operate in its default
		// blocking mode and wait for a child process to change state.
		waitpid(pipexStruct.pid1, &pipexStruct.pid1status, 0);
		waitpid(pipexStruct.pid2, &pipexStruct.pid2status, 0);


    if (WIFEXITED(pipexStruct.pid1status)) {
            printf("Child process (PID %d) exited with status %d\n", pipexStruct.pid1, WEXITSTATUS(pipexStruct.pid1status));
        } else if (WIFSIGNALED(pipexStruct.pid1status)) {
            printf("Child process (PID %d) terminated by signal %d\n", pipexStruct.pid1, WTERMSIG(pipexStruct.pid1status));
        }
		

		if (WIFEXITED(pipexStruct.pid2status)) {
            printf("Child process (PID %d) exited with status %d\n", pipexStruct.pid2, WEXITSTATUS(pipexStruct.pid2status));
        } else if (WIFSIGNALED(pipexStruct.pid2status)) {
            printf("Child process (PID %d) terminated by signal %d\n", pipexStruct.pid2, WTERMSIG(pipexStruct.pid2status));
        }
		// close both pipes
		// wait pid
		// free all the memory

		/*
		//!process orientated
		//close the pipe id and all

		argvs = ft_split(argv[2], ' ');
		i = 0;
		//argvs[0] is the command. Eg "ls"
		while(argvs[i])
		{
			printf("%s\n", argvs[i]);
			i++;
		}
		
		//re-assiging the path pointer
		i = 0;
		//loop through the paths and check whether it is valid
		while (paths[i])
		{
			
			path = ft_strjoin(paths[i], "/");
			path = ft_strjoin(path, argvs[0]);
			//check file exists
			if (access(path, F_OK) == 0)
			{
				break;
			}
			i++;
		}

		//path: "/bin/ls"
		//arg:  ["ls", "-l"]
		int execveResult;
		execveResult =  execve(path, argvs, envp);
		if (execveResult == -1)
		{
			perror("smth wrong with executing. Terminate now");
			return 0;
		}
		//end of process code
		*/

		// int P1 = getppid();
		// int P1 = getpid();

		//forking the process
		// int P1C = fork(); // 0 if success. -1 if error


	}
	else
	{
		return -1;
	}
	

}


// ./main  in "grep a1" "wc -w" out

//compile 
// gcc -o main main.c libftfiles.c

// run
// ./main infile "ls -l" "wc -l" outfile

//0:./main
//1:infile
//2:"ls -l"
//3:"wc -l"
//4:outfile