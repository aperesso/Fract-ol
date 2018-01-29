/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 03:29:50 by alexia            #+#    #+#             */
/*   Updated: 2018/01/27 03:30:39 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_vec3	sub_vec3(t_vec3 a, t_vec3 b)
{
	return (set_vector_3d(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec4	sub_vec4(t_vec4 a, t_vec4 b)
{
	return (set_vector_4d(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
}

t_vec2	sub_vec2(t_vec2 a, t_vec2 b)
{
	return (set_vector_2d(a.x - b.x, a.y - b.y));
}
