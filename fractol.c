
#include "fractol.h"

int handle_input(int key, void *param)
{
    // mlx_destroy_window(mlx, win);  // handle the input on the keycode.
    return(0);
}

int main(int ac, char *av[])
{
    t_fractal fractal;

    if (ac == 2 && !strncmp(av[1], "mandelbrot", 10))
    {
        fractal.name = av[1];
        puts("good!");
        fractal_init(&fractal);
        fractal_render(&fractal);
        //
        //
        mlx_loop(fractal.mlx_connection); // loop keep listening to any action from user

        // mlx = mlx_init();
        // win = mlx_new_window(mlx, 800, 600, "the first window");

        // mlx_key_hook(win, handle_input, NULL);
        //
        // mlx_loop(mlx);  // wait for events.
        // mlx_get_data_addr();
        return 0;
    }
}
