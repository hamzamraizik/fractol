#include <mlx.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000
#define ZOOM_FACTOR 1.5

typedef struct s_complex {
    double real;
    double imag;
} t_complex;

int mandelbrot(t_complex c) {
    t_complex z = {0, 0};
    int iterations = 0;

    while (z.real * z.real + z.imag * z.imag <= 4 && iterations < MAX_ITERATIONS) {
        double temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = temp;
        iterations++;
    }

    return iterations;
}

void draw_mandelbrot(void *mlx_ptr, void *win_ptr) {
    t_complex min = {-2.0, -1.5};
    t_complex max = {1.0, 1.5};
    double dx = (max.real - min.real) / WIDTH;
    double dy = (max.imag - min.imag) / HEIGHT;

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            t_complex c = {min.real + x * dx, min.imag + y * dy};
            int color = mandelbrot(c);
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
        }
    }
}

int main() {
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Fractal");

    draw_mandelbrot(mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);
    return 0;
}
