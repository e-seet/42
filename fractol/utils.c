#include "utils.h"

void	resetback(t_fractal *fractal)
{
	fractal->escape_val = 4;
	fractal->iteration = 25;
	fractal->iter = 0;
	fractal->xshift = 0;
	fractal->yshift = 0;
	fractal->zoom = 1;
}

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
	printf("button:%d x:%d, y:%d\n", button, x, y);
	if (button == 5)
	{
		printf("down");
		fractal->zoom = fractal->zoom * 1.05;
	}
	else if (button == 4)
	{
		printf("up");
		fractal->zoom = fractal->zoom * 0.95;
	}
	renderfractal(fractal);
	return (0);
}

// int (* f) (int keycode, void *param)
int	key_handler(int keyval, t_fractal *fractal)
{
	printf("%d %p\n", keyval, fractal);
	if (keyval == 53)
		close_handler(fractal);
	else if (keyval == 126)
		fractal -> yshift -= 0.5 * fractal->zoom;
	else if (keyval == 125)
		fractal -> yshift += 0.5 * fractal->zoom;
	else if (keyval == 123)
		fractal -> xshift += 0.5 * fractal->zoom;
	else if (keyval == 124)
		fractal -> xshift -= 0.5 * fractal->zoom;
	else if (keyval == 24)
		fractal -> iteration += 1;
	else if (keyval == 27)
		fractal -> iteration -= 1;
	else if (keyval == 15)
		resetback(fractal);
	renderfractal(fractal);
	return (0);
}

// change the mask from 0 back to mask. 
// TO DO! TAKE note
// mac version uses 0 as it does not matter
void	events_init(t_fractal *fractal)
{
	mlx_hook(
		fractal->mlx_win,
		KeyPress,
		0,
		key_handler,
		fractal
		);
	mlx_hook(fractal->mlx_win,
		ButtonPress,
		0,
		mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_win,
		DestroyNotify,
		0,
		close_handler,
		fractal);
	mlx_hook(fractal->mlx_win,
		MotionNotify,
		0,
		julia_track,
		fractal);
}
// ubuntu ver
// void	events_init(t_fractal *fractal)
// {
// 	mlx_hook(
// 		fractal->mlx_win,
// 		KeyPress,
// 		0,
// 		// KeyPressMask,
// 		key_handler,
// 		fractal
// 	);

// 	mlx_hook(fractal->mlx_win,
// 			ButtonPress,
// 			0,
// 			// ButtonPressMask,
// 			mouse_handler,
// 			fractal);

// 	// // destroy the window
// 	mlx_hook(fractal->mlx_win,
// 			DestroyNotify,
// 			0,
// 			// StructureNotifyMask,
// 			close_handler,
// 			fractal);

// 	// tracking for julia
// 		mlx_hook(fractal->mlx_win,
// 			MotionNotify,
// 			0,
// 			// PointerMotionMask,
// 			julia_track,
// 			fractal);
// }

double	scale(double unscaled_num, double new_min, double new_max,
	double old_max)
{
	double	old_min;
	double	newscale;
	double	oldscale;
	double	number;

	old_min = 0;
	newscale = new_max - new_min;
	oldscale = old_max - old_min;
	number = unscaled_num - old_min;
	return ((newscale * (number / oldscale)) + new_min);
}

t_complex_num	square_complex(t_complex_num z)
{
	t_complex_num	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_complex_num	sum_complex(t_complex_num z1, t_complex_num z2)
{
	t_complex_num	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

void	paintpixel(int x, int y, t_data *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void	cleanup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_instance, fractal->img.img);
	free(fractal->img.img);
	fractal->img.img = NULL;
	mlx_destroy_window(fractal->mlx_instance, fractal->mlx_win);
	free(fractal->mlx_win);
	fractal->mlx_win = NULL;
	free(fractal->mlx_instance);
	fractal->mlx_instance = NULL;
}

void	setup(t_fractal *fractal)
{
	fractal->mlx_instance = mlx_init();
	if (fractal->mlx_instance == NULL)
		return ;
	fractal->mlx_win = mlx_new_window(fractal->mlx_instance,
			fractal->width, fractal->height, fractal->name);
	if (fractal->mlx_win == NULL)
		cleanup(fractal);
	fractal->img.img = mlx_new_image(fractal->mlx_instance,
			fractal->width, fractal->height);
	if (fractal->img.img == NULL)
		cleanup(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
	resetback(fractal);
	events_init(fractal);
}
//ubuntu
// void	setup(t_fractal *fractal)
// {
// 	fractal->mlx_instance = mlx_init();
// 	if (fractal->mlx_instance == NULL)
// 	{
// 		printf("mlx isntance is null\n");
// 	}
// 	fractal->mlx_win = mlx_new_window(fractal->mlx_instance,
// 			fractal->width, fractal->height, fractal->name);
// 	if (fractal->mlx_win == NULL)
// 	{
// 		// mlx_destroy_display(fractal->mlx_instance); //missing in lib
// 		printf("mlx window failed\n");
// 		mlx_destroy_window(fractal->mlx_instance,
// 			fractal->mlx_win); //undeclared?
// 		free(fractal->mlx_instance);
// 		fractal->mlx_instance = NULL;
// 	}
// 	//  way to buffer the image you are rendering.
// 	fractal->img.img = mlx_new_image(fractal->mlx_instance,
// 			fractal->width, fractal->height);
// 	if (fractal->img.img == NULL)
// 	{
// 		printf("mlx img faield \n");
// 		// mlx_destroy_display(fractal->mlx_instance); // missing in lib.
// 		mlx_destroy_image(fractal->mlx_instance, fractal->img.img);
// 		free(fractal->img.img);
// 		fractal->img.img = NULL;
// 		mlx_destroy_window(fractal->mlx_instance, fractal->mlx_win);
// 		free(fractal->mlx_instance);
// 		fractal->mlx_instance = NULL;
// 	}
// 	printf("all ok\n");
// 	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
// 			&fractal->img.bits_per_pixel, &fractal->img.line_length,
// 			&fractal->img.endian);
// 	fractal->escape_val = 4;
// 	fractal->iteration = 25;
// 	fractal->iter = 0;
// 	fractal->xshift = 0;
// 	fractal->yshift = 0;
// 	fractal->zoom = 1;
// 	events_init(fractal);
// }

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000
#define ESCAPE_RADIUS 2

// Function to map iteration count to a color
unsigned int	map(int iter, t_fractal *fractal)
{
	if (iter == fractal->iteration)
		return (0x000000);
	return (0xFFFFFF / iter);
}

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

void	setupvariables(t_complex_num *c, t_fractal *fractal, int *i)
{
	c->x = 0;
	c->y = 0;
	*i = 0;
	if (ft_strncmp("julia", fractal->name, 5) == 0)
	{
		c->x = fractal->cx;
		c->y = fractal->cy;
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

	setupvariables(&c, fractal, &i);
	z.x = (scale(x, -2, +2, fractal->width)
			* fractal->zoom) + fractal -> xshift;
	z.y = (scale(y, 2, -2, fractal->height)
			* fractal->zoom) + fractal -> yshift;
	while (fractal->iteration > i)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_val)
		{
			color = colorscale(i, BLACK, WHITE, fractal->iteration);
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
			{
				render_burning_ship(x, y, fractal);
			}
			else
				handlecalculations(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_instance, fractal->mlx_win,
		fractal->img.img, 0, 0);
	mlx_string_put(fractal->mlx_instance, fractal->mlx_win,
		460, 355, COLOR_SILVER, "Controls");
}
