/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:10:14 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/17 00:23:42 by aperesso         ###   ########.fr       */
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
			while (++i < MAX_ITE && (z.r * z.r + z.im * z.im) < 4)
			{
				tmp = z.r;
				z.r = z.r * z.r - z.im * z.im + c.r;
				z.im = 2 * tmp * z.im + c.im;
			}
			fill_img_pixel(e->mlx->img, make_color(i * 25 / MAX_ITE,
				0 , i * 100 / MAX_ITE), pos.x, pos.y);
		}	
	}	
	return (e);
}