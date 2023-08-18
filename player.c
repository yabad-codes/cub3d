/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:07:40 by yabad             #+#    #+#             */
/*   Updated: 2023/08/18 13:46:24 by yabad            ###   ########.fr       */
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
	j = mlx->plyr.y + TILE / 2 - mlx->plyr.side / 2 + mlx->plyr.side / 2;
	i = mlx->plyr.x + TILE / 2 - mlx->plyr.side / 2 + mlx->plyr.side / 2;
	line_draw(mlx, i, j, i + cos(mlx->plyr.r_angle) * mlx->plyr.side * 2, j + sin(mlx->plyr.r_angle) * mlx->plyr.side * 2);
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
}

void	update_player(t_mlx *mlx, mlx_key_data_t keydata)
{	
	if (keydata.key == MLX_KEY_UP)
	{
		mlx->plyr.x = mlx->plyr.x - mlx->plyr.speed * cos(mlx->plyr.r_angle);
		mlx->plyr.y = mlx->plyr.y - mlx->plyr.speed * sin(mlx->plyr.r_angle);
	}
	else if (keydata.key == MLX_KEY_DOWN)
	{
		mlx->plyr.x = mlx->plyr.x + mlx->plyr.speed * cos(mlx->plyr.r_angle);
		mlx->plyr.y = mlx->plyr.y + mlx->plyr.speed * sin(mlx->plyr.r_angle);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
		mlx->plyr.r_angle += 0.1;
	else
		mlx->plyr.r_angle -= 0.1;
	render_map(mlx);
	render_player(mlx);
}
