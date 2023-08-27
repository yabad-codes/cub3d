/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:06:04 by yabad             #+#    #+#             */
/*   Updated: 2023/08/27 20:31:48 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_dda
{
	float dx;
	float dy;
	int steps;
} t_dda;

float ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float deg_to_radian(float degree)
{
	return (degree * M_PI / 180);
}
 
// DDA Function for line generation
void line_draw(t_mlx *mlx, int X0, int Y0, int X1, int Y1, unsigned int color)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        mlx_put_pixel(mlx->img, X, Y, color); // put pixel at (X,Y)
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
    }
}

float	normalize_angle(float angle)
{
	angle = remainderf(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
