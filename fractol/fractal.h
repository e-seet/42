
#ifndef FRACTAL_H
# define FRACTAL_H

// #define	black	0x000000
// #define	white	0xFFFFFF
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)

#define	RED		0xFF0000
#define	GREEN	0x00FF00
#define	BLUE	0x0000FF
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define COLOR_TUNDORA		0x444444
# define COLOR_SILVER		0xCCCCCC

// data to get from data address of current image 
typedef struct	s_data {
	void	*img; //img_ptr
	char	*addr; //pixel_ptr
	int		bits_per_pixel; // bpp
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_fractal {
	char	*name; //name of window
	void	*mlx_instance; // mlx_connection
	void	*mlx_win;
	int		escape_val;
	int		iteration;
	int		iter;

	double	xshift;
	double	yshift;

	int	width;
	int	height;

	double cx;
	double cy;

	double	zoom;
	t_data	img;
}				t_fractal;

typedef struct	s_complex_num {
	double	x;
	double	y;
}				t_complex_num;
#endif