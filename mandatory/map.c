/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:48:11 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 20:02:33 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	wall_coalition(t_mlx *mlx, float x, float y)
{
	if (x < 0 || x > mlx->map->width || y < 0 || y > mlx->map->height)
		return (true);
	if (mlx->map->grid[(int)(mlx->plyr.y / TILE)][(int)(x / TILE)] == '1')
		return (true);
	if (mlx->map->grid[(int)(y / TILE)][(int)(mlx->plyr.x / TILE)] == '1')
		return (true);
	return (false);
}

bool	has_wall(t_mlx *mlx, float x, float y)
{
	if (x < 0 || x > mlx->map->width || y < 0 || y > mlx->map->height)
		return (true);
	x = floor(x / TILE);
	y = floor(y / TILE);
	if (x < 0 || x >= mlx->map->rows || y < 0 || y >= mlx->map->cols)
		return (false);
	if (mlx->map->grid[(int)y][(int)x] == '1')
		return (true);
	return (false);
}
