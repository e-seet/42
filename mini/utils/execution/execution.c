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

// to decide if should add built in command before fork
// to decide if need to add zombie handler after executeprocess
void	execution2(t_parameters *parameters)
{
	pid_t	pid;

	if (parameters->argc < 0)
	{
		printf("return due to argc < 0 ");
		return ;
	}
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
