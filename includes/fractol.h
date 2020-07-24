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

# define WIDTH 1920
# define HEIGHT 1080
# define HELP_WIDTH 600
# define HELP_HEIGHT 400
# define MIN_RE -2.0f
# define MAX_RE 2.0f
# define MIN_IM -1.17f
# define MAX_IM 1.17f
# define OFFSET 0.05f

# define WHITE 0xffffff
# define BLACK 0x000000
# define RED 0xfa0c0c
# define DARK_RED 0x150000
# define ORANGE 0xfa620a
# define YELLOW 0xfae20a
# define INDIGO 0x4b0082
# define PURPLE 0x220033

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
	float 		zf;
	float 		zoom;
	float 		minX;
	float 		maxX;
	float 		minY;
	float 		maxY;
	float 		offsetX;
	float 		offsetY;
	float		mouse_re;
	float		mouse_im;
	float 		offset;
	float		julia_re;
	float		julia_im;
	int 		julia_change_mod;
	int			pressed_button;
	int 		zoom_x;
	int 		zoom_y;
	int 		button;
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
	size_t 				dim;
	size_t				global_size[2];
}				t_cl;

typedef struct	s_mlx
{
	void		*window;
	void		*mlx;
	void		*help;
	int			help_status;
	t_image		img;
	t_cl		cl;
	t_view		view;
	char		*sourse_fractal;
	int			fractal_type;
	int			iter;
	float 		*result;
}				t_mlx;

int				main(int ac, char **av);
t_mlx			*data_init(char *av);
void			default_settings(t_mlx *data);
void			errors(int err);
void			error(int err);

void			draw_image(t_mlx *data);
void			color_fractal(t_mlx *data);
t_rgb			new_rgb_color(unsigned char r, unsigned char g, unsigned char b);
t_rgb			hsv_to_rgb(float h, float s, float v);
int				zerg(float x, int max);
int				basic_one(float i, int max);
int				black_hole(float i, int max);
int				mix(float i, int max);
int				change_color(int key, t_mlx *data);

char			**get_kernel_source(t_cl *cl, char *type);
void			cl_init(t_cl *cl);
void			cl_free(t_cl *cl);

int				change_julia(int x, int y, t_mlx *data);
int				zoom(int key, t_mlx *data, int x, int y);
int				max_iter_change(int x, t_mlx *data);
int				refresh(int key, t_mlx *data);
int				redraw(int key, t_mlx *data);
int				arrow_move(int key, t_mlx *data);
void			close_fractol(t_mlx *data);
int				help_menu(int key, t_mlx *data);

t_rgb			*new_palette(t_rgb start, t_rgb end, int steps);


#endif
