/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 03:07:49 by alexia            #+#    #+#             */
/*   Updated: 2018/01/27 03:26:20 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_vec3		cross_product(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c = set_vector_3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
	return (c);
}

float		dot_product(t_vec3 a, t_vec3 b)
{
	float	d;

	d = a.x * b.x + a.y * b.y + a.z * b.z;
	return (d);
}

t_vec2		normalize_2d(t_vec2 a)
{
	float	absolute;
	t_vec2	n;

	absolute = a.x * a.x + a.y * a.y;
	absolute = sqrt(absolute);
	n = set_vector_2d(a.x / absolute, a.y / absolute);
	return (n);
}

t_vec3		normalize_3d(t_vec3 a)
{
	float	absolute;
	t_vec3	n;

	absolute = dot_product(a, a);
	absolute = sqrt(absolute);
	n = set_vector_3d(a.x / absolute, a.y / absolute, a.z / absolute);
	return (n);
}

t_vec4		normalize_4d(t_vec4 a)
{
	float	absolute;
	t_vec4	n;

	absolute = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
	absolute = sqrt(absolute);
	n = set_vector_4d(a.x / absolute, a.y / absolute, a.z / absolute,
		a.w / absolute);
	return (n);
}
