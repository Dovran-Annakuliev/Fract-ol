/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:26:37 by rfork             #+#    #+#             */
/*   Updated: 2019/09/18 16:06:12 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int cmp;

	i = -1;
	cmp = 0;
	while (s1[++i] && s2[i] && cmp == 0)
		cmp = (unsigned char)s1[i] - (unsigned char)s2[i];
	if ((s1[i] && !s2[i]) || (!s1[i] && s2[i]))
		cmp = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (cmp);
}
