/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dovran <dovran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:59:42 by dovran            #+#    #+#             */
/*   Updated: 2020/03/11 17:02:51 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_STR_H
#define LIB_STR_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

#include "../libft.h"

char				*ft_strcat(char *s1, const char *s2);

void				ft_strclr(char *s);

int					ft_strcmp(const char *s1, const char *s2);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strdup(const char *src);

int					ft_strequ(char const *s1, char const *s2);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

size_t				ft_strlen(char const *str);

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strncat(char *s1, const char *s2, size_t n);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strncpy(char *dest, const char *src, size_t n);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strnew(size_t size);

char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				**ft_strsplit(char const *s, char c);

char				*ft_strstr(const char *str, const char *to_find);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strtrim(char const *s);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

int					ft_count_words(char const *s, char c);

void				ft_strdel(char **as);

#endif
