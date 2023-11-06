#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (n > i && (str1[i] || str2[i]))
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((*(unsigned char *)(str1 + i)
				- *(unsigned char *)(str2 + i)));
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*cp;
	size_t	i;

	i = 0;
	cp = (char *)malloc(ft_strlen(src) + 1);
	if (!cp)
		return (NULL);
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	size_t	i;
	size_t	j;

	j_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!j_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		j_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		j_str[i] = s2[j];
		i++;
		j++;
	}
	j_str[i] = '\0';
	return (j_str);
}

void	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	
	printf("found path\n%s\n\n", *envp+5);
	return *envp+5;
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	printf("get  cmd\n");
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		printf("the temp is:\n%s\n", tmp);
		command = ft_strjoin(tmp, cmd);
		printf("the command is:\n%s\n", command);
		free(tmp);
		if (access(command, 0) == 0)
		{
			printf("command found:\n%s\n", command);
			return (command);
		}
		printf("\n\n");
		free(command);
		paths++;
	}
	return (NULL);
}

#include <unistd.h>
#include <stdio.h>
typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;


static size_t	words_count(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		else if (*s == c && i != 0)
		{
			j++;
			i = 0;
		}
		s++;
	}
	if (i != 0)
		j++;
	return (j);
}

static char	*word(char *s, char c)
{
	char	*buf;

	while (*s == c)
		s++;
	buf = s;
	while (*buf && *buf != c)
		buf++;
	*buf = '\0';
	return (ft_strdup(s));
}

static char	**free_arr(char **arr, char *s)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(s);
	return (NULL);
}

static char	**worker(char **arr, char *s1, char c, size_t j)
{
	size_t	i;
	char	*str;

	str = s1;
	i = 0;
	while (i < j)
	{
		if (*s1 != c)
		{
			arr[i] = word(s1, c);
			if (!arr[i])
				return (free_arr(arr, s1));
			s1 = s1 + ft_strlen(arr[i]);
			i++;
		}
		s1++;
	}
	arr[i] = NULL;
	free(str);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**w_arr;
	char	*s1;
	size_t	j;

	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	j = words_count(s1, c);
	w_arr = (char **)malloc(sizeof(char *) * (j + 1));
	if (!w_arr)
		return (NULL);
	return (worker(w_arr, s1, c, j));
}

int main(int argc, char *argv[], char *envp[]) {
    // printf("Number of arguments (argc): %d\n", argc);
    // printf("Program name (argv[0]): %s\n", argv[0]);

    // for (int i = 1; i < argc; i++) {
    //     printf("Argument %d (argv[%d]): %s\n", i, i, argv[i]);
    // }

	t_pipex pipex;

	int e = 0;
	printf("envp:\n");
	while (envp[e])
	{
		printf("%s\n", envp[e]);
		e++;
	}
	printf("end of envp:\n\n");

	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');

	int j = 0;
	while(pipex.cmd_paths[j])
	{
		printf("%s\n", pipex.cmd_paths[j]);
		j++;
	}

	pipex.cmd_args = ft_split(argv[2], ' ');
	// printf("thus:%s\n\n", pipex.cmd_args[0]);
	int i = 0;
	printf("to print cmd arg\n");
	while(pipex.cmd_args[i])
	{
		printf("%s\n", pipex.cmd_args[i]);
		i++;
	}
	printf("end of cmd arg\n\n");

	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);

	printf("cmd:%s\n",pipex.cmd);
	return 0;
}

// finding the bin to execute the arguments
// pipex.cmd = "/bin/ls"
// pipex.cmd_args = ["ls", "-l"]

// execve(pipex.cmd, pipex.cmd_args, envp);
// ./main infile "ls -l" "wc -l" outfile

//piping
// change std 1 to tube
// dup2(pipex[tube1], 1]
// close(pipex[tube0])
// dup2(pipex.infile,0)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, wpid;
    int status;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // This is the child process
        printf("Child process (PID %d) is running.\n", getpid());
        sleep(2); // Simulate some work
        exit(EXIT_SUCCESS);
    } else {
        // This is the parent process
        printf("Parent process (PID %d) waiting for child (PID %d) to finish...\n", getpid(), child_pid);

        // Wait for the child process to finish
        wpid = waitpid(child_pid, &status, 0);

        if (wpid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Child process (PID %d) exited with status %d\n", wpid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process (PID %d) terminated by signal %d\n", wpid, WTERMSIG(status));
        }
    }

    return 0;
}
