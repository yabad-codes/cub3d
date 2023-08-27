/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:03:27 by yabad             #+#    #+#             */
/*   Updated: 2023/08/27 13:18:20 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init(mlx->map->width, mlx->map->height, "(yabad && ael-maar)'s cub3D", false);
	if (!mlx->mlx)
	{
		// free_map(mlx->map);
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->mlx, mlx->map->width, mlx->map->height);
	if (!mlx->img)
	{
		// free_map(mlx->map);
		mlx_terminate(mlx->mlx);
		free(mlx);
		exit(EXIT_FAILURE);
	}
}

void	conductor(t_mlx *mlx)
{
	ft_init_mlx(mlx);
	init_player(mlx);
	render_map(mlx);
	render_player(mlx);
}

int	main(int ac, char **av)
{
	(void)ac, (void)av;
	t_mlx		*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx->map = get_map_info(av[1]);
	if (!mlx->map)
	{
		free(mlx);
		exit(EXIT_FAILURE);
	}
	conductor(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	mlx_key_hook(mlx->mlx, key_handler, mlx);
	mlx_loop(mlx->mlx);
	// free_all();
	return (0);
}
