// temporary put all my libft functions here
#include <stdlib.h>



//ft_strncmp
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (n > i && (str1[i] || str2[i]))
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((*(unsigned char *)(str1 + i)
				- *(unsigned char *)(str2 + i)));
	}
	return (0);
}

//ft_split
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


size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	size_t	i;
	size_t	j;
	char	*str;

	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc ((length + 1) * sizeof(char));
	if (!str)
		return (str);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
