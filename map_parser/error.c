/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:05:37 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/29 20:28:25 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	error_message(char *message)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	error_file(char *file, t_map_info *map_scene)
{
	error_message(file);
	free(map_scene);
	exit(EXIT_FAILURE);
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
	error_message(message);
}
