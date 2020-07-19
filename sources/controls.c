#include "../includes/fractol.h"

static float interpolate(float start, float end, float interpolation)
{
	return (start + ((end - start) * interpolation));
}

int		zoom(int key, t_mlx *data, int x, int y)
{
	float interpolation;

	interpolation = 1.0f;
	if ((key == MIN || key == RIGHT_MB || key == WHEEL_DOWN) && data->view.zf > 1)
	{
		data->iter -= 3;
		data->view.zf -= 1.0f;
		interpolation = 1.0f / (1.0f / 1.02f);

	}
	else if (key == PLUS || key == LEFT_MB || key == WHEEL_UP)
	{
		data->iter += 3;
		data->view.zf += 1.0f;
		interpolation = 1.0f / 1.02f;
	}
	data->view.mouse_re = (float)x / (W / (data->view.maxX - data->view.minX)) + data->view.minX;
	data->view.mouse_im = (float)y / (H / (data->view.maxY - data->view.minY)) + data->view.minY;
	data->view.minX = interpolate(data->view.mouse_re, data->view.minX, interpolation);
	data->view.minY = interpolate(data->view.mouse_im, data->view.minY, interpolation);
	data->view.maxX = interpolate(data->view.mouse_re, data->view.maxX, interpolation);
	data->view.maxY = interpolate(data->view.mouse_im, data->view.maxY, interpolation);
	mlx_clear_window(data->mlx, data->window);
	draw_image(data);
	mlx_do_sync(data->mlx);
	return (0);
}

int 	arrow_move(int key, t_mlx *data)
{
	data->view.offset = OFFSET * (1.0f / (float)(pow(1.02f, (double)data->view.zf)));
	if (key == A)
	{
		data->view.minX += data->view.offset * -1;
		data->view.maxX += data->view.offset * -1;
	}
	if (key == D)
	{
		data->view.minX += data->view.offset * 1;
		data->view.maxX += data->view.offset * 1;
	}
	if (key == W)
	{
		data->view.minY += data->view.offset * -1;
		data->view.maxY += data->view.offset * -1;
	}
	if (key == S)
	{
		data->view.minY += data->view.offset * 1;
		data->view.maxY += data->view.offset * 1;
	}
	mlx_clear_window(data->mlx, data->window);
	draw_image(data);
	mlx_do_sync(data->mlx);
	return (0);
}

int		change_julia(int x, int y, t_mlx *data)
{
	float re_factor;
	float im_factor;

	if (data->view.julia_change_mod == 1)
	{
		re_factor = (MAX_RE - MIN_RE) / (W);
		im_factor = (MAX_IM - MIN_IM) / (H);
		data->view.julia_re = MIN_RE + (float) x * re_factor;
		data->view.julia_im = MAX_IM - (float) y * im_factor;
		mlx_clear_window(data->mlx, data->window);
		draw_image(data);
		mlx_do_sync(data->mlx);
	}
	return (0);
}

int 	max_iter_change(int key, t_mlx *data)
{
	if (key == Q)
		data->iter -= 10;
	if (key == E)
		data->iter += 10;
	mlx_clear_window(data->mlx, data->window);
	draw_image(data);
	mlx_do_sync(data->mlx);
	return (0);
}

int		change_color(int key, t_mlx *data)
{
	if (key == ONE)
		data->view.color_type = 1;
	if (key == TWO)
		data->view.color_type = 2;
	if (key == THREE)
		data->view.color_type = 3;
	if (key == FOUR)
		data->view.color_type = 4;
	color_fractal(data);
	mlx_do_sync(data->mlx);
	return (0);
}

