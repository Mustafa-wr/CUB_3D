/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:50:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/23 21:54:54 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_xpos(t_ray res)
{
	double	x;
	double	r;

	if (res.side == SOUTH || res.side == NORTH)
		x = res.collision.x;
	else
		x = res.collision.y;
	r = fmod(x, CUBE_LENGTH);
	x = r * 2;
	return (x);
}


/**
 * @brief draws the vertical lines
 * @param hook_vars 
 */
void	draw_ver_line(t_hook_vars *hook, int i)
{
	double	line_height;
	int		draw_start;
	int		draw_end;
	t_tex	*tex;
	t_point	pic;
	double	ystep_size;

		tex = &(hook->textures[hook->res[i].side]);
		line_height = (CUBE_LENGTH * 255 / (hook->res[i].dist));
		ystep_size = 1.0 * CUBE_LENGTH / line_height;
		draw_start = -line_height / 2 + SHEIGHT / 2.0;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + SHEIGHT / 2.0;
		if (draw_end >= SHEIGHT)
			draw_end = SHEIGHT - 1;
		draw_line(hook->mlx_vars->main_img, (t_point){i, 0},
			(t_point){i, draw_start}, rgb2hex(hook->game->cieling));
		draw_line(hook->mlx_vars->main_img, (t_point){i, draw_end},
			(t_point){i, SHEIGHT - 1}, rgb2hex(hook->game->floor));
		pic.x = get_xpos(hook->res[i]);
		pic.y = (draw_start - SHEIGHT / 2 + line_height / 2) * ystep_size;
		while (draw_start <= draw_end)
		{
        	pic.y += ystep_size;
			render_pixel(hook->mlx_vars->main_img,
				(t_point){i, draw_start++},
				get_pixel(tex, (int)pic.x, (int)pic.y & (CUBE_LENGTH - 1) ));
			
		}
}
