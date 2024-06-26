#include "../utils.h"

// to do error checking 
void execute_cd(t_parameters *parameters, t_mini *mini)
{
	char	*envvariable;
	char	*currpwd;

	currpwd = ft_calloc(1024, sizeof(char));
	currpwd = getcwd(currpwd, 1024);

	// get home directory
    if (parameters->argc == 1)
	{
		envvariable = getenv("HOME");
		if (chdir(envvariable) != 0)
			perror("Error changing to this directory\n");
		if (mini->prevpwd != NULL)
		{
			free(mini->prevpwd);
			mini->prevpwd = currpwd;
		}
	}
    else if (parameters->argc > 2)
        printf("cd: Too many arguments\n");
    else 
	{
		// cater to just $ path
		if (parameters->argv[1][0] == '$')
		{
			envvariable = getenv(&parameters->argv[1][1]);
			if (envvariable == NULL)
				fprintf(stderr, "HOME environment variable not set\n");
			else
			{
				if (chdir(envvariable) != 0)
					perror("Error changing to this directory\n");
				if (mini->prevpwd != NULL)
				{
					free(mini->prevpwd);
					mini->prevpwd = currpwd;
				}
			}
		}
		// cater to ~
		else if (parameters->argv[1][0] == '~')
		{
			envvariable = getenv("HOME");
			// ~
			if (ft_strlen(parameters->argv[1]) == 1)
			{
				if (chdir(envvariable) != 0)
					perror("Error changing to this directory\n");
				if (mini->prevpwd != NULL)
				{
					free(mini->prevpwd);
					mini->prevpwd = currpwd;
				}
			}
			// ~/ etc
			else
			{
				if (chdir(ft_strjoin(envvariable, &parameters->argv[1][1])) != 0)
					perror("Error changing to this directory\n");
				if (mini->prevpwd != NULL)
				{
					free(mini->prevpwd);
					mini->prevpwd = currpwd;
				}
			}
		}
		// go back to previous directory
		// not done yet
		else if (parameters->argv[1][0] == '-')
		{
			// to do later
			if (mini->prevpwd != NULL)
			{
				if (chdir(mini->prevpwd) != 0)
					perror("Error changing to this directory\n");
				mini->prevpwd = currpwd;
			}
			else
				perror("Not set yet\n");
		}
		// default
		else
		{
			if (chdir(parameters->argv[1]) != 0)
				perror("Error changing to this directory\n");
            perror(parameters->argv[1]);
		}
    }
}

// double check this
void execute_pwd(t_parameters *parameters)
{
    pid_t	pid;
	int		fd;
	char	cwd[1024];

    if ((pid = fork()) == 0)
	{
        if (parameters->file_out)
		{
            fd = open(parameters->file_out, O_WRONLY | O_CREAT | O_TRUNC,
                          S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            if (fd == -1) 
			{
                perror(parameters->file_out);
                exit(1);
            }
            dup2(fd, STDOUT_FILENO);
        }
        if (parameters->writepipe)
			dup2(parameters->pipewrite, STDOUT_FILENO);
        if (getcwd(cwd, sizeof(cwd)) != NULL)
			write(STDOUT_FILENO, cwd, strlen(cwd));
        else 
            perror("getcwd() error");
        exit(0);
    }
    else if (pid < 0) 
	{
        perror("fork");
        return ;
    }
    else
		while (waitpid(pid, NULL, 0) <= 0);
    return ;
}

// void updatepwd(struct s_minishell *t_minishell)
// {
// 	char *currpwd;

// 	currpwd = ft_calloc(1024, sizeof(char));

// 	currpwd = getcwd(currpwd, 1024);
// 	if (t_minishell->currpwd != NULL)
// 	{
// 		free(t_minishell->currpwd);
// 	}
// 	t_minishell->currpwd = currpwd;
// 	if (!t_minishell->currpwd)
// 		printf("error in getting curr pwd");

// 	// printf("curr pwd: %s\n", t_minishell->currpwd);
// }

// void changedirectory(char *str, struct s_minishell *t_minishell)
// {
// 	printf("str:%s", str);

// 	// back to home directory
// 	// "cd "
// 	// The home directory can be retrieved by: echo $HOME
// 	if (ft_strncmp(str, "cd ", ft_strlen("cd ") == 0))
// 	{
// 		// to do
// 	}
// 	else if (ft_strncmp(str, "cd ~", ft_strlen("cd ~") == 0))
// 	{
// 		// To do
// 		// tilde as a shortcut to home directory
// 		// cd ~/Document
// 	}
// 	else if (ft_strncmp(str, "cd -", ft_strlen("cd -")) == 0)
// 	{
// 		// back to the previous directory that i was in
// 		// cd -
// 		if (chdir(t_minishell->prevpwd) != 0)
// 		{
// 			printf("Error navigating to:%s", t_minishell->prevpwd);
// 			perror("chdir: change directory error\n");
// 		}
// 		else
// 		{
// 			t_minishell->prevpwd = t_minishell->currpwd;
			
// 			char *currpwd;
// 			currpwd = ft_calloc(1024, sizeof(char));
// 			currpwd = getcwd(currpwd, 1024);
// 			t_minishell->currpwd = currpwd;
// 		}			
// 	}
// 	else
// 	{
// 		printf("else\n");
// 		// go up 1 level
// 		// "cd .."
// 		char **temp;
// 		char *dir;

// 		temp = ft_split(str, ' ');
// 		// printf("temp[1]:%s\n\n", temp[1]);
// 		dir = ft_calloc(ft_strlen(temp[1]) + 1, sizeof(char));
		
// 		ft_strlcpy(dir, temp[1], ft_strlen(temp[1]));

// 		printf("cd %s\n", dir);
		
// 		if (chdir(dir) != 0)
// 		{
// 			printf("Error navigating to:%s", dir);
// 			perror("chdir: change directory error\n");
// 		}
// 		else
// 		{
// 			t_minishell->prevpwd = t_minishell->currpwd;
			
// 			char *currpwd;
// 			currpwd = ft_calloc(1024, sizeof(char));
// 			currpwd = getcwd(currpwd, 1024);
// 			t_minishell->currpwd = currpwd;
// 		}
// 		// Works
// 		// "cd ." // does nothing .. so ignore

// 		// change to absolute / relative directory
// 		// more exmaples
// 		// Relative Paths
// 		// cd ../
// 		// cd ../../
// 		// cd ../42
// 		// remain in same directory
// 		// cd ./ 
// 		// cd ./anotherfile.txt
// 		// cd /Users/eddieseet/MDesktop/Curr/minishell/utils
// 		// cd /Users/eddieseet/MDesktop
// 		// cd /bin
// 		// cd /etc/hosts



// 		// not sure if required.
// 		// export CDPATH=.:~/Documents
// 		// cd directory_name
// 	}

// }