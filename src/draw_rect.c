/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:55:25 by bammar            #+#    #+#             */
/*   Updated: 2023/04/23 21:18:35 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @param void* Main image
 * @param t_point s: start position - top left
 * @param t_size size: struct with width and height
 * @param int color
*/
void	draw_rect(void *img, t_point s, t_size size, int color)
{
	draw_line(img, s, (t_point){s.x + size.width, s.y}, color);
	draw_line(img, s, (t_point){s.x, s.y + size.height}, color);
	draw_line(img, (t_point){s.x, s.y + size.height},
		(t_point){s.x + size.width, s.y + size.height}, color);
	draw_line(img, (t_point){s.x + size.width, s.y},
		(t_point){s.x + size.width, s.y + size.height}, color);
}
