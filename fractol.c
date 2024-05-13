
#include "fractol.h"
#define Left 123
#define Right 124
#define Up 126
#define Down 125
#define Plus 69
#define Min 78

int	exit_window(t_fractal *fractal)
{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		exit(0);
		return 0;
}

int	handle_events(int key, t_fractal *fractal)
{
	double	adjustement;

	adjustement = 0.1 / fractal->zoom;
	if (fractal->zoom < 1.0)
		adjustement = 0.1 * fractal->zoom;
	if (key == 53)
		exit_window(fractal);
	else if (key == Left)
		fractal->x_shift -= adjustement;
	else if (key == Plus)
		 fractal->iteration_definition += 50;
	else if (key == Min)
		 fractal->iteration_definition -= 50;
	else if (key == Right)
		fractal->x_shift += adjustement;
	else if (key == Up)
		fractal->y_shift += adjustement;
	else if (key == Down)
		fractal->y_shift -= adjustement;
	// else
	// 	printf("%d", key);
	fractal_render(fractal);
	return 0;
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
	return 0;
}

int main(int ac, char *av[])
{
	t_fractal	fractal;

	fractal.x_shift = 0.0;
	fractal.y_shift = 0.0;
	fractal.iteration_definition = 100;
	fractal.zoom = 1.0;
	if (ac >= 2 && (!strncmp(av[1], "mandelbrot", 11) || !strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		puts("good!");
		fractal_init(&fractal);
		if (ac == 4 && strncmp(av[1], "julia", 6) == 0)
		{
			fractal.julia_x = atof(av[2]);
			fractal.julia_y = atof(av[3]);
			fractal_render(&fractal);
		}
		else
			fractal_render(&fractal);
		mlx_mouse_hook(fractal.mlx_window, handle_zoom, &fractal);
		mlx_key_hook(fractal.mlx_window, handle_events, &fractal);
		mlx_hook(fractal.mlx_window, 17, 0, exit_window, &fractal);
		mlx_loop(fractal.mlx_connection);
		return 0;
	}
}
