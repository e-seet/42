/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:25:10 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:25:10 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		else
			path = ft_strjoin(path, pipexstruct.argvs2[0]);
		if (access(path, F_OK) == 0)
			break ;
		free (path);
		path = NULL;
		i++;
	}
	if (access(path, F_OK) == 0)
		return (path);
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

int	p1child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	printf("p1 child\n");
	path = findprocesspath(path, paths, pipexstruct, 1);
	printf("path:%s", path);
	if (access(path, F_OK) != 0)
	{
		perror("command not found p1path");
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

// int ft_strncmp2(char *str, char *str2, int n)
// {
// 	int i = 0;
// 	while (n > i)
// 	{
// 		if (str[i] != str2[i])
// 		{
// 			printf("Break!!\n i:%d\n", i);
// 			printf("1:%c\n2:%c", str[i], str2[i]);
// 			break;
// 		}
// 		i++;
// 	}
// 	return str2[i] - str[i];
// }

int	p2child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	path = findprocesspath(path, paths, pipexstruct, 2);
	if (access(path, F_OK) != 0)
	{
		perror("Path not found");
		return (1);
	}
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

	if (argc != 5)
		return (1);
	path = findpath(envp);
	paths = ft_split(path + 5, ':');
	if (pipe(pipexstruct.fdpipe) == -1)
		return (1);
	setstructure(argv, &pipexstruct);
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
	waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0);
	waitpid(pipexstruct.pid2, &pipexstruct.pid2status, 0);
	return (0);
}

/*{ ARGS("grep Hello",
 "awk \"{count++} 
END {print count}\""), DEFAULT_ENV,
"Hello World!\nHello World!\n" },

"awk \"{count++} END {print count}\""
{ ARGS("grep Hello", "awk '\"{count++} END {print count}\"'"), DEFAULT_ENV,
 "Hello World!\nHello World!\n" },
"awk '\"{count++} END {print count}\"'"
{ ARGS("grep Hello", "awk \"'{count++} END {print count}'\""),
 DEFAULT_ENV, "Hello World!\nHello World!\n" }
"awk \"'{count++} END {print count}'\""

./pipex "in_file" "grep Hello" "awk \"{count++} END {print count}\"" outfile
becomes  "{count++} END {print count}"
*/

// NO ISSUES
/*
./pipex "in_file" "grep Hello" "awk \"{count++} END {print count}\"" outfile
./pipex "in_file" "grep Hello" 
"awk '{count++} END {print count}'" outfile
./pipex "in_file" "grep Hello" 
"awk '\"{count++} END {print count}\"'" outfile
./pipex "in_file" "grep Hello" "awk \"'{count++} END {print count}'\"" outfile
*/

//pipex, file1, cmd1, cmd2, file2

//compile 
// gcc -o main main.c libftfiles.c

// run
// ./main infile "ls -l" "wc -l" outfile
// comamnd
// ls -l | wc -l > outfile

// ./main  infile "grep this" "wc -w" outfile

// ./pipex infile "grep file" "wc -l" outfile

//0:./main
//1:infile
//2:"ls -l"
//3:"wc -l"
//4:outfile

// ./main infile "ls -l" "wc -l" outfile
