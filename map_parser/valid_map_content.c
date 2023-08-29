/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:39:14 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/29 18:46:27 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	invalid_map_components(char **grid)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (not_valid_map_components(grid[y][x]))
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

bool	no_player_exist(char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'N' || grid[y][x] == 'W' \
			|| grid[y][x] == 'S' || grid[y][x] == 'E')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	duplicate_players(char **grid)
{
	int	x;
	int	count_players;
	int	y;

	y = 0;
	count_players = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'N' || grid[y][x] == 'W' \
			|| grid[y][x] == 'S' || grid[y][x] == 'E')
				count_players++;
			x++;
		}
		y++;
	}
	return (count_players != 1);
}

bool	not_surrounded_by_walls(char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == '0' || grid[y][x] == 'N' || grid[y][x] == 'E' \
			|| grid[y][x] == 'W' || grid[y][x] == 'S')
			{
				if (is_adjacent_to_empty_space(grid, x, y))
					return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

bool	valid_map_content(char **grid)
{
	if (!grid)
		return (false);
	if (invalid_map_components(grid))
		return (error_message("Invalid components in the map content") \
		, false);
	else if (no_player_exist(grid))
		return (error_message("Player not exist") \
		, false);
	else if (duplicate_players(grid))
		return (error_message("Duplicate Players"), false);
	else if (not_surrounded_by_walls(grid))
		return (error_message("The map is not surrounded by walls"), false);
	return (true);
}
