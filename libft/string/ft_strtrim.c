/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:30:13 by rfork             #+#    #+#             */
/*   Updated: 2020/03/02 19:42:21 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_str.h"

static char	*ft_check2(void)
{
	char *trim;

	if (!(trim = (char *)malloc(sizeof(char) * (1))))
		return (NULL);
	trim[0] = '\0';
	return (trim);
}

static char	*ft_check1(char const *s, int start, int end)
{
	int		i;
	int		j;
	char	*trim;

	j = 0;
	i = start;
	if (!(trim = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (i < (end + 1))
	{
		trim[j] = s[i];
		j++;
		i++;
	}
	trim[j] = '\0';
	return (trim);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*trim;

	if (!s)
		return (NULL);
	i = -1;
	start = 0;
	end = 0;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i])
		start++;
	i--;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			end = i;
	if (start > end)
		trim = ft_check2();
	else
		trim = ft_check1(s, start, end);
	return (trim);
}
