/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:06:04 by yabad             #+#    #+#             */
/*   Updated: 2023/08/30 16:17:48 by yabad            ###   ########.fr       */
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

typedef struct s_dda
{
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
}	t_dda;

void	line_draw(t_mlx *mlx, t_cord p0, t_cord p1, unsigned int color)
{
	t_dda	v;
	t_cord	p;
	int		i;

	v.dx = p1.xstep - p0.xstep;
	v.dy = p1.ystep - p0.ystep;
	v.steps = abs(v.dy);
	if (abs(v.dx) > abs(v.dy))
		v.steps = abs(v.dx);
	v.xinc = v.dx / (float)v.steps;
	v.yinc = v.dy / (float)v.steps;
	p.xstep = p0.xstep;
	p.ystep = p0.ystep;
	i = 0;
	while (i <= v.steps)
	{
		mlx_put_pixel(mlx->img, p.xstep, p.ystep, color);
		p.xstep += v.xinc;
		p.ystep += v.yinc;
		i++;
	}
}

float	normalize_angle(float angle)
{
	angle = remainderf(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
