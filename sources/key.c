#include "../includes/fractol.h"

static void		close_fractal(t_mlx *data)
{
	free(data->img.img_data);
	mlx_destroy_image(data->mlx, data->img.image);
	mlx_clear_window(data->mlx, data->window);
	cl_free(&data->cl);
	(void)data;
	exit(0);
}

int				keyboard_key(int key, t_mlx *data)
{
	if (key == ESC)
		close_fractal(data);
	return (0);
}

