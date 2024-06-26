
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

void updateenvvariable_set(struct s_minishell *t_minishell, char *str)
{
	// To do
	// export MY_VAR="HELLO"
	char **strs2 = ft_split(str, ' '); // MY_VAR="HELLO"
	// strs2[1] this is what we want to update
	char **newenvp;
	newenvp = ft_calloc(t_minishell->envplen+1, sizeof(char *));
	int i = 0;
	// let it finish copying
	// to double check
	while (t_minishell->envplen > i)
	{
		newenvp[i] = ft_calloc(ft_strlen(t_minishell->envp[i]), sizeof(char));
		ft_strlcpy(newenvp[i], t_minishell->envp[i], ft_strlen(t_minishell->envp[i]));
		free(t_minishell->envp[i]);
		i++;
	}
	newenvp[i] = ft_calloc(ft_strlen(strs2[1]), sizeof(char));
	ft_strlcpy(newenvp[i], strs2[1], ft_strlen(strs2[1]));
	// add on the number
	t_minishell->envplen = 	t_minishell->envplen + 1;
	t_minishell->envp = newenvp;

}
// to update the current minishell->envp
// will need to reallocate memory space for this.
void updateenvvariable_unset(struct s_minishell *t_minishell, char **strs)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char  **splits;
	char  **newenvp;


	while (t_minishell->envplen > i)
	{
		// split all of them.
		splits = ft_split(t_minishell->envp[i], '=');
		j = 0;
		if ( ft_strncmp(splits[0], strs[1], ft_strlen(strs[1])) == 0)
		{
			// found what i want
			// to create new and replace existing

			newenvp = ft_calloc(t_minishell->envplen-1, sizeof(char *));

			// copy first haf 
			while (i > k)
			{
				newenvp[k] = ft_calloc(ft_strlen(t_minishell->envp[k]), sizeof(char));
				ft_strlcpy(newenvp[k], t_minishell->envp[k], ft_strlen(t_minishell->envp[k]));
				free(t_minishell->envp[k]);
				k++;
			}
			// free this particular 1 that we dont want
			free(t_minishell->envp[k]);
			// continue the op with newenvp being k and minishell data being k + 1
			while (t_minishell->envplen > k)
			{
				newenvp[k] = ft_calloc(ft_strlen(t_minishell->envp[k+1]), sizeof(char));
				ft_strlcpy(newenvp[k], t_minishell->envp[k+1], ft_strlen(t_minishell->envp[k+1]));
				free(t_minishell->envp[k+1]);
				k++;
			}
			t_minishell->envplen = 	t_minishell->envplen - 1;
			t_minishell->envp = newenvp;
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
void exportstr(char *str, struct s_minishell *t_minishell)
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
	setenv(name, strs[1], 1);
	
	free(name);
	free(strs);
	updateenvvariable_set(t_minishell, str);
}

// unset MY_VAR
void unsetmyenv(char *str, struct s_minishell *t_minishell)
{
	char **strs;

	strs = ft_split(str, ' ');
	unsetenv(strs[1]);

	// update my minishell pointer
	updateenvvariable_unset(t_minishell, strs);
}

void envvariables(struct s_minishell *t_minishell, char *envp[])
{
	int temp = 0;
	int i  = t_minishell->envplen;

	while (i > temp)
	{
		t_minishell->envp[temp] = ft_calloc( ft_strlen(envp[temp]) + 10 , sizeof(char));
		
		// printf("original:%s\n", envp[temp]);
		
		ft_strlcpy(t_minishell->envp[temp], envp[temp], ft_strlen(envp[temp]) + 1 );
		// printf("%s\n", envp[i]);
		// printf("%d", temp);

		// printf("%s\n", t_minishell->envp[temp]);
		temp ++;
	}

}