/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:25:03 by alexia            #+#    #+#             */
/*   Updated: 2018/01/22 21:31:54 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

float	mix(float v1, float v2, float a)
{
	return (v1 * (1 - a) + v2 * a);
}

t_vec3	mix_vec3(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_vec3	r;

	r.x = mix(v1.x, v2.x, v3.x);
	r.y = mix(v1.y, v2.y, v3.y);
	r.z = mix(v1.z, v2.z, v3.z);
	return (r);
}
