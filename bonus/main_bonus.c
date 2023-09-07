/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:03:27 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 19:25:04 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	load_textures(t_mlx *mlx)
{
	mlx->no_text = NULL;
	mlx->so_text = NULL;
	mlx->ea_text = NULL;
	mlx->we_text = NULL;
	mlx->no_text = mlx_load_png(mlx->map->no_text);
	if (!mlx->no_text)
		safe_exit(mlx);
	mlx->so_text = mlx_load_png(mlx->map->so_text);
	if (!mlx->so_text)
		safe_exit(mlx);
	mlx->ea_text = mlx_load_png(mlx->map->ea_text);
	if (!mlx->ea_text)
		safe_exit(mlx);
	mlx->we_text = mlx_load_png(mlx->map->we_text);
	if (!mlx->we_text)
		safe_exit(mlx);
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->img = NULL;
	mlx->img_3d = NULL;
	mlx->mlx = mlx_init(WIDTH, HEIGHT, \
		"(yabad && ael-maar)'s cub3D", false);
	if (!mlx->mlx)
		safe_exit(mlx);
	mlx->img = mlx_new_image(mlx->mlx, mlx->map->width, mlx->map->height);
	if (!mlx->img)
		safe_exit(mlx);
	mlx->img_3d = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img_3d)
		safe_exit(mlx);
	load_textures(mlx);
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

	if (ac != 2)
		error_message("You have to specify one argument.");
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx->map = parse_map(av[1]);
	conductor(mlx);
	mlx_key_hook(mlx->mlx, key_handler, mlx);
	mlx_close_hook(mlx->mlx, cross_handler, mlx);
	mlx_loop_hook(mlx->mlx, mouse_handler, mlx);
	mlx_image_to_window(mlx->mlx, mlx->img_3d, 0, 0);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
