/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:22:29 by rfork             #+#    #+#             */
/*   Updated: 2020/03/09 13:27:07 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_mlx *data;

	data = start(ac, av);
//	draw_image(data);
//	mlx_hook(data->window, 2, 1l << 0, deal_key, data);
//	mlx_loop(data->mlx);

//	int i = -1;
//	while (++i < (ac - 1))
//		printf("fract[%d] = %d\n", i, data->fract[i].fract);
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img.img_data);
	return (0);
}
