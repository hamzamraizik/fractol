/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:53:14 by hmraizik          #+#    #+#             */
/*   Updated: 2024/05/16 19:43:25 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	init_vars(t_fractal *fractal)
{
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
	fractal->iteration_definition = 100;
	fractal->zoom = 1.0;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->mlx_window)
	{
		free(fractal->mlx_connection);
		error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}
