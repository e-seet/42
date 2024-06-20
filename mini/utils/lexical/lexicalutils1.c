#include "../utils.h"

int	ft_is_output_redirect(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '>')
	{
		return (1);
	}
	return (0);
}

int	ft_is_append_output_redirect(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '>' && str[i + 1] == '>')
	{
		return (1);
	}
	return (0);
}

int	ft_is_input_redirect(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '<')
	{
		return (1);
	}
	return (0);
}

int	ft_is_heredoc_redirect(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '<' && str[i + 1] == '<')
	{
		return (1);
	}
	return (0);
}

int	ft_is_conditional_or(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|' && str[i + 1] == '|')
	{
		return (1);
	}
	return (0);
}
