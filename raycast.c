/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:28:34 by yabad             #+#    #+#             */
/*   Updated: 2023/08/18 18:06:47 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycaster(t_mlx *mlx)
{
	float	ray_angle;
	int		i;
	int		num_of_rays;

	ray_angle = mlx->plyr.r_angle - (mlx->plyr.fov / 2);
	i = 0;
	num_of_rays = mlx->map->width;
	while (i < num_of_rays)
	{
		line_draw(mlx, mlx->plyr.x + TILE / 2, \
						mlx->plyr.y + TILE / 2, \
						mlx->plyr.x + TILE / 2 + cos(ray_angle) * 150, \
					  	mlx->plyr.y + TILE / 2 + sin(ray_angle) * 150);
		ray_angle += mlx->plyr.fov / num_of_rays;
		i++;
	}
}
