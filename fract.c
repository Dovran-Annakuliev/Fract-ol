/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dovran <dovran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:04:46 by dovran            #+#    #+#             */
/*   Updated: 2020/03/18 19:15:06 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fract(t_mlx *data, int x, int y)
{
	t_complex z;
	t_complex c;
	int i;

	z.a = 0;
	z.b = 0;
	c.a = x;
	c.b = y;
	i = -1;
	while (++i < data->iter)
	{
		z = ft_cplxadd(ft_cplxmul(z, z), c);
		if (ft_cplxmod(z) > 2)
			break;
	}
	if (i == data->iter)
		data->img.img_data[y * IW + x] = 0x000000;
	else
		data->img.img_data[y * IW + x] = 0xffffff;
}
