
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
# include "../minilibxopengl/mlx.h"

//eventhandler
void			resetback(t_fractal *fractal);
int				close_handler(t_fractal *fractal);
int				julia_track(int x, int y, t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				key_handler(int keyval, t_fractal *fractal);

//calculations
void			parseinteger(char *str, int *i, int *neg, double *value);
double			returndouble(char *str);
double			scale(double unscaled_num, double new_min, double new_max,
					double old_max);
t_complex_num	square_complex(t_complex_num z);
t_complex_num	sum_complex(t_complex_num z1, t_complex_num z2);

//utils
unsigned int	map(int iter, t_fractal *fractal);
void			paintpixel(int x, int y, t_data *img, int color);
void			setupvariables(t_complex_num *c, t_complex_num *z,
					t_fractal *fractal, t_complex_num *temp);
void			handlecalculations(int x, int y, t_fractal *fractal);
void			renderfractal(t_fractal *fractal);

//bonus
void			render_burning_ship(int x, int y, t_fractal *fractal);

// utils2
// convert double to char *
char			*ft_itoadouble(double num);
// void			ft_itoadouble_int(double num, double num2, char *str, int *z);
void			putstrings(t_fractal *fractal);

#endif
