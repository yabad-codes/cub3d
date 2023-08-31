/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:26:23 by yabad             #+#    #+#             */
/*   Updated: 2023/08/30 20:59:35 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	safe_exit(t_mlx *mlx)
{
	free_map_scene(mlx->map);
	if (mlx->img)
		mlx_delete_image(mlx->mlx, mlx->img);
	if (mlx->img_3d)
		mlx_delete_image(mlx->mlx, mlx->img_3d);
	if (mlx->mlx)
		mlx_terminate(mlx->mlx);
	free(mlx);
	exit(EXIT_FAILURE);
}

void	cross_handler(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	safe_exit(mlx);
}
