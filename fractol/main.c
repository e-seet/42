#include "fractal.h"
#include "utils.h"

// math math
void	parseinteger(char *str, int *i, int *neg, double *value)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*neg = *neg * -1;
		(*i)++;
	}
	while (str[*i] != '.' && (str[*i] >= '0' && str[*i] <= '9'))
	{
		*value = *value * 10 + (str[*i] - '0');
		(*i)++;
	}
}

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
	parseinteger(str, &i, &neg, &value);
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

// setup fractals from arguments
void	setupfractal(t_fractal *fractal, int argc, char *argv[])
{
	fractal->name = argv[1];
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

	if (argc < 7)
	{
		if (ft_strncmp("mandelbrot", argv[1], 10) == 0)
			setupfractal(&fractal, argc, argv);
		else if (ft_strncmp("julia", argv[1], 5) == 0)
			setupfractal(&fractal, argc, argv);
		else if (ft_strncmp("burningship", argv[1], 11) == 0)
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
