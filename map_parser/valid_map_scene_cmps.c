/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_scene_cmps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:48:32 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/31 15:32:48 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	are_textures_valid(char *components[], t_map_info *map_scene)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(components[i], O_RDONLY);
		if (fd == -1)
			return (false);
		close(fd);
		i++;
	}
	map_scene->no_text = components[NO_TEXT];
	map_scene->so_text = components[SO_TEXT];
	map_scene->we_text = components[WE_TEXT];
	map_scene->ea_text = components[EA_TEXT];
	return (true);
}

bool	is_color_unit_valid(char *color_unit)
{
	int	i;

	if (ft_strlen(color_unit) > 3)
		return (false);
	i = 0;
	while (color_unit[i])
	{
		if (!ft_isdigit(color_unit[i]))
			return (false);
		i++;
	}
	if (ft_atoi(color_unit) > 255)
		return (false);
	return (true);
}

u_int32_t	rgb_units_to_dec(int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 0X55);
}

bool	is_valid_rgb_color(char *color_cmp, u_int32_t *color)
{
	char	**rgb;
	int		i;

	rgb = ft_split(color_cmp, ',');
	if (!rgb)
		exit(EXIT_FAILURE);
	if (map_len(rgb) != comma_len(color_cmp) + 1)
	{
		free_2d_arr(rgb);
		return (false);
	}
	i = -1;
	while (rgb[++i])
	{
		if (!is_color_unit_valid(rgb[i]))
		{
			free_2d_arr(rgb);
			return (false);
		}
	}
	*color = rgb_units_to_dec(ft_atoi(rgb[0]), \
				ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_2d_arr(rgb);
	return (true);
}

void	valid_map_scene_cmps(char *components[], t_map_info *map_scene)
{
	if (!are_textures_valid(components, map_scene))
	{
		free_2d_arr(map_scene->grid);
		error_map_cmps("Invalid Texture Path", NULL, components, map_scene);
	}
	if (!is_valid_rgb_color(components[4], &(map_scene->floor_clr)))
	{
		free_2d_arr(map_scene->grid);
		error_map_cmps("Invalid RGB Color", NULL, components, map_scene);
	}
	if (!is_valid_rgb_color(components[5], &(map_scene->ceil_clr)))
	{
		free_2d_arr(map_scene->grid);
		error_map_cmps("Invalid RGB Color", NULL, components, map_scene);
	}
	free(components[4]);
	free(components[5]);
}
