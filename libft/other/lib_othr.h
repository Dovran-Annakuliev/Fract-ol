/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_othr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dovran <dovran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:13:12 by dovran            #+#    #+#             */
/*   Updated: 2020/03/12 10:15:46 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_OTHR_H
#define LIB_OTHR_H
# define BUFF_SIZE 10000

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

# include "../libft.h"

int					ft_atoi(const char *str);

char				*ft_itoa(int n);

void				ft_bzero(void *s, size_t n);

int					get_next_line(const int fd, char **line);

#endif
