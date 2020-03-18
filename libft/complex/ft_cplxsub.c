/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cplxsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:19:26 by rfork             #+#    #+#             */
/*   Updated: 2020/03/13 12:19:26 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_cmplx.h"

void ft_cplxsub(t_complex c1, t_complex c2, t_complex c)
{
	c.a = c1.a - c2.a;
	c.b = c1.b - c2.b;
}
