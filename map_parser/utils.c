/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:16:34 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/30 18:51:53 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	comma_len(char *color_cmp)
{
	int	len;

	len = 0;
	while (*color_cmp)
	{
		if (*color_cmp == ',')
			len++;
		color_cmp++;
	}
	return (len);
}

int	map_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

bool	not_valid_map_components(char cmp)
{
	return (cmp == '\n' || (cmp != '1' && cmp != '0' && cmp != 'N' \
			&& cmp != 'W' && cmp != 'E' && cmp != 'S' && cmp != ' '));
}

bool	is_adjacent_to_empty_space(char **grid, size_t x, size_t y)
{
	if (y == 0 || x == 0 || \
		!grid[y + 1] || \
		grid[y][x + 1] == ' ' || \
		grid[y][x + 1] == '\0' || \
		ft_strlen(grid[y - 1]) < (x + 1) || \
		ft_strlen(grid[y + 1]) < (x + 1) || \
		grid[y][x - 1] == ' ' || \
		grid[y + 1][x] == ' ' || \
		grid[y - 1][x] == ' ')
		return (true);
	return (false);
}

bool	is_newline(char **component)
{
	if (!ft_strcmp(component[0], "\n"))
	{
		free(component[0]);
		free(component);
		return (true);
	}
	return (false);
}
