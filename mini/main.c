#include "utils/utils.h"

// typedef struct node s_node;

//check if the last character is a \n and subtract accordingly
// go to the position before \0 and check if it is a \n
// int	linechecker(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	if (str[i - 1] == '\n')
// 		return (1);
// 	else
// 		return (0);
// }

// starts the program and get the input from user.
int	checkforexit(char *envp[])
{
	char	*str;
	// char	*paths;
	// struct s_minishell *t_minishell;

	// t_minishell = ft_calloc(1, sizeof(struct s_minishell));
	
	//setup 
	// setupstruct(t_minishell, envp);

	printf("\033[1;31m\n");
	printf("%p", envp);

	str = NULL;

	// initialize_readline();
	rl_clear_history();

	// Change from top:
	while (1)
	{
		str = readline("minishell>");
		if (!str)
			break;

		// if input is not just an empty str
		// add to history
		if (*str)
			add_history(str);

		// To do: Check the first 2
        if (strcmp(str, "clear") == 0)
		{
            // Clear the screen if the command 'clear' is entered
            rl_replace_line("", 0); // Clear the readline line buffer
            system("clear"); // Use system call to clear the terminal screen // Check if this is allowed
        }
		else if (strcmp(str, "reset_hist") == 0)
		{
            // Reset the history if 'reset_hist' command is entered
			// clearhistory();
			rl_clear_history();

            printf("History cleared.\n");
        }
		else
		{
            // Handle other commands
            printf("You entered: %s\n", str);
	
			if (ft_strncmp(str, "env", ft_strlen("env")) == 0)
			{
				// if just env [Based off eval]
				// int i = 0;
				// while (t_minishell->envp[i])
				// {
				// 	printf("%s\n", t_minishell->envp[i]);
				// 	i++;
				// }

				// if there are other commands EG:
				// 1.Run command with modified env
				// env VAR1=foo VAR2=bar command
				// 2.Modify the env for shell session
				// env Path=$PATH:/new/path
				// 3.Print value of specific env
				// env | grep PATH
				// 4. execute command with clean env
				// env -i command
				// 5. setting env variable for a command
				// env -u VAR1 -i VAR2=value command

			}
			// Export and set don't really need clean up since they are more or less fixed
			// eg: Export MY_VAR="smth" || unset MY_VAR
			else if (ft_strncmp(str, "export", ft_strlen("export")) == 0)
			{
				// export to env
				// exportstr(str, t_minishell);	
			}
			else if (ft_strncmp(str, "unset", ft_strlen("unset")) == 0)
			{
				// unset a variable in the env
				// unsetmyenv(str, t_minishell);
			}
			else if (ft_strncmp(str, "pwd", ft_strlen("pwd")) ==0)
			{
				// updatepwd(t_minishell);
				// printf("%s\n", t_minishell->currpwd);
			}
			else if (ft_strncmp(str, "cd", ft_strlen("cd")) ==0)
			{
				// changedirectory(str, t_minishell);
			}
			else
			{
				// token_list token_list;

				t_linkedlist *node;

				// printf("lexical\n");
				node = lexical(str);// this return a linked list
				// // pass the linked list into the parser

				// while (node)
				// {
				// 	printf("%s\n", node->data);
				// 	node = node ->next;
				// }
				// printf("end of lexical \n\n");


				// printf("parsing\n");
				struct s_AST_Node *ast_node;
				ast_node = breakcommandline(node);
				execute_syntax_tree(ast_node);





				// the value may have issue.
				// int numoftoken = lexical(str, t_minishell, ft_strlen(str), &token_list);

				// struct AST_Node* exectree;

				// if (!numoftoken || parsingthis(token_list.token_ll, &exectree) != 0)
				// {
				// 	continue;
				// }

				// //execute it accordingly 
				// execute_syntax_tree(exectree);


			}
        }

        rl_on_new_line(); // Prepare readline for new input
		// this should comment out
        // rl_redisplay(); // Redisplay the line (useful if line was replaced)
        
        free(str); // Free the input string allocated by readline
 
		
	}

	// clear the history
	// clearhistory();
	rl_clear_history();

	return (0);
}

/*
1. i will also need some kind of mechanism to expand env
eg: $abc = /root/eseet/...
i need to be able to expand $abc

So what do i really need? to handle?
""
''
$

2. Handle extra quotations and all when it is just a single string.

3.remove quotes from words / things not interfered with seperators

4. Bonus: Handle *
*/

int main(int argc, char *argv[], char *envp[])
{
	// printf("argv:%d %p\n",argc, argv[0]);
	if (argc == 1)
	{
		if (ft_strncmp("./minishell", argv[0], 11) == 0)
		{
			checkforexit(envp);
		}
	}
	return (0);
}