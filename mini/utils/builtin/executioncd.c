#include "../utils.h"

// ~
// ~/ etc
void	execute_cd_arg_tilde(char *envvariable, t_mini *mini,
		char *currpwd, t_parameters *parameters)
{
	envvariable = getenv("HOME");
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
	else
	{
		if (chdir(ft_strjoin(envvariable,
					&parameters->argv[1][1])) != 0)
			perror("Error changing to this directory\n");
		if (mini->prevpwd != NULL)
		{
			free(mini->prevpwd);
			mini->prevpwd = currpwd;
		}
	}
}

// cd to $env_variable
// cater to just $ path
// eg: $Home
// $DOCUMENT
void	execute_cd_arg_env(char *envvariable, t_mini *mini,
		char *currpwd, t_parameters *parameters)
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

// Go back to previous directory or
// default
void	execute_cd_argc2(t_mini *mini, char *currpwd, t_parameters *parameters)
{
	if (parameters->argv[1][0] == '-')
	{
		if (mini->prevpwd != NULL)
		{
			if (chdir(mini->prevpwd) != 0)
				perror("Error changing to this directory\n");
			mini->prevpwd = currpwd;
		}
		else
			perror("Not set yet\n");
	}
	else
	{
		if (chdir(parameters->argv[1]) != 0)
			perror("Error changing to this directory\n");
		perror(parameters->argv[1]);
	}
}

void	execute_cd_argc1(char	*envvariable, t_mini *mini, char *currpwd)
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

// to do error checking 
void	execute_cd(t_parameters *parameters, t_mini *mini)
{
	char	*envvariable;
	char	*currpwd;

	envvariable = NULL;
	currpwd = ft_calloc(1024, sizeof(char));
	currpwd = getcwd(currpwd, 1024);
	// get home directory
	if (parameters->argc == 1)
		execute_cd_argc1(envvariable, mini, currpwd);
	else if (parameters->argc > 2)
		printf("cd: Too many arguments\n");
	else
	{
		if (parameters->argv[1][0] == '$')
			execute_cd_arg_env(envvariable, mini, currpwd, parameters);
		else if (parameters->argv[1][0] == '~')
			execute_cd_arg_tilde(envvariable, mini, currpwd, parameters);
		else
			execute_cd_argc2(mini, currpwd, parameters);
	}
}
