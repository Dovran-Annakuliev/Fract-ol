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
        float2 r1, r2, r3, d1, d2, d3;
        r1 = (float2)(1.0, 0.0);
        r2 = (float2)(-0.5, sqrt((float)3.0) / 2);
        r3 = (float2)(-0.5, -sqrt((float)3.0) / 2);
        float tolerance = 0.00001;

       	z = (float2)(map((float)x, 0, width - 1, minX, maxX), map((float)y, 0, height - 1, minY, maxY));
        while (i < max_iter)
        {
        	float2 tmp2;
        	float2 tmp3;
        	float2 div;

        	tmp2 = (float2)(z.x * z.x + (-1) * (z.y * z.y), z.y * z.x + z.x * z.y);
        	tmp2 = tmp2 * (float2)(3.0, 0.0);
        	tmp3 = (float2)(z.x * z.x + (-1) * (z.y * z.y), z.y * z.x + z.x * z.y);
        	tmp3 = (float2)(z.x * tmp3.x + (-1) * (z.y * tmp3.y), z.y * tmp3.x + z.x * tmp3.y);
        	tmp3 = tmp3 - (float2)(1.0, 0.0);
    		div = (float2)((tmp3.x * tmp2.x + tmp3.y * tmp2.y) / (tmp2.x * tmp2.x + tmp2.y * tmp2.y),
    						(tmp3.y * tmp2.x - tmp3.x * tmp2.y) / (tmp2.x * tmp2.x + tmp2.y * tmp2.y));
    		z -= div;
    		d1 = z - r1;
    		d2 = z - r2;
    		d3 = z - r3;
        	if ((float2)(fabs(d1.x), fabs(d.y)) < tolerance)
        		break;
        	if (fabs(d2.x) < tolerance && fabs(d2.y) < tolerance)
        		break;
        	if (fabs(d3.x) < tolerance && fabs(d3.y) < tolerance)
    			break;

        	i++;
        }
        output[y * width + x] = i;
}
