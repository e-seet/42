#include "../utils.h"

int	executeprocess_child(t_parameters *parameters, t_mini *mini)
{
	int		stdoutfd;
	int		result;

	stdoutfd = dup(STDOUT_FILENO);
	redirection(parameters);
	mini->path = findprocesspath(mini, parameters);
	if (mini->path == NULL)
	{
		perror("Access Path not found. Should free properly\n");
		free(mini->path);
		exit (0);
	}
	result = execve(mini->path, parameters->argv, mini->envp);
	if (result == -1)
	{
		// restore the stdout for displaying error message
		dup2(stdoutfd, STDOUT_FILENO);
		printf("Command not found: \'%s\'\n", parameters->argv[0]);
		// mini->exit_status = 1;
		return (1);
		exit(1);
	}
	else
		// mini->exit_status = result;
		return (0);
}

// allow signals to be used
// restore the crtl c signal in the child process
// restore_sigint_in_child();
// store the stdout file desc

// execvp example
// char *argv[] = {"/bin/ls", "-l", NULL}; 
// Command and its arguments
// char *envp[] = {"PATH=/usr/bin", "HOME=/home/user", NULL};
// Environment variables
// (execve("/bin/ls", argv, envp) == -1) 

// to test execve. Not done testing
void	executeprocess(t_parameters *parameters, int *pid, t_mini *mini)
{
	if ((*pid) == 0)
	{
		if (executeprocess_child(parameters, mini) == -1)
			mini->exit_status = 1;
		else
			mini->exit_status = 0;
	}
	else if ((*pid) < 0)
	{
		perror("fork");
		return ;
	}
	if (!parameters->async)
	{
		// wait till the process has not finished
		while (waitpid(*pid, NULL, 0) <= 0)
		{
			continue ;
		}
		printf("\n");
	}
}

// combine everything to a string
// write to fd
void	execute_echo(t_parameters *parameters, t_mini *mini)
{
	int		i;
	char	*str;

	str = calloc(1, sizeof(char));
	str[0] = '\0';	
	i = 1;
	if (ft_strncmp(parameters->argv[1], "-n", ft_strlen("-n")) == 0)
		i = 2;
	while (parameters->argv[i])
	{
		str = ft_strjoin(str, parameters->argv[i]);
		i ++;
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	if (ft_strncmp(parameters->argv[1], "-n", ft_strlen("-n")) == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
	mini->exit_status = 0;
}

int	builtincommand(t_parameters *parameters, t_mini *mini)
{
	if (parameters->argc < 0)
		return (1);
	// echo
	else if (ft_strncmp(parameters->argv[0], "cd", ft_strlen("echo")) == 0)
	{
		execute_echo(parameters, mini);
		return (1);
	}
	// cd
	else if (ft_strncmp(parameters->argv[0], "cd", ft_strlen("cd")) == 0)
	{
		execute_cd(parameters, mini);
		return (1);
	}
	// pwd
	else if (ft_strncmp(parameters->argv[0], "pwd", ft_strlen("pwd")) == 0)
	{
		execute_pwd(parameters);
		return (1);
	}
	// // export
	// No input / output reditection
	// no pipes
	else if (ft_strncmp(parameters->argv[0], "export",
			ft_strlen("export")) == 0)
	{
		exportstr(mini);
		return (1);
	}
	// unset
	// No input / output reditection
	// no pipes
	else if (ft_strncmp(parameters->argv[0], "unset", ft_strlen("unset")) == 0)
	{
		unsetmyenv(mini);
		return (1);
	}
	// // env
	// No input / output reditection
	// no pipes
	else if (ft_strncmp(parameters->argv[0], "env", ft_strlen("env")) == 0)
	{
		printenv(mini);
		return (1);
	}
	// exit
	else if (strcmp(parameters->argv[0], "exit") == 0)
	{
		// to free stuff first
		exit(0);
		return (1);
	}
	else
		return (0);
}

// to decide if should add built in command before fork
// to decide if need to add zombie handler after executeprocess
void	execution2(t_parameters *parameters, t_mini	*mini)
{
	pid_t	pid;

	if (parameters->argc < 0)
	{
		printf("return due to argc < 0 ");
		return ;
	}
	// if there is built in
	if (builtincommand(parameters, mini))
		return ;
	pid = fork();
	executeprocess(parameters, &pid, mini);
	return ;
}

// to remove test variable
// void	execution2(t_parameters *parameters)
// {
// 	pid_t	pid;
// 	int		stdoutfd;
// 	// int		fdout;
// 	// int		fdin;
// 	// int		fdasync;

// 	if (parameters->argc < 0)
// 	{
// 		printf("return due to argc < 0 ");
// 		return ;
// 	}
// 	// check for built-in commands
// 	// if (strcmp(parameters->argv[0], "cd") == 0) {
// 	//     execute_cd(parameters);
// 	//     return;
// 	// }
// 	// else if (strcmp(parameters->argv[0], "pwd") == 0)
// 	//     return execute_pwd(parameters);
// 	// else if(strcmp(parameters->argv[0], "exit") == 0) {
// 	// 	exit(0);
// 	// 	return;
// 	// }
// 	// test = 0;
// 	// printf("find out what is inside my cmd internal\n");
// 	// while (parameters->argv[test])
// 	// {
// 	// 	printf("%s\n", parameters->argv[test]);
// 	// 	test ++;
// 	// }
// 	// printf("\n\n");
// 	//execute the stuff

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		// allow signals to be used
// 		// restore the crtl c signal in the child process
// 		// restore_sigint_in_child();
// 		// store the stdout file desc
// 		stdoutfd = dup(STDOUT_FILENO);

// 		// // for bckgrnd jobs redirect stdin from /dev/null
// 		// if (parameters->async)
// 		// {
// 		// 	printf("is async\n");
// 		// 	fdasync = open("/dev/null", O_RDWR);
// 		// 	if (fdasync == -1)
// 		// 	{
// 		// 		perror("/dev/null");
// 		// 		exit(1);
// 		// 	}
// 		// 	dup2(fdasync, STDIN_FILENO);
// 		// }
// 		// // redirect stdin from file if specified
// 		// if (parameters->file_in)
// 		// {
// 		// 	// printf("file in\n");
// 		// 	// printf("actual file:%s\n",parameters->file_in);
// 		// 	fdin = open(parameters->file_in, O_RDONLY);
// 		// 	if (fdin == -1)
// 		// 	{
// 		// 		perror(parameters->file_in);
// 		// 		printf("fd error\n");
// 		// 		exit(1);
// 		// 	}
// 		// 	dup2(fdin, STDIN_FILENO);
// 		// }
// 		// // redirect stdout to file if specified
// 		// else if (parameters->file_out)
// 		// {
// 		// 	printf("file out\n");
// 		// 	if (parameters->append == 1)
// 		// 	{
// 		// 		fdout = open(parameters->file_out, O_WRONLY | O_CREAT
// 		// 				| O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
// 		// 	}
// 		// 	else
// 		// 		fdout = open(parameters->file_out, O_WRONLY | O_CREAT | O_TRUNC,
// 		// 				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
// 		// 	if (fdout == -1)
// 		// 	{
// 		// 		perror(parameters->file_out);
// 		// 		exit(1);
// 		// 	}
// 		// 	dup2(fdout, STDOUT_FILENO);
// 		// }
// 		// // read stdin from pipe if present
// 		// if (parameters->readpipe)
// 		// {
// 		// 	printf("read from pipe\n");
// 		// 	dup2(parameters->piperead, STDIN_FILENO);
// 		// }
// 		// // write stdout to pipe if present
// 		// if (parameters->writepipe)
// 		// {
// 		// 	printf("write to pipe\n");
// 		// 	dup2(parameters->pipewrite, STDOUT_FILENO);
// 		// }
// 		redirection(parameters);

// 		// printf("check the command %s", parameters->argv[0]);
// 		// int x = 0;
// 		// while (parameters->argv[x])
// 		// {
// 		// 	printf("check the argv %s", parameters->argv[x]);
// 		// 	x++;
// 		// }
// 		if (execvp(parameters->argv[0], parameters->argv) == -1)
// 		{
// 			// restore the stdout for displaying error message
// 			dup2(stdoutfd, STDOUT_FILENO);
// 			printf("Command not found: \'%s\'\n", parameters->argv[0]);
// 			exit(1);
// 		}
// 		else
// 			printf("ended execution\n");
// 	}
// 	else if (pid < 0)
// 	{
// 		perror("fork");
// 		return ;
// 	}

// 	// may or may not need
// 	// not async
// 	if (!parameters->async)
// 	{
// 		// wait till the process has not finished
// 		while (waitpid(pid, NULL, 0) <= 0)
// 		{
// 			continue ;
// 		}
// 	}
// 	// else
// 	// {
// 	// 	// set the sigchild handler for the spawned process
// 	//     printf("%d started\n", pid);
// 	//     struct sigaction act;
// 	//     act.sa_flags = 0;
// 	//     act.sa_handler = zombie_process_handler;
// 	//     sigfillset( & (act.sa_mask) ); // to block all
// 	//     if (sigaction(SIGCHLD, &act, NULL) != 0)
// 	//         perror("sigaction");
// 	// }
// 	return ;
// }
