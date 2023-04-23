/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/04/21 03:25:07 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
// static t_point	*intersection(t_point p[4], t_point *inter_p)
// {
// 	double	denomx;
// 	double	denomy;
// 	double	numex;
// 	double	numey;

// 	denomx = (p[1 - 1].x - p[2 - 1].x) * (p[3 - 1].y - p[4 - 1].y) - 
// 		(p[1 - 1].y - p[2 - 1].y) * (p[3 - 1].x - p[4 - 1].x);
// 	numex = (p[1 - 1].x * p[2 - 1].y - p[1 - 1].y * p[2 - 1].x) *
// 		(p[3 - 1].x - p[4 - 1].x) - (p[1 - 1].x - p[2 - 1].x) *
// 		(p[3 - 1].x * p[4 - 1].y - p[3 - 1].y * p[4 - 1].x);
// 	if (denomx == 0)
// 		return (NULL);
// 	denomy = denomx;
// 	numey = (p[1 - 1].x * p[2 - 1].y - p[1 - 1].y * p[2 - 1].x) *
// 		(p[3 - 1].y - p[4 - 1].y) - (p[1 - 1].y - p[2 - 1].y) *
// 		(p[3 - 1].x * p[4 - 1].y - p[3 - 1].y * p[4 - 1].x);
// 	inter_p->x = numex / denomx;
// 	inter_p->y = numey / denomx;
// 	return (inter_p);
// }

/**
 * Squares are unit squares (side length is 1)
 * https://www.youtube.com/watch?v=eOCQfxRQ2pY
*/
double	send_ray(t_cub3d *game, t_vec vec)
{
	int px;
	int py;
	t_point tile_step;
	t_point step;
	double raylen_x;
	double raylen_y;
	bool hit;

	px = (int)vec.p.x;
	py = (int)vec.p.y;
	if ((vec.angle >= 0 && vec.angle < 90)
		|| vec.angle > 270)
		tile_step.x = 1;
	else
		tile_step.x = -1;
	if  ((vec.angle >= 0 && vec.angle <= 90)
		|| vec.angle >= 90 && vec.angle < 180)
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
			if (hit)
				return (raylen_x);
			px += tile_step.x;
			raylen_x += step.x;
		}
		while ((raylen_y < py && tile_step.y == 1)
			|| (raylen_y > py && tile_step.y == -1))
		{
			hit = game->path[px][(int)raylen_y] != 0;
			if (hit)
				return (raylen_y);
			py += tile_step.y;
			raylen_y += step.y;
		}
	}


}

// void	draw_ver_lines(t_hook_vars *hook_vars);
