/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:01:12 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/27 00:17:46 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix_3	rotatex_3(float t)
{
	t_matrix_3	rx;
	float		c;
	float		s;

	t = DEGREESTORADIANS(t);
	c = cos(t);
	s = sin(t);
	rx = set_identity_3();
	rx.data[1][1] = c;
	rx.data[1][2] = s;
	rx.data[2][1] = -s;
	rx.data[2][2] = c;
	return (rx);
}

t_matrix_3	rotatey_3(float t)
{
	t_matrix_3	ry;
	float		c;
	float		s;

	t = DEGREESTORADIANS(t);
	c = cos(t);
	s = sin(t);
	ry = set_identity_3();
	ry.data[0][0] = c;
	ry.data[0][2] = -s;
	ry.data[2][0] = s;
	ry.data[2][2] = c;
	return (ry);
}

t_matrix_3	rotatez_3(float t)
{
	t_matrix_3	rz;
	float		c;
	float		s;

	t = DEGREESTORADIANS(t);
	c = cos(t);
	s = sin(t);
	rz = set_identity_3();
	rz.data[0][0] = c;
	rz.data[0][1] = s;
	rz.data[1][0] = -s;
	rz.data[1][1] = c;
	return (rz);
}
