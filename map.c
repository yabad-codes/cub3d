/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:48:11 by yabad             #+#    #+#             */
/*   Updated: 2023/08/28 23:43:30 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**get_grid(void)
{
	char	**grid;

	grid = (char **)malloc(sizeof(char *) * 15);
	if (!grid)
		return (NULL);
	grid[0] = ft_strdup("        1111111111111111111111111");
	grid[1] = ft_strdup("        1000000000110000000000001");
	grid[2] = ft_strdup("        1011000001110000000000001");
	grid[3] = ft_strdup("        1001000000000000000000001");
	grid[4] = ft_strdup("111111111011000001110000000000001");
	grid[5] = ft_strdup("100000000011000001110111111101111");
	grid[6] = ft_strdup("11110111111111011100000000001    ");
	grid[7] = ft_strdup("11110111111111011101010000001    ");
	grid[8] = ft_strdup("11000000110101011100100010001    ");
	grid[9] = ft_strdup("10000000000000001100000010001    ");
	grid[10] = ft_strdup("10000000000000001101010010001    ");
	grid[11] = ft_strdup("11000001110101011111011110N0111  ");
	grid[12] = ft_strdup("11110111 1110101 101111010001    ");
	grid[13] = ft_strdup("11111111 1111111 111111111111    ");
	grid[14] = NULL;
	return (grid);
}

t_map_info	*get_map_info(char *path)
{
	t_map_info	*map;

	(void)path;
	map = (t_map_info *)malloc(sizeof(t_map_info));
	if (!map)
		return (NULL);
	map->grid = get_grid();
	map->rows = 33;
	map->cols = 14;
	map->width = map->rows * TILE;
	map->height = map->cols * TILE;
	map->direction = NO;
	map->no_text = NULL;
	map->so_text = NULL;
	map->we_text = NULL;
	map->ea_text = NULL;
	map->floor_clr = 0;
	map->ceil_clr = 0;
	return (map);
}

void	draw_tile(mlx_image_t *img, int px, int py, unsigned int color)
{
	int	i;
	int	j;

	j = py * TILE;
	while (j < ((py * TILE) + TILE))
	{
		i = px * TILE;
		while (i < ((px * TILE) + TILE))
		{
			mlx_put_pixel(img, i, j, color);
			i++;
		}
		j++;
	}
}

void	render_map(t_mlx *mlx)
{
	int	i;
	int	j;
	
	j = -1;
	while (++j < mlx->map->cols)
	{
		i = -1;
		while (++i < mlx->map->rows)
		{
			if (mlx->map->grid[j][i] == '1')
				draw_tile(mlx->img, i, j, 0xFFFFFF99);
			else if (mlx->map->grid[j][i] == '0' || mlx->map->grid[j][i] == 'N' || \
					mlx->map->grid[j][i] == 'S' || \
					mlx->map->grid[j][i] == 'E' || \
					mlx->map->grid[j][i] == 'W')
				draw_tile(mlx->img, i, j, 0x77777799);
			else
				draw_tile(mlx->img, i, j, 0x00000000);
		}
	}
}

bool	has_wall(t_mlx *mlx, float x, float y)
{
	if (x < 0 || x > mlx->map->width || y < 0 || y > mlx->map->height)
		return (true);
	x = floor(x / TILE);
	y = floor(y / TILE);
	if (x < 0 || x >= mlx->map->rows || y < 0 || y >= mlx->map->cols)
		return (false);
	if (mlx->map->grid[(int)y][(int)x] == '1')
		return (true);
	return (false);
}
