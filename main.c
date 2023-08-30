/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:03:27 by yabad             #+#    #+#             */
/*   Updated: 2023/08/30 16:58:45 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->img = NULL;
	mlx->img_3d = NULL;
	mlx->mlx = mlx_init(WIDTH, HEIGHT, "(yabad && ael-maar)'s cub3D", false);
	if (!mlx->mlx)
		safe_exit(mlx);
	mlx->img = mlx_new_image(mlx->mlx, mlx->map->width, mlx->map->height);
	if (!mlx->img)
		safe_exit(mlx);
	mlx->img_3d = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img_3d)
		safe_exit(mlx);
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
	t_mlx	*mlx;

	(void)ac, (void)av;
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx->map = get_map_info(av[1]);
	conductor(mlx);
	mlx_key_hook(mlx->mlx, key_handler, mlx);
	mlx_close_hook(mlx->mlx, cross_handler, mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	mlx_image_to_window(mlx->mlx, mlx->img_3d, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
