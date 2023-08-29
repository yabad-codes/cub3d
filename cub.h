/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:03:42 by yabad             #+#    #+#             */
/*   Updated: 2023/08/29 19:13:10 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "map_parser/get_next_line/get_next_line.h"
# include "Libft/libft.h"

# define TILE 60
/*************************************************************/
/*                         MAP_PARSE                         */
/*************************************************************/

typedef enum e_identifier {
	NO_TEXT = 0,
	SO_TEXT,
	WE_TEXT,
	EA_TEXT,
	F,
	C,
	NONE
}	t_identifier;

typedef enum e_direction {
	NO,
	SO,
	WE,
	EA,
}	t_direction;

typedef struct s_map_info {
	char		**grid;
	int			rows;
	int			cols;
	int			width;
	int			height;
	t_direction	direction;
	char		*no_text;
	char		*so_text;
	char		*we_text;
	char		*ea_text;
	u_int32_t	floor_clr;
	u_int32_t	ceil_clr;
}	t_map_info;

void		extract_map_cmps(t_map_info *map_scene, char *map_file, \
									char *component_checks[]);
void		valid_map_scene_cmps(char *components[], t_map_info *map_scene);

bool		valid_map_content(char **grid);

void		free_2d_arr(char **arr);

void		error_map_cmps(char *message, char **component, \
					char *component_checks[], t_map_info *map_scene);

void		error_file(char *file, t_map_info *map_scene);

void		error_message(char *message);

void		error_map_content(char *message);

void		free_2d_arr(char **arr);

int			comma_len(char *color_cmp);

int			map_len(char **arr);

bool		is_adjacent_to_empty_space(char **grid, int x, int y);

bool		not_valid_map_components(char cmp);

void		free_map_scene(t_map_info *map_scene);

bool		is_newline(char **component);

t_map_info	*parse_map(char *map_file);

/**************************************************************/
/*                         RAYCASTING                         */
/**************************************************************/

#endif
