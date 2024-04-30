#include "fractol.h"

void error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
//INIT

void fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
											WIDTH, HEIGHT,
											fractal->name);

	if (fractal->mlx_window == NULL)
	{
		// mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
											WIDTH, HEIGHT);

	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		// mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
												&fractal->img.bpp,
												&fractal->img.line_len,
												&fractal->img.endian);

	//events_init(fractal);

}