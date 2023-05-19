/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:50:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/19 16:25:48 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_tex	*get_texture(t_ray *res, t_tex *texs)
{
	if (res->side == HOR && res->ray.angle < PI)
		return (&(texs[SOUTH]));
	if (res->side == HOR && res->ray.angle > PI)
		return (&(texs[NORTH]));
	if (res->ray.angle > PI / 2 && res->ray.angle < 3 * PI / 2)
		return (&(texs[EAST]));
	return (&(texs[WEST]));
}

/**
 * @brief draws the vertical lines
 * @param hook_vars 
 */
void	draw_ver_lines(t_hook_vars *hook)
{
	int	i;
	int		line_height;
	int		draw_start;
	int		draw_end;
	t_tex	*tex;
	t_point	pic;

	i = -1;
	while (++i < SWIDTH)
	{
		line_height = (hook->side_length * SHEIGHT / hook->res[i].dist);
		draw_start = -line_height / 2 + SHEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + SHEIGHT / 2;
		if (draw_end >= SHEIGHT)
			draw_end = SHEIGHT - 1;
		tex = get_texture(&(hook->res[i]), hook->textures);
		if (hook->res[i].side == HOR)
			pic.x = hook->player->p.y + hook->res[i].dist;
		else
			pic.x = hook->player->p.x + hook->res[i].dist;
		
		draw_line(hook->mlx_vars->main_img, (t_point){i, 0},
			(t_point){i, draw_start}, rgb2hex(hook->game->cieling));
		
		draw_line(hook->mlx_vars->main_img, (t_point){i, draw_end},
			(t_point){i, SHEIGHT}, rgb2hex(hook->game->floor));
	}
}
