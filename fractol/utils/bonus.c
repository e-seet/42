/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:17:26 by eseet             #+#    #+#             */
/*   Updated: 2024/04/08 17:17:27 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	render_burning_ship(int x, int y, t_fractal *fractal)
{
	double			temp;
	t_complex_num	c;
	t_complex_num	z;

	c.x = fractal->cx + (((x - fractal->width / 2.0) * 4.0) / fractal->width)
		* fractal->zoom + fractal->xshift;
	c.y = fractal->cy + (((y - fractal->height / 2.0) * 3.0) / fractal->height)
		* fractal->zoom + fractal->yshift;
	z.x = 0;
	z.y = 0;
	fractal->iter = 0;
	while (z.x * z.x + z.y * z.y < 4 && fractal->iter < fractal->iteration)
	{
		temp = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2 * z.x * z.y) + c.y;
		z.x = fabs(temp);
		fractal->iter = fractal->iter + 1;
	}
	paintpixel(x, y, &fractal->img, map(fractal->iter, fractal));
}

void	putstrings2(t_fractal *fractal)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = (char *) ft_calloc(10, sizeof(char));
	str2 = (char *) ft_calloc (10, sizeof(char));
	str3 = (char *) ft_calloc (10, sizeof(char));
	str4 = (char *) ft_calloc (10, sizeof(char));
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
	putstrings2(fractal);
}
