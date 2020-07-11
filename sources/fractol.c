#include "../includes/fractol.h"

static void julia(t_mlx *data, int x, int y)
{
	t_complex z;
	t_complex c;
	int i;

	z.a = (double)x / IW - 1.5;
	z.b = (double)y / IH - 0.5;
	c.a = -0.4;
	c.b = 0.6;
//	c.a = -0.835;
//	c.b = - 0.2321;
	i = -1;
	while (++i < data->iter)
	{
		z = ft_cplxadd(ft_cplxmul(z, z), c);
//		if (ft_cplxmod(z) > 2)
		if ((z.a * z.a + z.b * z.b) > 4)
			break;
	}
	if (i >= data->iter / 2)
		data->img.img_data[y * IW + x] = 0x106060;
	else
		data->img.img_data[y * IW + x] = 0x000000;
}

static void mandelbrot(t_mlx *data, int x, int y)
{
	t_complex z;
	t_complex c;
	int i;

	z.a = 0;
	z.b = 0;
	c.a = (double)x / IW - 1.5;
	c.b = (double)y / IH - 0.5;
	i = -1;
	while (++i < data->iter)
	{
		z = ft_cplxadd(ft_cplxmul(z, z), c);
//		if (ft_cplxmod(z) > 2)
		if ((z.a * z.a + z.b * z.b) > 4)
			break;
	}
	if (i == data->iter)
		data->img.img_data[y * IW + x] = 0x106060;
	else
		data->img.img_data[y * IW + x] = 0x000000;
}

void fractol(t_mlx *data, int x, int y)
{
	if (data->fract.fract == 1)
		julia(data, x, y);
	else if (data->fract.fract == 2)
		mandelbrot(data, x, y);
}
