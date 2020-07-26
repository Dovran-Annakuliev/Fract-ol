#include "../includes/fractol.h"

void help(t_mlx *data)
{
	mlx_string_put(data->mlx, data->window, 50, 50, WHITE, "H - help menu");
	mlx_string_put(data->mlx, data->window, 50, 100, WHITE, "W, A, S, D - move imadge");
	mlx_string_put(data->mlx, data->window, 50, 150, WHITE, "Q, E - change gradient");
	mlx_string_put(data->mlx, data->window, 50, 200, WHITE, "1, 2, 3, 4, 5, 6 - change color");
	mlx_string_put(data->mlx, data->window, 50, 250, WHITE, "M - fix Julia");
	mlx_string_put(data->mlx, data->window, 50, 300, WHITE, "SPACE - default");
	mlx_string_put(data->mlx, data->window, 50, 350, WHITE, "ESC - exit");
}

void		draw_image(t_mlx *data)
{
	cl_mem output_buffer;

	output_buffer = clCreateBuffer(data->cl.context, CL_MEM_WRITE_ONLY, sizeof(float) * WIDTH * HEIGHT, NULL, NULL);
	clSetKernelArg(data->cl.kernel, 0, sizeof(int), &data->iter);
	clSetKernelArg(data->cl.kernel, 1, sizeof(float), &data->view.minX);
	clSetKernelArg(data->cl.kernel, 2, sizeof(float), &data->view.maxX);
	clSetKernelArg(data->cl.kernel, 3, sizeof(float), &data->view.minY);
	clSetKernelArg(data->cl.kernel, 4, sizeof(float), &data->view.maxY);
	if (data->fractal_type == 2)
	{
		clSetKernelArg(data->cl.kernel, 5, sizeof(float), &data->view.julia_re);
		clSetKernelArg(data->cl.kernel, 6, sizeof(float), &data->view.julia_im);
		clSetKernelArg(data->cl.kernel, 7, sizeof(cl_mem), &output_buffer);
	}
	else
		clSetKernelArg(data->cl.kernel, 5, sizeof(cl_mem), &output_buffer);
	clEnqueueNDRangeKernel(data->cl.queue, data->cl.kernel, data->cl.dim, NULL,
						   data->cl.global_size, NULL, 0, NULL, NULL);
	clFinish(data->cl.queue);
	clEnqueueReadBuffer(data->cl.queue, output_buffer, CL_TRUE, 0, sizeof(float) * WIDTH * HEIGHT,
						data->result, 0, NULL, NULL);
	clFinish(data->cl.queue);
	color_fractal(data);
	if (data->help_status)
		help(data);
	clReleaseMemObject(output_buffer);
}

