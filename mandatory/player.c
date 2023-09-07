/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:07:40 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 20:03:08 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_player(t_mlx *mlx)
{
	raycaster(mlx);
}

void	get_player_pos(t_mlx *mlx, float *x, float *y)
{
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
	*y = i * TILE + TILE / 2;
	*x = ((int)(ft_strchr(mlx->map->grid[i], plyr_dir) - \
			mlx->map->grid[i])*TILE) + TILE / 2;
}

void	init_player(t_mlx *mlx)
{
	get_player_pos(mlx, &mlx->plyr.x, &mlx->plyr.y);
	mlx->plyr.side = TILE / 2 * SCALE;
	mlx->plyr.speed = 4;
	mlx->plyr.fov = deg_to_radian(60);
}

void	change_player_coor(t_mlx *mlx, int sign, int key)
{
	float	new_x;
	float	new_y;
	float	direction_angle;

	direction_angle = mlx->plyr.r_angle;
	if (key == MLX_KEY_D || key == MLX_KEY_A)
		direction_angle += M_PI / 2;
	new_x = mlx->plyr.x + sign * mlx->plyr.speed * cos(direction_angle);
	new_y = mlx->plyr.y + sign * mlx->plyr.speed * sin(direction_angle);
	if (!wall_coalition(mlx, new_x, new_y))
	{
		mlx->plyr.x = new_x;
		mlx->plyr.y = new_y;
	}
}

void	update_player(t_mlx *mlx, mlx_key_data_t keydata)
{
	int		sign;
	float	spin_speed;

	sign = 1;
	spin_speed = 0.1;
	if (keydata.key == MLX_KEY_W || \
				keydata.key == MLX_KEY_S || \
				keydata.key == MLX_KEY_A || \
				keydata.key == MLX_KEY_D)
	{
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_A)
			sign = -1;
		change_player_coor(mlx, sign, keydata.key);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
		mlx->plyr.r_angle += spin_speed;
	else
		mlx->plyr.r_angle -= spin_speed;
	render_player(mlx);
}
