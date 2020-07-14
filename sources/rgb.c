#include "../includes/fractol.h"

t_rgb	new_rgb_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_rgb new_color;

	new_color.t_rgba.r = r;
	new_color.t_rgba.g = g;
	new_color.t_rgba.b = b;
	new_color.t_rgba.a = 0;
	return (new_color);
}

t_rgb	hsv_to_rgb(float h, float s, float v)
{
	int i;
	int f;
	float p;
	float q;
	float t;

	if (s == 0.0)
		return (new_rgb_color(v * 255, v * 255, v * 255));
	i = (int)(h / 60.0);
	f = (h / 60.0) - i;
	p = 255 * v * (1.0 - s);
	q = 255 * v * (1.0 - s * f);
	t = 255 * v * (1.0 - s * (1.0 - f));
	i %= 6;
	if (i == 0)
		return (new_rgb_color(v * 255, t, p));
	if (i == 1)
		return (new_rgb_color(q, v * 255, p));
	if (i == 2)
		return (new_rgb_color(p, v * 255, t));
	if (i == 3)
		return (new_rgb_color(p, q, v * 255));
	if (i == 4)
		return (new_rgb_color(t, p, v * 255));
	return (new_rgb_color(v * 255, p, q));
}

//t_rgb	*new_palette(t_rgb start, t_rgb end, int steps)
//{
//	t_rgb *palette;
//	int dr;
//	int dg;
//	int db;
//	int i;
//
//	palette = (t_rgb*)malloc(sizeof(t_rgb) * (steps + 2));
//	palette[0] = start;
//	palette[steps + 1] = end;
//	i = 1;
//	dr = (start.t_rgba.r - end.t_rgba.r) / (steps + 1);
//	dg = (start.t_rgba.g - end.t_rgba.g) / (steps + 1);
//	db = (start.t_rgba.b - end.t_rgba.b) / (steps + 1);
//	while (i <= steps)
//	{
//		palette[i] = new_rgb_color(palette[i - 1].t_rgba.r - dr, palette[i - 1].t_rgba.g - dg, palette[i - 1].t_rgba.b - db);
//		i++;
//	}
//	for (int j = 0; j < (steps + 2) ; ++j)
//	{
//		printf("%d = %d %d %d\n", j, palette[j].t_rgba.r, palette[j].t_rgba.g, palette[j].t_rgba.b);
//	}
//	return (palette);
//}
