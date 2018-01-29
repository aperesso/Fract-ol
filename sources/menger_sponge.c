/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menger_sponge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 03:29:50 by alexia            #+#    #+#             */
/*   Updated: 2018/01/27 03:30:39 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

void			*menger_sponge(t_thread *t)
{
	t_vec2		p;
	t_vec2		z;
	t_vec3		color;

	p.y = t->tile[0].y - 1;
	while (++p.y < t->tile[1].y)
	{
		p.x = t->tile[0].x - 1;
		while (++p.x < t->tile[1].x)
		{
			z.x = map(p.x, set_vector_2d(0, WIDTH),
				set_vector_2d(-t->env->zoom, t->env->zoom));
			z.y = map(p.y, set_vector_2d(0, HEIGHT),
				set_vector_2d(-t->env->zoom, t->env->zoom));
			color = set_vector_3d(255, 255, 255);
			fill_img_pixel(t->env->mlx->img, make_color(color.x, color.y,
				color.z), p.x, p.y);
		}
	}
	return (t);
}
