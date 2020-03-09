/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:33:16 by rfork             #+#    #+#             */
/*   Updated: 2020/03/09 13:33:16 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errors(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./fractol [argument ...]\n", 32);
		exit(0);
	}
	else if (err == 2)
	{
		write(1, "invalid argument\n", 17);
		exit(0);
	}
	else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}
