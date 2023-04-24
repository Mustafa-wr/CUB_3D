/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/04/24 18:41:33 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Squares are unit squares (side length is 1)
 * https://www.youtube.com/watch?v=eOCQfxRQ2pY
*/
void send_ray(t_raycast_res *res, t_cub3d *game, t_vec ray)
{
	int	px;
	int	py;
	t_point	tile_step;
	t_point	step;
	double raylen_x; // xIntercept
	double raylen_y; // yIntercept
	bool hit;

	px = (int)ray.p.x;
	py = (int)ray.p.y;
	if ((ray.angle >= 0 && ray.angle < PI / 2)
		|| ray.angle > 3 * PI / 2)
		tile_step.x = 1;
	else
		tile_step.x = -1;
	if  ((ray.angle >= 0 && ray.angle <= PI / 2)
		|| (ray.angle >= PI / 2 && ray.angle < PI))
		tile_step.y = 1;
	else
		tile_step.y = -1;
	raylen_x = ray.p.x - ((ray.p.y - py) / tan(ray.angle));
	raylen_y = ray.p.y + ((ray.p.x - px) / tan(ray.angle));
	step.x = tan(ray.angle);
	if (ray.angle == 0)
		step.y = INT_MAX;
	else
		step.y = 1 / tan(ray.angle);
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
