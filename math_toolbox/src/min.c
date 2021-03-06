/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:46:36 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/23 17:47:17 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

float   min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float   max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}
