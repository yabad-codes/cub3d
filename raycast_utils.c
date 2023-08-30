/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:27:08 by yabad             #+#    #+#             */
/*   Updated: 2023/08/30 16:27:39 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_cord	horizontal_intersection(t_mlx *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;
	bool	is_ray_facing_up;

	is_ray_facing_up = ray_angle > M_PI && ray_angle < 2 * M_PI;
	sign = 1;
	if (is_ray_facing_up)
		sign = -1;
	cord.ystep = floor(mlx->plyr.y / TILE) * TILE;
	if (!is_ray_facing_up)
		cord.ystep += TILE;
	cord.xstep = mlx->plyr.x + (cord.ystep - mlx->plyr.y) / tan(ray_angle);
	while (true)
	{
		if ((is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep - TILE)) || \
			(!is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += sign * TILE / tan(ray_angle);
		cord.ystep += sign * TILE;
	}
	return (cord);
}

t_cord	vertical_intersection(t_mlx *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;
	bool	is_ray_facing_left;

	is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	sign = 1;
	cord.xstep = ceil(mlx->plyr.x / TILE) * TILE;
	if (is_ray_facing_left)
	{
		cord.xstep -= TILE;
		sign = -1;
	}
	cord.ystep = mlx->plyr.y - (mlx->plyr.x - cord.xstep) * tan(ray_angle);
	while (true)
	{
		if ((is_ray_facing_left && \
				has_wall(mlx, cord.xstep - TILE, cord.ystep)) || \
			(!is_ray_facing_left && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += sign * TILE;
		cord.ystep += sign * TILE * tan(ray_angle);
	}
	return (cord);
}
