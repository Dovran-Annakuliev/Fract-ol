#include "../includes/fractol.h"
void	cl_init(t_cl *cl)
{
	cl_int				ret;


	ret = clGetPlatformIDs(1, &cl->platform_id, NULL);
	ret = clGetDeviceIDs(cl->platform_id, CL_DEVICE_TYPE_GPU, 1, &cl->device_id, NULL);

	cl->context = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &ret);

	cl->program = clCreateProgramWithSource(cl->context, cl->count, (const char **)cl->kernel_source, NULL, &ret);
	/* скомпилировать программу */
	ret = clBuildProgram(cl->program, 1, &cl->device_id, NULL, NULL, NULL);

	size_t log_size;
	clGetProgramBuildInfo(cl->program, cl->device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
	char *log = (char *)malloc(sizeof(char) * log_size);
	clGetProgramBuildInfo(cl->program, cl->device_id, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);
	write(open("log.txt", O_WRONLY), log, log_size);

	/* создать кернел, передваемое имя - название kernela в файле .cl */
	cl->kernel = clCreateKernel(cl->program, "array_add", &ret);
	cl->queue = clCreateCommandQueue(cl->context, cl->device_id, 0, &ret);
}

void	cl_free(t_cl *cl)
{
	cl_int		ret;

	ret = clReleaseKernel(cl->kernel);
	ret = clReleaseProgram(cl->program);
	ret = clReleaseCommandQueue(cl->queue);
	ret = clReleaseContext(cl->context);
}
