/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:50:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/17 18:42:30 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static t_tex	*texture(t_ray *res, t_tex *texs)
// {
// 	if (res->side == HOR && res->ray.angle < PI)
// 		return (&(texs[SOUTH]));
// 	if (res->side == HOR && res->ray.angle > PI)
// 		return (&(texs[NORTH]));
// 	if (res->ray.angle > PI / 2 && res->ray.angle < 3 * PI / 2)
// 		return (&(texs[EAST]));
// 	return (&(texs[EAST]));
// }

/**
 * @brief draws the vertical lines
 * @param hook_vars 
 */
void	draw_ver_lines(t_hook_vars *hook)
{
	int		i;
	t_vars	v;

	i = -1;
	while (++i < SWIDTH)
	{
		v.line_height = (hook->side_length * SHEIGHT / hook->res[i].dist);
		v.draw_start = -v.line_height / 2 + SHEIGHT / 2;
		if (v.draw_start < 0)
			v.draw_start = 0;
		v.draw_end = v.line_height / 2 + SHEIGHT / 2;
		if (v.draw_end >= SHEIGHT)
			v.draw_end = SHEIGHT - 1;
		if (hook->res[i].side == HOR)
			draw_line(hook->mlx_vars->main_img, (t_point){i, v.draw_start},
				(t_point){i, v.draw_end}, BLUE);
		else
			draw_line(hook->mlx_vars->main_img, (t_point){i, v.draw_start},
				(t_point){i, v.draw_end}, GRN);
		draw_line(hook->mlx_vars->main_img, (t_point){i, 0},
			(t_point){i, v.draw_start}, rgb2hex(hook->game->cieling));
		draw_line(hook->mlx_vars->main_img, (t_point){i, v.draw_end},
			(t_point){i, SHEIGHT}, rgb2hex(hook->game->floor));
	}
}
