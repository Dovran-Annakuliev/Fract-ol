#include "../includes/fractol.h"

int		help_menu(int key, t_mlx *data)
{
	if (key == H)
	{
		if (data->help_status == 0)
		{
			if (!(data->help = mlx_new_window(data->mlx, HELP_WIDTH, HELP_HEIGHT, "Help")))
				error(0);
			data->help_status = 1;
			mlx_hook(data->help, 2, (1L << 0), close_menu, data);
		}
		else
		{
			mlx_destroy_window(data->mlx, data->help);
			data->help_status = 0;
		}
	}
	return (0);
}

static int	close_menu(int key, t_mlx *data)
{
	if (key == H)
		help_menu(key, data);
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

int 	refresh(int key, t_mlx *data)
{
	if (key == R)
	{
		mlx_clear_window(data->mlx, data->window);
		mlx_do_sync(data->mlx);
		draw_image(data);
	}
	return (0);
}

void	close_fractol(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img.image);
	(void)data;
	exit(0);
}


