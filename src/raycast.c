/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/05/09 16:00:25 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hor_cast(double ray_angle, t_hook_vars *hook)
{
	t_point		hor_inter;
	double		hor_depth;
	t_point		o;
	t_map_pos	map;
	t_size		d;
	t_size		tile_hor;
	double		delta_depth;

	o = hook->player->p;
	map = (t_map_pos){hook->player->p.x, hook->player->p.y};

	if (sin(ray_angle * PI / 180) > 0)
	{
			hor_inter.y = map.y + 1;
			d.height = 1;
	}
	else
	{
		hor_inter.y = map.y - 0.0001;
		d.height = -1;
	}
	hor_depth = (hor_inter.y - o.y) / sin(ray_angle * PI / 180);
	hor_inter.x = o.x + hor_depth * cos(ray_angle * PI / 180);

	delta_depth = d.height / sin(ray_angle * PI / 180);
	d.width = delta_depth / cos(ray_angle * PI / 180);
	
	int depth = 10;
	while (((int)hor_inter.y < hook->game->height && (int)hor_inter.x < hook->game->width
		&& (int)hor_inter.y >= 0 && (int)hor_inter.x >= 0)
		&& hook->game->path[(int)hor_inter.y][(int)hor_inter.x] != '1'
		&& depth-- > 0)
	{
		
		hor_inter.y += d.height;
		hor_inter.x += d.width; 
		hor_depth += delta_depth;
	}
}

static void	vert_cast(double ray_angle, t_hook_vars *hook)
{
	t_point		vert_inter;
	double		vert_depth;
	t_point		o;
	t_map_pos	map;
	t_size		d;
	t_size		tile_vert;
	double		delta_depth;

	o = hook->player->p;
	map = (t_map_pos){hook->player->p.x, hook->player->p.y};

	if (cos(ray_angle * PI / 180) > 0)
	{
			vert_inter.x = map.x + 1;
			d.width = 1;
	}
	else
	{
		vert_inter.x = map.x - 0.0001;
		d.width = -1;
	}
	vert_depth = (vert_inter.x - o.x) / cos(ray_angle * PI / 180);
	vert_inter.x = o.x + vert_depth * sin(ray_angle * PI / 180);

	delta_depth = d.width / cos(ray_angle * PI / 180);
	d.height = delta_depth / sin(ray_angle * PI / 180);
	
	int depth = 10;
	while (((int)vert_inter.y < hook->game->height && (int)vert_inter.x < hook->game->width
		&& (int)vert_inter.y >= 0 && (int)vert_inter.x >= 0)
		&& hook->game->path[(int)vert_inter.y][(int)vert_inter.x] != '1'
		&& depth-- > 0)
	{
		
		vert_inter.y += d.height;
		vert_inter.x += d.width; 
		vert_depth += delta_depth;
	}
}

void	send_rays(t_raycast_res *res, t_hook_vars *hook)
{
	double		ray_angle;	
	int			ray;

	(void)res;
	ray_angle = hook->player->angle - (FOV / 2) + 0.05;
	
	ray = NUM_RAYS;
	while (ray)
	{
		// if (hook->player->angle == 0 || hook->player->angle == 180)
		// 	return ;
		hor_cast(ray_angle, hook);
		vert_cast(ray_angle, hook);
		--ray;
		ray_angle += DELTA_ANGLE;

		// if (((int)vert_inter.y < hook->game->height && (int)vert_inter.x < hook->game->width
		// && (int)vert_inter.y >= 0 && (int)vert_inter.x >= 0)
		// && hook->game->path[(int)vert_inter.y][(int)vert_inter.x] == '1')
		// draw_line(hook->mlx_vars->main_img,
		// 	(t_point){hook->player->p.x * hook->side_length, hook->player->p.y * hook->side_length},
		// 	(t_point){vert_inter.x * hook->side_length, vert_inter.y * hook->side_length}, RED);
	}
}

