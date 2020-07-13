static float 	map(float value, float fmin, float fmax, float tmin, float tmax)
{
	return ((value - fmin) * (tmax - tmin) / (fmax - fmin) + tmin);
}

__kernel void array_add(int max_iter, float minX, float maxX, float minY, float maxY, __global float *output)
{
	int x = get_global_id(0);
	int y = get_global_id(1);
	int width = get_global_size(0);
	int height = get_global_size(1);
	int i = 0;

	float2 z, c;
	z = (float2)(0.0, 0.0);
	c.x = map((float)x, 0, width - 1, minX, maxX);
	c.y = map((float)y, 0, height - 1, minY, maxY);
	while (i < max_iter)
	{
		float2 tmp;
    	tmp = (float2)(z.x * z.x + (-1) * (z.y * z.y),z.y * z.x + z.x * z.y);
		z = tmp + c;
		if (dot(z,z) > 20.0)
			break;
		i++;
	}
	if (i == max_iter)
		output[y * width + x] = i;
	else
		output[y * width + x] = i - (log2(log2(dot(z,z)))) + 20.0;
}
