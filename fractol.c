/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:53:27 by hmraizik          #+#    #+#             */
/*   Updated: 2024/05/17 21:07:32 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_options(void)
{
	write(1, "Write arguments!, Here some options:\n", 37);
	write(1, "\n* mandelbrot\n", 14);
	write(1, "\n* julia   0.355  0.355\n", 24);
	exit(1);
	return (1);
}
int	is_valid(char *str)
{
	int	i;

	i = 0;
	while(str[i] ==  ' ' || str[i] == '\t')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.') 
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
int	main(int ac, char *av[])
{
	t_fractal	fractal;

	init_vars(&fractal);
	if ((ac == 2 && !cmp(av[1], "mandelbrot", 11))
	|| (ac == 4 && (!cmp(av[1], "julia", 6) && (is_valid(av[2]) && is_valid(av[3])))))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		if (!cmp(av[1], "julia", 6))
		{
			fractal.julia_x = ft_atof(av[2], 0.0, 1);
			fractal.julia_y = ft_atof(av[3], 0.0, 1);
			fractal_render(&fractal);
		}
		else if (ac == 2 && cmp(av[1], "mandelbrot", 11) == 0)
			fractal_render(&fractal);
		mlx_mouse_hook(fractal.mlx_window, handle_zoom, &fractal);
		mlx_key_hook(fractal.mlx_window, handle_events, &fractal);
		mlx_hook(fractal.mlx_window, 17, 0, exit_window, &fractal);
		mlx_loop(fractal.mlx_connection);
		return (0);
	}
	else
		return (ft_options());
}
