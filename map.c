/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:48:11 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 16:33:37 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_tile(mlx_image_t *img, int px, int py, unsigned int color)
{
	int	i;
	int	j;

	j = (py * TILE) * SCALE;
	while (j < ((py * TILE) + TILE) * SCALE)
	{
		i = (px * TILE) * SCALE;
		while (i < ((px * TILE) + TILE) * SCALE)
		{
			mlx_put_pixel(img, i, j, color);
			i++;
		}
		j++;
	}
}

void	render_map(t_mlx *mlx)
{
	int	i;
	int	j;

	j = -1;
	while (++j < mlx->map->cols)
	{
		i = -1;
		while (++i < mlx->map->rows && mlx->map->grid[j][i])
		{
			if (mlx->map->grid[j][i] == '1')
				draw_tile(mlx->img, i, j, 0xFFFFFF99);
			else if (mlx->map->grid[j][i] == '0' || \
					mlx->map->grid[j][i] == 'N' || \
					mlx->map->grid[j][i] == 'S' || \
					mlx->map->grid[j][i] == 'E' || \
					mlx->map->grid[j][i] == 'W')
				draw_tile(mlx->img, i, j, 0x77777799);
			else
				draw_tile(mlx->img, i, j, 0x00000000);
		}
	}
}

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
