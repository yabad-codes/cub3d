/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:08:04 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/29 20:28:28 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_map_scene(t_map_info *map_scene)
{
	free_2d_arr(map_scene->grid);
	free(map_scene->no_text);
	free(map_scene->so_text);
	free(map_scene->we_text);
	free(map_scene->ea_text);
	free(map_scene);
}
