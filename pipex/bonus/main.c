/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:25:43 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:25:43 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
// #include "utils2.h"

void	dup2child2(struct s_pipex *pipexstruct)
{
	if (pipexstruct->curr % 2 == 1)
	{
		if (pipexstruct->opened == 2 && pipexstruct->curr == 3)
			dup2(pipexstruct->fdpipe0[0], 0);
		else
			dup2(pipexstruct->fdpipe2[0], 0);
		dup2(pipexstruct->fdpipe1[1], 1);
	}
	else if (pipexstruct->curr % 2 == 0)
	{
		dup2(pipexstruct->fdpipe1[0], 0);
		dup2(pipexstruct->fdpipe2[1], 1);
	}
}

void	dup2child( struct s_pipex *pipexstruct)
{
	if (pipexstruct->curr == pipexstruct->opened)
	{
		dup2(pipexstruct->p1fd, 0);
		if (pipexstruct->curr == 2)
			dup2(pipexstruct->fdpipe0[1], 1);
		else
			dup2(pipexstruct->fdpipe1[1], 1);
	}
	else if (pipexstruct->argc - 2 == pipexstruct->curr)
	{
		if (pipexstruct->curr % 2 == 1)
		{
			dup2(pipexstruct->fdpipe2[0], 0);
			if (pipexstruct->opened == 2 && pipexstruct->curr == 3)
				dup2(pipexstruct->fdpipe0[0], 0);
		}
		else
			dup2(pipexstruct->fdpipe1[0], 0);
		dup2(pipexstruct->p2fd, 1);
	}
	else
	{
		dup2child2(pipexstruct);
	}
}

int	setuppipe(struct s_pipex *pipexstruct)
{
	if (pipexstruct->curr == 2)
	{
		if (pipe(pipexstruct->fdpipe0) == -1)
			return (1);
	}
	else if (pipexstruct->curr % 2 == 1)
	{
		if (pipe(pipexstruct->fdpipe1) == -1)
			return (1);
	}
	else if (pipexstruct->curr % 2 == 0)
		if (pipe(pipexstruct->fdpipe2) == -1)
			return (1);
	return (0);
}

int	refactormain(struct s_pipex pipexstruct, char *envp[], char *argv[])
{
	pipexstruct.argvs3 = ft_split(argv[pipexstruct.curr], ' ');
	pipexstruct.pid3 = fork();
	if (pipexstruct.pid3 == 0)
	{
		dup2child(&pipexstruct);
		if (p3child(envp, pipexstruct) == 1)
			exit(1);
	}
	else
	{
		if (pipexstruct.opened == 2 && pipexstruct.curr == 2)
			close(pipexstruct.fdpipe0[1]);
		if (pipexstruct.curr % 2 == 1)
			close(pipexstruct.fdpipe1[1]);
		else if (pipexstruct.curr % 2 == 0)
			close(pipexstruct.fdpipe2[1]);
		else
			exit(1);
		waitpid(pipexstruct.pid3, NULL, 0);
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	struct s_pipex	pipexstruct;

	setstructure(argc, argv, &pipexstruct, envp);
	if (checkforheredoc(argv, &pipexstruct) == 1)
		return (1);
	while (pipexstruct.argc - 1 > pipexstruct.curr)
	{
		if (setuppipe(&pipexstruct) == 1)
			return (1);
		if (refactormain(pipexstruct, envp, argv) == 1)
			return (1);
		pipexstruct.curr = pipexstruct.curr +1;
	}
	return (0);
}
