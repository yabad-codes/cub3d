/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:26:23 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 19:34:19 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	delete_textures(t_mlx *mlx)
{
	if (mlx->no_text)
		mlx_delete_texture(mlx->no_text);
	if (mlx->so_text)
		mlx_delete_texture(mlx->so_text);
	if (mlx->ea_text)
		mlx_delete_texture(mlx->ea_text);
	if (mlx->we_text)
		mlx_delete_texture(mlx->we_text);
}

void	safe_exit(t_mlx *mlx)
{
	free_map_scene(mlx->map);
	if (mlx->img_3d)
		mlx_delete_image(mlx->mlx, mlx->img_3d);
	if (mlx->mlx)
		mlx_terminate(mlx->mlx);
	delete_textures(mlx);
	free(mlx);
	exit(EXIT_FAILURE);
}

void	cross_handler(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	safe_exit(mlx);
}
