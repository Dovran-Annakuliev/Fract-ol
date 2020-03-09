/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:23:49 by rfork             #+#    #+#             */
/*   Updated: 2020/03/09 13:29:50 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
#define FRACTOL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
//# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "libft/libft.h"
//# include "key.h"
# include "minilibx/mlx.h"

# define W 2560
# define H 1600
# define IW 2560
# define IH 1600

typedef struct	s_fract
{
	int 		fract;

}				t_fract;

typedef struct	s_image
{
	void		*image;
	int			*img_data;
	int			bbp;
	int			sz_l;
	int			end;
}				t_image;

typedef struct	s_mlx
{
	void		*window;
	void		*mlx;
//	t_point		*arr;
//	t_cam		cam;
//	t_map		map;
	t_image		img;
//	t_clr		clr;
	t_fract		*fract;
	int 		count_frct;
}				t_mlx;

int				main(int ac, char **av);
t_mlx			*start(int ac, char **av);
void			read_arg(int ac, char **av, t_mlx *data);
void			errors(int err);

#endif
