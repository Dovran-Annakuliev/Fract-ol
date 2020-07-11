/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:23:49 by rfork             #+#    #+#             */
/*   Updated: 2020/03/18 19:52:19 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
#define FRACTOL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "../libft/libft.h"
# include "key.h"

#ifdef __APPLE__
# include "../minilibx/minilibx_macos/mlx.h"
#else
# include "../minilibx/minilibx/mlx.h"
#endif


//# define W 2560
//# define H 1600
//# define IW 2560
//# define IH 1600

/*
** -------------------LINUX----------------------
*/

//# define W 1920
//# define H 1080
//# define IW 1920
//# define IH 1080

# define W 1000
# define H 1000
# define IW 1000
# define IH 1000

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
	t_fract		fract;
	int 		count_frct;
	int 		iter;

}				t_mlx;

int				main(int ac, char **av);
t_mlx			*start(int ac, char **av);
void			read_arg(int ac, char **av, t_mlx *data);
void			draw_image(t_mlx *data);
void			fractol(t_mlx *data, int x, int y);
void			errors(int err);
int				deal_key(int key, t_mlx *data);

#endif
