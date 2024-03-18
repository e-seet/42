#include "fractal.h"
#include "utils.h"

double	returndouble(char *str)
{
	double	value;
	int		i;
	int		neg;
	double	tenth;

	value = 0;
	i = 0;
	neg = 1;
	tenth = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] != '.' && (str[i] >= '0' && str[i] <= '9'))
	{
		value = value * 10 + (str[i] - '0');
		i ++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] != '.' && (str[i] >= '0' && str[i] <= '9'))
	{
		tenth = tenth / 10;
		value = value + ((str[i] - '0') * (tenth));
		i++;
	}
	return (value * neg);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	printf("argc:%d\n", argc);
	if (argc < 7)
	{
		if (ft_strncmp("mandelbrot", argv[1], 10) == 0)
		{
			fractal.name = "mandelbrot";
			fractal.width = ft_atoi(argv[2]);
			fractal.height = ft_atoi(argv[3]);
			printf("mandelbrot\n");
		}
		else if (ft_strncmp("julia", argv[1], 5) == 0)
		{
			fractal.name = argv[1];
			printf("fractal name :%s\n", fractal.name);
			fractal.width = ft_atoi(argv[2]);
			fractal.height = ft_atoi(argv[3]);
			fractal.cx = returndouble(argv[4]);
			fractal.cy = returndouble(argv[5]);
			printf("value1:%f\n", fractal.cx);
			printf("value2:%f\n", fractal.cy);
			printf("julia\n");
		}
		else if (ft_strncmp("burningship", argv[1], 11) == 0)
		{
			printf("burning ship\n");
			fractal.name = argv[1];
			fractal.width = ft_atoi(argv[2]);
			fractal.height = ft_atoi(argv[3]);
			fractal.cx = returndouble(argv[4]);
			fractal.cy = returndouble(argv[5]);
		}
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
