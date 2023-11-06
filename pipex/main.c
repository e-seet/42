// To do: find out what happen if file is missing. To test
//


//note stdin0 stdout1 stderr2
// fd[0] read, fd[1] write
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.c"

struct pipeStructure {
    int pid1;
	int p1fd;
    int pid2;
	int p2fd;
};

//do stuff to p1 child.
// P1 is the read process
int P1child(char *argv[], char *paths[], char *path, char envp[], struct pipeStructure pipexStruct, int fd[])
{
		int i;
		char **argvs;

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

		//!! settle the fd
		// 1, we need to block write. 
		// 2. Just read

		int readfd = open(argv[1], O_RDONLY);
		close(fd[1]); //close pipe for reading
		
		//use a instead of b
		dup2(fd[0], 0);
		dup2(fd[1], 1);

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
}

//do stuff to p2 child
int p2child(char *argv[], char *paths[], char *path, char envp[], struct pipeStructure pipexStruct)
{
		int i;
		char **argvs;

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


		//!! settle the fd

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
		while(paths[i])
		{
			printf("%s\n", paths[i]);
			i++;
		}
		printf("\n");


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
// ./main infile "ls -l" "wc -l" outfile
