#include "../includes/fractol.h"

void	errors(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./fractol [argument ...]\n", 32);
		write(1, "\tuse argument:\tJulia\n", 21);
		write(1, "\tuse argument:\tMandelbrot\n", 26);
		write(1, "\tuse argument:\tDragon\n", 22);
		exit(0);
	}
	else if (err == 2)
	{
		write(1, "invalid argument\n", 17);
		write(1, "\tuse argument:\tJulia\n", 21);
		write(1, "\tuse argument:\tMandelbrot\n", 26);
		write(1, "\tuse argument:\tDragon\n", 22);
		exit(0);
	}
	else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}
