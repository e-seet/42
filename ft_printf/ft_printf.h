/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:37:39 by eseet             #+#    #+#             */
/*   Updated: 2023/10/05 18:37:40 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

# ifndef FILE_DESCRIPTOR
#  define FILE_DESCRIPTOR 1
# endif

int		ft_printf(const char *s, ...);

// void	ft_putchar(int c, int fd);
// void	ft_puthex(unsigned int n, int fd);
// void	ft_puthexup(unsigned int n, int fd);
// void	ft_putnbr_fd(int n, int fd);
// void	ft_putptr(void *ptr, int fd);
// void	ft_putunbr(unsigned int n, int fd);
// void	ft_putstr(char *s, int fd);

void	ft_putchar(int c, int *ptrnum);
void	ft_puthex(unsigned int n, int *ptrnum);
void	ft_puthexup(unsigned int n, int *ptrnum);
void	ft_putnbr_fd(int n, int *ptrnum);
void	ft_putptr(void *ptr, int *ptrnum);
void	ft_putunbr(unsigned int n, int *ptrnum);
void	ft_putstr(char *s, int *ptrnum);
void	ft_helper(size_t write_ok, size_t size, int *ptrnum);

#endif
