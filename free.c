/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:26:23 by yabad             #+#    #+#             */
/*   Updated: 2023/08/30 17:03:33 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_map_scene(t_map_info *map)
{
	(void)map;
	return ;
}

void	free_textures(t_mlx *mlx)
{
	free(mlx->map->ea_text);
	free(mlx->map->no_text);
	free(mlx->map->so_text);
	free(mlx->map->we_text);
}

void	safe_exit(t_mlx *mlx)
{
	free_map_scene(mlx->map);
	free_textures(mlx);
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
