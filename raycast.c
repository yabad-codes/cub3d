/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:28:34 by yabad             #+#    #+#             */
/*   Updated: 2023/09/01 10:05:02 by yabad            ###   ########.fr       */
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
	{
		c1.is_vertical = false;
		return (c1);
	}
	c2.is_vertical = true;
	return (c2);
}

u_int32_t	txt_color(mlx_texture_t *text, int y, int x)
{
	u_int32_t	text_pixel;

	text_pixel = ((u_int32_t*)text->pixels)[text->width * y + x];
	return ((text_pixel & 0xFF000000) >> 24 | (text_pixel & 0x00FF0000) >> 8
		| (text_pixel & 0x0000FF00) << 8 | (text_pixel & 0x000000FF) << 24);
}

void	draw_wall_height(t_mlx *mlx, int id, float wall_height, int text_offsetx)
{
	int	j;
	int	offsety;

	offsety = (mlx->height - wall_height) / 2;
	j = 0;
	while (j < mlx->height)
	{
		if (j > offsety && j < offsety + wall_height)
		{
			int text_offsety = (j - offsety) * ((float)mlx->no_text->height / wall_height);
			mlx_put_pixel(mlx->img_3d, id, j, txt_color(mlx->no_text, text_offsety, text_offsetx));
		}
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
	num_of_rays = mlx->width;
	while (id < num_of_rays)
	{
		intersection = smallest(mlx, \
			horizontal_intersection(mlx, ray_angle), \
			vertical_intersection(mlx, ray_angle));
		wall_height = (TILE / get_distance(mlx, ray_angle, intersection)) * \
						(mlx->width / 2) / tan(mlx->plyr.fov / 2);
		int texture_offsetx;
		if (intersection.is_vertical)
			texture_offsetx = (mlx->no_text->width / TILE) * \
			(intersection.ystep - (int)(intersection.ystep / TILE) * TILE);
		else
			texture_offsetx = (mlx->no_text->width / TILE) * \
			(intersection.xstep - (int)(intersection.xstep / TILE) * TILE);
		draw_wall_height(mlx, id, wall_height, texture_offsetx);
		ray_angle = normalize_angle(ray_angle + mlx->plyr.fov / num_of_rays);
		id++;
	}
}
