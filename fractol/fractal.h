
#ifndef FRACTAL_H
# define FRACTAL_H

#define	black	0x000000
#define	white	0xFFFFFF

#define	red		0xFF0000
#define	green	0x00FF00
#define	blue	0x0000FF

// data to get from data address of current image 
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_fractal {
	char	*name;
	void	*mlx_instance;
	void	*mlx_win;
	int		escape_val;
	int		iteration;
	t_data	img;
}				t_fractal;

typedef struct	s_complex_num {
	double	x;
	double	y;
}				t_complex_num;

#endif
