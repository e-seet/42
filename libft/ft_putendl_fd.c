/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:16:02 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 19:16:03 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: The string to output.
// fd: The file descriptor on which to write
// Outputs the string ’s’ to the given file descriptor
// followed by a newline.
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
