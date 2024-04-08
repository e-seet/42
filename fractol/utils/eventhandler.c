/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:17:42 by eseet             #+#    #+#             */
/*   Updated: 2024/04/08 17:17:42 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	resetback(t_fractal *fractal)
{
	fractal->escape_val = 4;
	fractal->iteration = 50;
	fractal->iter = 0;
	fractal->xshift = 0;
	fractal->yshift = 0;
	fractal->zoom = 1;
}
// fractal->zoom = 300;

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_instance, fractal->img.img);
	mlx_destroy_window(fractal->mlx_instance, fractal->mlx_win);
	free(fractal->mlx_instance);
	exit(0);
}
//ubuntu
// int	close_handler(t_fractal *fractal)
// {
// 	mlx_destroy_image(fractal->mlx_instance, fractal->img.img);
// 	mlx_destroy_window(fractal->mlx_instance, fractal->mlx_win);
// 	// mlx_destroy_display(fractal->mlx_instance); //missing in macos
// 	free(fractal->mlx_instance);
// 	exit(0);
// }

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->cx = (scale(x, -2, +2, fractal->width)
				* fractal->zoom) + fractal->xshift;
		fractal->cy = (scale(y, +2, -2, fractal->height)
				* fractal->zoom) + fractal->yshift;
		renderfractal(fractal);
	}
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void) x;
	(void) y;
	if (button == 5)
		fractal->zoom = fractal->zoom * 1.05;
	else if (button == 4)
		fractal->zoom = fractal->zoom * 0.95;
	renderfractal(fractal);
	return (0);
}

// int (* f) (int keycode, void *param)
int	key_handler(int keyval, t_fractal *fractal)
{
	if (keyval == 53 || keyval == 65307)
		close_handler(fractal);
	else if (keyval == 126 || keyval == 65362)
		fractal -> yshift -= 0.5 * fractal->zoom;
	else if (keyval == 125 || keyval == 65364)
		fractal -> yshift += 0.5 * fractal->zoom;
	else if (keyval == 123 || keyval == 65361)
		fractal -> xshift += 0.5 * fractal->zoom;
	else if (keyval == 124 || keyval == 65363)
		fractal -> xshift -= 0.5 * fractal->zoom;
	else if (keyval == 24 || keyval == 61)
		fractal -> iteration += 1;
	else if (keyval == 27 || keyval == 45)
		fractal -> iteration -= 1;
	else if (keyval == 15 || keyval == 114)
		resetback(fractal);
	renderfractal(fractal);
	return (0);
}
