
#include "fractol.h"

#define KEY_PRESS_EVENT 2
#define KEY_PRESS_MASK (1L << 0)

int	handle_events(int key, t_fractal *fractal)
{
	// printf("%d/n", key);
	exit(1);
	return 0;
}

int main(int ac, char *av[])
{
	t_fractal fractal;

	if (ac == 2 && !strncmp(av[1], "mandelbrot", 11))
	{
		fractal.name = av[1];
		puts("good!");
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
		mlx_hook(&fractal.mlx_window, 02, 0, (int (*)())handle_events, &fractal);
		return 0;
	}
}
