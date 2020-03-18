/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_put.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dovran <dovran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:08:49 by dovran            #+#    #+#             */
/*   Updated: 2020/03/11 17:08:49 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUT_H
#define LIB_PUT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

#include "../libft.h"

void				ft_putchar(char c);

void				ft_putchar_fd(char c, int fd);

void				ft_putnbr(int n);

void				ft_putstr(char const *s);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

void				ft_putendl(char const *s);

void				ft_putendl_fd(char const *s, int fd);

#endif
