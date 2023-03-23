/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:05:15 by bammar            #+#    #+#             */
/*   Updated: 2023/03/24 02:07:34 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(void *img, t_point p1, t_point p2, int color)
{
	
	int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x = p1.x;
    float y = p1.y;
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    for (int i = 0; i <= steps; i++) {
        render_pixel(img, (t_point){x,y}, color);
        x += x_inc;
        y += y_inc;
    }
}
