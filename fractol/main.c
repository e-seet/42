/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:16:16 by eseet             #+#    #+#             */
/*   Updated: 2024/04/08 17:16:18 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/fractal.h"
#include "utils/utils.h"

// change the mask from 0 back to mask. 
// TO DO! TAKE note
// mac version uses 0 as it does not matter
// void	events_init(t_fractal *fractal)
// {
// 	mlx_hook(
// 		fractal->mlx_win,
// 		KeyPress,
// 		0,
// 		key_handler,
// 		fractal
// 		);
// 	mlx_hook(fractal->mlx_win,
// 		ButtonPress,
// 		0,
// 		mouse_handler,
// 		fractal);
// 	mlx_hook(fractal->mlx_win,
// 		DestroyNotify,
// 		0,
// 		close_handler,
// 		fractal);
// 	mlx_hook(fractal->mlx_win,
// 		MotionNotify,
// 		0,
// 		julia_track,
// 		fractal);
// }

// ubuntu ver
void	events_init(t_fractal *fractal)
{
	mlx_hook(
		fractal->mlx_win,
		KeyPress,
		KeyPressMask,
		key_handler,
		fractal);
	mlx_hook(fractal->mlx_win,
		ButtonPress,
		ButtonPressMask,
		mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_win,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		fractal);
	mlx_hook(fractal->mlx_win,
		MotionNotify,
		PointerMotionMask,
		julia_track,
		fractal);
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

// //ubuntu backup
// void	setup(t_fractal *fractal)
// {
// 	fractal->mlx_instance = mlx_init();
// 	if (fractal->mlx_instance == NULL)
// 		return ;
// 	fractal->mlx_win = mlx_new_window(fractal->mlx_instance,
// 			fractal->width, fractal->height, fractal->name);
// 	if (fractal->mlx_win == NULL)
// 	{
// 		//to check
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

// 	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
// 			&fractal->img.bits_per_pixel, &fractal->img.line_length,
// 			&fractal->img.endian);
// 	// fractal->escape_val = 4;
// 	// fractal->iteration = 25;
// 	// fractal->iter = 0;
// 	// fractal->xshift = 0;
// 	// fractal->yshift = 0;
// 	// fractal->zoom = 1;
// 	events_init(fractal);
// }

// setup fractals wiith default values unless specified from arguments 
void	setupfractal(t_fractal *fractal, int argc, char *argv[])
{
	fractal->name = argv[1];
	fractal->width = 400;
	fractal->height = 400;
	fractal->cx = 0;
	fractal->cy = 0;
	fractal->xshift = 1.0;
	fractal->yshift = 1.0;
	fractal->iteration = 50;
	fractal->iter = 0.0;
	fractal->zoom = 0.0;
	if (argc >= 3)
		fractal->width = ft_atoi(argv[2]);
	if (argc >= 4)
		fractal->height = ft_atoi(argv[3]);
	if (argc >= 5)
		fractal->cx = returndouble(argv[4]);
	if (argc >= 6)
		fractal->cy = returndouble(argv[5]);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (argc == 1)
	{
		write(1, "mandelbrot\njulia\nburningship", 29);
	}
	else if (argc < 7)
	{
		if (ft_strncmp("mandelbrot", ft_lowercase(argv[1]), 10) == 0)
			setupfractal(&fractal, argc, argv);
		else if (ft_strncmp("julia", ft_lowercase(argv[1]), 5) == 0)
			setupfractal(&fractal, argc, argv);
		else if (ft_strncmp("burningship", ft_lowercase(argv[1]), 11) == 0)
			setupfractal(&fractal, argc, argv);
		else
			exit(1);
		fractal.name = argv[1];
		setup(&fractal);
		renderfractal(&fractal);
		mlx_loop(fractal.mlx_instance);
	}
	else
		exit(1);
	return (0);
}
