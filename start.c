/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:33:30 by rfork             #+#    #+#             */
/*   Updated: 2020/03/18 19:01:26 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*static void	displace(t_mlx *data)
{
	int i;
	int d_x;
	int d_y;

	i = -1;
	d_x = data->map.len / 2;
	d_y = data->map.heg / 2;
	while (++i < data->map.heg * data->map.len)
	{
		data->arr[i].x -= d_x;
		data->arr[i].y -= d_y;
	}
}

static void	def_values(t_mlx *data)
{
	data->map.prj = 0;
	data->cam.zoom = 2.0f;
	data->cam.zoom_z = 1.0f;
	data->cam.angle_x = 0.0f;
	data->cam.angle_y = 0.0f;
	data->cam.angle_z = 0.0f;
	data->cam.sin_x = 0.0f;
	data->cam.cos_x = 1.0f;
	data->cam.sin_y = 0.0f;
	data->cam.cos_y = 1.0f;
	data->cam.sin_z = 0.0f;
	data->cam.cos_z = 1.0f;
	data->cam.x_dp = 0.0f;
	data->cam.y_dp = 0.0f;
}*/

t_mlx		*start(int ac, char **av)
{
	t_mlx *data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		errors(0);
	if (!(data->mlx = mlx_init()))
		errors(0);
	if (!(data->window = mlx_new_window(data->mlx, W, H, "fractol")))
		errors(0);
	if (!(data->img.image = mlx_new_image(data->mlx, IW, IH)))
		errors(0);
	if (!(data->img.img_data = (int *)mlx_get_data_addr(data->img.image,
			&data->img.bbp, &data->img.sz_l, &data->img.end)))
		errors(0);
	data->iter = 200;
	read_arg(ac, av, data);
//	draw_image(data);
//	displace(data);
//	def_values(data);
	return (data);
}
