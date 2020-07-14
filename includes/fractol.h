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
# include "color_schemes.h"

# define W 1000
# define H 1000
//# define IW 1000
//# define IH 1000

typedef union	u_rgb
{
	unsigned int c;
	struct s_rgba
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char a;
	} t_rgba;
}				t_rgb;

typedef struct	s_image
{
	void		*image;
	int			*img_data;
	int			bbp;
	int			sz_l;
	int			end;
}				t_image;

typedef	struct	s_view
{
	int			color_type;
	double 		zf;
	double 		zoom;
	double 		minX;
	double 		maxX;
	double 		minY;
	double 		maxY;
	double 		offsetX;
	double 		offsetY;
	double 		prev_mouseX;
	double 		prev_mouseY;
	double 		mouseShiftX;
	double 		mouseShiftY;
	double		mouse_re;
	double		mouse_im;

}				t_view;

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
	t_view		view;
	char		*sourse_fractal;
	int			fractal_type;
	int			iter;
	double 		*result;
}				t_mlx;

int				main(int ac, char **av);
t_mlx			*data_init(int ac, char **av);
void			errors(int err);

int				keyboard_key(int key, t_mlx *data);
int				mouse_key(int key, t_mlx *data);
int				change_julia(int key, t_mlx *data);

void			draw_image(t_mlx *data);
void			color_fractal(t_mlx *data);
t_rgb			new_rgb_color(unsigned char r, unsigned char g, unsigned char b);
t_rgb			hsv_to_rgb(float h, float s, float v);

//void			read_arg(int ac, char **av, t_mlx *data);
//void			fractol(t_mlx *data, int x, int y);

char			**get_kernel_source(t_cl *cl, char *type);
void			cl_init(t_cl *cl);
void			cl_free(t_cl *cl);

#endif
