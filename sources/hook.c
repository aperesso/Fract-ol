/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 22:31:58 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/18 19:04:33 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_env	*update(t_env *e)
{
	mlx_destroy_image(e->mlx->ptr, e->mlx->img->ptr);
	free(e->mlx->img);
	e->mlx->img = init_img(e->mlx);
	if (e->mode == 0)
		e = mandelbrot(e);
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->win, e->mlx->img->ptr, 0, 0);
	return (e);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == SCROLL_UP)
		e->zoom /= 1.5;
	if (button == SCROLL_DOWN)
		e->zoom *= 1.5;
	if (button == CLICK)
	{
		e->origine.x = map(x, set_vector_2d(0, WIDTH),
			set_vector_2d(e->origine.x - e->zoom, e->origine.x + e->zoom));
		e->origine.y = map(y, set_vector_2d(0, HEIGHT),
			set_vector_2d(e->origine.y - e->zoom, e->origine.y + e->zoom));
	}
	e = update(e);
	return (1);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == KEY_UP)
		e->origine.y += 0.1 / e->zoom;
	else if (keycode == KEY_DOWN)
		e->origine.y -= 0.1f / e->zoom;
	else if (keycode == KEY_LEFT)
		e->origine.x += 0.1f / e->zoom;
	else if (keycode == KEY_RIGHT)
		e->origine.x -= 0.1f / e->zoom;
	else if (keycode == I)
		e->iteration++;
	e = update(e);
	ft_putnbr(keycode);
	ft_putendl("");
	return (1);
}
