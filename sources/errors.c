#include "../includes/fractol.h"

void	errors(int err)
{
	if (err > 0)
	{
		if (err == 1)
			write(1, "usage: ./fractol [argument]\n", 28);
		else if (err == 2)
			write(1, "Invalid argument\n", 17);
		write(1, "\tuse argument:\tMandelbrot\n", 26);
		write(1, "\t\t\tJulia\n", 9);
		write(1, "\t\t\tShip\n", 8);
		write(1, "\t\t\tWrong_Phoenix\n", 17);
		write(1, "\t\t\tPhoenix\n", 11);
	}
	else
		write(1, "error\n", 6);
	exit(0);
}
