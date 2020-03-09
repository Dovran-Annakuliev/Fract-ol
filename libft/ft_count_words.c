/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dovran <dovran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:29:24 by dovran            #+#    #+#             */
/*   Updated: 2020/03/02 19:29:43 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] != c && (!s[i + 1] || s[i + 1] == c))
			count++;
	return (count);
}
