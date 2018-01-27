/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_identity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:19:13 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/27 00:06:20 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix	set_identity(void)
{
	t_matrix	mat;
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mat.data[i][j] = (i == j) ? 1 : 0;
	}
	return (mat);
}

t_matrix_3	set_identity_3(void)
{
	t_matrix_3	mat;
	int			i;
	int			j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			mat.data[i][j] = (i == j) ? 1 : 0;
	}
	return (mat);
}
