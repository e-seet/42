#include "../utils.h"

// top layer: job ; command line
void	execute_cmdline(struct s_AST_Node **rootnode,
	t_parameters *parameters, t_mini *mini)
{
	if ((*rootnode) == NULL)
	{
		return ;
	}
	if (nodetype((*rootnode)->type) == NODE_SEQ)
	{
		execute_job(&((*rootnode)->left), 0, parameters, mini);
		if (sigint_received == -1)
			return ;
		execute_cmdline(&((*rootnode)->right), parameters, mini);
	}
	// else if (nodetype(rootnode->type) == NODE_BCKGRND)
	// {
	// 	execute_job(rootnode->left, 1);  // job to be background
	// 	execute_cmdline(rootnode->right);
	// }
	else
		execute_job((rootnode), 0, parameters, mini);
	if (sigint_received == -1)
		return ;
}

int	nodetype(enum e_NodeType type)
{
	return (type & (~NODE_DATA));
}

// check type of node
// int isNodeType(int node, e_NodeType type)
// {
// 	if ((node & type) != 0)
// 		return 1;
// 	else
// 		return 0;
// }

// int checktype(int nodeType)
// {
// 	if (isNodeType(nodeType, NODE_PIPE))
// 	{
// 		printf("Node is a PIPE.\n");
// 		return 1;
//     }
//     else if (isNodeType(nodeType, NODE_BCKGRND)) {
//         printf("Node is a BACKGROUND.\n");
// 		return 1;
//     }
//     else  if (isNodeType(nodeType, NODE_SEQ)) {
//         printf("Node is a SEQ.\n");
// 		return 1;
//     }
//     else  if (isNodeType(nodeType, NODE_REDIRECT_IN)) {
//         printf("Node is a REDIRECT_IN.\n");
// 		return 1;
//     }
//     else  if (isNodeType(nodeType, NODE_REDIRECT_OUT)) {
//         printf("Node is a REDIRECT_OUT.\n");
// 		return 1;
//     }
//     else  if (isNodeType(nodeType, NODE_REDIRECT)) {
//         printf("Node is a REDIRECT (appending).\n");
// 		return 1;
//     }
//     else  if (isNodeType(nodeType, NODE_HEREDOC)) {
//         printf("Node is a HEREDOC.\n");
// 		return -1;
//     }
//     else  if (isNodeType(nodeType, NODE_CMDPATH)) {
//         printf("Node is a CMDPATH.\n");
// 		return 1;
//     }
//     else if (isNodeType(nodeType, NODE_ARGUMENT)) {
//         printf("Node is an ARGUMENT.\n");
// 		return 1;
//     }
//     else if (isNodeType(nodeType, NODE_DATA)) {
//         printf("Node contains DATA.\n");
// 		return 1;
//     }
// 	return 0;
// }

void	free_ast(struct s_AST_Node **rootnode, struct s_AST_Node *original)
{
	if (*rootnode == NULL)
		return ;
	else
	{
		if ((*rootnode)->left != NULL)
			free_ast(&((*rootnode)->left), original);
		else if ((*rootnode)->right != NULL)
			free_ast(&((*rootnode)->right), original);
	}
	if ((*rootnode)->data != NULL)
	{
		if (*rootnode != original)
		{
			free((*rootnode)->data);
			(*rootnode)->data = NULL;
		}
	}
	free(*rootnode);
	*rootnode = NULL;
}

void	execute_syntax_tree(struct s_AST_Node *rootnode,
	t_parameters *parameters, t_mini *mini)
{
	execute_cmdline(&rootnode, parameters, mini);
}
// to free ast here
// printf("before free ast\n");
// printf("free ast no issues\n");