#include "../includes/fractol.h"

void	errors(int err)
{
	if (err > 0)
	{
		if (err == 1)
			write(1, "\tusage: ./fractol [flag]\n", 25);
		else if (err == 2)
			write(1, "\tInvalid flag\n", 14);
		write(1, "\tuse flag:\t-M (Mandelbrot)\n", 27);
		write(1, "\t\t\t-J (Julia)\n", 14);
		write(1, "\t\t\t-S (Ship)\n", 13);
		write(1, "\t\t\t-W (Wrong_Phoenix)\n", 22);
		write(1, "\t\t\t-P (Phoenix)\n", 16);
	}
	else
		write(1, "error\n", 6);
	exit(0);
}
