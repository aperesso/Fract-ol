/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:15:54 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/27 00:04:06 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix	create_matrix(void)
{
	t_matrix	mat;
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mat.data[i][j] = 0;
	}
	return (mat);
}

t_matrix_3	create_matrix_3d(void)
{
	t_matrix_3	mat;
	int			i;
	int			j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			mat.data[i][j] = 0;
	}
	return (mat);
}
