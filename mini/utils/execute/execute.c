#include "../utils.h"

// int execution(t_parameters *parameters)
// {
// 	if (parameters->argc < 0)
// 	{
// 		return -1;
// 	}

// 	//execution
// 	// fork
// 	// pipe
// 	int	pid;

// 	pid = fork();

// 	// child process
// 	if (pid == 0)
// 	{

// 		// input

// 		// stdin
// 		// file input
// 		// pipe read
// 		// if (path == NULL)
// 		// {
// 		// 	perror("Path not found");
// 		// 	return (1);
// 		// }

// 		// dup2(pipexstruct.fdpipe[1], 1);
// 		// close(pipexstruct.fdpipe[0]);

// 		// dup2(pipexstruct.p1fd, 0);

// 		// execveresult = execve(path, pipexstruct.argvs1, envp);
// 		// if (execveresult == -1)
// 		// 	perror("Execve failed in P1child. Terminating Now");
// 		// free(path);
// 	}

// 	return 0;
// }

// top layer: job ; command line
void	execute_cmdline(struct s_AST_Node **rootnode, t_parameters *parameters)
{
	if ((*rootnode) == NULL)
	{
		printf("root node is null ?? wtf");
		return ;
	}
	if (NODETYPE((*rootnode)->type) == NODE_SEQ)
	{
		execute_job(&((*rootnode)->left), 0, parameters);
		execute_cmdline(&((*rootnode)->right), parameters);
	}
	// else if (NODETYPE(rootnode->type) == NODE_BCKGRND)
	// {
	// 	execute_job(rootnode->left, 1);  // job to be background
	// 	execute_cmdline(rootnode->right);
	// }
	else
		execute_job((rootnode), 0, parameters);
}

void	execute_syntax_tree(struct s_AST_Node *rootnode)
{
	t_parameters	parameters;

	execute_cmdline(&rootnode, &parameters);
}
// to free ast here
// printf("before free ast\n");
// printf("free ast no issues\n");