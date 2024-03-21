/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:26:09 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:26:10 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//for read write, permission with files, creating files
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

struct s_pipex {
	int		p1fd;
	int		p2fd;

	int		pid3;
	char	**argvs3;
	int		fdpipe0[2];
	int		fdpipe1[2];
	int		fdpipe2[2];
	int		opened;
	int		curr;
	int		argc;
	char	*delimiter;
	int		heredocwritefd;
	int		heredocreadfd;
	char	*path;
	char	**paths;
};

void	setstructure(int argc, char *argv[], struct s_pipex *pipexstruct,
			char *envp[]);

int		linechecker(char *str);

char	*findprocesspath(struct s_pipex *pipexstruct);

char	*findpath(char *envp[]);

int		heredoccmd(struct s_pipex *pipexstruct);

int		checkforheredoc(char *argv[], struct s_pipex *pipexstruct);

int		p3child(char *envp[], struct s_pipex *pipexstruct);

#endif
// opened = 0. Haven't opened
// opened = 1. Opened
