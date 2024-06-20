#include "../utils.h"

// first layer
struct AST_Node *breakcommandline1(s_linkedlist *node)
{
	struct AST_Node	*job_node;
	struct AST_Node	*cmdline_node;
	struct AST_Node	*rootnode;


	// while (node)
	// {
	// 	printf("%s\n", node->data);
	// 	printf("%d\n", node->type);
		
	// 	node = node -> next;
	// }
	// printf("end of traverse node\n");

	job_node = breakjob(node);
	if (job_node == NULL)
	{
		// printf("breakjob is null. Return null\n");
		return (NULL);
	}

	// check it is semicolon, then move to next node and skip this if statement
	// otherwise delete the node and move on
	if (!term(SEMICOLON, NULL, &node))
	{
		nodedelete(job_node);
		return (NULL);
	}
	// Look for the next command line
	// if null delete
	cmdline_node = breakcommandline(node);
	if (cmdline_node == NULL)
	{
		nodedelete(job_node);
		return (NULL);
	}
	rootnode = malloc(sizeof(struct AST_Node));
	nodesettype(rootnode, NODE_SEQ);
	printf("set seq. %d\n",NODETYPE((rootnode)->type));

	attachbinarybranch(rootnode, job_node, cmdline_node);
	return (rootnode);
}

struct AST_Node *breakcommandline2(s_linkedlist *node)
{
	struct AST_Node	*job_node;
	// struct AST_Node	*cmdline_node;
	struct AST_Node	*rootnode;

	job_node = breakjob(node);
	if (job_node == NULL)
		return (NULL);

	// check it is semicolon, then move to next node and skip this if statement
	// otherwise delete the node and move on
	if (!term(SEMICOLON, NULL, &node))
	{
		nodedelete(job_node);
		return (NULL);
	}
	rootnode = malloc(sizeof(struct AST_Node));
	nodesettype(rootnode, NODE_SEQ);
	printf("set seq:%d.\n", NODETYPE((rootnode)->type));
	

	attachbinarybranch(rootnode, job_node, NULL);
	return (rootnode);
}

struct AST_Node	*breakcommandline3(s_linkedlist *node)
{
	return (breakjob(node));
}


// job ; command line
// job ;
// job
// this is the entry leh
struct AST_Node *breakcommandline(s_linkedlist *node)
{
	s_linkedlist	*saved;
	struct AST_Node	*ast_node;

	saved = node;
	// printf("check the node:%s\n\n", node->data);
	ast_node = breakcommandline1(node);
	if (ast_node != NULL)
	{
		return (ast_node);
	}

	node = saved;
	// printf("check the node:%s\n\n", node->data);
	ast_node = breakcommandline2(node);
	if (ast_node != NULL)
		return (ast_node);

	node = saved;
	// printf("check the node:%s\n\n", node->data);
	ast_node = breakcommandline3(node);
	if (ast_node != NULL)
		return (ast_node);

	printf("\n\nreturn null from bcl of parsing1\n");
	return NULL;
}
