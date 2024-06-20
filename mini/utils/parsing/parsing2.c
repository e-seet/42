#include "../utils.h"

struct s_AST_Node *breakjob1(t_linkedlist *node)
{
	struct s_AST_Node	*command_node;
	struct s_AST_Node	*job_node;
	struct s_AST_Node	*rootnode;

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
	rootnode = malloc(sizeof(struct s_AST_Node));
	nodesettype(rootnode, NODE_PIPE);
	attachbinarybranch(rootnode, command_node, job_node);
	return (rootnode);
}

struct s_AST_Node *breakjob2(t_linkedlist *node)
{
	return (breakcommand(node));
}

// <job>			::=		<command> '|' <job>
// 						|	<command>
struct s_AST_Node *breakjob(t_linkedlist *node)
{
	t_linkedlist	*saved;
	struct s_AST_Node	*s_AST_Node;

	saved = node;
	s_AST_Node = breakjob1(node);
	if (s_AST_Node != NULL)
	{
		return (s_AST_Node);
	}
	node = saved;
	s_AST_Node = breakjob2(node);
	if (s_AST_Node != NULL)
	{
		// printf("return null from breakjob parsing2\n");	
		return (s_AST_Node);
	}

	return (NULL);
}
