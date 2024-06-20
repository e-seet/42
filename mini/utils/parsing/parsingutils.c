#include "../utils.h"

// void	free_ast(struct s_AST_Node *rootnode)
// {
// 	if (rootnode == NULL)
// 		return ;
// 	if (rootnode->type & NODE_DATA)
// 		free(rootnode->data);
// 	free_ast(rootnode->left);
// 	free_ast(rootnode->right);
// 	free(rootnode);
// 	rootnode = NULL;
// }

void	attachbinarybranch(struct s_AST_Node *root,
	struct s_AST_Node *leftnode, struct s_AST_Node *rightnode)
{
	if (root != NULL)
	{
		root->left = leftnode;
		root->right = rightnode;
	}
}

void	nodesettype(struct s_AST_Node *node, e_NodeType nodetype)
{
	if (node != NULL)
		node->type = nodetype;
}

void	nodesetdata(struct s_AST_Node *node, char *data)
{
	if (node != NULL)
	{
		if (data != NULL)
		{
			node->data = data;
			node->type |= NODE_DATA;
		}
	}
}

void	nodedelete(struct s_AST_Node *node)
{
	if (node == NULL)
		return ;
	if (node->type & NODE_DATA)
		free(node->data);
	nodedelete(node->left);
	nodedelete(node->right);
	free(node);
}

int	term(int type, char **buffer, t_linkedlist **node)
{
	if ((*node) == NULL)
		return (0);
	if ((*node)->type == type)
	{
		if (buffer != NULL)
		{
			*buffer = malloc(ft_strlen((*node)->data) + 1);
			ft_strlcpy(*buffer, (*node)->data, ft_strlen((*node)->data) + 1);
		}
		(*node) = (*node)->next;
		return (1);
	}
	(*node) = (*node)->next;
	return (0);
}
