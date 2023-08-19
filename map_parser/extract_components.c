/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_components.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:07:07 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/19 18:22:07 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	error_file(char *file)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	error_map_cmps(char *message, char **component, \
					char *component_checks[], t_map_info *map_scene)
{
	int	i;

	i = 0;
	while (component && component[i])
		free(component[i++]);
	free(component);
	i = 0;
	while (i < 6)
		free(component_checks[i++]);
	free(map_scene);
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

t_direction	get_type(char *type_cmp)
{
	if (!ft_strcmp(type_cmp, "NO"))
		return (NO);
	else if (!ft_strcmp(type_cmp, "SO"))
		return (SO);
	else if (!ft_strcmp(type_cmp, "WE"))
		return (WE);
	else if (!ft_strcmp(type_cmp, "EA"))
		return (EA);
	else if (!ft_strcmp(type_cmp, "F"))
		return (F);
	else if (!ft_strcmp(type_cmp, "C"))
		return (C);
	else
		return (NONE);
}

bool	extract_cmps(char *line, char *component_checks[], t_map_info *map_scene)
{
	char		**component;
	t_direction	type_cmp;

	component = ft_split(line, ' ');
	if (!component)
		exit(EXIT_FAILURE);
	if (!ft_strcmp(component[0], "\n"))
		return (true);
	type_cmp = get_type(component[0]);
	if (type_cmp != NONE && component_checks[type_cmp] != NULL)
		error_map_cmps("Duplicate for a specific type", component, \
		component_checks, map_scene);
	else if (type_cmp != NONE && component[1] == NULL)
		error_map_cmps("No specific information for a type", component, \
		component_checks, map_scene);
	else if (type_cmp != NONE && component[2] == NULL)
	{
		component_checks[type_cmp] = component[1];
		free(component[0]);
		free(component);
	}
	else
	{
		free_2d_arr(component);
		return (false);
	}
	return (true);
}

char	**fill_2d_map(char **map, char *line)
{
	char	**tmp_map;
	int		size;

	size = 0;
	while (map && map[size])
		size++;
	tmp_map = malloc((size + 2) * sizeof(char *));
	if (!tmp_map)
		exit(EXIT_FAILURE);
	ft_memcpy(tmp_map, map, sizeof(tmp_map));
	tmp_map[size++] = line;
	if (line[0] != '\n')
		line[ft_strlen(line) - 1] = '\0';
	tmp_map[size] = NULL;
	free(map);
	return (tmp_map);
}

void	check_unexist_map_components(t_map_info **map_scene, \
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

void	extract_map_cmps(t_map_info **map_cmps, char *map_scene, \
										char *component_checks[])
{
	char	*line;
	char	**component;
	int		fd;

	fd = open(map_scene, O_RDONLY);
	if (fd == -1)
		error_file(map_scene);
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	while (line)
	{
		if (!extract_cmps(line, component_checks, map_cmps))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	check_unexist_map_components(map_scene, component_checks);
	while (line)
	{
		(*map_cmps)->grid = fill_2d_map((*map_cmps)->grid, line);
		line = get_next_line(fd);
		if (!line)
			exit(EXIT_FAILURE);
	}
	close(fd);
}
