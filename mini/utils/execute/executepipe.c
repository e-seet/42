#include "../utils.h"

// <job>			::=		<command> '|' <job>
// left node pipe to right node
// the number 1 and 0 signifies whether we need the pipe read and write
void	execute_pipe(struct s_AST_Node **rootnode,
	int async, t_parameters *parameters)
{
	int					fd[2];
	struct s_AST_Node	*jobnode;

	pipe(fd);
	parameters->readpipe = 0;
	parameters->writepipe = 1;
	parameters->piperead = fd[0];
	parameters->pipewrite = fd[1];
	parameters->async = async;
	execute_command(&((*rootnode)->left), parameters);
	jobnode = (*rootnode)->right;
	execute_pipe_job(rootnode, parameters, jobnode, fd);
}

void	execute_pipe_job(struct s_AST_Node **rootnode,
	t_parameters *parameters, struct s_AST_Node *jobnode, int fd[])
{
	while (jobnode != NULL && NODETYPE(jobnode->type) == PIPE)
	{
		close(parameters->pipewrite);
		pipe(fd);
		parameters->pipewrite = fd[1];
		parameters->readpipe = 1;
		parameters->writepipe = 1;
		execute_command(&((*rootnode)->left), parameters);
		close(parameters->piperead);
		parameters->piperead = fd[0];
		jobnode = jobnode -> right;
	}
	parameters->piperead = fd[0];
	close(parameters->pipewrite);
	parameters->readpipe = 1;
	parameters->writepipe = 0;
	execute_command(&((*rootnode)->left), parameters);
	close(parameters->piperead);
}
