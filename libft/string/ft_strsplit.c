/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:05:17 by rfork             #+#    #+#             */
/*   Updated: 2020/03/02 19:24:29 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_str.h"

static void		*ft_free_split(char **arr, size_t k)
{
	size_t i;

	i = -1;
	while (++i < k)
		ft_strdel(&arr[i]);
	free(arr);
	arr = NULL;
	return (NULL);
}

static size_t	ft_count_len(const char *s, char c, size_t i)
{
	size_t k;

	k = i;
	while (s[k] && s[k] != c)
		k++;
	return (k - i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	l;
	char	**split;

	i = -1;
	if (!s)
		return (NULL);
	k = ft_count_words(s, c);
	if (!(split = (char**)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	k = -1;
	while (s[++i])
		if (s[i] != c)
		{
			l = ft_count_len(s, c, i);
			if (!(split[++k] = ft_strsub(s, i, l)))
				return (ft_free_split(split, k));
			i = i + l - 1;
		}
	split[k] = NULL;
	return (split);
}
