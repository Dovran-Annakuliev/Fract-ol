#include "../includes/fractol.h"

void 	default_settings(t_mlx *data)
{
	data->view.color_type = 1;
	data->view.zf = 1.0f;
	data->view.minX = -2.0f;
	data->view.maxX = 2.0f;
	data->view.minY = -1.17f;
	data->view.maxY = 1.17f;
	data->view.offset = 0.0f;
	data->view.color_type = 1;
	data->view.mouse_re = 0.0f;
	data->view.mouse_im = 0.0f;
	data->view.julia_re = 0.0f;
	data->view.julia_im = 0.0f;
	data->view.button = 0;
	data->view.pressed_button = -1;
	data->view.julia_change_mod = 1;
}

void	read_arg(int ac, char **av, t_mlx *data)
{
	if (ac != 2)
		errors(1);
	if ((ft_strcmp(av[1], "Mandelbrot")) == 0)
	{
		data->fractal_type = 1;
		data->sourse_fractal = "cl_sources/mandelbrot.cl";
	}
	else if ((ft_strcmp(av[1], "Julia")) == 0)
	{
		data->fractal_type = 2;
		data->sourse_fractal = "cl_sources/julia.cl";
	}
	else if ((ft_strcmp(av[1], "Ship")) == 0)
	{
		data->fractal_type = 3;
		data->sourse_fractal = "cl_sources/ship.cl";
	}
	else if ((ft_strcmp(av[1], "Wrong_Phoenix")) == 0)
	{
		data->fractal_type = 4;
		data->sourse_fractal = "cl_sources/wrong_phoenix.cl";
	}
	else if ((ft_strcmp(av[1], "Phoenix")) == 0)
	{
		data->fractal_type = 5;
		data->sourse_fractal = "cl_sources/classic_phoenix.cl";
	}

	else if ((ft_strcmp(av[1], "Dragon")) == 0)
	{
		data->fractal_type = 6;
		data->sourse_fractal = "cl_sources/newton.cl";
	}
	else
		errors(2);
}

t_mlx		*data_init(int ac, char **av)
{
	t_mlx *data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		errors(0);
	read_arg(ac, av, data);
	if (!(data->mlx = mlx_init()))
		errors(0);
	if (!(data->window = mlx_new_window(data->mlx, W, H, "fractol")))
		errors(0);
	if (!(data->img.image = mlx_new_image(data->mlx, W, H)))
		errors(0);
	if (!(data->img.img_data = (int *)mlx_get_data_addr(data->img.image,
			&data->img.bbp, &data->img.sz_l, &data->img.end)))
		errors(0);
	read_arg(ac, av, data);
	default_settings(data);
	if (data->fractal_type == 3)
	{
		data->view.maxY -= 0.6f;
		data->view.minY -= 0.6f;
	}
	data->iter = 100;
	data->result = (float *)malloc(sizeof(float) * (W * H));
	return (data);
}
