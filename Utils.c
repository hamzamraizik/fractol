#include "fractol.h"

double	ft_atof(const char *str, double result, int sign)
{
	int	decimal;
	int	power;

	decimal = 0;
	power = 1;
	while (isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = (*str++ == '-');
	while (isdigit(*str))
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (isdigit(*str))
		{
			result = result * 10 + (*str++ - '0');
			power *= 10;
		}
		decimal = 1;
	}
	result *= sign;
	if (decimal)
		result /= power;
	return (result);
}

int	cmp(const char	*s1, const char	*s2, size_t	n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

double	map(double num, double n_min, double n_max, double o_max)
{
	double	o_min;

	o_min = 0;
	return ((n_max - n_min) * (num - o_min) / (o_max - o_min)
		+ n_min);
}

t_complex	sum_complex(t_complex nb1, t_complex nb2)
{
	t_complex	result;

	result.x = nb1.x + nb2.x;
	result.y = nb1.y + nb2.y;
	return (result);
}

t_complex	squar_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
