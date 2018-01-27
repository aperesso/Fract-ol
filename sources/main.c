/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:57:57 by alexia            #+#    #+#             */
/*   Updated: 2018/01/26 22:56:54 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*error(char *error_message)
{
	ft_putendl(error_message);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (!(e = launch_program(ac, av)))
		return (EXIT_FAILURE);
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->win, e->mlx->img->ptr, 0, 0);
	//mlx_hook(e->mlx->win, 2, 3, key_hook, e);
	//mlx_hook(e->mlx->win, 6, (1L << 6), mouse_move, e);
	mlx_hook(e->mlx->win, 4, (1L << 2), mouse_hook, e);
	mlx_loop(e->mlx->ptr);
	return (EXIT_SUCCESS);
}
