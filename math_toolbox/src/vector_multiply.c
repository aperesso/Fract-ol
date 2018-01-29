/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiply                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:32:19 by alexia            #+#    #+#             */
/*   Updated: 2018/01/27 03:29:39 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/toolbox.h"

t_vec2	mul_vec2(t_vec2 a, float m)
{
	return (set_vector_2d(a.x * m, a.y * m));
}

t_vec3	mul_vec3(t_vec3 a, float m)
{
	return (set_vector_3d(a.x * m, a.y * m, a.z * m));
}

t_vec4	mul_vec4(t_vec4 a, float m)
{
	return (set_vector_4d(a.x * m, a.y * m, a.z * m, a.w * m));
}
