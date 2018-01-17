/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 21:38:36 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/16 23:04:15 by aperesso         ###   ########.fr       */
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
	mlx_hook(e->mlx->win, 2, 3, key_hook, e->mlx);
	mlx_loop(e->mlx->ptr);	
	return (EXIT_SUCCESS);
}