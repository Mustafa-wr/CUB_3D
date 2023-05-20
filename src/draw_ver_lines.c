/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:50:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/20 07:59:42 by bammar           ###   ########.fr       */
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

static int	get_xpos(t_ray res, t_point p, int side_length)
{
	int	x;

	if (res.side == HOR)
		x = p.y + res.dist;
	else
		x = p.x + res.dist;
	x = (x % side_length) * CUBE_LENGTH;
	return (x);
}

// Never changed image pixels, so only one image copy is needed.
static int	get_pixel(t_tex *tex, int x, int y)
{
	int			index;
	int			val;

	index = (((int)y) * tex->size_line) + (((int)x) * (tex->bpp / 8));
	val = tex->data[index];
	return (val);
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
		line_height = (hook->side_length * SHEIGHT / hook->res[i].dist);
		repeat_count = line_height / CUBE_LENGTH;
		counter = 0;
		tex = get_texture(&(hook->res[i]), hook->textures);
		draw_start = -line_height / 2 + SHEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + SHEIGHT / 2;
		if (draw_end >= SHEIGHT)
			draw_end = SHEIGHT - 1;
		draw_line(hook->mlx_vars->main_img, (t_point){i, 0},
			(t_point){i, draw_start}, rgb2hex(hook->game->cieling));
		draw_line(hook->mlx_vars->main_img, (t_point){i, draw_end},
			(t_point){i, SHEIGHT}, rgb2hex(hook->game->floor));
		pic.x = get_xpos(hook->res[i], hook->player->p, hook->side_length);
		pic.y = 0;
		while ((draw_end - draw_start) > 0)
		{
			counter = repeat_count;
			while ((draw_end - draw_start) > 0 && counter-- > 0)
			{
				render_pixel(hook->mlx_vars->main_img,
					(t_point){i, draw_start++}, get_pixel(tex, pic.x, pic.y));
			}
			pic.y++;
		}
	}
}
