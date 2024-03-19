/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:00:14 by eseet             #+#    #+#             */
/*   Updated: 2024/03/19 18:00:14 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin2(char *str, char *buffer, int bufferi)
{
	int		strlen;
	int		i;
	char	*newstr;
	int		j;

	i = 0;
	strlen = ft_strlen2(str);
	newstr = malloc(sizeof(char) * (strlen + bufferi + 1));
	if (!newstr)
		return (NULL);
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	j = 0;
	while (bufferi > j)
	{
		newstr[i + j] = buffer[j];
		j++;
	}
	newstr[i + j] = '\0';
	free(str);
	return (newstr);
}

// Return the index of \n in str. 
// the \n needs to be returned as well.
int	ft_findline2(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0' && str[j] != '\n')
		j++;
	if (str[j] == '\n')
	{
		return (j + 1);
	}
	else
	{
		return (-1);
	}
}
