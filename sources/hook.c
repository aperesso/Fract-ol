/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 22:31:58 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/16 22:36:04 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == ESC)
		exit(0);
	ft_putnbr(keycode);
	ft_putendl("");
	return (1);
}