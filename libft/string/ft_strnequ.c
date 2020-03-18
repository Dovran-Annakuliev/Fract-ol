/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:03:20 by rfork             #+#    #+#             */
/*   Updated: 2019/09/18 16:06:13 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_str.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if ((!s1 && !s2) || !n)
		return (1);
	if ((s1 && !s2) || (!s1 && s2))
		return (0);
	i = -1;
	while (s1[++i] && s2[i] && i != n)
		if (s1[i] != s2[i])
			return (0);
	if (s1[i] == s2[i] || i == n)
		return (1);
	return (0);
}
