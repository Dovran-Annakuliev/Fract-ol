#include "includes/fractol.h"

int		draw_image(t_mlx *data)
{
	cl_init(&data->cl);
	cl_int				ret;
	cl_mem output_buffer;

	output_buffer = clCreateBuffer(data->cl.context, CL_MEM_WRITE_ONLY, sizeof(float) * WIDTH * HEIGHT, NULL, &ret);
//	printf("buffer ret = %d\n", ret);
	clSetKernelArg(data->cl.kernel, 0, sizeof(int), &data->max_iter);
	clSetKernelArg(data->cl.kernel, 1, sizeof(float), &data->view.minX);
	clSetKernelArg(data->cl.kernel, 2, sizeof(float), &data->view.maxX);
	clSetKernelArg(data->cl.kernel, 3, sizeof(float), &data->view.minY);
	clSetKernelArg(data->cl.kernel, 4, sizeof(float), &data->view.maxY);
	if (data->fractal_type == 2)
	{
		clSetKernelArg(data->cl.kernel, 5, sizeof(float), &data->view.mouse_re);
		clSetKernelArg(data->cl.kernel, 6, sizeof(float), &data->view.mouse_im);
		clSetKernelArg(data->cl.kernel, 7, sizeof(cl_mem), &output_buffer);
	}
	else
		clSetKernelArg(data->cl.kernel, 5, sizeof(cl_mem), &output_buffer);

	size_t dim = 2;
	size_t global_size[] = {WIDTH,HEIGHT};
	clEnqueueNDRangeKernel(data->cl.queue, data->cl.kernel, dim, NULL, global_size, NULL, 0, NULL, NULL);
	clFinish(data->cl.queue);
	clEnqueueReadBuffer(data->cl.queue, output_buffer, CL_TRUE, 0, sizeof(float) * WIDTH * HEIGHT, data->result, 0, NULL, NULL);
	clFinish(data->cl.queue);

//	printf("started drawing\n");
	color_fractal(data);
//	printf("finished drawing\n");

//	printf("----------started free------------\n");
	cl_free(&data->cl);
	ret = clReleaseMemObject(output_buffer);
//	printf("output free ret = %d\n", ret);
//	printf("----------finished free------------\n");
	return (0);
}
