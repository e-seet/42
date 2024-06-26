#include "utils.h"

int ft_breakspace(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len --)
	{
		if (str[len] == ' ')
		{
			break;
		}
	}
	return len;
}

void updateenvvariable_set(t_mini *mini, char *str)
{
	// To do
	// export MY_VAR="HELLO"
	char **strs2 = ft_split(str, ' '); // MY_VAR="HELLO"
	// strs2[1] this is what we want to update
	char **newenvp;
	newenvp = ft_calloc(mini->envplen+1, sizeof(char *));
	int i = 0;
	// let it finish copying
	// to double check
	while (mini->envplen > i)
	{
		newenvp[i] = ft_calloc(ft_strlen(mini->envp[i]), sizeof(char));
		ft_strlcpy(newenvp[i], mini->envp[i], ft_strlen(mini->envp[i]));
		free(mini->envp[i]);
		i++;
	}
	newenvp[i] = ft_calloc(ft_strlen(strs2[1]), sizeof(char));
	ft_strlcpy(newenvp[i], strs2[1], ft_strlen(strs2[1]));
	// add on the number
	mini->envplen = 	mini->envplen + 1;
	mini->envp = newenvp;

}
// to update the current minishell->envp
// will need to reallocate memory space for this.
void updateenvvariable_unset(t_mini *mini, char **strs)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char  **splits;
	char  **newenvp;


	while (mini->envplen > i)
	{
		// split all of them.
		splits = ft_split(mini->envp[i], '=');
		j = 0;
		if ( ft_strncmp(splits[0], strs[1], ft_strlen(strs[1])) == 0)
		{
			// found what i want
			// to create new and replace existing

			newenvp = ft_calloc(mini->envplen-1, sizeof(char *));

			// copy first haf 
			while (i > k)
			{
				newenvp[k] = ft_calloc(ft_strlen(mini->envp[k]), sizeof(char));
				ft_strlcpy(newenvp[k], mini->envp[k], ft_strlen(mini->envp[k]));
				free(mini->envp[k]);
				k++;
			}
			// free this particular 1 that we dont want
			free(mini->envp[k]);
			// continue the op with newenvp being k and minishell data being k + 1
			while (mini->envplen > k)
			{
				newenvp[k] = ft_calloc(ft_strlen(mini->envp[k+1]), sizeof(char));
				ft_strlcpy(newenvp[k], mini->envp[k+1], ft_strlen(mini->envp[k+1]));
				free(mini->envp[k+1]);
				k++;
			}
			mini->envplen = 	mini->envplen - 1;
			mini->envp = newenvp;
			break;
		}
		else
		{
			// free the space
			while (splits[j])
			{
				free(splits[j]);
				j++;
			}
		}
		i++;
	}
}


// // dont over write if it exist 
// // setenv("MY_VARIABLE", "Hello, World!", 0);
// // over write if it exist. BASH DOES THIS
// setenv("MY_VARIABLE", strs[1], 1);

// sample
// export MY_VAR="Hello"
void exportstr(t_parameters *parameters, t_mini *mini)
{
	char **strs;
	char *name;
	strs = ft_split(str, '=');

	// dont over write if it exist 
	// setenv("MY_VARIABLE", "Hello, World!", 0);
	// over write if it exist. BASH DOES THIS
	// setenv("MY_VARIABLE", strs[1], 1);

	name = ft_calloc(ft_strlen(strs[0]) - ft_breakspace(strs[0]) + 1,sizeof(char));
	ft_strlcpy(name, &str[ft_breakspace(strs[0])], ft_strlen(strs[0]) - ft_breakspace(strs[0]));

	// key, value
	// we not setting. 
	// just store in mini
	// setenv(name, strs[1], 1);
	
	free(name);
	free(strs);
	updateenvvariable_set(mini, str);
}

// unset MY_VAR
void unsetmyenv(char *str, t_mini *mini)
{
	char **strs;

	strs = ft_split(str, ' ');
	unsetenv(strs[1]);

	// update my minishell pointer
	updateenvvariable_unset(mini, strs);
}

void envvariables(t_mini *mini, char *envp[])
{
	int temp = 0;
	int i  = mini->envplen;

	while (i > temp)
	{
		mini->envp[temp] = ft_calloc( ft_strlen(envp[temp]) + 10 , sizeof(char));
		
		// printf("original:%s\n", envp[temp]);
		
		ft_strlcpy(mini->envp[temp], envp[temp], ft_strlen(envp[temp]) + 1 );
		// printf("%s\n", envp[i]);
		// printf("%d", temp);

		// printf("%s\n", mini->envp[temp]);
		temp ++;
	}

}