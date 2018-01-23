/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:46:33 by alexia            #+#    #+#             */
/*   Updated: 2018/01/22 17:47:25 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

float clamp(float x, float lowerlimit, float upperlimit)
{
	if (x < lowerlimit)
		x = lowerlimit;
 	if (x > upperlimit)
 		x = upperlimit;
	return (x);
}
