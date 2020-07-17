#include "includes/fractol.h"

void	error(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./fractol {fractal_type}\n", 32);
		write(1, "List of available fractals types:\n", 34);
		write(1, "1 - Mandelbrot\n", 15);
		write(1, "2 - Julia\n", 10);
		write(1, "3 - Ship\n", 9);
		write(1, "4 - Black Hole\n", 15);
		exit(0);
	}
	else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}
