/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:37:25 by eseet             #+#    #+#             */
/*   Updated: 2023/10/05 18:37:25 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

// int	ft_putchar(int c);
// void	ft_puthex(unsigned int n);
// void	ft_puthexup(unsigned int n);
// void	ft_putnbr_fd(int n);
// void	ft_putptr(void *ptr);
// void	ft_putunbr(unsigned int n);
// void	ft_putstr(char *s);

void	ft_putchar(int c, int *ptrnum);
void	ft_puthex(unsigned int n, int *ptrnum);
void	ft_puthexup(unsigned int n, int *ptrnum);
void	ft_putnbr_fd(int n, int *ptrnum);
void	ft_putptr(void *ptr, int *ptrnum);
void	ft_putunbr(unsigned int n, int *ptrnum);
void	ft_putstr(char *s, int *ptrnum);
void	ft_helper(size_t write_ok, size_t size, int *num);

#endif
