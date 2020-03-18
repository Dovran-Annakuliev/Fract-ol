/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_is.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dovran <dovran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:10:21 by dovran            #+#    #+#             */
/*   Updated: 2020/03/11 17:13:41 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_IS_H
#define LIB_IS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

#include "../libft.h"

int					ft_isspace(int c);

int					ft_iscntrl(int c);

int					ft_isupper(int c);

int					ft_islower(int c);

int					ft_isblank(int c);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

#endif
