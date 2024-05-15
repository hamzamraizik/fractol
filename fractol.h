#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>

# define WIDTH 800
# define HEIGHT 800
//
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)
// Buttons
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PLUS 69
# define MIN 78
// Psychedelic colors

typedef struct s_complex
{
	//  real number
	double	x;
	//  i
	double	y;
}		t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iteration_definition;
	double	x_shift;
	double	y_shift;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

void		fractal_init(t_fractal *fractal);
double		map(double num, double n_min, double n_max, double o_max);
t_complex	squar_complex(t_complex z);
t_complex	sum_complex(t_complex nb1, t_complex nb2);
void		fractal_render(t_fractal *fractal);
double		ft_atof(const char *str, double result, int sign);
int			cmp(const char	*s1, const char	*s2, size_t	n);

#endif