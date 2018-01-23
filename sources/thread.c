/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 03:12:42 by alexia            #+#    #+#             */
/*   Updated: 2018/01/22 03:39:54 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	*fractal_runner(void *arg)
{
	t_thread	*t;
	float		s_w;
	float		s_h;
	int			i;

	t = (t_thread *)arg;
	i = t->id;
	s_w = (float) WIDTH / t->env->n_square;
	s_h = (float) HEIGHT / t->env->n_square;
	t->tile[0] = set_vector_2d((i % t->env->n_square) * s_w,
		(i / t->env->n_square) * s_h);
	t->tile[1] = set_vector_2d(t->tile[0].x + s_w, t->tile[0].y + s_h);
	if (t->env->mode == 0)
		mandelbrot(t);
	if (t->env->mode == 1)
		julia(t);
	pthread_exit(NULL);
}

int			thread_fractal(t_env *e)
{
	t_thread	thread[NB_THREAD];
	t_thread	*current;
	int			i;

	i = -1;
	while (++i < NB_THREAD)
	{
		current = &thread[i];
		current->env = e;
		current->id = i;
		pthread_create(&thread[i].t, NULL, fractal_runner, &thread[i]);
	}
	i = -1;
	while (++i < NB_THREAD)
		pthread_join(thread[i].t, NULL);
	return (EXIT_SUCCESS);
}
