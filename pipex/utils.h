/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:25:36 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:25:36 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/wait.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
//for read write, permission with files, creating files
# include <fcntl.h>

// For mkdir. Check if allowed
# include <sys/stat.h>
# include <errno.h>

# include "utils2.h"
# include "pipex_struct.h"

// void	freestuff2(struct s_pipex *pipexstruct);

// char	*ft_newstr(char *str, struct s_pipex *pipexstruct);
void	ft_newstr(char *str, struct s_pipex *pipexstruct, int n);
void	ft_modify(char *str, struct s_pipex *pipexstruct, int n);

void	setstructure(char *argv[], struct s_pipex *pipexstruct, char *path);
void	closepipes(struct s_pipex *pipexstruct);

char	*findprocesspath(char *path,
			struct s_pipex pipexstruct, int processnum);
int		p1child(char *path, char *envp[],
			struct s_pipex pipexstruct);

int		p2child(char *path, char *envp[],
			struct s_pipex pipexstruct);

char	*findpath(char *envp[]);
void	freestuff(struct s_pipex *pipexstruct);

#endif
