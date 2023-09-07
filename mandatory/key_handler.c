/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:19:23 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 19:32:11 by yabad            ###   ########.fr       */
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
