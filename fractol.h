#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define WIDTH 800
#define HEIGHT 800
typedef struct s_complex
{
    //  real number
    double  x;
    //  i
    double  y;
}       t_complex;

typedef struct s_img
{
    void    *img_ptr; // pointer to img struct.
    char    *pixels_ptr; // points to the actual pixels "points to one byte"
    int     bpp;
    int     endian;
    int     line_len;
}       t_img;

typedef struct s_fractal
{
    char *name;
    //MLX
    void    *mlx_connection; // mlx_init()
    void    *mlx_window; //mlx_new_window
    //IMG
    t_img   img;

    //Hooks member variables
}       t_fractal;
void fractal_init(t_fractal *fractal);
double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex squar_complex(t_complex z);
t_complex sum_complex(t_complex nb1, t_complex nb2);

#endif