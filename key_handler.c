/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:19:23 by yabad             #+#    #+#             */
/*   Updated: 2023/08/27 13:32:36 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT \
			|| keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
		update_player(mlx, keydata);
}
