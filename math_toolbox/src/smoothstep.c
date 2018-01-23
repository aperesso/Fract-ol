/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smoothstep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:49:21 by alexia            #+#    #+#             */
/*   Updated: 2018/01/22 17:51:26 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

/*
** smoothstep implements the cubic Hermite interpolation after clamping
*/

float	smoothstep(float edge0, float edge1, float x)
{
	x = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
	return (x * x * (3 - 2 * x));
}
