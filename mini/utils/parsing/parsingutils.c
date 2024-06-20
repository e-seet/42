#include "../utils.h"

void	attachbinarybranch(struct AST_Node *root,
	struct AST_Node *leftnode, struct AST_Node *rightnode)
{
	// assert(root != NULL);
	if (root != NULL)
	{
		root->left = leftnode;
		root->right = rightnode;
	}
}

void	nodesettype(struct AST_Node *node, NodeType nodetype)
{
	// assert(node != NULL);
	if (node != NULL)
		node->type = nodetype;
}

void	nodesetdata(struct AST_Node *node, char *data)
{
	// assert(node != NULL);
	if (node != NULL)
	{
		if (data != NULL)
		{
			// node->szData = data;
			node->data = data;
			node->type |= NODE_DATA;
		}
	}
}

void	nodereset(struct AST_Node *node)
{
	if (node->type & NODE_HEREDOC) {
        free(node->data);
        node->data = NULL;  // Reset data pointer to NULL after freeing
    }

    // Clear the type field
    node->type = 0;  // Assuming 0 represents no flags set or an appropriate default

	// if (node == NULL)
	// 	return ;
	// if (node->type & NODE_HEREDOC)
	// 	free(node->data);
}

void	nodedelete(struct AST_Node *node)
{
	if (node == NULL)
		return ;
	if (node->type & NODE_DATA)
		free(node->data);
	nodedelete(node->left);
	nodedelete(node->right);
	free(node);
}

int	term(int type, char **buffer, s_linkedlist **node)
{
	if ((*node) == NULL)
		return (0);

	// printf("check pased in type:%d\n", type);
	// printf("check term type:%d\n", (*node)->type);
	// printf("check term data:%s\n\n", (*node)->data);


	if ((*node)->type == type)
	{
		if (buffer != NULL)
		{
			*buffer = malloc(ft_strlen((*node)->data) + 1);
			ft_strlcpy(*buffer, (*node)->data, ft_strlen((*node)->data)+1);
		}
		(*node) = (*node)->next;
		return (1);
	}
	(*node) = (*node)->next;
	return 0;
}

