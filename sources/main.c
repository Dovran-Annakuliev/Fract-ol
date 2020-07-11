#include "../includes/fractol.h"

int		main(int ac, char **av)
{
	t_mlx *data;

	data = data_init(ac, av);
	data->cl.kernel_source = get_kernel_source(&data->cl, data->sourse_fractal);
	cl_init(&data->cl);
	draw_image(data);

	mlx_hook(data->window, 2, 1l << 0, keyboard_key, data);
	mlx_hook(data->window, 4, (1L << 2), mouse_key, data);
	mlx_hook(data->window, 6, (1L << 2), change_julia, data);
	mlx_loop(data->mlx);
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img.img_data);
	return (0);
}
