/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 03:35:00 by alexia            #+#    #+#             */
/*   Updated: 2018/01/23 17:47:58 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	color_julia(t_vec4 dmin, t_env *e, t_vec2 p)
{
	t_vec3		col;
	float			m;

	col = set_vector_3d(dmin.w, dmin.w, dmin.w);
	m = min(1.0, pow(dmin.x * 0.25, 0.4));
	col = mix_vec3(col, set_vector_3d(1, 0.8, 0.6),
		set_vector_3d(m, m, m));
	m = min(1.0, pow(dmin.y * 0.50, 0.2));
	col = mix_vec3(col, set_vector_3d(0, 0, 0),
		set_vector_3d(m, m, m));
	m = 1.0 - min(1.0, pow(dmin.z, 0.3));
	col = mix_vec3(col, set_vector_3d(1, 1, 1), set_vector_3d(m, m, m));
	col = set_vector_3d(1.25 * col.x * col.x, 1.25 * col.y * col.y,
		1.25 * col.z * col.z);
	col.x *= 255;
	col.y *= 255;
	col.z *= 255;
	fill_img_pixel(e->mlx->img, make_color(col.x, col.y, col.z), p.x, p.y);
}

static t_vec4	trapped_julia(t_complex z, t_env *e)
{
	int				i;
	double	tmp;
	t_vec4	dmin;

	i = 0;
	dmin = set_vector_4d(1000, 1000, 1000, 1000);
	while (++i < e->iteration && (z.r * z.r + z.im * z.im) < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.im * z.im + e->origine.x;
		z.im = 2 * tmp * z.im + e->origine.y;
		dmin.x = min(dmin.x, fabs(0.0 + z.im + 0.5 * sin(z.r)));
		dmin.y = min(dmin.y, fabs(1.0 + z.r + 0.5 * sin(z.im)));
		dmin.z = min(dmin.z, z.r * z.r + z.im * z.im);
		dmin.w = min(dmin.w, sqrt(pow(z.r - floor(z.r) - 0.5, 2) +
			pow(z.im - floor(z.im) - 0.5, 2)));
	}
	return (dmin);
}

void					*julia(t_thread *t)
{
	t_vec2		p;
	t_complex	z;
	t_env		*e;
	t_vec4		dmin;

	e = t->env;
	p.y = t->tile[0].y - 1;
	while (++p.y < t->tile[1].y)
	{
		p.x = t->tile[0].x - 1;
		while (++p.x < t->tile[1].x)
		{
			z.r = map(p.x, set_vector_2d(0, WIDTH),
				set_vector_2d(-e->zoom, e->zoom));
			z.im = map(p.y, set_vector_2d(0, HEIGHT),
				set_vector_2d(-e->zoom, e->zoom));
			dmin = trapped_julia(z, e);
			color_julia(dmin, e, p);
		}
	}
	return (t);
}
