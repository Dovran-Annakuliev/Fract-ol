#include "includes/fractol.h"

static	void check_argv(int type)
{
	if (type != 1 && type != 2 && type != 3 && type != 4  && type != 5)
		error(1);
}

static int	mouse_button_press(int button, int x, int y, t_mlx *data)
{
	if (button == LEFT_MB || button == RIGHT_MB)
		zoom(button, data, x, y);
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
	if (key == P)
	{
		write(open("screenshot.png", O_WRONLY | O_CREAT), data->img.img_data, WIDTH * HEIGHT);
	}
	if (key == SPACE)
		redraw(key, data);
	if (key == ONE || key == TWO || key == THREE || key == FOUR)
		change_color(key,data);
	if (key == ESC)
		close_fractol(data);
	return (0);
}



int			main(int argc, char **argv)
{
	t_mlx *data;

	if (argc != 2)
		error(1);
	check_argv(ft_atoi(argv[1]));
	data = init_data(ft_atoi(argv[1]));
	data->cl.kernel_source = get_kernel_source(&data->cl, data->cl_source);
	draw_image(data);
	mlx_hook(data->win, 2, (1L << 0), key_press, data);
	mlx_hook(data->win, 4, (1L << 2), mouse_button_press, data);
	mlx_hook(data->win, 6, (1L << 2), change_julia, data);// 4 for press, 5 for release, 6 for movement
	mlx_loop(data->mlx);
	return (0);
}
