
#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "fractal.h"
# include <unistd.h>
//for read write, permission with files, creating files
// # include <fcntl.h>
# include <stdlib.h>
# include <stdio.h> // for printing stuff
# include <limits.h> // for limits
# include <math.h>  // check if this is allowed

#include "X11/X.h"

// mlx library
#include "minilibxopengl/mlx.h"

// functions
double	scale(double num, double o_min, double o_max, double new_min, double new_max );
void paintpixel(int x, int y, t_data *img, int color);
void	setup(t_fractal *fractal);
void handlecalculations(int x, int y, t_fractal *fractal);
void renderfractal(t_fractal *fractal);


#endif
