/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:00:09 by eseet             #+#    #+#             */
/*   Updated: 2024/03/19 18:00:09 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

int		ft_strlen2(char *str);
char	*ft_strjoin2(char *str, char *buffer, int bufferi);
int		ft_findline2(char *str);

char	*ft_processstr(char *str, int len);
char	*ft_processline(char *str, char *line, int len);
char	*ft_read_and_join(char *str, int fd, int *bufferi);
char	*ft_createstr(char *str);
char	*get_next_line(int fd);

#endif
//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
