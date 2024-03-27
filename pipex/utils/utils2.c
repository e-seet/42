/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:59:15 by eseet             #+#    #+#             */
/*   Updated: 2024/03/19 17:59:15 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
void	freestuff3(struct s_pipex *pipexstruct)
{
	int	i;

	i = 0;
	while (pipexstruct->paths && pipexstruct->paths[i])
	{
		free(pipexstruct->paths[i]);
		pipexstruct->paths[i] = NULL;
		i++;
	}
	free(pipexstruct->paths);
	pipexstruct->paths = NULL;	
}
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
