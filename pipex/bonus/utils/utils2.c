/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:25:56 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:25:56 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	heredoccmd(struct s_pipex *pipexstruct)
{
	char	*line;

	if (pipexstruct->heredocwritefd < 0)
	{
		perror("invalid fd. quitting now\n");
		exit(1);
	}
	while (1)
	{
		write(1, "heredoc>", 8);
		line = get_next_line(0);
		if (line == NULL
			|| ((ft_strncmp(line, pipexstruct->delimiter, ft_strlen(
							pipexstruct->delimiter)) == 0) && (ft_strlen(line)
					- linechecker(line)) == ft_strlen(pipexstruct->delimiter)))
			break ;
		write(pipexstruct->heredocwritefd, line, ft_strlen(line));
		write(1, line, ft_strlen(line));
		line = NULL;
	}
	return (0);
}

int	checkforheredoc(char *argv[], struct s_pipex *pipexstruct)
{
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		if (heredoccmd(pipexstruct) == 0)
		{
			pipexstruct->curr = 3 ;
			pipexstruct->opened = 3 ;
			pipexstruct->heredocreadfd = open("heredoctemp.txt", O_RDONLY);
			if (pipexstruct->heredocreadfd == -1)
			{
				perror("heredocreadfd opened with error\n");
				return (1);
			}
		}
		else
		{
			perror("heredoccmd failed. Nothing inside\n");
			return (1);
		}
	}
	return (0);
}

int	p3child(char *envp[], struct s_pipex *pipexstruct)
{
	int		execveresult;

	execveresult = -1;
	pipexstruct->path = findprocesspath(pipexstruct);
	if (access(pipexstruct->path, F_OK) != 0)
		perror("3 Access Path not found");
	if ((pipexstruct->curr != pipexstruct -> opened) || pipexstruct->p1fd >= 0)
		execveresult = execve(pipexstruct->path, pipexstruct->argvs3, envp);
	if (execveresult == -1)
		perror("Execve weent wrong while executing. Terminate now");
	free(pipexstruct->path);
	exit (0);
}
