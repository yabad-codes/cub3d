/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:07:40 by yabad             #+#    #+#             */
/*   Updated: 2023/08/29 19:09:49 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_player_sqr(t_mlx *mlx)
{
	int	i;
	int	j;

	j = mlx->plyr.y - 1;
	while (++j < mlx->plyr.y + mlx->plyr.side)
	{
		i = mlx->plyr.x - 1;
		while (++i < mlx->plyr.x + mlx->plyr.side)
			mlx_put_pixel(mlx->img, i, j, 0xFF0000AA);
	}
}

void	render_player(t_mlx *mlx)
{
	mlx_put_pixel(mlx->img, mlx->plyr.x, mlx->plyr.y, 0x0000FFFF);
	draw_player_sqr(mlx);
	line_draw(mlx, mlx->plyr.x + mlx->plyr.side / 2, \
					mlx->plyr.y + mlx->plyr.side / 2, \
					mlx->plyr.x + mlx->plyr.side / 2 + cos(mlx->plyr.r_angle) * 20, \
					mlx->plyr.y + mlx->plyr.side / 2 + sin(mlx->plyr.r_angle) * 20, 0xFF0000AA);
	raycaster(mlx);
}

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
	*y = i * TILE + TILE / 2;
	*x = (int)(ft_strchr(mlx->map->grid[i], plyr_dir) - mlx->map->grid[i]) * TILE + TILE / 2;
}

void	init_player(t_mlx *mlx)
{
	get_player_pos(mlx, &mlx->plyr.x, &mlx->plyr.y);
	mlx->plyr.side = TILE / 2;
	mlx->plyr.speed = 4;
	mlx->plyr.fov = deg_to_radian(60);
}

void	change_player_coor(t_mlx *mlx, int sign, int dir)
{
	float	new_x;
	float	new_y;

	new_x = mlx->plyr.x + sign * mlx->plyr.speed * cos(mlx->plyr.r_angle * dir);
	new_y = mlx->plyr.y + sign * mlx->plyr.speed * sin(mlx->plyr.r_angle * dir);
	if (!has_wall(mlx, new_x, new_y))
	{
		mlx->plyr.x = new_x;
		mlx->plyr.y = new_y;
	}
}

void	update_player(t_mlx *mlx, mlx_key_data_t keydata)
{
	int		sign;
	int		dir;

	sign = 1;
	dir = 1;
	if (keydata.key == MLX_KEY_W || \
				keydata.key == MLX_KEY_S || \
				keydata.key == MLX_KEY_A || \
				keydata.key == MLX_KEY_D)
	{
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_A)
			sign = -1;
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
			dir = 0;
		change_player_coor(mlx, sign, dir);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
		mlx->plyr.r_angle += 0.15;
	else
		mlx->plyr.r_angle -= 0.15;
	render_map(mlx);
	render_player(mlx);
}
