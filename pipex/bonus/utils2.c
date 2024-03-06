#include "utils2.h"

int	checkforheredoc(char *argv[], struct s_pipex *pipexstruct)
{
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		if (heredoccmd(pipexstruct) == 0)
		{
			pipexstruct->curr = 3 ;
			pipexstruct->opened = 3 ;
			pipexstruct->heredocreadfd = open("heredoctemp.txt", O_RDONLY);
			if (pipexstruct->heredocreadfd == -1)
			{
				perror("heredocreadfd opened with error\n");
				return (1);
			}
		}
		else
		{
			perror("heredoccmd failed. Nothing inside\n");
			return (1);
		}
	}
	return (0);
}

int	p3child(char *envp[], struct s_pipex pipexstruct)
{
	int		execveresult;

	pipexstruct.path = findprocesspath(pipexstruct);
	if (access(pipexstruct.path, F_OK) != 0)
	{
		perror("command not found");
		return (-1);
	}
	execveresult = execve(pipexstruct.path, pipexstruct.argvs3, envp);
	if (execveresult == -1)
		perror("smth wrong with executing. Terminate now");
	free(pipexstruct.path);
	return (0);
}
