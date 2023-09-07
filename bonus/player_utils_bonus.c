/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:23:29 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 19:25:15 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

char	get_player_direction(t_mlx *mlx)
{
	if (mlx->map->direction == NO)
	{
		mlx->plyr.r_angle = deg_to_radian(270);
		return ('N');
	}
	if (mlx->map->direction == SO)
	{
		mlx->plyr.r_angle = deg_to_radian(90);
		return ('S');
	}
	if (mlx->map->direction == WE)
	{
		mlx->plyr.r_angle = deg_to_radian(0);
		return ('W');
	}
	mlx->plyr.r_angle = deg_to_radian(180);
	return ('E');
}

void	draw_player_sqr(t_mlx *mlx)
{
	int	i;
	int	j;

	j = (mlx->plyr.y - 1) * SCALE;
	while (++j < (mlx->plyr.y + mlx->plyr.side) * SCALE)
	{
		i = (mlx->plyr.x - 1) * SCALE;
		while (++i < (mlx->plyr.x + mlx->plyr.side) * SCALE)
			mlx_put_pixel(mlx->img, i, j, 0xFF0000AA);
	}
}
