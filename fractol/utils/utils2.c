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

char	*ft_itoadouble_int2(double *num, int *z, int *i)
{
	int		sign;
	double	num2;
	char	*str;

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
	str = (char *) malloc (sizeof(char) * (*i + 17 + 1 + 1));
	if (!str)
		return (NULL);
	if (sign == 1)
		str[*z] = '+';
	else
		str[*z] = '-';
	return (str);
}

// str size = int number  + null + sign +deci point + decimal numbers
char	*ft_itoadouble_int(double *num, int *z, int *i)
{
	char	*str;

	str = ft_itoadouble_int2(num, z, i);
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
	return (str);
}

char	*ft_itoadouble2(double num, char *str, int z, int i)
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
	return (str);
}

// size i = integer + range of decimal (17) + 1 null terminator
// convert a double to str with 2 dp.
char	*ft_itoadouble(double num)
{
	int		i;
	char	*str;
	int		z;

	i = 0;
	z = 0;
	str = NULL;
	str = ft_itoadouble_int(&num, &z, &i);
	i = z;
	str = ft_itoadouble2(num, str, z, i);
	return (str);
}

void	putstrings(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		5, 20, COLOR_SILVER, "xshift:	");

	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		5, 30, COLOR_SILVER, "yshift:	");
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		5, 50, COLOR_SILVER, "iteration:	");
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		5, 40, COLOR_SILVER, "zoom:	");

	char *str1;
	str1 = ft_itoadouble(fractal->xshift);
	// the following causes memory leak. Very nice!
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		80, 20, COLOR_SILVER, str1);
	free(str1);
	// mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
	// 	80, 30, COLOR_SILVER, ft_itoadouble(fractal->yshift));
	// mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
	// 	80, 40, COLOR_SILVER, ft_itoadouble(fractal->zoom));

	// mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
	// 	80, 50, COLOR_SILVER, ft_itoa(fractal->iteration));
}
