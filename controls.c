#include "includes/fractol.h"

int		zoom(int key, t_mlx *data, int x, int y)
{
	if ((key == MIN || key == RIGHT_MB) && data->view.zf > 1)
	{
		data->max_iter -= 3;
		data->view.zf -= 1.0f;
	}
	if (key == PLUS || key == LEFT_MB)
	{
		data->max_iter += 3;
		data->view.zf += 1.0f;
	}
	data->view.zoom = powf(ZOOM, data->view.zf);
	data->view.offsetX += MAX_RE / (WIDTH / 2.0) * (x - 640) * data->view.zoom;
	if (y >= 360)
		data->view.offsetY += MIN_IM / (HEIGHT / 2.0)  * (360 - y) * data->view.zoom;
	else
		data->view.offsetY -= MAX_IM / (HEIGHT / 2.0)  * (360 - y) * data->view.zoom;
	data->view.minX = MIN_RE * data->view.zoom + data->view.offsetX;
	data->view.maxX = MAX_RE * data->view.zoom + data->view.offsetX;
	data->view.minY = MIN_IM * data->view.zoom + data->view.offsetY;
	data->view.maxY = MAX_IM * data->view.zoom + data->view.offsetY;
	mlx_clear_window(data->mlx, data->win);
	draw_image(data);
	mlx_do_sync(data->mlx);
	return (0);
}

int 	arrow_move(int key, t_mlx *data)
{
	float	offset;
	float	zoom;

	zoom = data->view.zoom;
	offset = OFFSET * zoom;
	if (key == A)
		data->view.offsetX -= offset;
	if (key == D)
		data->view.offsetX += offset;
	if (key == W)
		data->view.offsetY -= offset;
	if (key == S)
		data->view.offsetY += offset;
	data->view.minX = MIN_RE * zoom + data->view.offsetX;
	data->view.maxX = MAX_RE * zoom + data->view.offsetX;
	data->view.minY = MIN_IM * zoom + data->view.offsetY;
	data->view.maxY = MAX_IM * zoom + data->view.offsetY;
	mlx_clear_window(data->mlx, data->win);
	draw_image(data);
	mlx_do_sync(data->mlx);
	return (0);
}

int		change_julia(int x, int y, t_mlx *data)
{
	float re_factor;
	float im_factor;

	re_factor = (MAX_RE - MIN_RE) / (WIDTH);
	im_factor = (MAX_IM - MIN_IM) / (HEIGHT);
	data->view.mouse_re = MIN_RE + x * re_factor;
	data->view.mouse_im = MAX_IM - y * im_factor;
	mlx_clear_window(data->mlx, data->win);
	draw_image(data);
	mlx_do_sync(data->mlx);
	return (0);
}

int 	max_iter_change(int key, t_mlx *data)
{
	if (key == Q)
		data->max_iter -= 10;
	if (key == E)
		data->max_iter += 10;
	mlx_clear_window(data->mlx, data->win);
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

