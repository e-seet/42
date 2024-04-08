/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:18:19 by eseet             #+#    #+#             */
/*   Updated: 2024/04/08 17:18:20 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_itoadouble_int2(double *num, int *z, int *i, char *str)
{
	int		sign;
	double	num2;

	num2 = *num;
	sign = 1;
	if (0 > *num)
	{
		sign = -1;
		*num = sign * *num;
	}
	num2 = *num;
	while (num2 >= 1)
	{
		num2 = num2 / 10;
		*i = *i + 1;
	}
	if (sign == 1)
		str[*z] = '+';
	else
		str[*z] = '-';
}

// str size = int number  + null + sign +deci point + decimal numbers
void	ft_itoadouble_int(double *num, int *z, int *i, char *str)
{
	ft_itoadouble_int2(num, z, i, str);
	*z = *z + 1;
	if (*num < 1)
	{
		str[*z] = '0';
		*z = *z + 1;
	}
	else
	{
		while (*num >= 1)
		{
			str[*z] = ((int) *num % 10) + '0';
			*num = *num - (int)*num % 10;
			*num = *num / 10;
			*z = *z + 1;
		}
		*num = *num * 10;
	}
	str[*z] = '.';
	*z = *z + 1;
}

void	ft_itoadouble2(double num, char *str, int z, int i)
{
	int		digit;

	while (2 + i > z)
	{
		digit = 0;
		if (num < 1)
		{
			z = z + 1;
			z = z + 1;
			digit = (int)(num * 10 * 10);
			str[z - 1] = digit % 10 + '0';
			str[z - 2] = ((digit / 10) % 10) + '0';
		}
		else
		{
			digit = (int)(num) % 10;
			str[z] = '0' + digit;
			num = num - digit % 10;
		}
		z ++;
	}
}

// size i = integer + range of decimal (17) + 1 null terminator
// convert a double to str with 2 dp.
void	ft_itoadouble(double num, char *str)
{
	int		i;
	int		z;
	int		n;

	i = 0;
	z = 0;
	n = 0;
	ft_itoadouble_int(&num, &z, &i, str);
	i = z;
	ft_itoadouble2(num, str, z, i);
	while (str[n])
	{
		if ((str[n] >= '0' && str[n] <= '9') || str[n] == '.')
			n++;
		else
		{
			str[n] = '\0';
			break ;
		}
	}
}

void	putstrings(t_fractal *fractal)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = (char *) malloc (sizeof(char) * (32));
	str2 = (char *) malloc (sizeof(char) * (32));
	str3 = (char *) malloc (sizeof(char) * (32));
	str4 = (char *) malloc (sizeof(char) * (32));
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		5, 20, COLOR_SILVER, "xshift:	");
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		5, 30, COLOR_SILVER, "yshift:	");
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		5, 50, COLOR_SILVER, "iteration:	");
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		5, 40, COLOR_SILVER, "zoom:	");
	ft_itoadouble(fractal->xshift, str1);
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		80, 20, COLOR_SILVER, str1);
	free(str1);
	ft_itoadouble(fractal->yshift, str2);
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		80, 30, COLOR_SILVER, str2);
	free(str2);
	ft_itoadouble(fractal->zoom, str3);
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		80, 40, COLOR_SILVER, str3);
	free(str3);
	ft_itoadouble(fractal->iteration, str4);
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		80, 50, COLOR_SILVER, str4);
	free(str4);
}
