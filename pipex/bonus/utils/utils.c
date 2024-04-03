/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:25:49 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:25:49 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	setstructurefd(struct s_pipex *pipexstruct, char *argv[])
{
	if (pipexstruct->p2fd < 0)
		pipexstruct->err = 1;
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		pipexstruct->delimiter = argv[2];
		pipexstruct->heredocwritefd = open("heredoctemp.txt", O_TRUNC | O_CREAT
				| O_RDWR, 0644);
		if (pipexstruct->heredocwritefd == -1)
			pipexstruct->err = 1;
		pipexstruct->p1fd = open("heredoctemp.txt", O_RDONLY);
		if (pipexstruct->p1fd < 0)
			pipexstruct->err = 1;
	}
	else
	{
		pipexstruct->p1fd = open(argv[1], O_RDONLY);
		if (pipexstruct->p1fd < 0)
			pipexstruct->err = 1;
		if (ftruncate(pipexstruct->p2fd, 0) == -1)
			pipexstruct->err = 1;
	}
}

void	setstructure(int argc, char *argv[], struct s_pipex *pipexstruct,
	char *envp[])
{
	pipexstruct->path = findpath(envp);
	pipexstruct->paths = ft_split(pipexstruct->path + 5, ':');
	pipexstruct->curr = 2;
	pipexstruct->opened = 2;
	pipexstruct->argc = argc;
	pipexstruct->err = 0;
	pipexstruct->p2fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	setstructurefd(pipexstruct, argv);
}

//check if the last character is a \n and subtract accordingly
// go to the position before \0 and check if it is a \n
int	linechecker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '\n')
		return (1);
	else
		return (0);
}

char	*findprocesspath(struct s_pipex *pipexstruct)
{
	int		i;
	char	*path;

	i = 0;
	while (pipexstruct->paths[i])
	{
		path = ft_strjoin(pipexstruct->paths[i], "/");
		pipexstruct->path = ft_strjoin(path,
				pipexstruct->argvs3[0]);
		free(path);
		if (access(pipexstruct->path, F_OK) == 0)
			break ;
		free (pipexstruct->path);
		pipexstruct->path = NULL;
		i++;
	}
	if (pipexstruct->path != NULL && access(pipexstruct->path, F_OK) == 0)
		return (pipexstruct->path);
	else
		return (NULL);
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
