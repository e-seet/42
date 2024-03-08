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

// void	setstructure(char *argv[], struct s_pipex *pipexstruct)
// {
// 	char	**strs;
// 	int		size;

// 	strs = ft_split(argv[4], '/');
// 	size = ft_strlen(argv[4]);
// 	if (ft_strncmp(strs[0], argv[4], size) != 0)
// 		mkdir(strs[0], 0777);
// 	pipexstruct->p2fd = open(argv[4], O_APPEND | O_CREAT | O_RDWR, 0644);
// 	if (pipexstruct->p2fd < 0)
// 		perror("Error in opening file. Terminating now");
// 	if (ftruncate(pipexstruct->p2fd, 0) == -1)
// 		perror("ftruncate");
// 	pipexstruct->p1fd = open(argv[1], O_RDONLY);
// 	if (pipexstruct->p1fd < 0)
// 		perror("Error in opening file. Terminating now");
// 	pipexstruct->argvs1 = ft_split(argv[2], ' ');
// 	pipexstruct->argvs2 = ft_split(argv[3], ' ');
// }
#include <string.h>
char *ft_newstr(char *str)
{
	int		i;
	int		len;
	int		displace;
	char	*newstr;

	i = 0;
	displace = 3;
	len = ft_strlen(str);
	while (str[displace] == ' ' || str[displace] == '"' || str[displace] == '\'')
	{
		displace ++;
	}
	newstr = (char *)malloc(sizeof(char)*(len-2 - 2*displace));
	newstr[0] = '"';
	while ((len-displace) > i)
	{
		newstr[1+i] = str[displace + i];
		i++;
	}
	if (newstr[i-1] == '"')
	{
		newstr[i] = '"';
		newstr[i] = '\0';
	}
	else
	{
		newstr[i] = '"';
		newstr[i+1] = '\0';
	}
	// printf("new str:%s\n", newstr);
    return newstr;
}

void ft_modify(char *str, struct s_pipex *pipexstruct)
{
	int	i;

	i = 1;
	while (pipexstruct->argvs2[i])
	{
		free(pipexstruct->argvs2[i]);
		pipexstruct->argvs2[i] = NULL;
		i ++;
	}
	pipexstruct->argvs2[1] = (char *) malloc (sizeof(char *));
	pipexstruct->argvs2[1] = ft_newstr(str);
	// printf("string:%s\n", pipexstruct->argvs2[1]);
}

void	setstructure(char *argv[], struct s_pipex *pipexstruct)
{
	pipexstruct->p2fd = open(argv[4], O_APPEND | O_CREAT | O_RDWR, 0644);
	if (pipexstruct->p2fd < 0)
		perror("Error in opening file. Terminating now");
	if (ftruncate(pipexstruct->p2fd, 0) == -1)
		perror("ftruncate");
	pipexstruct->p1fd = open(argv[1], O_RDONLY);
	if (pipexstruct->p1fd < 0)
		perror("Error in opening file. Terminating now");
	pipexstruct->argvs1 = ft_split(argv[2], ' ');
	
	// ./pipex "in_file" "grep Hello" "awk \"{count++} END {print count}\"" outfile
	pipexstruct->argvs2 = ft_split(argv[3], ' ');
	if (ft_strncmp(argv[3], "awk",3) == 0)
		ft_modify(argv[3], pipexstruct);

	//./pipex "in_file" "grep Hello" "awk'{count++} END {print count}'" outfile
	// if (ft_strncmp(argv[3], "awk", 3) == 0)
	// 	pipexstruct->argvs2 = ft_split(argv[3], '"');
	// 	// pipexstruct->argvs2 = ft_split(argv[3], '\'');
	// else
	// 	pipexstruct->argvs2 = ft_split(argv[3], ' ');

}

void	closepipes(struct s_pipex *pipexstruct)
{
	close(pipexstruct->fdpipe[0]);
	close(pipexstruct->fdpipe[1]);
}
