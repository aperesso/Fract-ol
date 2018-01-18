/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c  		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:10:14 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/18 19:05:20 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_env	*julia(t_env *e)
{
	t_vec2		p;
	t_complex	z;
	t_complex	c;
	int			i;
	double		tmp;

	c.r = (double) e->origine.x;
	c.im = (double) e->origine.y;
	p = set_vector_2d(-1, -1);
	while (++p.y < HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIDTH)
		{
			z.r = map(p.x, set_vector_2d(0, WIDTH),
				set_vector_2d(-e->zoom, e->zoom));
			z.im = map(p.y, set_vector_2d(0, HEIGHT),
				set_vector_2d(-e->zoom, e->zoom));
			i = 0;
			while (++i < e->iteration && (z.r * z.r + z.im * z.im) < 4)
			{
				tmp = z.r;
				z.r = z.r * z.r - z.im * z.im + c.r;
				z.im = 2 * tmp * z.im + c.im;
			}
			fill_img_pixel(e->mlx->img, make_color(i * 25 / e->iteration,
				0 , i * 100 / e->iteration), p.x, p.y);
		}
	}
	return (e);
}
