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

#include "utils/utils.h"

char	*findprocesspath(char *path,
struct s_pipex pipexstruct, int processnum)
{
	int	i;

	i = 0;
	while (pipexstruct.paths[i])
	{
		path = ft_strjoin(pipexstruct.paths[i], "/");
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

int	p1child( char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	path = findprocesspath(path, pipexstruct, 1);
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

int	p2child(char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	path = findprocesspath(path, pipexstruct, 2);
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

	if (argc != 5)
		return (1);
	path = findpath(envp);
	if (pipe(pipexstruct.fdpipe) == -1)
		return (1);
	setstructure(argv, &pipexstruct, path);
	if (pipexstruct.pid1 != 0)
		wait(NULL);
	pipexstruct.pid1 = fork();
	if (pipexstruct.pid1 == 0)
		if (p1child(path, envp, pipexstruct) == 1)
			exit(1);
	pipexstruct.pid2 = fork();
	if (pipexstruct.pid2 == 0)
		if (p2child(path, envp, pipexstruct) == 1)
			exit(1);
	closepipes(&pipexstruct);
	waitpid(pipexstruct.pid1, &pipexstruct.pid1status, 0);
	waitpid(pipexstruct.pid2, &pipexstruct.pid2status, 0);
	freestuff(&pipexstruct);
	return (0);
}
