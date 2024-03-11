#include "utils2.h"

void	freestuff2(struct s_pipex *pipexstruct)
{
	int	i;

	i = 0;
	while (pipexstruct->argvs1 && pipexstruct->argvs1[i])
	{
		free(pipexstruct->argvs1[i]);
		pipexstruct->argvs1[i] = NULL;
		i++;
	}
	free(pipexstruct->argvs1);
	pipexstruct->argvs1 = NULL;
	i = 0;
	while (pipexstruct->argvs2 && pipexstruct->argvs2[i])
	{
		free(pipexstruct->argvs2[i]);
		pipexstruct->argvs2[i] = NULL;
		i++;
	}
	free(pipexstruct->argvs2);
	pipexstruct->argvs2 = NULL;
}
