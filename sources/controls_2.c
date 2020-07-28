#include "../includes/fractol.h"



int		help_menu(int key, t_mlx *data)
{
	data->help_status = (data->help_status == 0) ? 1 : 0;
	draw_image(data);
	return (0);
}

int 	redraw(int key, t_mlx *data)
{
	if (key == SPACE)
	{
		default_settings(data);
		mlx_clear_window(data->mlx, data->window);
		draw_image(data);
	}
	return (0);
}

void	close_fractol(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img.image);
	cl_free(&data->cl);
	(void)data;
	exit(0);
}


