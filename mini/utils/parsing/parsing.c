#include "../utils.h"

struct s_AST_Node	*tokenlist1(t_linkedlist **node)
{
	struct s_AST_Node	*tokenlistnode;
	struct s_AST_Node	*rootnode;
	char			*arg;

	if (!term(TOKEN, &arg, node))
	{
		return (NULL);
	}
	tokenlistnode = breaktokenlist(node);
	rootnode = malloc(sizeof(struct s_AST_Node));
	
	
	nodesettype(rootnode, NODE_ARGUMENT);
	// printf("set argument. %s, %d\n", arg, NODETYPE((rootnode)->type));
	nodesetdata(rootnode, arg);
	attachbinarybranch(rootnode, NULL, tokenlistnode);
	return (rootnode);
}

struct	s_AST_Node *tokenlist2(void)
{
	return (NULL);
}

// this just return the token list node. Does not have any binary nodes
// <token list>	::=		<token> <token list>
// <token list>	::=		<EMPTY>

struct s_AST_Node	*breaktokenlist(t_linkedlist **node)
{
	t_linkedlist	*saved;
	struct s_AST_Node	*s_AST_Node;

	saved = *node;
	s_AST_Node = tokenlist1(node);
	if (s_AST_Node != NULL)
	{
		return (s_AST_Node);
	}

	*node = saved;
	s_AST_Node = tokenlist2();
	if (s_AST_Node != NULL)
	{
		return (s_AST_Node);
	}
	return (NULL);
}

struct s_AST_Node *simplecommand(t_linkedlist **node)
{
	struct s_AST_Node	*tokenlistnode;
	struct s_AST_Node	*rootnode;
	char			*path;
	// t_linkedlist	*saved;

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
	
	rootnode = malloc(sizeof(struct s_AST_Node));
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
// struct s_AST_Node	*simplecommand(t_linkedlist *node)
// {
// 	t_linkedlist	*saved;
// 	saved = node;

// 	printf("%p", saved);
// 	return simplecommand1(node);

// }



//entry is in parsing1.c
// struct s_AST_Node *breakcommandline(t_linkedlist *node)
