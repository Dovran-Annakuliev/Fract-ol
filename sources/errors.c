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
		write(1, "\tuse argument:\tJulia\n", 21);
		write(1, "\tuse argument:\tShip\n", 20);
		write(1, "\tuse argument:\tWrong_Phoenix\n", 29);
		write(1, "\tuse argument:\tPhoenix\n", 24);
		write(1, "\tuse argument:\tDragon\n", 22);
	}
	else
		write(1, "error\n", 6);
	exit(0);
}
