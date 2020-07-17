#include "../includes/fractol.h"

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

int		main(int ac, char **av)
{
	t_mlx *data;

	data = data_init(ac, av);
	data->cl.kernel_source = get_kernel_source(&data->cl, data->sourse_fractal);
	cl_init(&data->cl);
	draw_image(data);

	mlx_hook(data->window, 2, 1l << 0, key_press, data);
	mlx_hook(data->window, 4, (1L << 2), mouse_button_press, data);
	mlx_hook(data->window, 6, (1L << 2), change_julia, data);

	mlx_loop(data->mlx);
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img.img_data);
	cl_free(&data->cl);
	return (0);
}
