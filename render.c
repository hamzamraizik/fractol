#include "fractol.h"

void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;
    //first iteration
    z.x = 0.0;
    z.y = 0.0;

    c.x = map(x, -2, 2, 0, WIDTH);
    c.y = map(x, -2, 2, 0, HEIGHT);

    //how many times you want to iteration  to check 
                //if the point escaped
    while (i < fractal->iteration_definition)
    {
        // Actual z^2 + c
        // z = z^2 + c
        z = sum_complex(squar_complex(z), c);

        //if the value escaped ??
        //if hypotenuse > 2 i assume the point has escaped
        if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            color = map(i, BLACK, WHITE, 0, fractal->iteration_definition);
            my_pixel_put(); //TODO
            return ;
        }


    }
    //we are in MANDELBROT given the iterations made
}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while(++y < HEIGHT)
    {
        x = -1;
        while(++x < WIDTH)
            handle_pixel(x, y, fractal);
    }
}
