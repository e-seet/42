#include "utils.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	printf("argc:%d\n", argc);
	if (argc == 2)
	{
		if (ft_strncmp("mandelbrot", argv[1], 10) == 0)
		{
			printf("mandelbrot\n");
		}
		else if (ft_strncmp("julia", argv[1], 5) == 0)
		{
			printf("julia\n");
		}
		else if (ft_strncmp("burningship", argv[1], 11) == 0)
		{
			printf("burning ship\n");
		}	
		else
			exit(1);
		fractal.name = argv[1];
		
		// We could add in parameters for the window size if required in the argv
		setup(&fractal);
		renderfractal(&fractal);
		mlx_loop(fractal.mlx_instance);

	}
	else
		exit(1);
	return (0);
}