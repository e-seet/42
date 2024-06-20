#include "../utils.h"


struct AST_Node	*tokenlist1(s_linkedlist **node)
{
	struct AST_Node	*tokenlistnode;
	struct AST_Node	*rootnode;
	char			*arg;

	if (!term(TOKEN, &arg, node))
	{
		return (NULL);
	}
	tokenlistnode = breaktokenlist(node);
	rootnode = malloc(sizeof(struct AST_Node));
	
	
	nodesettype(rootnode, NODE_ARGUMENT);
	// printf("set argument. %s, %d\n", arg, NODETYPE((rootnode)->type));
	nodesetdata(rootnode, arg);
	attachbinarybranch(rootnode, NULL, tokenlistnode);
	return (rootnode);
}

struct	AST_Node *tokenlist2(void)
{
	return (NULL);
}

// this just return the token list node. Does not have any binary nodes
// <token list>	::=		<token> <token list>
// <token list>	::=		<EMPTY>

struct AST_Node	*breaktokenlist(s_linkedlist **node)
{
	s_linkedlist	*saved;
	struct AST_Node	*ast_node;

	saved = *node;
	ast_node = tokenlist1(node);
	if (ast_node != NULL)
	{
		return (ast_node);
	}

	*node = saved;
	ast_node = tokenlist2();
	if (ast_node != NULL)
	{
		return (ast_node);
	}
	return (NULL);
}

struct AST_Node *simplecommand(s_linkedlist **node)
{
	struct AST_Node	*tokenlistnode;
	struct AST_Node	*rootnode;
	char			*path;
	// s_linkedlist	*saved;

	// printf("simple command function in parsing.c\n");
	// printf("what is the data? %s\n", node->data);
	// printf("what is the type? %d\n\n", node->type);
	if (!term(TOKEN, &path, node))
	{
		return (NULL);
	}
	// saved = *node;

	// printf("break token list is twhy i moved another itme\n");
	tokenlistnode = breaktokenlist(node);
	// if (tokenlistnode == NULL)
	// {
		// printf("tokenlistnode is null\n");
		// *node = saved;
		// we don't check whether tokenlistnode is NULL since its a valid grammer
	// }
	
	rootnode = malloc(sizeof(struct AST_Node));
	// rootnode->type = NULL;
	// printf("set it as node cmdpath\n");
	// printf("before set path. %s, %d\n", path, NODETYPE((rootnode)->type));
	nodesettype(rootnode, NODE_CMDPATH);
	// printf("set path. %s, %d\n", path, NODETYPE((rootnode)->type));
	nodesetdata(rootnode, path);
	attachbinarybranch(rootnode, NULL, tokenlistnode);
	return (rootnode);
}

// <simple command>::=		<pathname> <token list>
// struct AST_Node	*simplecommand(s_linkedlist *node)
// {
// 	s_linkedlist	*saved;
// 	saved = node;

// 	printf("%p", saved);
// 	return simplecommand1(node);

// }


























//entry is in parsing1.c
// struct AST_Node *breakcommandline(s_linkedlist *node)
