#include "../utils.h"

void	free_parameters(t_parameters *parameters)
{
	int	i;

	i = 0;
	while (parameters->argc > i)
	{
		free(parameters->argv[i]);
		i++;
	}
	free(parameters->argv);
	parameters->argc = 0;
	if (parameters->file_in)
	{
		free(parameters->file_in);
	}
	if (parameters->file_out)
	{
		free(parameters->file_out);
	}
}

void	execute_simple_command(struct s_AST_Node *rootnode,
							t_parameters *parameters,
							char	*redirect_in,
							char	*redirect_out
							)
{
	int	errors;

	errors = init_command_internal(rootnode, parameters,
			redirect_in, redirect_out);
	if (errors == 0)
	{
		execution2(parameters);
	}
	free_parameters(parameters);
}

void	execute_command2(struct s_AST_Node **rootnode, t_parameters *parameters)
{
	if (NODETYPE((*rootnode)->type) == NODE_REDIRECT)
	{
		parameters->append = 1;
		execute_simple_command(((*rootnode)->right),
			parameters, NULL, (*rootnode)->data);
	}
	else if (NODETYPE((*rootnode)->type) == NODE_REDIRECT_OUT)
	{
		parameters->append = 0;
		execute_simple_command(((*rootnode)->right),
			parameters, NULL, (*rootnode)->data);
	}
	else
	{
		parameters->append = 0;
		execute_simple_command((*rootnode), parameters, NULL, NULL);
	}
}

// 5 main cases
void	execute_command(struct s_AST_Node **rootnode, t_parameters *parameters)
{
	if ((*rootnode) == NULL)
	{
		printf("root node is null");
		return ;
	}
	if (NODETYPE((*rootnode)->type) == NODE_HEREDOC)
	{
		parameters->append = 1;
		execute_simple_command(((*rootnode)->right),
			parameters, (*rootnode)->data, NULL);
	}
	else if (NODETYPE((*rootnode)->type) == NODE_REDIRECT_IN)
	{
		parameters->append = 0;
		execute_simple_command(((*rootnode)->right),
			parameters, (*rootnode)->data, NULL);
	}
	else
	{
		execute_command2(rootnode, parameters);
	}
}
