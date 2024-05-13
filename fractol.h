#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define WIDTH 800
#define HEIGHT 800

//
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

//
typedef struct s_complex
{
	//  real number
	double  x;
	//  i
	double  y;
}       t_complex;


typedef struct s_img
{
	void    *img_ptr;
	char    *pixels_ptr;
	int     bpp;
	int     endian;
	int     line_len;
}       t_img;

typedef struct s_fractal
{
	char	*name;
	void    *mlx_connection;
	void    *mlx_window;
	t_img   img;
	double	escape_value;
	int		iteration_definition;
	double	x_shift;
	double	y_shift;
	double		zoom;
}       t_fractal;

void fractal_init(t_fractal *fractal);
double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex squar_complex(t_complex z);
t_complex sum_complex(t_complex nb1, t_complex nb2);
void fractal_render(t_fractal *fractal);

#endif