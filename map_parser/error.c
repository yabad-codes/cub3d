/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:05:37 by ael-maar          #+#    #+#             */
/*   Updated: 2023/09/07 19:47:45 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub.h"

void	error_message(char *message)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	error_file(char *file, t_map_info *map_scene)
{
	char	*error_file_message;

	error_file_message = ft_strjoin(file, " file doesn't exist");
	error_message(error_file_message);
	free(error_file_message);
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
