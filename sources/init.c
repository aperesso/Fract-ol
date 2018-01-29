/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 02:58:11 by alexia            #+#    #+#             */
/*   Updated: 2018/01/27 00:46:57 by alexia           ###   ########.fr       */
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
	if (!(ft_strcmp(av[1], "julia")))
		mode = 1;
	if (!(ft_strcmp(av[1], "menger_sponge")))
		mode = 2;
	if (mode == -1)
		return ((t_env *)error("unknown fractal"));
	if (!(e = ft_memalloc(sizeof(t_env))))
		return ((t_env *)error("error during environment initilisation"));
	if (!(e->mlx = init_mlx()))
		return ((t_env *)error("error during minilibx initilisation"));
	e->mode = mode;
	e->n_square = sqrt(NB_THREAD);
	if (e->n_square != 1 && e->n_square != 2 && e->n_square != 4 && e->n_square != 5)
		return ((t_env *)error("incorrect number of threads"));
	return (e);
}

static t_env	*set_menger(t_env *e)
{
	e->menger.renderer.max_steps = 204;
	e->menger.renderer.max_distance = 10;
	e->menger.renderer.epsilon = 0.1;
	e->menger.renderer.back_step = 0.001;
	e->menger.renderer.delta = 0.001;
	e->menger.scale = 3;
	e->menger.offset = set_vector_3d(1, 1, 1);
	e->menger.mat = set_identity_3();
	e->menger.light.sky_color = set_vector_3d(0.55f, 0.66f, 1);
	e->menger.light.sun_vector = set_vector_3d(0.535, 0.267, 0.802);
	e->menger.light.sun_color = set_vector_3d(1, 1, 1);
	e->menger.light.sun_size = 0.001;
	e->menger.light.sun_sharpness = 1.1;
	e->menger.theta = 57.2958f;
	e->menger.phi = 0;
	return (e);
}

static t_env	*set_env(t_env *env, t_vec2 o, double z, int i)
{
	t_env	*e;

	e = env;
	e->origine = set_vector_2d(o.x, o.y);
	e->zoom = z;
	e->iteration = i;
	return (e);
}

t_env			*launch_program(int ac, char **av)
{
	t_env	*e;

	if (!(e = check_parameters(ac, av)))
		return (NULL);
	if (e->mode == 0)
		e = set_env(e, set_vector_2d(-0.5, 0), 1.5, 200);
	if (e->mode == 1)
		e = set_env(e, set_vector_2d(-0.70176,-0.342), 1.5, 100);
	if (e->mode == 2)
	{
		e = set_env(e, set_vector_2d(0, 0), 2, 7);
		e = set_menger(e);
	}
	// if (e->mode == 1)
	// {
	// 	e->origine = set_vector_2d(-0.70176,-0.3842);
	// 	e->zoom = 2;
	// 	e->iteration = 100;
	// }
	thread_fractal(e);
	return (e);
}
