/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:50:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/21 19:57:12 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_xpos(t_ray res, t_point p)
{
	double	x;

	if (res.side == SOUTH || res.side == NORTH)
		x = p.x + res.dist;
	else
		x = p.y + res.dist;
	x = x - ((unsigned long)x);
	x *= CUBE_LENGTH;
	return (x);
}

// Never changed image pixels, so only one image copy is needed.
static int	get_pixel(t_tex *tex, int x, int y)
{
	int			index;
	int			*data;

	index = ((y * tex->size_line) + (x * (tex->bpp / 8)));
	data = (int *)(tex->data + index);
	return (*data);
}

/**
 * @brief draws the vertical lines
 * @param hook_vars 
 */
void	draw_ver_lines(t_hook_vars *hook)
{
	int		i;
	int		line_height;
	int		draw_start;
	int		draw_end;
	t_tex	*tex;
	t_point	pic;
	int		counter;
	int		repeat_count;

	i = -1;
	while (++i < SWIDTH)
	{
		tex = &(hook->textures[hook->res[i].side]);
		line_height = (hook->side_length * SHEIGHT / (hook->res[i].dist ));
		repeat_count = line_height / CUBE_LENGTH;
		counter = 0;
		draw_start = -line_height / 2 + SHEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + SHEIGHT / 2;
		if (draw_end >= SHEIGHT)
			draw_end = SHEIGHT - 1;
		draw_line(hook->mlx_vars->main_img, (t_point){i, 0},
			(t_point){i, draw_start}, rgb2hex(hook->game->cieling));
		draw_line(hook->mlx_vars->main_img, (t_point){i, draw_end},
			(t_point){i, SHEIGHT - 1}, rgb2hex(hook->game->floor));
		pic.x = get_xpos(hook->res[i], hook->player->p);
		pic.y = 0;
		while ((draw_end - draw_start) > 0)
		{
			
			counter = repeat_count;
			while ((draw_end - draw_start) > 0 && counter-- > 0)
			{
				
				render_pixel(hook->mlx_vars->main_img,
					(t_point){i, draw_start++},
					get_pixel(tex, pic.x, pic.y));
			}
			pic.y++;
		}
	}
}
