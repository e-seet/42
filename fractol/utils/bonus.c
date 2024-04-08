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
