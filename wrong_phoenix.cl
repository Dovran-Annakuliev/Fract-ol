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

    float2 z;
  	float2 zp;
  	float2 p;

   	z = (float2)(map((float)x, 0, width - 1, minX, maxX), map((float)y, 0, height - 1, minY, maxY));
   	p = (float2)(0.5667, -0.5);
    while (i < max_iter)
    {
    	zp = z;
    	z = (float2)(z.x * z.x + (-1) * (z.y * z.y) + p.x + p.y * zp.x, 2 * z.y * z.x + p.y * zp.y);

    	if (dot(z,z) > 20.0)
    		break;
    	i++;
    }
    if (i == max_iter)
    	output[y * width + x] = i;
    else
    	output[y * width + x] = i - (log2(log2(dot(z,z)))) + 20.0;
}
