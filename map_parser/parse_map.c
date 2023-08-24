/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:45:45 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/24 19:56:25 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	player_direction(t_map_info *map_scene)
{
	int	x;
	int	y;

	y = 0;
	while (map_scene->grid[y])
	{
		x = 0;
		while (map_scene->grid[y][x])
		{
			if (map_scene->grid[y][x] == 'N')
				map_scene->direction = NO;
			else if (map_scene->grid[y][x] == 'S')
				map_scene->direction = SO;
			else if (map_scene->grid[y][x] == 'W')
				map_scene->direction = WE;
			else if (map_scene->grid[y][x] == 'E')
				map_scene->direction = EA;
			x++;
		}
		y++;
	}
}

void	map_resolution(t_map_info *map_scene)
{
	int	col;
	int	row_len;

	map_scene->rows = ft_strlen(map_scene->grid[0]);
	map_scene->cols = map_len(map_scene->grid);
	col = 1;
	while (col < map_scene->cols)
	{
		row_len = ft_strlen(map_scene->grid[col]);
		if (row_len > map_scene->rows)
			map_scene->rows = row_len;
		col++;
	}
	map_scene->width = map_scene->rows * TILE;
	map_scene->height = map_scene->cols * TILE;
}

t_map_info	*parse_map(char *map_file)
{
	t_map_info	*map_scene;
	char		*component_checks[6];

	ft_memset(component_checks, 0, sizeof(component_checks));
	map_scene = malloc(sizeof(t_map_info));
	if (!map_scene)
		exit(EXIT_FAILURE);
	map_scene->grid = NULL;
	// 1 - Extract components
	extract_map_cmps(map_scene, map_file, component_checks);
	// 2 - Check if the components are valid one by one (COLORS, TEXTURES).
	valid_map_scene_cmps(component_checks, map_scene);
	// 3 - Check if the map content is valid (SURROUNDED BY WALLS.....).
	if (!valid_map_content(map_scene->grid))
	{
		free_map_scene(map_scene);
		exit(EXIT_FAILURE);
	}
	map_resolution(map_scene);
	player_direction(map_scene);
	return (map_scene);
}