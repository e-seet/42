/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:09:41 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 16:09:42 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: The string to be split.
// c: The delimiter character.

// The array of new strings resulting from the split.
// NULL if the allocation fails.

#include "libft.h"

int	numofwords(const char *s, char c)
{
	int		count;
	char	*str;

	str = (char *) s;
	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			count = count + 1;
			str++;
		}
		while (*str && *str != c)
			str++;
	}
	return (count);
}

int	wordlen(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	*copycontent(const char *s, char c)
{
	int		i;
	int		len;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	len = wordlen(s, c);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (len > i)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*list_free(char **strs, int i)
{
	while (--i >= 0)
		free(strs[i]);
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		num;
	int		i;
	char	*str;
	char	**strs;

	i = 0;
	str = (char *) s;
	num = numofwords(str, c);
	strs = malloc(sizeof(char *) * (num + 1));
	if (!strs)
		return (0);
	while (num > i)
	{
		while (*str && *str == c)
			str++;
		strs[i] = copycontent(str, c);
		if (!strs[i])
			return (list_free(strs, i));
		str = str + wordlen(str, c);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

/*
int main(void)
{
	// char *str = "Hello,World,How,Are,You";
	// char **strs = ft_split(str, ',');
	// int i = 0;
	// while (strs[i])
	// {
	// 	printf("%s\n", strs[i]);
	// 	i++;
	// }
	
	char **strs =ft_split("hello!",' ');
	int i = 0;
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}

	return (0);
}*/