/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:16:34 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/23 13:04:57 by ael-maar         ###   ########.fr       */
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

bool	is_adjacent_to_empty_space(char **grid, int x, int y)
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
