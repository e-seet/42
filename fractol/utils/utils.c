#include "utils.h"

// Function to map iteration count to a color
unsigned int	map(int iter, t_fractal *fractal)
{
	if (iter == fractal->iteration)
		return (0x000000);
	return (0xFFFFFF / iter);
}

void	paintpixel(int x, int y, t_data *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void	setupvariables(t_complex_num *c, t_complex_num *z, t_fractal *fractal,
	t_complex_num *temp)
{
	if (ft_strncmp("julia", fractal->name, 5) == 0)
	{
		z->x = (scale(temp->x, -2, +2, fractal->width)
				* fractal->zoom) + fractal -> xshift;
		z->y = (scale(temp->y, 2, -2, fractal->height)
				* fractal->zoom) + fractal -> yshift;
		c->x = fractal->cx;
		c->y = fractal->cy;
	}
	else
	{
		z->x = 0;
		z->y = 0;
		c->x = (scale(temp->x, -2, +2, fractal->width) * fractal->zoom)
			+ fractal->xshift;
		c->y = (scale(temp->y, 2, -2, fractal->height) * fractal->zoom)
			+ fractal->yshift;
	}
}

// c is the actual starting point
// z is the calculated points
void	handlecalculations(int x, int y, t_fractal *fractal)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;
	int				color;
	t_complex_num	temp;

	temp.x = x;
	temp.y = y;
	i = 0;
	setupvariables(&c, &z, fractal, &temp);
	while (fractal->iteration > i)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_val)
		{
			color = scale(i, BLACK, WHITE, fractal->iteration);
			paintpixel(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	paintpixel(x, y, &fractal->img, WHITE);
}

void	renderfractal(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fractal->height)
	{
		x = -1;
		while (++x < fractal->width)
		{
			if (ft_strncmp(fractal->name, "burningship", 11) == 0)
				render_burning_ship(x, y, fractal);
			else
				handlecalculations(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_instance, fractal->mlx_win,
		fractal->img.img, 0, 0);
	putstrings(fractal);
}
