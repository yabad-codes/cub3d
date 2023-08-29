/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:03:42 by yabad             #+#    #+#             */
/*   Updated: 2023/08/28 22:04:14 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"

# define SCALE 0.8
# define WIDTH 1980
# define HEIGHT 1024
# define TILE 15
/*************************************************************/
/*                         MAP_PARSE                         */
/*************************************************************/

typedef enum e_direction {
	NO,
	SO,
	WE,
	EA
}	t_direction;

typedef struct s_map_info
{
	char		**grid;
	int			rows; //width
	int			cols; //height
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

typedef struct s_mlx_data
{
	t_map_info	*map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*img_3d;
	t_player	plyr;
}	t_mlx;

/* Player */
void		init_player(t_mlx *mlx);
void		render_player(t_mlx *mlx);
void		update_player(t_mlx *mlx, mlx_key_data_t keydata);

/* Map */
void		render_map(t_mlx *mlx);
t_map_info	*get_map_info(char *path);
bool		has_wall(t_mlx *mlx, float x, float y);

/* Math */
void		line_draw(t_mlx *mlx, int X0, int Y0, int X1, int Y1, unsigned int color);
float		deg_to_radian(float degree);
float		normalize_angle(float angle);

/* Key and mouse handling */
void		key_handler(mlx_key_data_t key, void *param);

/* Raycasting */
void		raycaster(t_mlx *mlx);
#endif
