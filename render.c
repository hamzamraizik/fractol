#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	unsigned int	*offset;

	offset = (unsigned int *)img->pixels_ptr;
	offset[y * WIDTH + x] = color;
}

int	map_color(int iteration_count, int max_iteration)
{
	int		red;
	int		green;
	int		blue;
	float	intensity;
	int		final_color;

	intensity = (float)iteration_count / max_iteration;
	red = (int)(255 * intensity);
	green = (int)(255 * intensity);
	blue = (int)(255 * intensity);
	final_color = red << 16;
	final_color |= green << 8;
	final_color |= blue;
	return (final_color * intensity);
}

void	handle_pixel2(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->x_shift;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->y_shift;
	fractal->escape_value = 4;
	while (i < fractal->iteration_definition)
	{
		z = sum_complex(squar_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map_color(i, fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->x_shift;
	c.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->y_shift;
	fractal->escape_value = 4;
	while (i < fractal->iteration_definition)
	{
		z = sum_complex(squar_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map_color(i, fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	if (strncmp(fractal->name, "julia", 6) == 0)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
				handle_pixel2(x, y, fractal);
		}
	}
	else
	{
		y = -1;
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
				handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
