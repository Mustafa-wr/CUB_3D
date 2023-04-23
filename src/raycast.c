/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/04/23 21:08:22 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Squares are unit squares (side length is 1)
 * https://www.youtube.com/watch?v=eOCQfxRQ2pY
*/
void send_ray(t_raycast_res *res, t_cub3d *game, t_vec vec)
{
	int px;
	int py;
	t_point tile_step;
	t_point step;
	double raylen_x; // xIntercept
	double raylen_y; // yIntercept
	bool hit;

	px = (int)vec.p.x;
	py = (int)vec.p.y;
	if ((vec.angle >= 0 && vec.angle < 90)
		|| vec.angle > 270)
		tile_step.x = 1;
	else
		tile_step.x = -1;
	if  ((vec.angle >= 0 && vec.angle <= 90)
		|| (vec.angle >= 90 && vec.angle < 180))
		tile_step.y = 1;
	else
		tile_step.y = -1;
	raylen_x = vec.p.x - ((vec.p.y - py) / tan(vec.angle * PI / 180));
	raylen_y = vec.p.y + ((vec.p.x - px) / tan(vec.angle * PI / 180));
	step.x = tan(vec.angle * PI / 180);
	if (vec.angle == 0)
		step.y = 0;
	else
		step.y = 1 / tan(vec.angle * PI / 180);
	hit = false;
	while (!hit)
	{
		while ((raylen_x < px && tile_step.x == 1)
			|| (raylen_x > px && tile_step.x == -1))
		{
			hit = game->path[(int)raylen_x][py] != 0;
			px += tile_step.x;
			raylen_x += step.x;
			res->length = raylen_x;
			res->side = 0 + (tile_step.x == 1);
		}
		while ((raylen_y < py && tile_step.y == 1)
			|| (raylen_y > py && tile_step.y == -1))
		{
			hit = game->path[px][(int)raylen_y] != 0;
			py += tile_step.y;
			raylen_y += step.y;
			res->length = raylen_y;
			res->side = 2 + (tile_step.y == 1);
		}
	}
	
}

// void	draw_ver_lines(t_hook_vars *hook_vars);
