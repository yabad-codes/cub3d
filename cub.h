/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:03:42 by yabad             #+#    #+#             */
/*   Updated: 2023/08/18 13:46:45 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"

# define TILE 60
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
	float	r_angle;
}	t_player;

typedef struct s_mlx_data
{
	t_map_info	*map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	plyr;
}	t_mlx;

/* Player */
void		init_player(t_mlx *mlx);
void		render_player(t_mlx *mlx);
void		update_player(t_mlx *mlx, mlx_key_data_t keydata);

/* Map */
void		render_map(t_mlx *mlx);
t_map_info	*get_map_info(char *path);

/* Math */
void		line_draw(t_mlx *mlx, float x0, float y0, float x1, float y1);
float		deg_to_radian(float degree);

/* Key and mouse handling */
void		key_handler(mlx_key_data_t key, void *param);
#endif
