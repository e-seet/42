#include "../utils.h"

void	waitprocess(t_parameters *parameters, int *pid)
{
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

// allow signals to be used
// restore the crtl c signal in the child process
// restore_sigint_in_child();
// store the stdout file desc
void	executeprocess(t_parameters *parameters, int	*pid)
{
	int		stdoutfd;

	if ((*pid) == 0)
	{
		stdoutfd = dup(STDOUT_FILENO);
		redirection(parameters);
		// To change to execve
		if (execvp(parameters->argv[0], parameters->argv) == -1)
		{
			// restore the stdout for displaying error message
			dup2(stdoutfd, STDOUT_FILENO);
			printf("Command not found: \'%s\'\n", parameters->argv[0]);
			exit(1);
		}
		else
			printf("ended execution\n");
	}
	else if ((*pid) < 0)
	{
		perror("fork");
		return ;
	}
	waitprocess(parameters, pid);
}

int	builtincommand(t_parameters *parameters, t_mini *mini)
{
	int	i;

	if (parameters->argc < 0)
		return (1);
	// echo
	// cd
	else if (ft_strncmp(parameters->argv[0], "cd", ft_strlen("cd")) == 0)
	{
		execute_cd(parameters, mini);
		// changedirectory(str, t_minishell);
		return (1);
	}
	// pwd
	else if (ft_strncmp(parameters->argv[0], "pwd", ft_strlen("pwd")) == 0)
	{
		execute_pwd(parameters);
		// updatepwd(t_minishell);
		return (1);
	}
	// // export
	// No input / output reditection
	// no pipes
	else if (ft_strncmp(parameters->argv[0], "export",
			ft_strlen("export")) == 0)
	{
		// export to env
		exportstr(mini);
		return (1);
	}
	// unset
	// No input / output reditection
	// no pipes
	else if (ft_strncmp(parameters->argv[0], "unset", ft_strlen("unset")) == 0)
	{
		// 	// unset a vabuiltiriable in the env
		unsetmyenv(mini);
		return (1);
	}
	// // env
	// No input / output reditection
	// no pipes
	else if (ft_strncmp(parameters->argv[0], "env", ft_strlen("env")) == 0)
	{
		// 	just env [Based off eval]
		i = 0;
		while (mini->envp[i])
		{
			printf("%s\n", mini->envp[i]);
			i++;
		}
		return (1);
	}
	// exit
	else if (strcmp(parameters->argv[0], "exit") == 0)
	{
		// to free stuff first
		exit(0);
		return (1);
	}
	// // ??	
	// if (ft_strncmp(parameters->argv[0], "clear", ft_strlen("clear")) == 0)
	// {
	// Clear the readline line buffer
	// 	rl_replace_line("", 0);
	// Use system call to clear the terminal screen // Check if this is allowed
	// 	// system("clear");
	// 	return (1);
	// }
	else
		return (0);
}

// to decide if should add built in command before fork
// to decide if need to add zombie handler after executeprocess
void	execution2(t_parameters *parameters, t_mini	*mini)
{
	pid_t	pid;

	printf("mini pointer:%p. To use for execute process. To do\n", mini);
	if (parameters->argc < 0)
	{
		printf("return due to argc < 0 ");
		return ;
	}
	// if there is built in
	if (builtincommand(parameters, mini))
		return ;
	pid = fork();
	executeprocess(parameters, &pid);
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
