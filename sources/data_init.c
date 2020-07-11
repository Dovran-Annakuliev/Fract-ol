#include "../includes/fractol.h"

t_mlx		*data_init(int ac, char **av)
{
	t_mlx *data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		errors(0);
	data->iter = 200;
	read_arg(ac, av, data);
	if (!(data->mlx = mlx_init()))
		errors(0);
	if (!(data->window = mlx_new_window(data->mlx, W, H, "fractol")))
		errors(0);
	if (!(data->img.image = mlx_new_image(data->mlx, IW, IH)))
		errors(0);
	if (!(data->img.img_data = (int *)mlx_get_data_addr(data->img.image,
			&data->img.bbp, &data->img.sz_l, &data->img.end)))
		errors(0);
	return (data);
}
