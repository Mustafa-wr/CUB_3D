/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:05:15 by bammar            #+#    #+#             */
/*   Updated: 2023/04/23 21:17:24 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(void *img, t_point p1, t_point p2, int color)
{
	int		dx;
	int		dy;
	int		steps;
	float	x_inc;
	float	y_inc;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	while (steps >= 0)
	{
		render_pixel(img, (t_point){p1.x, p1.y}, color);
		p1.x += x_inc;
		p1.y += y_inc;
		steps--;
	}
}
