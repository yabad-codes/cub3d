/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:03:42 by yabad             #+#    #+#             */
/*   Updated: 2023/08/17 16:15:16 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"

/*************************************************************/
/*                         MAP_PARSE                         */
/*************************************************************/

typedef enum e_direction {
	NO,
	SO,
	WE,
	EA
}	t_direction;

typedef struct s_map_info {
	char		**grid;
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

#endif
