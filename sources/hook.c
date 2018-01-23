/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 03:30:16 by alexia            #+#    #+#             */
/*   Updated: 2018/01/22 03:41:17 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_env	*update(t_env *e)
{
	mlx_destroy_image(e->mlx->ptr, e->mlx->img->ptr);
	free(e->mlx->img);
	e->mlx->img = init_img(e->mlx);
	thread_fractal(e);
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->win, e->mlx->img->ptr, 0, 0);
	return (e);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (e->mode == 1)
	{
		e->origine.x = map(x, set_vector_2d(0, WIDTH),
			set_vector_2d(-e->zoom, e->zoom));
		e->origine.y = map(y, set_vector_2d(0, HEIGHT),
			set_vector_2d(-e->zoom, e->zoom));
	}
	e = update(e);
	return (1);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (e->mode == 0 && (button == SCROLL_UP || button == CLICK))
	{
		e->zoom /= 1.1;
		e->origine.x = map(x, set_vector_2d(0, WIDTH),
			set_vector_2d(e->origine.x - e->zoom, e->origine.x + e->zoom));
		e->origine.y = map(y, set_vector_2d(0, HEIGHT),
			set_vector_2d(e->origine.y - e->zoom, e->origine.y + e->zoom));
	}
	if (button == SCROLL_DOWN && e->mode == 0)
	{
		e->zoom *= 1.1;
		e->origine.x = map(x, set_vector_2d(0, WIDTH),
			set_vector_2d(e->origine.x - e->zoom, e->origine.x + e->zoom));
		e->origine.y = map(y, set_vector_2d(0, HEIGHT),
			set_vector_2d(e->origine.y - e->zoom, e->origine.y + e->zoom));
	}
	e = update(e);
	return (1);
}
