/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:03:42 by yabad             #+#    #+#             */
/*   Updated: 2023/09/07 14:48:10 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "map_parser/get_next_line/get_next_line.h"

# define MAX_WIDTH 2500
# define MAX_HEIGHT 900
# define TILE_BOX 64
# define TILE 15
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

typedef struct s_map_info
{
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

u_int32_t	rgb_unit_to_dec(int r, int g, int b, int a);

void		free_2d_arr(char **arr);

int			comma_len(char *color_cmp);

int			map_len(char **arr);

bool		is_adjacent_to_empty_space(char **grid, size_t x, size_t y);

bool		not_valid_map_components(char cmp);

void		free_map_scene(t_map_info *map_scene);

bool		is_newline(char **component);

t_map_info	*parse_map(char *map_file);

/**************************************************************/
/*                         RAYCASTING                         */
/**************************************************************/

typedef struct s_player
{
	float	x;
	float	y;
	int		side;
	int		speed;
	float	fov;
	float	r_angle;
}	t_player;

typedef struct s_mouse
{
	int	x;
	int	y;
}	t_mouse;

typedef struct s_mlx_data
{
	t_mouse			mouse;
	t_map_info		*map;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*img_3d;
	t_player		plyr;
	mlx_texture_t	*no_text;
	mlx_texture_t	*ea_text;
	mlx_texture_t	*we_text;
	mlx_texture_t	*so_text;
	mlx_texture_t	*wall_text;
	int				width;
	int				height;
}	t_mlx;

typedef struct s_cord
{
	float	xstep;
	float	ystep;
	bool	is_vertical;
}	t_cord;

/* Player */
void		init_player(t_mlx *mlx);
void		render_player(t_mlx *mlx);
void		update_player(t_mlx *mlx, mlx_key_data_t keydata);
void		draw_player_sqr(t_mlx *mlx);
char		get_player_direction(t_mlx *mlx);

/* Map */
void		render_map(t_mlx *mlx);
bool		has_wall(t_mlx *mlx, float x, float y);
bool		wall_coalition(t_mlx *mlx, float x, float y);

/* Math */
void		line_draw(t_mlx *mlx, t_cord p0, t_cord p1, unsigned int color);
float		deg_to_radian(float degree);
float		normalize_angle(float angle);

/* Key and mouse handling */
void		key_handler(mlx_key_data_t key, void *param);
void		cross_handler(void *param);
void		mouse_handler(void *param);

/* Raycasting */
void		raycaster(t_mlx *mlx);
t_cord		vertical_intersection(t_mlx *mlx, float ray_angle);
t_cord		horizontal_intersection(t_mlx *mlx, float ray_angle);

/* Free */
void		safe_exit(t_mlx *mlx);
void		free_map_scene(t_map_info *map);

/* Wall texture */
int			calc_texture_offsetx(t_mlx *mlx, t_cord *intersection);
void		detect_and_get_wall_texture(t_mlx *mlx, bool is_vertical, \
											float ray_angle);
u_int32_t	get_text_pixel(mlx_texture_t *texture, int y, int x);

#endif
