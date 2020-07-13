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

    float2 z, tmp;
  	float2 z_prev, z_prev_prev;
  	float2 c_im_z;
  	float2 c_re, c_im;

   	z = (float2)(map((float)x, 0, width - 1, minX, maxX), map((float)y, 0, height - 1, minY, maxY));
	z_prev = (float2)(0.0, 0.0);
	z_prev_prev = (float2)(0.0, 0.0);
   	c_re = (float2)(0.5667, 0.0);
   	c_im = (float2)(0.0, -0.5);
    while (i < max_iter && z.x * z.x + z.y * z.y < 4)
       	{
            z_prev_prev = z_prev;
            z_prev = z;
            z = (float2)(z_prev.x * z_prev.x - z_prev.y * z_prev.y + c_re.x + c_im.y * z_prev_prev.x,
             			-2.0 * z_prev.y * z_prev.x + c_im.y * z_prev_prev.y);
        	i++;
        }
    if (i == max_iter)
    	output[y * width + x] = i;
    else
    	output[y * width + x] = i - (log2(log2(dot(z,z)))) + 20.0;
}
