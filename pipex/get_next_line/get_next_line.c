/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:00:06 by eseet             #+#    #+#             */
/*   Updated: 2024/03/19 18:00:06 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Create a remainder string based on the len given.
// Copy the new string content from the start of the len
char	*ft_processstr(char *str, int len)
{
	int		newlen;
	char	*newstr;
	int		j;

	if (len == -1)
		len = ft_strlen2(str);
	j = 0;
	newlen = ft_strlen2(str) - len;
	newstr = malloc(sizeof(char) * (newlen + 1));
	if (!newstr)
		return (NULL);
	while (str[len + j] != '\0')
	{
		newstr[j] = str[len + j];
		j++;
	}
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

//Create a new line based on the len given.
//the line will cut from the front of the string
char	*ft_processline(char *str, char *line, int len)
{
	int		i;

	if (len == -1)
		len = ft_strlen2(str);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (len > i)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

//1. Read fd.
//2. Join copy buffer to str
//3. Find \n in str
//4. if found, break and return str
char	*ft_read_and_join(char *str, int fd, int *bufferi)
{
	char	*buffer;
	int		linelen;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*bufferi = read(fd, buffer, BUFFER_SIZE);
	while (*bufferi > 0)
	{
		str = ft_strjoin2(str, buffer, *bufferi);
		linelen = ft_findline2(str);
		if (linelen != -1)
			break ;
		*bufferi = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (str);
}

//1. create a str if it doesnt exist.
//2. The string is null terminated.
//3. return null if malloc fail
char	*ft_createstr(char *str)
{
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			bufferi;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_createstr(str);
	if (!str)
		return (NULL);
	str = ft_read_and_join(str, fd, &bufferi);
	if (str[0] == '\0' || bufferi == -1)
	{
		free(str);
		str = NULL;
		return (str);
	}
	else if (str[0] != '\0')
	{
		line = ft_processline(str, line, ft_findline2(str));
		str = ft_processstr(str, ft_findline2(str));
		return (line);
	}
	else
		return (NULL);
}

