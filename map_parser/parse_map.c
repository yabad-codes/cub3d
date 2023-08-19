/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:45:45 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/19 14:11:30 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_map_info	*parse_map(char *map)
{
	t_map_info	*map_scene;
	char		*component_checks[6];

	ft_memset(component_checks, 0, sizeof(component_checks));
	map_scene = malloc(sizeof(t_map_info));
	if (!map_scene)
		exit(EXIT_FAILURE);
	map_scene->grid = NULL;
	// 1 - Extract components
	extract_map_cmps(&map_scene, map, component_checks);
	// 2 - Check if the components are valid one by one (COLORS, TEXTURES).
	valid_map_scene_cmps(component_checks, map_scene);
	// 3 - Check if the map content is valid (SURROUNDED BY WALLS.....).
}