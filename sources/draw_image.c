#include "../includes/fractol.h"

void		draw_image(t_mlx *data)
{
	cl_init(&data->cl);
	cl_int				ret;
	cl_mem output_buffer;

	output_buffer = clCreateBuffer(data->cl.context, CL_MEM_WRITE_ONLY, sizeof(float) * W * H, NULL, &ret);
	clSetKernelArg(data->cl.kernel, 0, sizeof(int), &data->iter);
	clSetKernelArg(data->cl.kernel, 1, sizeof(float), &data->view.minX);
	clSetKernelArg(data->cl.kernel, 2, sizeof(float), &data->view.maxX);
	clSetKernelArg(data->cl.kernel, 3, sizeof(float), &data->view.minY);
	clSetKernelArg(data->cl.kernel, 4, sizeof(float), &data->view.maxY);

	if (data->fractal_type == 1)
	{
		clSetKernelArg(data->cl.kernel, 5, sizeof(float), &data->view.mouse_re);
		clSetKernelArg(data->cl.kernel, 6, sizeof(float), &data->view.mouse_im);
		clSetKernelArg(data->cl.kernel, 7, sizeof(cl_mem), &output_buffer);
	}
	else
		clSetKernelArg(data->cl.kernel, 5, sizeof(cl_mem), &output_buffer);

	size_t dim = 2;
	size_t global_size[] = {W, H};
	clEnqueueNDRangeKernel(data->cl.queue, data->cl.kernel, dim, NULL, global_size, NULL, 0, NULL, NULL);
	clFinish(data->cl.queue);
	clEnqueueReadBuffer(data->cl.queue, output_buffer, CL_TRUE, 0, sizeof(float) * W * H, data->result, 0, NULL, NULL);
	clFinish(data->cl.queue);

	color_fractal(data);
	ret = clReleaseMemObject(output_buffer);
}
