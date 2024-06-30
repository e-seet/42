#include "../utils.h"

void	execution_cd_success(t_mini *mini, char *currpwd)
{
	mini->exit_status = 0;
	if (mini->prevpwd != NULL)
		free(mini->prevpwd);
	mini->prevpwd = currpwd;
}

// case 1 if: ~
// case 2 else: ~/smth
void	execute_cd_arg_tilde(char *envvariable, t_mini *mini,
		char *currpwd, t_parameters *parameters)
{
	envvariable = getenv("HOME");
	if (ft_strlen(parameters->argv[1]) == 1)
	{
		if (chdir(envvariable) != 0)
		{
			perror("Error changing to this directory\n");
			mini->exit_status = 2;
		}
		else
			execution_cd_success(mini, currpwd);
	}
	else
	{
		if (chdir(ft_strjoin(envvariable,
					&parameters->argv[1][1])) != 0)
		{
			perror("Error changing to this directory\n");
			mini->exit_status = 2;
		}
		else
			execution_cd_success(mini, currpwd);
	}
}

// cd to $env_variable
// cater to just $ path
// eg: $Home
// $DOCUMENT
// this may not be used as i have changed from env to path
void	execute_cd_arg_env(char *envvariable, t_mini *mini,
		char *currpwd, t_parameters *parameters)
{
	envvariable = getenv(&parameters->argv[1][1]);
	if (envvariable == NULL)
	{
		perror("env variable not set");
		mini->exit_status = 1;
	}
	else
	{
		if (chdir(envvariable) != 0)
		{
			perror("Error changing to this directory\n");
			mini->exit_status = 2;
		}
		else
			execution_cd_success(mini, currpwd);
	}
}

// Go back to previous directory or
// move to the argument location
// default
void	execute_cd_argc2(t_mini *mini, char *currpwd, t_parameters *parameters)
{
	if (parameters->argv[1][0] == '-')
	{
		if (mini->prevpwd != NULL)
		{
			if (chdir(mini->prevpwd) != 0)
			{
				perror("Error changing to this directory\n");
				mini->exit_status = 2;
			}
			else
				execution_cd_success(mini, currpwd);
		}
		else
		{
			perror("No previous directory\n");
			mini->exit_status = 2;
		}
	}
	else
	{
		if (chdir(parameters->argv[1]) != 0)
		{
			perror("Error changing to this directory\n");
			mini->exit_status = 2;
		}
		else
			execution_cd_success(mini, currpwd);
	}
}

// only 1 argc so it is just: "cd"
// get home directory
void	execute_cd_argc1(char	*envvariable, t_mini *mini, char *currpwd)
{
	envvariable = getenv("HOME");
	if (chdir(envvariable) != 0)
	{
		perror("Error changing to this directory\n");
		mini->exit_status = 2;
	}
	else
		execution_cd_success(mini, currpwd);
}

// to do error checking 
void	execute_cd(t_parameters *parameters, t_mini *mini)
{
	char	*envvariable;
	char	*currpwd;

	envvariable = NULL;
	currpwd = ft_calloc(1024, sizeof(char));
	currpwd = getcwd(currpwd, 1024);
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
