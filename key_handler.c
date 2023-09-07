/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:19:23 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 14:46:50 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		safe_exit(mlx);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT \
			|| keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A \
			|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
		update_player(mlx, keydata);
}

void	mouse_handler(void *param)
{
	int32_t	x;
	int32_t	y;
	int32_t	dx;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_get_mouse_pos(mlx->mlx, &x, &y);
	if (x > mlx->width)
		mlx->plyr.r_angle += 0.01;
	if (x < 0)
		mlx->plyr.r_angle -= 0.01;
	dx = x - mlx->mouse.x;
	mlx->plyr.r_angle += dx * 0.001;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	render_map(mlx);
	render_player(mlx);
}
