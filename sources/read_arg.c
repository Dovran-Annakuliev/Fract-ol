#include "../includes/fractol.h"

void	read_arg(int ac, char **av, t_mlx *data)
{
	if (ac != 2)
		errors(1);
	if ((ft_strcmp(av[1], "Julia")) == 0)
		data->fract.fract = 1;
	else if ((ft_strcmp(av[1], "Mandelbrot")) == 0)
		data->fract.fract = 2;
	else if ((ft_strcmp(av[1], "Dragon")) == 0)
		data->fract.fract = 3;
	else
		errors(2);

}
