/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:18:38 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 19:18:39 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// n: The integer to output.
// fd: The file descriptor on which to write.

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = n * -1;
	}
	else
		num = n;
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd(num % 10 + '0', fd);
}
// void	ft_putnbr_fd(int n, int fd)
// {
// 	char *str;
// 	int len;

// 	str = ft_itoa(n);
// 	len = ft_strlen(str);
// 	write(fd, ft_itoa(n), len);
// }

// int main(void)
// {
// 	ft_putnbr_fd(123, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-123, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(0, 1);
// 	return (0);
// }
