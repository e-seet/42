
#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "fractal.h"
# include <unistd.h>
//for read write, permission with files, creating files
// # include <fcntl.h>
# include <stdlib.h>

// for printing stuff. To remove
# include <stdio.h>
// for math limits
# include <limits.h>
// check if this is allowed
# include <math.h>
// The x11 library
# include "X11/X.h"

// mlx library
# include "minilibxopengl/mlx.h"

// functions
double	scale(double unscaled_num, double new_min,
			double new_max, double old_max);
void	paintpixel(int x, int y, t_data *img, int color);
void	setup(t_fractal *fractal);
void	handlecalculations(int x, int y, t_fractal *fractal);
void	renderfractal(t_fractal *fractal);

#endif
