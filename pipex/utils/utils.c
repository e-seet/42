/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:25:34 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:25:34 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_newstr(char *str, struct s_pipex *pipexstruct, int n)
{
	int		i;
	int		len;
	int		displace;
	char	*newstr;

	i = 0;
	displace = 3;
	len = ft_strlen(str);
	while (str[displace] == ' ' || str[displace] == '"'
		|| str[displace] == '\'')
		displace++;
	newstr = (char *)malloc(sizeof(char) * (len - 2 - 2 * displace));
	while ((len - displace) > i)
	{
		newstr[i] = str[displace + i];
		i++;
	}
	if (newstr[i - 1] == '"' || newstr[i - 1] == '\'')
		newstr[i - 1] = '\0';
	else
		newstr[i] = '\0';
	if (n == 2)
		pipexstruct->argvs2[1] = newstr;
	else
		pipexstruct->argvs1[1] = newstr;
}

void	ft_modify(char *str, struct s_pipex *pipexstruct, int n)
{
	int	x;

	x = 1;
	if (n == 2)
	{
		while (pipexstruct->argvs2[x])
		{
			free(pipexstruct->argvs2[x]);
			pipexstruct->argvs2[x] = NULL;
			x ++;
		}
		ft_newstr(str, pipexstruct, n);
	}
	else
	{
		while (pipexstruct->argvs1[x])
		{
			free(pipexstruct->argvs1[x]);
			pipexstruct->argvs1[x] = NULL;
			x ++;
		}
		ft_newstr(str, pipexstruct, n);
	}
}

void	setstructure(char *argv[], struct s_pipex *pipexstruct, char *path)
{
	pipexstruct->err = 0;
	pipexstruct->p2fd = open(argv[4], O_APPEND | O_CREAT | O_RDWR, 0644);
	if (pipexstruct->p2fd < 0)
		pipexstruct->err = 1;
	if (ftruncate(pipexstruct->p2fd, 0) == -1)
		pipexstruct->err = 1;
	pipexstruct->paths = ft_split(path + 5, ':');
	path = NULL;
	pipexstruct->p1fd = open(argv[1], O_RDONLY);
	if (pipexstruct->p1fd < 0)
	{
		perror("Error in opening file. Terminating now");
		pipexstruct->err = 1;
	}
	pipexstruct->argvs1 = ft_split(argv[2], ' ');
	pipexstruct->argvs2 = ft_split(argv[3], ' ');
}

void	closepipes(struct s_pipex *pipexstruct)
{
	close(pipexstruct->fdpipe[0]);
	close(pipexstruct->fdpipe[1]);
}

void	freestuff(struct s_pipex *pipexstruct)
{
	int	i;

	i = 0;
	if (pipexstruct->err == 1)
		perror("Something went wrong! Terminating now");
	while (pipexstruct->paths && pipexstruct->paths[i])
	{
		free(pipexstruct->paths[i]);
		pipexstruct->paths[i] = NULL;
		i++;
	}
	free(pipexstruct->paths);
	pipexstruct->paths = NULL;
	freestuff2(pipexstruct);
}
