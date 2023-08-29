/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:28:34 by yabad             #+#    #+#             */
/*   Updated: 2023/08/29 19:11:54 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_cord
{
	float	xstep;
	float	ystep;
	float	distance;
}	t_cord;

float	rad_to_deg(float rad)
{
	return (rad * 180 / M_PI);
}

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
		if (is_ray_facing_up)
		{
			if (has_wall(mlx, cord.xstep, cord.ystep - TILE))
				break ;
		}
		else
		{
			if (has_wall(mlx, cord.xstep, cord.ystep))
				break ;
		}
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
		if (is_ray_facing_left)
		{
			if (has_wall(mlx, cord.xstep - TILE, cord.ystep))
				break ;
		}
		else
		{
			if (has_wall(mlx, cord.xstep, cord.ystep))
				break ;
		}
		cord.xstep += sign * TILE;
		cord.ystep += sign * TILE * tan(ray_angle);
	}
	return (cord);
}

t_cord smallest(t_mlx *mlx, t_cord c1, t_cord c2)
{
    float d1;
    float d2;

    d1 = sqrt((c1.xstep - mlx->plyr.x) * (c1.xstep - mlx->plyr.x) + (c1.ystep - mlx->plyr.y) * (c1.ystep - mlx->plyr.y));
    d2 = sqrt((c2.xstep - mlx->plyr.x) * (c2.xstep - mlx->plyr.x) + (c2.ystep - mlx->plyr.y) * (c2.ystep - mlx->plyr.y));

    if (d1 < d2)
    {
        c1.distance = d1;
        return c1;
    }

    c2.distance = d2;
    return c2;
}


void	draw_wall_height(t_mlx *mlx, int id, float wall_height)
{
	int	j;
	int	offsety;

	(void)mlx;
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	offsety = (HEIGHT - wall_height) / 2;
	j = 0;
	while (j < HEIGHT)
	{
		if (j > offsety && j < offsety + wall_height)
			mlx_put_pixel(mlx->img_3d, id, j, 0xFF000055);
		else
			mlx_put_pixel(mlx->img_3d, id, j, 0x0);
		j++;
	}
}

void raycaster(t_mlx *mlx)
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
		intersection = smallest(mlx, horizontal_intersection(mlx, ray_angle), vertical_intersection(mlx, ray_angle));
		intersection.distance *= cos(ray_angle - mlx->plyr.r_angle);
		wall_height = (TILE / intersection.distance) * (WIDTH / 2) / tan(mlx->plyr.fov / 2);
		draw_wall_height(mlx, id, wall_height);
		ray_angle = normalize_angle(ray_angle + mlx->plyr.fov / num_of_rays);
		id++;
	}
}
