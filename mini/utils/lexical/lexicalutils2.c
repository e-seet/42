#include "../utils.h"

int	ft_is_whitespaces(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_is_single_quote(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\'')
	{
		return (1);
	}
	return (0);
}

int	ft_is_double_quote(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '"')
	{
		return (1);
	}
	return (0);
}

int	ft_is_pipe(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|')
	{
		return (1);
	}
	return (0);
}

int	ft_is_dollar(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
	{
		return (1);
	}
	return (0);
}

int	ft_is_semicolon(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ';')
	{
		return (1);
	}
	return (0);
}

int	ft_is_double_ampersand(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '&' && str[i + 1] == '&' )
	{
		return (1);
	}
	return (0);
}

// (
int	ft_is_bracket1(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '(')
	{
		return (1);
	}
	return (0);
}

// )
int	ft_is_bracket2(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ')')
	{
		return (1);
	}
	return (0);
}
