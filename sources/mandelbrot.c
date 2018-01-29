/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 03:27:33 by alexia            #+#    #+#             */
/*   Updated: 2018/01/26 22:59:21 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static float	smooth_mandelbrot(t_complex c, t_thread *t, t_vec2 p)
{
	float		i;
	double		tmp;
	t_complex	z;
	float		intensity;
	t_vec3		color;

	i = -1;
	z.r = 0;
	z.im = 0;
	while (++i < t->env->iteration && (z.r * z.r + z.im * z.im) < 1024)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.im * z.im + c.r;
		z.im = 2 * tmp * z.im + c.im;
	}
	intensity = (i == t->env->iteration) ? 0 : i / t->env->iteration;
	color.x = intensity*((-1./4.)*log((-1.0/11.112347)*intensity+0.09)-0.25);
	color.y = color.x;
	color.z = (intensity*(1.-3.4*log(intensity+0.0000000001)));
	fill_img_pixel(t->env->mlx->img, make_color(color.x * 255, color.y * 255,
		color.z * 255), p.x, p.y);
	return (i);
}

void 			*mandelbrot(t_thread *t)
{
	t_vec2		pos;
	t_complex	c;
	float		i;
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
			i = smooth_mandelbrot(c, t, pos);
		}
	}
	return (t);
}
