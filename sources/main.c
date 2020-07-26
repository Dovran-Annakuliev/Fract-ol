#include "../includes/fractol.h"

static int	mouse_button_release(int button, int x, int y, t_mlx *data)
{
	if (button == LEFT_MB || button == RIGHT_MB)
		if (x && y)
			data->view.button = 0;
	return (0);
}

static int	mouse_button_press(int button, int x, int y, t_mlx *data)
{
	if (button == LEFT_MB || button == RIGHT_MB || button == WHEEL_UP || button == WHEEL_DOWN)
	{
		data->view.button = 1;
		data->view.pressed_button = button;
		data->view.zoom_x = x;
		data->view.zoom_y = y;
		zoom(button, data, x, y);
		if (button == WHEEL_UP || button == WHEEL_DOWN)
			data->view.button = 0;
	}
	return (0);
}

static int no_events(t_mlx *data)
{
	if (data->view.button == 1)
		zoom(data->view.pressed_button, data, data->view.zoom_x, data->view.zoom_y);
	return (0);
}

static int	key_press(int key, t_mlx *data)
{
	if (key == W || key == A || key == S || key == D)
		arrow_move(key, data);
	if (key == Q || key == E)
		max_iter_change(key, data);
	if (key == R)
		refresh(key, data);
	if (key == H)
		help_menu(key, data);
	if (key == M)
		data->view.julia_change_mod = (data->view.julia_change_mod == 1) ? 0 : 1;
	if (key == SPACE)
		redraw(key, data);
	if (key == ONE || key == TWO || key == THREE || key == FOUR || key == FIVE || key == SIX)
		change_color(key,data);
	if (key == ESC)
		close_fractol(data);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx *data;
	t_mlx *data2;

	if (ac < 2 || ac > 3)
		errors(1);
	data = data_init(av[1]);
	draw_image(data);
	mlx_hook(data->window, 2, (1L << 2), key_press, data);
	mlx_hook(data->window, 4, (1L << 2), mouse_button_press, data);
	mlx_hook(data->window, 6, (1L << 2), change_julia, data);
	mlx_hook(data->window, 5, (1L << 2), mouse_button_release, data);
	mlx_loop_hook(data->mlx, no_events, data);
	mlx_loop(data->mlx);
	return (0);
}
