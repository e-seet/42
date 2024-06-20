#include "../utils.h"

struct AST_Node *breakjob1(s_linkedlist *node)
{
	struct AST_Node	*command_node;
	struct AST_Node	*job_node;
	struct AST_Node	*rootnode;

	command_node = breakcommand(node);
	if (command_node == NULL)
		return (NULL);

	// check it is semicolon, then move to next node and skip this if statement
	// otherwise delete the node and move on
	if (!term(PIPE, NULL, &node))
	{
		nodedelete(command_node);
		return (NULL);
	}
	// Look for the next command line
	// if null delete
	job_node = breakjob(node);
	if (job_node == NULL)
	{
		nodedelete(job_node);
		return (NULL);
	}
	rootnode = malloc(sizeof(struct AST_Node));
	nodesettype(rootnode, NODE_PIPE);
	attachbinarybranch(rootnode, command_node, job_node);
	return (rootnode);
}

struct AST_Node *breakjob2(s_linkedlist *node)
{
	return (breakcommand(node));
}

// <job>			::=		<command> '|' <job>
// 						|	<command>
struct AST_Node *breakjob(s_linkedlist *node)
{
	s_linkedlist	*saved;
	struct AST_Node	*ast_node;

	saved = node;
	ast_node = breakjob1(node);
	if (ast_node != NULL)
	{
		return (ast_node);
	}
	node = saved;
	ast_node = breakjob2(node);
	if (ast_node != NULL)
	{
		// printf("return null from breakjob parsing2\n");	
		return (ast_node);
	}

	return (NULL);
}
