/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:25:53 by eseet             #+#    #+#             */
/*   Updated: 2024/03/07 16:25:54 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_H
# define UTILS2_H

# include "utils.h"

int		p3child(char *envp[], struct s_pipex pipexstruct);

int		checkforheredoc(char *argv[], struct s_pipex *pipexstruct);

#endif
