/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:07:40 by yabad             #+#    #+#             */
/*   Updated: 2023/08/18 17:52:56 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_player(t_mlx *mlx)
{
	float	i;
	float	j;
	
	j = mlx->plyr.y + TILE / 2 - mlx->plyr.side / 2;
	while (j < mlx->plyr.y + TILE / 2 - mlx->plyr.side / 2 + mlx->plyr.side)
	{
		i = mlx->plyr.x + TILE / 2 - mlx->plyr.side / 2;
		while (i < mlx->plyr.x + TILE / 2 - mlx->plyr.side / 2 + mlx->plyr.side)
		{
			mlx_put_pixel(mlx->img, i, j, 0xFF000050);
			i++;
		}
		j++;
	}
	raycaster(mlx);
}

char	get_player_direction(t_mlx *mlx)
{
	if (mlx->map->direction == NO)
	{
		mlx->plyr.r_angle = deg_to_radian(90);
		return ('N');
	}
	if (mlx->map->direction == SO)
	{
		mlx->plyr.r_angle = deg_to_radian(-90);
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

void	get_player_pos(t_mlx *mlx, float *x, float *y)
{
	//N, S, E, W
	int		i;
	char	plyr_dir;
	
	i = 0;
	plyr_dir = get_player_direction(mlx);
	while (mlx->map->grid[i])
	{
		if (!ft_strchr(mlx->map->grid[i], plyr_dir))
		{
			i++;
			continue ;
		}
		break ;
	}
	*y = i * TILE;
	*x = (int)(ft_strchr(mlx->map->grid[i], plyr_dir) - mlx->map->grid[i]) * TILE;
}

void	init_player(t_mlx *mlx)
{
	get_player_pos(mlx, &mlx->plyr.x, &mlx->plyr.y);
	mlx->plyr.side = TILE / 4;
	mlx->plyr.speed = 4;
	mlx->plyr.fov = deg_to_radian(60);
}

void	update_player(t_mlx *mlx, mlx_key_data_t keydata)
{
	float	new_x;
	float	new_y;
	int		sign;

	sign = 1;
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
	{
		if (keydata.key == MLX_KEY_UP)
			sign = -1;
		new_x = mlx->plyr.x + sign * mlx->plyr.speed * cos(mlx->plyr.r_angle);
		new_y = mlx->plyr.y + sign * mlx->plyr.speed * sin(mlx->plyr.r_angle);
		if (!has_wall(mlx, new_x, new_y))
		{
			mlx->plyr.x = new_x;
			mlx->plyr.y = new_y;
		}
	}
	else if (keydata.key == MLX_KEY_RIGHT)
		mlx->plyr.r_angle += 0.1;
	else
		mlx->plyr.r_angle -= 0.1;
	render_map(mlx);
	render_player(mlx);
}
