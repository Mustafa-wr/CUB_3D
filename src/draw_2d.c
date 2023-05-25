/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:05:40 by bammar            #+#    #+#             */
/*   Updated: 2023/05/25 19:07:44 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_grid(t_hook_vars *hook)
{
	int		i;
	t_point	s;
	t_point	e;

	i = -1;
	while (++i < hook->wall_count)
	{
		if (hook->walls[i].hide)
			continue ;
		s = (t_point){hook->walls[i].start.x / 4, hook->walls[i].start.y / 4};
		e = (t_point){hook->walls[i].end.x / 4, hook->walls[i].end.y / 4};
		draw_line(hook->mlx_vars->main_img, s, e, RED);
	}
}

void	draw_player(t_hook_vars *hook)
{
	t_point	p;
	int		i;

	p = (t_point){hook->player->p.x / 4, hook->player->p.y / 4};
	render_pixel(hook->mlx_vars->main_img, p, RED);
	draw_rect(hook->mlx_vars->main_img, (t_point){p.x, p.y}, \
			(t_size){2, 2}, RED);
	i = -1;
	while (++i < NUM_RAYS)
		draw_line(hook->mlx_vars->main_img, p,
			(t_point){hook->res[i].collision.x / 4, \
				hook->res[i].collision.y / 4}, WHT);
}

void	draw2d(t_hook_vars *hook_vars)
{
	draw_grid(hook_vars);
	draw_player(hook_vars);
}
