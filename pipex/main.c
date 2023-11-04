
#include <stdio.h>
#include <unistd.h>
#include "libft.c"

//pipex, file1, cmd1, cmd2, file2
int main(int argc, char *argv[], char *envp[])
{

	char *path;
	char **paths;
	char **argvs;

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

		//testing afterwards

		int fd[2];
		if(pipe(fd) == -1)
		{
			printf("Error in creating pipe\n");
		}

		// int P1 = getppid();
		// int P1 = getpid();
		// int P1C = fork(); // 0 if success. -1 if error

		//create process
		//create child process
		//parent to wait for child  

		//Find env + arg
		//create process 2
		//create child process2
		//close pipe
		//wait for pid
	}
	else
	{
	}
	

}


// ./main  in "grep a1" "wc -w" out
// ./main infile "ls -l" "wc -l" outfile
