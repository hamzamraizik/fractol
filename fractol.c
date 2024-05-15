#include "fractol.h"

int	exit_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(0);
	return (0);
}

int	handle_events(int key, t_fractal *fractal)
{
	double	adjustement;

	adjustement = 0.1 / fractal->zoom;
	if (fractal->zoom < 1.0)
		adjustement = 0.1 * fractal->zoom;
	if (key == 53)
		exit_window(fractal);
	else if (key == LEFT)
		fractal->x_shift -= adjustement;
	else if (key == PLUS)
		fractal->iteration_definition += 50;
	else if (key == MIN)
		fractal->iteration_definition -= 50;
	else if (key == RIGHT)
		fractal->x_shift += adjustement;
	else if (key == UP)
		fractal->y_shift += adjustement;
	else if (key == DOWN)
		fractal->y_shift -= adjustement;
	fractal_render(fractal);
	return (0);
}

int	handle_zoom(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractal->zoom *= 0.96;
	else if (button == 5)
		fractal->zoom *= 1.04;
	fractal_render(fractal);
	return (0);
}

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	fractal.x_shift = 0.0;
	fractal.y_shift = 0.0;
	fractal.iteration_definition = 100;
	fractal.zoom = 1.0;
	if (ac >= 2 && (!cmp(av[1], "mandelbrot", 11) || !cmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		puts("good!");
		fractal_init(&fractal);
		if (ac == 4 && strncmp(av[1], "julia", 6) == 0)
		{
			fractal.julia_x = ft_atof(av[2], 0.0, 1);
			fractal.julia_y = ft_atof(av[3], 0.0, 1);
			fractal_render(&fractal);
		}
		else
			fractal_render(&fractal);
		mlx_mouse_hook(fractal.mlx_window, handle_zoom, &fractal);
		mlx_key_hook(fractal.mlx_window, handle_events, &fractal);
		mlx_hook(fractal.mlx_window, 17, 0, exit_window, &fractal);
		mlx_loop(fractal.mlx_connection);
		return (0);
	}
}
