/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:17:49 by eseet             #+#    #+#             */
/*   Updated: 2024/04/08 17:17:50 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)

# define RED		0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
// # define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
// # define DARK_ELECTRIC_PINK 0xCC00CC
# define DARK_NEON_GREEN 0x00CC00
# define DARK_HOT_PURPLE 0x99004C

# define COLOR_SILVER		0xCCCCCC

// data to get from data address of current image 
// img_ptr
// pixel_ptr
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// name of window
// mlx connection
typedef struct s_fractal {
	char	*name;
	void	*mlx_instance;
	void	*mlx_win;
	int		escape_val;
	int		iteration;
	int		iter;

	double	xshift;
	double	yshift;

	int		width;
	int		height;

	double	cx;
	double	cy;

	double	zoom;
	t_data	img;
}				t_fractal;

typedef struct s_complex_num {
	double	x;
	double	y;
}				t_complex_num;
#endif
