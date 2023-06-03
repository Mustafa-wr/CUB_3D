/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:50:19 by bammar            #+#    #+#             */
/*   Updated: 2023/06/03 19:08:29 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_xpos(t_ray res, int cwidth)
{
	double	x;
	double	r;

	if (res.side == SOUTH || res.side == NORTH)
		x = res.collision.x;
	else
		x = res.collision.y;
	r = fmod(x, cwidth);
	x = r;
	return (x);
}

static void	draw_cf(t_hook_vars *hook, int i, t_map_pos draw)
{
	draw_line(hook->mlx_vars->main_img, (t_point){i, 0},
		(t_point){i, draw.x}, rgb2hex(hook->game->cieling));
	draw_line(hook->mlx_vars->main_img, (t_point){i, draw.y},
		(t_point){i, SHEIGHT - 1}, rgb2hex(hook->game->floor));
}

/**
 * @brief draws the vertical lines
 * @param hook_vars 
 */
void	draw_ver_line(t_hook_vars *hook, int i)
{
	double			line_height;
	t_map_pos		draw;
	t_tex			*tex;
	t_point			pic;
	double			ystep_size;

	tex = &(hook->textures[hook->res[i].side]);
	line_height = (100 * SHEIGHT / (hook->res[i].dist));
	ystep_size = 1.0 * hook->textures->h / line_height;
	draw.x = -line_height / 2 + SHEIGHT / 2.0;
	if (draw.x < 0)
		draw.x = 0;
	draw.y = line_height / 2 + SHEIGHT / 2.0;
	if (draw.y >= SHEIGHT)
		draw.y = SHEIGHT - 1;
	draw_cf(hook, i, draw);
	pic.x = get_xpos(hook->res[i], hook->textures->w);
	pic.y = (draw.x - SHEIGHT / 2 + line_height / 2) * ystep_size;
	while (draw.x <= draw.y)
	{
		render_pixel(hook->mlx_vars->main_img, (t_point){i, draw.x++},
			get_pixel(tex, (int)pic.x, (int)pic.y & (hook->textures->h - 1)));
		pic.y += ystep_size;
	}
}
