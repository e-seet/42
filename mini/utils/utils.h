
#ifndef UTILS_H
# define UTILS_H

#define RED "\033[1;31m";

// libft
# include "../libft/libft.h"
// gnl
# include "../get_next_line/get_next_line.h"

// my structs that is required
# include "struct.h"

// libraries required
// #include <readline/readline.h>
// #include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <termios.h>
#include <termcap.h>

// extra: To check if allowed libraries
#include <errno.h>
#include <term.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>


// #include <readline/readline.h>

// mac os
// #include <editline/readline.h>

// lexical file
// void			lexical(char *str, struct s_minishell *t_minishell);
// int				lexical(char *str, struct s_minishell *t_minishell, int strlen, token_list *token_list);
// void lexical(char *str);
typedef struct node s_node;
s_node	*lexical(char *str);



// void copycontentover(char *str, token *token_ll, int strlen);

// lexicalutils
int				ft_is_output_redirect(char *str);
int				ft_is_append_output_redirect(char *str);
int				ft_is_input_redirect(char *str);
int				ft_is_heredoc_redirect(char *str);
int				ft_is_conditional_or(char *str);

// lexicalutils2
int				ft_is_pipe(char *str);
int				ft_is_double_ampersand(char *str);
int				ft_is_bracket1(char *str);
int				ft_is_bracket2(char *str);
int				ft_is_semicolon(char *str);

int				ft_is_dollar(char *str);
int				ft_is_single_quote(char *str);
int				ft_is_double_quote(char *str);
int				ft_is_whitespaces(char *str);

// astree
typedef enum {
	// 1
    NODE_PIPE 			= (1 << 0),
	// 2
    NODE_BCKGRND 		= (1 << 1),
    // 4
	NODE_SEQ 			= (1 << 2),
	// 8
	// <
    NODE_REDIRECT_IN 	= (1 << 3),
	// 16
	// >
    NODE_REDIRECT_OUT 	= (1 << 4),
	// 32
	// >>
	// appending
    NODE_REDIRECT 	= (1 << 5),
	 // 64
	 // <<
    NODE_HEREDOC 	= (1 << 6),
    
	// 128
	NODE_CMDPATH		= (1 << 7),
	// 256
	NODE_ARGUMENT		= (1 << 8),
    // 512
	NODE_DATA 			= (1 << 9),
} NodeType;

// #define NODETYPE(a) (a & (~NODE_DATA))	// get the type of the nodes
#define NODETYPE(a) (a & (~NODE_DATA))	// get the type of the nodes




// for lexer below
enum Token{
	PIPE = '|',
	GREATER = '>',
	LESSER = '<',
	SEMICOLON = ';',
	//unique code for 1001: >> and 1002: <<
	// >>
	REDIR = 1001,
	// <<
	HEREDOC = 1002,
	// CHAR_NULL = 0,
	TOKEN	= -1,
};


// parser
struct AST_Node
{
	char	*data;
	// char	type; // To store the type: Command, Redirection, Arguments
	int		type;

	struct AST_Node* left;
    struct AST_Node* right;
};

struct node {
	char		*data;
	int			type;
	struct node	*next;
};
typedef struct node s_linkedlist;


// parsing ast
struct AST_Node *breakcommandline(s_linkedlist *token);
struct AST_Node *breakjob(s_linkedlist *token);
struct AST_Node *breakcommand(s_linkedlist *token);
struct AST_Node *simplecommand(s_linkedlist **token);
struct AST_Node *breaktokenlist(s_linkedlist **token);

void	nodereset(struct AST_Node *node);


// parsing 
// utils
void	attachbinarybranch(struct AST_Node *root,
	struct AST_Node *leftnode, struct AST_Node *rightnode);
void	nodesettype(struct AST_Node *node, NodeType nodetype);
void	nodesetdata(struct AST_Node *node, char *data);
void	nodedelete(struct AST_Node *node);
// int	term(int type, char **buffer, s_linkedlist *node);
int	term(int type, char **buffer, s_linkedlist **node);

// layer1
struct AST_Node *breakcommandline(s_linkedlist *node);
// layer2
struct AST_Node *breakjob(s_linkedlist *node);
// layer3
struct AST_Node *breakcommand(s_linkedlist *node);

// top
//parsing1
// <command line>	::= 	<job> ';' <command line>
// 					|	<job> ';'
// 						<job>

//parsing2
// <job>			::=		<command> '|' <job>
// 					|	<command>

//parsing3
// <command>		::=		<simple command> '<' filename // this grammer is a bit incorrect, see grammer.llf
// 					|	<simple command> '>' filename
// 					|	<simple command> '>>' filename
// 					|	<simple command> '<<' filename
// 					|	<simple command>

//parsing1
// <simple command>::=		<pathname> <token list>


// <token list>	::=		<token> <token list>
// |	(EMPTY)
// bottom

struct parameters
{
	int argc;
	char **argv;
	// whether we need to read
	int readpipe;
	int writepipe;

	// the fd to read from
	int piperead;
	int pipewrite;
	int	append;
	char* file_in;
	char* file_out;
	int async;
};
typedef struct parameters s_parameters;
// execute
// void	execute_job(struct AST_Node *rootnode, int async);
void	execute_job(struct AST_Node **rootnode, int async, s_parameters *parameters);
void execution2(s_parameters *parameters);

void	execute_syntax_tree(struct AST_Node *rootnode);

#endif