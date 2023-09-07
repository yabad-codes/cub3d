/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_components.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:07:07 by ael-maar          #+#    #+#             */
/*   Updated: 2023/09/07 19:48:10 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub.h"

t_identifier	get_type(char *type_cmp)
{
	if (!ft_strcmp(type_cmp, "NO"))
		return (NO_TEXT);
	else if (!ft_strcmp(type_cmp, "SO"))
		return (SO_TEXT);
	else if (!ft_strcmp(type_cmp, "WE"))
		return (WE_TEXT);
	else if (!ft_strcmp(type_cmp, "EA"))
		return (EA_TEXT);
	else if (!ft_strcmp(type_cmp, "F"))
		return (F);
	else if (!ft_strcmp(type_cmp, "C"))
		return (C);
	else
		return (NONE);
}

bool	extract_cmps(char *line, char *component_checks[], \
						t_map_info *map_scene)
{
	char			**component;
	t_identifier	type_cmp;

	component = ft_split(line, ' ');
	if (!component)
		exit(EXIT_FAILURE);
	if (is_newline(component))
		return (true);
	type_cmp = get_type(component[0]);
	if (type_cmp != NONE && component_checks[type_cmp] != NULL)
		error_map_cmps("Duplicate for a specific type", component, \
		component_checks, map_scene);
	else if (type_cmp != NONE && component[1] == NULL)
		error_map_cmps("No specific information for a type", component, \
		component_checks, map_scene);
	else if (type_cmp != NONE && component[2] == NULL)
		component_checks[type_cmp] = component[1];
	else
	{
		free_2d_arr(component);
		return (false);
	}
	free(component[0]);
	free(component);
	return (true);
}

char	**fill_2d_map(char **map, char *line)
{
	char	**tmp_map;
	int		size;
	int		i;

	size = 0;
	while (map && map[size])
		size++;
	tmp_map = malloc((size + 2) * sizeof(char *));
	if (!tmp_map)
		exit(EXIT_FAILURE);
	i = 0;
	while (map && map[i])
	{
		tmp_map[i] = map[i];
		i++;
	}
	tmp_map[i++] = line;
	if (line[0] != '\n' && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	tmp_map[i] = NULL;
	free(map);
	return (tmp_map);
}

void	check_unexist_map_components(t_map_info *map_scene, \
							char *component_checks[])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (component_checks[i] == NULL)
		{
			error_map_cmps("Some elements not exist in the map scene", NULL, \
			component_checks, map_scene);
		}
		i++;
	}
}

void	extract_map_cmps(t_map_info *map_scene, char *map_file, \
										char *component_checks[])
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_file(map_file, map_scene);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n' && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (!extract_cmps(line, component_checks, map_scene))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	check_unexist_map_components(map_scene, component_checks);
	while (line)
	{
		map_scene->grid = fill_2d_map(map_scene->grid, line);
		line = get_next_line(fd);
	}
	close(fd);
}
