#include "fractol.h"

double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex sum_complex(t_complex nb1, t_complex nb2)
{
    t_complex   result;
    result.x = nb1.x + nb2.x;
    result.y = nb1.y + nb2.y;
    return result;
}

t_complex squar_complex(t_complex z)
{
    t_complex result;
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return result;
}
