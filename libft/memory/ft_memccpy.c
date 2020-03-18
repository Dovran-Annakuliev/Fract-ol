/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:46:16 by rfork             #+#    #+#             */
/*   Updated: 2020/03/02 19:58:47 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mem.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		if (((char*)src)[i] == (char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
