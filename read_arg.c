/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:33:32 by rfork             #+#    #+#             */
/*   Updated: 2020/03/09 13:29:41 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	read_arg(int ac, char **av, t_mlx *data)
{
	int i;
	int j;

	if (ac < 2)
		errors(1);
	data->fract = (t_fract *)malloc(sizeof(t_fract) * (ac - 1));
	i = 0;
	j = 0;
	while (++i < ac)
	{
		if ((ft_strcmp(av[i], "Julia")) == 0)
			data->fract[j].fract = 1;
		else if ((ft_strcmp(av[i], "Mandelbrot")) == 0)
			data->fract[j].fract = 2;
		else if ((ft_strcmp(av[i], "Dragon")) == 0)
			data->fract[j].fract = 3;
		else
			errors(2);
		j++;
	}
}
