/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:28:34 by yabad             #+#    #+#             */
/*   Updated: 2023/08/30 16:27:35 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_cord	smallest(t_mlx *mlx, t_cord c1, t_cord c2)
{
	float	d1;
	float	d2;

	d1 = sqrt((c1.xstep - mlx->plyr.x) * (c1.xstep - mlx->plyr.x) + \
				(c1.ystep - mlx->plyr.y) * (c1.ystep - mlx->plyr.y));
	d2 = sqrt((c2.xstep - mlx->plyr.x) * (c2.xstep - mlx->plyr.x) + \
				(c2.ystep - mlx->plyr.y) * (c2.ystep - mlx->plyr.y));
	if (d1 < d2)
		return (c1);
	return (c2);
}

void	draw_wall_height(t_mlx *mlx, int id, float wall_height)
{
	int	j;
	int	offsety;

	offsety = (HEIGHT - wall_height) / 2;
	j = 0;
	while (j < HEIGHT)
	{
		if (j > offsety && j < offsety + wall_height)
			mlx_put_pixel(mlx->img_3d, id, j, 0xFF000055);
		else if (j < offsety)
			mlx_put_pixel(mlx->img_3d, id, j, mlx->map->ceil_clr);
		else
			mlx_put_pixel(mlx->img_3d, id, j, mlx->map->floor_clr);
		j++;
	}
}

float	get_distance(t_mlx *mlx, float ray_angle, t_cord inter)
{
	float	eucl_distance;

	eucl_distance = sqrt((inter.xstep - mlx->plyr.x) * \
				(inter.xstep - mlx->plyr.x) + \
				(inter.ystep - mlx->plyr.y) * (inter.ystep - mlx->plyr.y));
	return (eucl_distance * cos(ray_angle - mlx->plyr.r_angle));
}

void	raycaster(t_mlx *mlx)
{
	float	ray_angle;
	int		id;
	int		num_of_rays;
	float	wall_height;
	t_cord	intersection;

	ray_angle = normalize_angle(mlx->plyr.r_angle - (mlx->plyr.fov / 2));
	id = 0;
	num_of_rays = WIDTH;
	while (id < num_of_rays)
	{
		intersection = smallest(mlx, \
			horizontal_intersection(mlx, ray_angle), \
			vertical_intersection(mlx, ray_angle));
		wall_height = (TILE / get_distance(mlx, ray_angle, intersection)) * \
						(WIDTH / 2) / tan(mlx->plyr.fov / 2);
		draw_wall_height(mlx, id, wall_height);
		ray_angle = normalize_angle(ray_angle + mlx->plyr.fov / num_of_rays);
		id++;
	}
}
