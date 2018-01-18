/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:10:14 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/18 19:05:20 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_env	*mandelbrot(t_env *e)
{
	t_vec2		pos;
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			i;

	pos = set_vector_2d(-1, -1);
	while (++pos.y < HEIGHT)
	{
		pos.x = -1;
		while (++pos.x < WIDTH)
		{
			c.r = map(pos.x, set_vector_2d(0, WIDTH),
				set_vector_2d(e->origine.x - e->zoom, e->origine.x + e->zoom));
			c.im = map(pos.y, set_vector_2d(0, HEIGHT),
				set_vector_2d(e->origine.y - e->zoom, e->origine.y + e->zoom));
			z.r = 0;
			z.im = 0;
			i = -1;
			while (++i < e->iteration && (z.r * z.r + z.im * z.im) < 4)
			{
				tmp = z.r;
				z.r = z.r * z.r - z.im * z.im + c.r;
				z.im = 2 * tmp * z.im + c.im;
			}
			fill_img_pixel(e->mlx->img, make_color(i * 25 / e->iteration,
				0 , i * 100 / e->iteration), pos.x, pos.y);
		}
	}
	return (e);
}
