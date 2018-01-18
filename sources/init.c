/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:03:21 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/18 19:03:19 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->ptr = mlx_init()))
		return (NULL);
	if (!(mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "Fract'ol'")))
		return (NULL);
	if (!(mlx->img = init_img(mlx)))
		return (NULL);
	return (mlx);
}

static t_env	*check_parameters(int ac, char **av)
{
	t_env	*e;
	int		mode;

	mode = -1;
	if (ac != 2)
		return ((t_env *)error("usage: fractol -fractal_name"));
	if (!(ft_strcmp(av[1], "mandelbrot")))
		mode = 0;
	if (mode == -1)
		return ((t_env *)error("unknown fractal"));
	if (!(e = ft_memalloc(sizeof(t_env))))
		return ((t_env *)error("error during environment initilisation"));
	if (!(e->mlx = init_mlx()))
		return ((t_env *)error("error during minilibx initilisation"));
	e->mode = mode;
	return (e);
}

t_env			*launch_program(int ac, char **av)
{
	t_env	*e;

	if (!(e = check_parameters(ac, av)))
		return (NULL);
	if (e->mode == 0)
	{
		e->origine = set_vector_2d(-0.5, 0);
		e->zoom = 1.5;
		e->iteration = 30;
		e = mandelbrot(e);
	}
	return (e);
}
