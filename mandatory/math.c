/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:06:04 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 19:40:26 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	deg_to_radian(float degree)
{
	return (degree * M_PI / 180);
}

float	normalize_angle(float angle)
{
	angle = remainderf(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}