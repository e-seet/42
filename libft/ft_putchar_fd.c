/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:55:26 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 18:55:27 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parameter
// c: The character to output.
// fd: The file descriptor on which to write.

// Description
// Outputs the character ’c’ to the given file descriptor.
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
