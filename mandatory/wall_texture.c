/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:01:55 by ael-maar          #+#    #+#             */
/*   Updated: 2023/09/07 12:19:19 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

u_int32_t	get_text_pixel(mlx_texture_t *texture, int y, int x)
{
	t_color	color;
	int		color_pos;

	color_pos = y * texture->width + x;
	color.r = texture->pixels[color_pos++];
	color.g = texture->pixels[color_pos++];
	color.b = texture->pixels[color_pos++];
	color.a = texture->pixels[color_pos];
	return (rgb_unit_to_dec(color.r, color.g, color.b, color.a));
}

void	detect_and_get_wall_texture(t_mlx *mlx, bool is_vertical, \
										float ray_angle)
{
	bool	is_ray_facing_up;
	bool	is_ray_facing_left;

	is_ray_facing_up = ray_angle > M_PI && ray_angle < 2 * M_PI;
	is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	if (is_vertical)
	{
		if (is_ray_facing_left)
			mlx->wall_text = mlx->we_text;
		else
			mlx->wall_text = mlx->ea_text;
	}
	else
	{
		if (is_ray_facing_up)
			mlx->wall_text = mlx->no_text;
		else
			mlx->wall_text = mlx->so_text;
	}
}

int	calc_texture_offsetx(t_mlx *mlx, t_cord *intersection)
{
	if (intersection->is_vertical)
		return ((mlx->wall_text->width / TILE) * \
		(intersection->ystep - (int)(intersection->ystep / TILE) * TILE));
	else
		return ((mlx->wall_text->width / TILE) * \
		(intersection->xstep - (int)(intersection->xstep / TILE) * TILE));
}
