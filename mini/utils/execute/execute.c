#include "../utils.h"

//check if the last character is a \n and subtract accordingly
// go to the position before \0 and check if it is a \n
int	linechecker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '\n')
		return (1);
	else
		return (0);
}



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

int init_command_internal(struct s_AST_Node *rootnode, t_parameters *parameters, char *file_in, char *file_out)
{
	printf("init command structure\n");
	printf("what is the value of nodetype:%d\n", NODETYPE((rootnode)->type));

    if (rootnode == NULL || !(NODETYPE(rootnode->type) == NODE_CMDPATH))
    {
        parameters->argc = 0;
	
		// if (rootnode == NULL)
		// {
		// 	printf("root node is null\n");
		// }
		// else 
		// {
		// 	printf("rootnode type :%d\n", NODETYPE(rootnode->type));
		// }

		printf("return -1 in internal\n");
        return -1;
    }

    struct s_AST_Node *argNode = rootnode;



	int i = 0;
	// original
	// while (argNode != NULL && (NODETYPE(argNode->type) == NODE_ARGUMENT 
	// || NODETYPE(argNode->type) == NODE_CMDPATH)) 
	//mine
    while (argNode != NULL && (!(NODETYPE(argNode->type) == NODE_ARGUMENT) 
	|| !(NODETYPE(argNode->type) == NODE_CMDPATH)))
	{
        argNode = argNode->right;
        i++;
    }


    

	// mine
	if (i == 0)
	{
		printf("i = 0; type:%d \n", argNode->type);
	    parameters->argv = (char**)malloc(sizeof(char*) * (1 + 1));
	}
	else
	    parameters->argv = (char**)malloc(sizeof(char*) * (i + 1));
   
    argNode = rootnode;
    i = 0;


	// while (argNode != NULL && (NODETYPE(argNode->type) == NODE_ARGUMENT 
	// 	|| NODETYPE(argNode->type) == NODE_CMDPATH))
		// mine
    while
	(
		argNode != NULL 
		&& (NODETYPE(argNode->type) == NODE_ARGUMENT ||
			NODETYPE(argNode->type) == NODE_CMDPATH)
	)
	{
        parameters->argv[i] = (char*)malloc(ft_strlen(argNode->data) + 1);
		// modified
        ft_strlcpy(parameters->argv[i], argNode->data, ft_strlen(argNode->data)+1);

        argNode = argNode->right;
        i++;
    }



	if (i != 0)
	{
		parameters->argc = i;
		parameters->argv[i] = NULL;
		parameters->file_in = file_in;
		parameters->file_out = file_out;
	}
	else
	{
		printf("i is 0. %d\n",  (NODETYPE(argNode->type)));



		parameters->argv[0] = (char*)malloc(ft_strlen(argNode->data) + 1);
        ft_strlcpy(parameters->argv[0], argNode->data, ft_strlen(argNode->data)+1);
		parameters->argc = i;
		parameters->argv[i] = NULL;
		parameters->file_in = file_in;
		parameters->file_out = file_out;
	}
	// if (i == 0 && (NODETYPE(argNode->type) == NODE_CMDPATH))
	// {
	// 	printf("i = 0; type:%d \n", argNode->type); // cmdpath

	// 	i = 1;
	// 	parameters->argv[0] = (char*)malloc(ft_strlen(argNode->data) + 1);
    //     ft_strlcpy(parameters->argv[0], argNode->data, ft_strlen(argNode->data)+1);
	// 	parameters->argc = i;
	// 	parameters->argv[i] = NULL;
	// 	parameters->file_in = file_in;
	// 	parameters->file_out = file_out;

	// }

	// printf("init command number:%d\n", i);
	return 0;
}

void free_parameters(t_parameters *parameters)
{
	int i;

	i = 0;
	
	while (parameters->argc > i)
	{
		// printf("i loop:%d\n", i);
		free(parameters->argv[i]);
		i++;
	}
	// printf("free the var\n");
	free(parameters->argv);
    parameters->argc = 0;

	// printf("to free file in and out\n");
	if (parameters->file_in)
	{
		free(parameters->file_in);
	}
	
	if (parameters->file_out)
	{
		free(parameters->file_out);
	}
}

void execute_simple_command(struct s_AST_Node* rootnode,
							t_parameters *parameters,
                             char *redirect_in,
                             char *redirect_out
                            )
{
	int	errors;

    errors = init_command_internal(rootnode, parameters, redirect_in, redirect_out);
	if (errors == 0)
	{
		execution2(parameters);
	}

	free_parameters(parameters);
}



// 5 cases
void	execute_command(struct s_AST_Node **rootnode, t_parameters *parameters)
{
	   if ((*rootnode) == NULL)
	   {
			printf("root node is null");
			return;
	   }


	// << 
	if (NODETYPE((*rootnode)->type) == NODE_HEREDOC)
	{
		printf("heredoc\n");
		parameters->append = 1;
		
		execute_simple_command(((*rootnode)->right),
							parameters,
							(*rootnode)->data, NULL
							);
	}
	// <
    else if (NODETYPE((*rootnode)->type) == NODE_REDIRECT_IN)
    {
		printf("run <\n");
		parameters->append = 0;
		execute_simple_command(((*rootnode)->right),
							parameters,
							(*rootnode)->data, NULL
							);
	}

	// >>
    else if (NODETYPE((*rootnode)->type) == NODE_REDIRECT)
	{
		printf("run >>\n");
		parameters->append = 1;
		execute_simple_command(((*rootnode)->right),
								parameters,
								NULL, (*rootnode)->data
								);
	}

	// >
    else if (NODETYPE((*rootnode)->type) == NODE_REDIRECT_OUT)
	{

		printf("run >\n");
		parameters->append = 0;
		execute_simple_command(((*rootnode)->right),
							parameters,
							NULL, (*rootnode)->data
							);
	}
	else
	{
			parameters->append = 0;
			printf("else");
			execute_simple_command((*rootnode),
								parameters,
								NULL, NULL
								);

    }
}



// <job>			::=		<command> '|' <job>

// left node pipe to right node
// the number 1 and 0 signifies whether we need the pipe read and write
void	execute_pipe(struct s_AST_Node **rootnode, int async, t_parameters *parameters)
{
	int 			fd[2];
	struct s_AST_Node *jobnode;

	pipe(fd);
	parameters->readpipe = 0;
	parameters->writepipe = 1;
	parameters->piperead = fd[0];
	parameters->pipewrite = fd[1];
	parameters->async = async;

	// command
	// read from pipe is false, write to pipe is true.
	execute_command( &((*rootnode)->left), parameters);
	jobnode = (*rootnode)->right;

	while (jobnode !=  NULL && NODETYPE(jobnode->type) == PIPE)
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

	close(parameters->pipewrite); // close the write end
	
	// need to read but not write
	parameters->readpipe = 1;
	parameters->writepipe = 0;
	execute_command( &( (*rootnode)->left), parameters);
	close(parameters->piperead);
}















// <job>			::=		<command> '|' <job>
// 						|	<command>
// No need of pipes so all 4 parameters are 0
void	execute_job(struct s_AST_Node **rootnode, int async, t_parameters *parameters)
{
	// printf("ejob\n");
	// printf("the value :%d\n", (*rootnode)->type);
	// printf("the data :%s\n", (*rootnode)->data);
	// printf("the data :%c\n", NODETYPE((*rootnode)->type));


	if ((*rootnode) == NULL)
		return ;


	if (NODETYPE((*rootnode)->type) == NODE_PIPE)
	{
		execute_pipe((rootnode), async, parameters);
	}
	else if  (NODETYPE((*rootnode)->type) == NODE_HEREDOC)
	{
		char	*input;
		int heredocwritefd;

		heredocwritefd = open("heredoctemp.txt", O_TRUNC | O_CREAT| O_RDWR, 0644);
		while (1)
		{
			input = readline(">>:");
			if (input == NULL)
			{
				printf("Ctrl + D pressed outside heredoc\n");
				break;
			}

			if (input[0] != '\0' || input != NULL)
			{
				// To break
				if (((strncmp(input, (*rootnode)->data, strlen(
									(*rootnode)->data)) == 0) && (strlen(input)
							- linechecker(input)) == strlen((*rootnode)->data)))
					{
						break ;
					}

					write(heredocwritefd, input, ft_strlen(input));
					// if u want to write out
					// write(1,  input, ft_strlen(input));
					free(input);
					input = NULL;
					add_history(input);
			}
			free(input);
		}
		if (input != NULL)
			free(input);


		char *filein = ft_calloc(16, sizeof(char));
		ft_strlcpy(filein, "heredoctemp.txt", ft_strlen("heredoctemp.txt")+1);

		printf("what is the value of nodetype here for heredoc (rootnode):%d\n", NODETYPE((*rootnode)->type));

		struct s_AST_Node *nextnode = (*rootnode) -> right;
		printf("curr node:%s\n", (*rootnode)->data);
		nodesetdata(*rootnode, filein);
		printf("curr node updated:%s\n", (*rootnode)->data);
		
		printf("next node:%s\n", (nextnode)->data);
		printf("what is the value of nodetype here for nextnode:%d\n\n", NODETYPE((nextnode)->type));



		// reset it to the same type of node as file in
		// since it is pretty muc hthe same
		// nodesettype(*rootnode, NODE_REDIRECT_IN);

		// true / false
		parameters->readpipe = 0;
		parameters->writepipe = 0;

		// the fd
		parameters->piperead = 0;
		parameters->pipewrite = 0;
		parameters->async = async;
		printf("\n\n\n");
		// printf("what is the value of nodetype here for heredoc:%d\n", NODETYPE((*rootnode)->type));
		execute_command(rootnode, parameters);
	}
	else 
	{

		parameters->readpipe = 0;
		parameters->writepipe = 0;
		parameters->piperead = 0;
		parameters->pipewrite = 0;
		parameters->async = async;
		execute_command(rootnode, parameters);
	}
}

// top layer: job ; command line
void	execute_cmdline(struct s_AST_Node **rootnode, t_parameters *parameters)
{

	// printf("execute syntax tree\n");

	if ((*rootnode) == NULL)
	{
		printf("root node is null ?? wtf");
		return ;
	}
	if (NODETYPE((*rootnode)->type) == NODE_SEQ)
	{
		execute_job( &((*rootnode)->left), 0, parameters); // looking into this
		execute_cmdline(&((*rootnode)->right), parameters);
	}
	// else if (NODETYPE(rootnode->type) == NODE_BCKGRND)
	// {
	// 	execute_job(rootnode->left, 1);  // job to be background
	// 	execute_cmdline(rootnode->right);
	// }
	else
	{

		// this is what is getting executed
		execute_job((rootnode), 0, parameters);
	}
}




void	execute_syntax_tree(struct s_AST_Node *rootnode)
{
	t_parameters parameters;

	// struct s_AST_Node *testnode;
	// testnode = rootnode;
	// while (testnode)
	// {
	// 	printf("rootnode")

	// 	testnode = testnode-> 
	// }



	execute_cmdline(&rootnode, &parameters);
	
	//free ast here
	// printf("before free ast\n");
	// printf("free ast no issues\n");
}
