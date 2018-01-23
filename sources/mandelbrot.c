/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 03:27:33 by alexia            #+#    #+#             */
/*   Updated: 2018/01/22 22:55:59 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


static void		color_mandelbrot(float s_i, t_thread *t, t_vec2 pos)
{
	t_vec3	color;
	t_vec3	c;

	c = set_vector_3d(0.1, 1.0, 0.1);
	color.x = (0.5 + 0.5 * cos(3.0 + s_i * 0.25 + c.x)) * 255;
	color.y = (0.5 + 0.5 * cos(3.0 + s_i * 0.25 + c.y)) * 255;
	color.z = (0.5 + 0.5 * cos(3.0 + s_i * 0.25 + c.z)) * 255;
	fill_img_pixel(t->env->mlx->img, make_color(color.x, color.y, color.z),
		pos.x, pos.y);
}

static float	smooth_mandelbrot(t_complex c, t_thread *t)
{
	float		i;
	double		tmp;
	t_complex	z;
	float		smooth_iteration;
	float		a;

	i = -1;
	z.r = 0;
	z.im = 0;
	while (++i < t->env->iteration && (z.r * z.r + z.im * z.im) < 256 * 256)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.im * z.im + c.r;
		z.im = 2 * tmp * z.im + c.im;
	}
	smooth_iteration = i - log2(log2(z.r * z.r + z.im * z.im)) + 4.0;
	a = smoothstep(-0.1, 0.0, sin(0.5 * 6.2381));
	i = mix(i, smooth_iteration, a);
	return (i);
}

void 			*mandelbrot(t_thread *t)
{
	t_vec2		pos;
	t_complex	c;
	int			i;

	pos.y = t->tile[0].y - 1;
	while (++pos.y < t->tile[1].y)
	{
		pos.x = t->tile[0].x - 1;
		while (++pos.x < t->tile[1].x)
		{
			c.r = map(pos.x, set_vector_2d(0, WIDTH),
				set_vector_2d(t->env->origine.x - t->env->zoom,
					t->env->origine.x + t->env->zoom));
			c.im = map(pos.y, set_vector_2d(0, HEIGHT),
				set_vector_2d(t->env->origine.y - t->env->zoom,
					t->env->origine.y + t->env->zoom));
			i = smooth_mandelbrot(c, t);
			color_mandelbrot(i, t, pos);
		}
	}
	return (t);
}
