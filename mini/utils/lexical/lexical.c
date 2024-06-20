#include "../utils.h"

// struct node {
// 	char		*data;
// 	int			type;
// 	struct node	*next;
// };
typedef struct node s_node;

// enum Token{
// 	PIPE = '|',
// 	GREATER = '>',
// 	LESSER = '<',
// 	SEMICOLON = ';',
// 	//unique code for 1001: >> and 1002: <<
// 	REDIR = 1001,
// 	HEREDOC = 1002,
// 	// CHAR_NULL = 0,
// 	TOKEN	= -1
// };

int returnint(char *str, int i)
{
	if (ft_is_append_output_redirect(&str[i]) == 1)
		return REDIR;
	else if (ft_is_heredoc_redirect(&str[i]) == 1)
		return HEREDOC;
	else if (ft_is_output_redirect(&str[i]) == 1)
		return GREATER;
	else if(ft_is_input_redirect(&str[i]) == 1)
		return LESSER;
	else if(ft_is_pipe(&str[i]) == 1)
		return	PIPE;
	else
		return TOKEN;
}

void	create_node(s_node **node, char *str, int i, int strlen)
{
	s_node	*newnode;
	int		start;

	start = 0;
	(*node)->data = ft_calloc(strlen + 1, sizeof(char));
	(*node)->data[strlen + 1] = '\0';


	i = i - strlen;
	
	if
	(
		(ft_is_append_output_redirect(&str[i]) == 1)
		|| (ft_is_heredoc_redirect(&str[i]) == 1)
		|| (ft_is_output_redirect(&str[i]) == 1)
		|| (ft_is_input_redirect(&str[i]) == 1)
		|| (ft_is_pipe(&str[i]) == 1)
	)
	{
		(*node)->type = returnint(str, i);
	}
	else
	{
		(*node)->type = TOKEN;
	}


	while (strlen > start)
	{
		(*node)->data[start] = str[(i) + start];
		start ++;
	}
	
	// printf("the node string: %s\n", (*node)->data);
	// printf("the node type: %d\n", (*node)->type);
	
	
	newnode = malloc(sizeof(s_node));
	newnode -> next = NULL;

	
	(*node)->next = newnode;
	(*node) = (*node)->next;
}



// (cd .. && pwd) && pwd >> file

// Check for sepeartor, if found. Add to list.
// > : ft_is_output_redirect
// <  :ft_is_input_redirect
// >> : ft_is_append_output_redirect
// << ft_is_heredoc_redirect
// || ft_is_conditional_or
// | ft_is_pipe
// && ft_is_double_ampersand
// ( ft_is_bracket1
// ) ft_is_bracket2

// ^ type: token
// ^ type: Char INT

s_node	*ft_breakup_str(char *str)
{
	int		i;
	int		counter;
	s_node	*node;
	s_node	*head;

	i = 0;
	counter = 0;
	head = malloc(sizeof(s_node));
	head->next = NULL;
	node = head;
	while (str[i] != '\0')
	{
		// >> or << 
		if
		(
			(ft_is_append_output_redirect(&str[i]) == 1)
			|| (ft_is_heredoc_redirect(&str[i]) == 1)
			// || (ft_is_conditional_or(&str[i]) == 1)
			// || (ft_is_double_ampersand(&str[i]) == 1)
		)
		{
			if (counter > 0)
			{
				create_node(&node, str, i, counter);
				create_node(&node, str, i + 2, 2);
				counter = 0;
			}
			else
			{
				create_node(&node, str, i + 2, 2);
				// ^ type: Char INT
			}
			i = i + 2;
		}
		// > or < or |
		else if (
			(ft_is_output_redirect(&str[i]) == 1)
			|| (ft_is_input_redirect(&str[i]) == 1)
			|| (ft_is_pipe(&str[i]) == 1)

			// || (ft_is_bracket1(&str[i]) == 1)
			// || (ft_is_bracket2(&str[i]) == 1)
			// || (ft_is_double_ampersand(&str[i]) == 1)
		)
		{
			if (counter > 0)
			{
				// no issues encountereed here
				create_node(&node, str, i, counter);
				// ^ type: Char INT

				create_node(&node, str, i + 1, 1);
				// ^ type: Char INT
				counter = 0;
			}
			else
			{
				create_node(&node, str, i+1, 1);
				// ^ type: Char INT
			}
			i ++;
		}
		else if (ft_is_whitespaces(&str[i]) == 1)
		{
			if (counter > 0)
			{
				// no issues encountereed here
				create_node(&node, str, i, counter);
				// ^ type: Char INT
				counter = 0;
			}
			i ++;

		}
		else
		{
			i++;
			counter ++;
		}
	}
	if (counter > 0)
	{
		create_node(&node, str, i, counter);
		// type: token
	}
return (head);

}


void	ft_strip_quote(char *str, char *dest)
{
	char	c;
	int		j;
	int		n;
	int		i;
	char	lastquote;

	n = ft_strlen(str);
	if (n <= 1)
	{
		ft_strlcpy(dest, str, n);
		return ;
	}
	lastquote = 0;
	j = 0;
	i = 0;
	while (n > i)
	{
		c = str[i];
		if ((c == '\'' || c == '\"') && lastquote == 0)
			lastquote = c;
		else if (c == lastquote)
			lastquote = 0;
		else
			dest[j++] = c;
		i++;
	}
	dest[j] = '\0';
}

s_node	*lexical(char *str)
{
	s_node	*node;

	node = ft_breakup_str(str);
	// printf("finish breakup str\n");

	// s_node	*token;
	// token = node;

	// char	*string;
	// while (token != NULL)
	// {
	// 	if (token->type == TOKEN)
	// 	{
	// 		string = malloc(ft_strlen(token->data) + 1);
	// 		ft_strip_quote(token->data, string);
	// 		free(token->data);
	// 		token->data = string;
	// 	}
	// }
	// printf("%p", node);

	
	
	return node;
}
