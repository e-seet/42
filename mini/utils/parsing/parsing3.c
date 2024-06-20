#include "../utils.h"

// <<
struct s_AST_Node *breakcommand1(t_linkedlist *node)
{
	// printf("\n\n\nthis should work for heredoc\n");
	struct s_AST_Node	*simplecommand_node;
	char			*filename;
	struct s_AST_Node	*rootnode;

	simplecommand_node = simplecommand(&node);
	if (simplecommand_node == NULL)
	{
		// printf("simple command node got issue\n");
		return (NULL);
	}

	// by here, it should have moved but didnot.3

	// printf("\nshould be 1002 \n");
	if (!term(1002, NULL, &node))
	{
		// printf("\nhere doc not found\n");
		nodedelete(simplecommand_node);
		return (NULL);
	}
	// printf("found heredoc sign\n");


	filename = NULL;
	// printf("Token which is for end file\n");
	if (!term(TOKEN, &filename, &node))
	{
		// printf("\nfile name got issue\n");
		nodedelete(simplecommand_node);
		free(filename);
		return (NULL);
	}
	
	rootnode = malloc(sizeof(struct s_AST_Node));
	nodesettype(rootnode, NODE_HEREDOC);
	printf("set type:%d\n", NODETYPE((rootnode)->type));
	
	nodesetdata(rootnode, filename);
	attachbinarybranch(rootnode, NULL, simplecommand_node);
	return (rootnode);
}

// <
struct s_AST_Node *breakcommand2(t_linkedlist *node)
{
	struct s_AST_Node	*simplecommand_node;
	char			*filename;
	struct s_AST_Node	*rootnode;

	simplecommand_node = simplecommand(&node);
	if (simplecommand_node == NULL)
		return (NULL);

	if (!term(LESSER, NULL, &node))
	{
		nodedelete(simplecommand_node);
		return (NULL);
	}
	filename = NULL;
	if (!term(TOKEN, &filename, &node))
	{
		nodedelete(simplecommand_node);
		free(filename);
		return (NULL);
	}
	rootnode = malloc(sizeof(struct s_AST_Node));
	nodesettype(rootnode, NODE_REDIRECT_IN);
	printf("set type:%d\n", NODETYPE((rootnode)->type));
	nodesetdata(rootnode, filename);
	attachbinarybranch(rootnode, NULL, simplecommand_node);
	return (rootnode);
}

// >>
// to fix the permission for this
// this needs to append and not overwrite like breakcommand4
struct s_AST_Node *breakcommand3(t_linkedlist *node)
{
	struct s_AST_Node	*simplecommand_node;
	char			*filename;
	struct s_AST_Node	*rootnode;

	simplecommand_node = simplecommand(&node);
	if (simplecommand_node == NULL)
		return (NULL);

	if (!term(REDIR, NULL, &node))
	{
		nodedelete(simplecommand_node);
		return (NULL);
	}
	filename = NULL;
	if (!term(TOKEN, &filename, &node))
	{
		nodedelete(simplecommand_node);
		free(filename);
		return (NULL);
	}
	rootnode = malloc(sizeof(struct s_AST_Node));
	nodesettype(rootnode, NODE_REDIRECT);
	printf("set type:%d\n", NODETYPE((rootnode)->type));
	
	nodesetdata(rootnode, filename);
	attachbinarybranch(rootnode, NULL, simplecommand_node);
	return (rootnode);
}



// > 
struct s_AST_Node *breakcommand4(t_linkedlist *node)
{
	struct s_AST_Node	*simplecommand_node;
	char			*filename;
	struct s_AST_Node	*rootnode;

	simplecommand_node = simplecommand(&node);
	if (simplecommand_node == NULL)
		return (NULL);

	if (!term(GREATER, NULL, &node))
	{
		nodedelete(simplecommand_node);
		return (NULL);
	}
	filename = NULL;
	if (!term(TOKEN, &filename, &node))
	{
		nodedelete(simplecommand_node);
		free(filename);
		return (NULL);
	}
	rootnode = malloc(sizeof(struct s_AST_Node));
	nodesettype(rootnode, NODE_REDIRECT_OUT);
	printf("set type:%d\n", NODETYPE((rootnode)->type));
	
	nodesetdata(rootnode, filename);
	attachbinarybranch(rootnode, NULL, simplecommand_node);
	return (rootnode);
}


struct s_AST_Node *breakcommand5(t_linkedlist *node)
{
	return simplecommand(&node);
}

struct s_AST_Node *breakcommand(t_linkedlist *node)
{
	t_linkedlist	*saved;
	struct s_AST_Node	*ast_node;


	saved = node;
	ast_node = breakcommand1(node);
	if (ast_node != NULL)
		return (ast_node);
	node = saved;
	ast_node = breakcommand2(node);
	if (ast_node != NULL)
		return (ast_node);

	node = saved;
	ast_node = breakcommand3(node);
	if (ast_node != NULL)
		return (ast_node);

	node = saved;
	ast_node = breakcommand4(node);
	if (ast_node != NULL)
		return (ast_node);
	
	node = saved;
	ast_node = breakcommand5(node);
	if (ast_node != NULL)
		return (ast_node);

	return (NULL);
}
