#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	unsigned int	*offset;
	
	offset = (unsigned int *)img->pixels_ptr;
	offset[y * WIDTH + x] = color;
}

void	handle_pixel2(int x, int y, t_fractal *fractal)
{
	t_complex   z;
	t_complex   c;
	int         i;
	int       	color;

	i = 0;
	//first iteration
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;

	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->x_shift;
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->y_shift;

	fractal->escape_value = 4;
	while (i < fractal->iteration_definition)
	{
		z = sum_complex(squar_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex   z;
	t_complex   c;
	int         i;
	int       	color;

		i = 0;
		z.x = 0.0;
		z.y = 0.0;

		c.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->x_shift;
		c.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->y_shift;

		fractal->escape_value = 4;
		while (i < fractal->iteration_definition)
		{
			z = sum_complex(squar_complex(z), c);
			if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
			{
				color = map(i, BLACK, WHITE, 0, fractal->iteration_definition);
				my_pixel_put(x, y, &fractal->img, color);
				return ;
			}
			++i;
		}
		my_pixel_put(x, y, &fractal->img, BLACK);
}

void fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	if (strncmp(fractal->name, "julia", 6) == 0)
	{
		y = -1;
		while(++y < HEIGHT)
		{
			x = -1;
			while(++x < WIDTH)
				handle_pixel2(x, y, fractal);
		}
	}
	else
	{
		y = -1;
		while(++y < HEIGHT)
		{
			x = -1;
			while(++x < WIDTH)
				handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
}
