#include "utils.h"

char	*findprocesspath(char *path, char *paths[],
struct s_pipex pipexstruct, int processnum)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (processnum == 1)
			path = ft_strjoin(path, pipexstruct.argvs1[0]);
		else if (processnum == 2)
			path = ft_strjoin(path, pipexstruct.argvs2[0]);
		else
			path = ft_strjoin(path, pipexstruct.argvs3[0]);
		if (access(path, F_OK) == 0)
		{
			break ;
		}
		free (path);
		path = NULL;
		i++;
	}
	if (access(path, F_OK) == 0)
		return (path);
	else
		return (NULL);
}

int	p3child(char *paths[], char *path, char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	path = findprocesspath(path, paths, pipexstruct, 3);
	if (access(path, F_OK) != 0)
	{
		perror("command not found");
		return (1);
	}
	execveresult = execve(path, pipexstruct.argvs3, envp);
	if (execveresult == -1)
		perror("smth wrong with executing. Terminate now");
	free(path);
	return (0);
}

char	*findpath(char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			path = envp[i];
			break ;
		}
		i++;
	}
	if (ft_strncmp("PATH=", path, 5) == 0)
		return (path);
	else
		return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	struct s_pipex	pipexstruct;
	char			*path;
	char			**paths;
	int				temp;

	path = findpath(envp);
	paths = ft_split(path + 5, ':');
	if (pipe(pipexstruct.fdpipe1) == -1 || pipe(pipexstruct.fdpipe2) == -1)
		return (1);
	setstructure(argc, argv, &pipexstruct);
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		temp = heredoccmd(&pipexstruct, argv);
		if (temp == 0)
		{
			pipexstruct.heredocreadfd = open("heredoctemp.txt", O_RDONLY);
			if (pipexstruct.heredocreadfd == -1)
			{
				printf("heredocreadfd opened with error\n");
				exit(1);
			}
			else
				printf("no error\n");
		}
		else
			perror("heredoccmd failed. Nothing inside\n");
	}
	while (pipexstruct.argc - 1 > pipexstruct.curr)
	{
		pipexstruct.argvs3 = ft_split(argv[pipexstruct.curr], ' ');
		if (pipexstruct.curr != 3 && pipexstruct.curr % 2 == 1)
		{
			if (pipe(pipexstruct.fdpipe1) == -1)
				return (1);
		}
		else if (pipexstruct.curr != 4 && pipexstruct.curr % 2 == 0)
		{
			if (pipe(pipexstruct.fdpipe2) == -1)
				return (1);
		}
		pipexstruct.pid3 = fork();
		if (pipexstruct.pid3 == 0)
		{
			if (pipexstruct.curr == 3)
			{
				dup2(pipexstruct.p1fd, 0);
				dup2(pipexstruct.fdpipe1[1], 1);
			}
			else if (pipexstruct.argc - 2 == pipexstruct.curr)
			{
				dup2(pipexstruct.fdpipe2[0], 0);
				dup2(pipexstruct.p2fd, 1);
			}
			else if (pipexstruct.curr % 2 == 0)
			{
				dup2(pipexstruct.fdpipe1[0], 0);
				dup2(pipexstruct.fdpipe2[1], 1);
			}
			else if (pipexstruct.curr % 2 == 1)
			{
				dup2(pipexstruct.fdpipe2[0], 0);
				dup2(pipexstruct.fdpipe1[1], 1);
			}
			if (p3child(paths, path, envp, pipexstruct) == 1)
			{
				printf("error: 1, exiting\n");
				exit(1);
			}
		}
		else
		{
			if (pipexstruct.curr % 2 == 1)
				close(pipexstruct.fdpipe1[1]);
			else if (pipexstruct.curr % 2 == 0)
				close(pipexstruct.fdpipe2[1]);
			else
				exit(1);
			waitpid(pipexstruct.pid3, NULL, 0);
		}
		pipexstruct.curr += 1;
	}
	return (0);
}

//  ./pipex "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file"
