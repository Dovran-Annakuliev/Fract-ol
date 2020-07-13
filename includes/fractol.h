#ifndef FRACTOL_H
#define FRACTOL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

#ifdef __APPLE__
# include "../minilibx/minilibx_macos/mlx.h"
# include <OpenCL/cl.h>
#else
# include "../minilibx/minilibx/mlx.h"
# include <CL/opencl.h>
#endif

# include "../libft/libft.h"
# include "key.h"

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

typedef struct	s_cl
{
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	queue;
	cl_program			program;
	cl_kernel			kernel;
	char 				**kernel_source;
	int 				count;
}				t_cl;

typedef struct	s_mlx
{
	void		*window;
	void		*mlx;
	t_image		img;
	t_cl		cl;
	char		*sourse_fractal;
	int			type;
	int 		count_frct;
	int 		iter;

}				t_mlx;

int				main(int ac, char **av);
t_mlx			*data_init(int ac, char **av);
char			**get_kernel_source(t_cl *cl, char *type);
void			read_arg(int ac, char **av, t_mlx *data);
void			draw_image(t_mlx *data);
void			fractol(t_mlx *data, int x, int y);
void			errors(int err);
int				keyboard_key(int key, t_mlx *data);
void			cl_init(t_cl *cl);
void			cl_free(t_cl *cl);

#endif
