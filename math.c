/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:06:04 by yabad             #+#    #+#             */
/*   Updated: 2023/08/18 13:10:00 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_dda
{
	float	dx;
	float	dy;
	int		steps;
}	t_dda;

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

void	line_draw(t_mlx *mlx, float x0, float y0, float x1, float y1)
{
	t_dda	v;
	int		i;

	v.dx = x0 - x1;
	v.dy = y0 - y1;
	v.steps = ft_max(fabs(v.dx), fabs(v.dy));
	v.dx /= v.steps;
	v.dy /= v.steps;
	i = 0;
	while (i < v.steps)
	{
		mlx_put_pixel(mlx->img, x0, y0, 0xFF0000FF);
		x0 += v.dx;
		y0 += v.dy;
		i++;
	}
}
