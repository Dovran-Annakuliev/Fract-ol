#include "../includes/fractol.h"

void			color_fractal(t_mlx *data)
{
	for (int i = 0; i < H ; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (data->view.color_type == 1)
				data->img.img_data[i * W + j] = basic_one(data->result[i * W + j], data->max_iter);
			if (data->view.color_type == 2)
				data->img.img_data[i * W + j] = zerg(data->result[i * W + j], data->max_iter);
			if (data->view.color_type == 3)
				data->img.img_data[i * W + j] = black_hole(data->result[i * W + j], data->max_iter);
			if (data->view.color_type == 4)
				data->img.img_data[i * W + j] = mix(data->result[i * W + j], data->max_iter);
		}
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}

int				zerg(float x, int max)
{
	float k;
	t_rgb color;

	if (x == max)
		return (BLACK);
	k = (x / max);
	color = hsv_to_rgb(320, 0.8, 1 * k);

	return (color.c);
}

int				basic_one(float i, int max)
{
	t_rgb color;
	float k;

	if (i == max)
		return (BLACK);
	k = i / (float)max;
	color.t_rgba.r = (int)(9 * (1 - k) * (k * k * k) * 255);
	color.t_rgba.g = (int)(15 * ((1 - k) * (1 - k)) * (k * k) * 255);
	color.t_rgba.b = (int)(8.5 * ((1 - k) * (1 - k) * (1 - k)) * k * 255);
	color.t_rgba.a = 0;
	return (color.c);
}

int				black_hole(float i, int max)
{
	float k;
	t_rgb color;

	if (i == max)
		return (WHITE);
	k = (i / max);
	color = hsv_to_rgb(15, 1, 1 * k);
	return (color.c);

}

int				mix(float i, int max)
{
	t_rgb color;
	float k;

	if (i == max)
		return (BLACK);
	k = i / (float)max;
	color.t_rgba.r = (int)(6.4 * ((1 - k) * (1 - k) * (1 - k)) * k * 255);
	color.t_rgba.g = (int)(9.2 * ((1 - k) * (1 - k)) * (k * k) * 255);
	color.t_rgba.b = (int)(12.7 * (1 - k) * (k * k * k) * 255);
	color.t_rgba.a = 0;
	return (color.c);
}
