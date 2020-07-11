/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:22:29 by rfork             #+#    #+#             */
/*   Updated: 2020/03/18 18:45:31 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int ac, char **av)
{
	t_mlx *data;

//	printf("1\n");
	data = start(ac, av);
//	printf("2\n");
	draw_image(data);
//	printf("3\n");
//	int i = -1;
//	while (++i < (ac - 1))
//		printf("fract[%d] = %d\n", i, data->fract[i].fract);

	mlx_hook(data->window, 2, 1l << 0, deal_key, data);
	mlx_loop(data->mlx);
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img.img_data);
	return (0);
}
