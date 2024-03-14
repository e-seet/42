#include "utils.h"

// param1: number given
// param2: old min value: 0
// param3: old min max value: whatever the limit u set for screen
// param4: new min value: -2
// param5: new max value: 2

double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}
// double	scale(double num, double o_min, double o_max, double new_min, double new_max )
// {
// 	printf("func scale \n");
// 	double	olddistancefromo_min;
// 	double	newscalefactor;
// 	double	oldscalefactor;
	
// 	olddistancefromo_min = num - o_min;
// 	newscalefactor = new_max - new_min;
// 	oldscalefactor = o_max - o_min;

// 	return	(((olddistancefromo_min / oldscalefactor) * newscalefactor) + new_min);
// }

t_complex_num square_complex(t_complex_num z)
{
	t_complex_num result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return result;
}

t_complex_num sum_complex(t_complex_num z1, t_complex_num z2)
{
	t_complex_num result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return result;
}


void paintpixel(int x, int y, t_data *img, int color)
{
	int offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *) (img->addr + offset) = color;
}

void	setup(t_fractal *fractal)
{
	printf("func setup \n");
	//init
	fractal->mlx_instance = mlx_init();
	printf("mlx inited\n");
	
	if (fractal->mlx_instance == NULL)
	{
		printf("mlx isntance is null\n");
		// do something to exit safely
	}

	// create new window 
	// To change the 800 LOL
	fractal->mlx_win = mlx_new_window(fractal->mlx_instance, 800, 800, "Hello world!");
	if (fractal->mlx_win == NULL)
	{
		// mlx_destroy_display(fractal->mlx_instance); //missing in lib
		printf("mlx window failed\n");

		mlx_destroy_window(fractal->mlx_instance, fractal->mlx_win); //undeclared?
		free(fractal->mlx_instance);
		fractal->mlx_instance = NULL;
	}
	
	//  way to buffer the image you are rendering.
	fractal->img.img = mlx_new_image(fractal->mlx_instance, 800, 800);
	if (fractal->img.img == NULL)
	{
		printf("mlx img faield \n");

		// do something to exit safely
		// mlx_destroy_display(fractal->mlx_instance); // missing in lib.
		
		mlx_destroy_image(fractal->mlx_instance, fractal->img.img);
		free(fractal->img.img);
		fractal->img.img = NULL;

		mlx_destroy_window(fractal->mlx_instance, fractal->mlx_win);
		free(fractal->mlx_instance);
		fractal->mlx_instance = NULL;
	}
	printf("all ok\n");
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_per_pixel, &fractal->img.line_length, &fractal->img.endian);
	fractal->escape_val = 4;
	fractal->iteration = 42;
}

// c is the actual starting point
// z is the calculated points
void handlecalculations(int x, int y, t_fractal *fractal)
{
	// printf("func handlecalculations\n");

	t_complex_num z;
	t_complex_num c;
	int			i;
	int color;

	i = 0;
	z.x = 0;
	z.y = 0;

	// 799 is some magical number that we should amend based off argv eventually
	c.x = scale(x, -2, +2, 0, 799);
	c.y = scale(y, 2, -2, 0, 799);

	// to do a while loop to loop through the fractal

	while (fractal->iteration > i)
	{
		z = sum_complex(square_complex(z), c);

		// not escaped
		if ( (z.x * z.x) + (z.y * z.y) > fractal->escape_val)
	 	{
			color = scale(i, BLACK , WHITE, 0, fractal->iteration);
			paintpixel(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}

	// mandelbrot set
	paintpixel(x, y, &fractal->img, WHITE);
	// the main thing
}

void renderfractal(t_fractal *fractal)
{
	printf("func renderfractal\n");

	int x;
	int y;

	y = -1;	
	// to change the 800 into variable number
	while(++y < 800)
	{
		x = -1;
		while(++x < 800)
		{
			handlecalculations(x, y, fractal);
		}
	}

	mlx_put_image_to_window(
		fractal->mlx_instance,
		fractal->mlx_win,
		fractal->img.img,
		0,
		0
	);
}