/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:07:40 by yabad             #+#    #+#             */
/*   Updated: 2023/08/30 17:21:51 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_player(t_mlx *mlx)
{
	t_cord	init;
	t_cord	dst;

	init.xstep = mlx->plyr.x + mlx->plyr.side / 2;
	init.ystep = mlx->plyr.y + mlx->plyr.side / 2;
	dst.xstep = mlx->plyr.x + mlx->plyr.side / 2 + cos(mlx->plyr.r_angle) * 20;
	dst.ystep = mlx->plyr.y + mlx->plyr.side / 2 + sin(mlx->plyr.r_angle) * 20;
	draw_player_sqr(mlx);
	line_draw(mlx, init, dst, 0xFF0000AA);
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
	mlx->plyr.side = TILE / 2;
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
	if (!has_wall(mlx, new_x, new_y))
	{
		mlx->plyr.x = new_x;
		mlx->plyr.y = new_y;
	}
}

void	update_player(t_mlx *mlx, mlx_key_data_t keydata)
{
	int		sign;

	sign = 1;
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
		mlx->plyr.r_angle += 0.15;
	else
		mlx->plyr.r_angle -= 0.15;
	render_map(mlx);
	render_player(mlx);
}
