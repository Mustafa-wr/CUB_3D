/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/05/09 21:19:28 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hor_cast(t_raycast_res *res, double ray_angle, t_hook_vars *hook)
{
	t_point		o;
	t_map_pos	map;
	t_size		d;
	double		delta_depth;

	o = hook->player->p;
	map = (t_map_pos){hook->player->p.x, hook->player->p.y};

	if (sin(ray_angle) > 0)
	{
			res->inter.y = map.y + 1;
			d.height = 1;
	}
	else
	{
		res->inter.y = map.y - 0.0001;
		d.height = -1;
	}
	res->depth = (res->inter.y - o.y) / sin(ray_angle);
	res->inter.x = o.x + res->depth * cos(ray_angle);

	delta_depth = d.height / sin(ray_angle);
	d.width = delta_depth / cos(ray_angle);
	
	int depth = 10;
	while (((int)res->inter.y < hook->game->height
		&& (int)res->inter.x < hook->game->width
		&& (int)res->inter.y >= 0 && (int)res->inter.x >= 0)
		&& hook->game->path[(int)res->inter.y][(int)res->inter.x] != '1'
		&& depth-- > 0)
	{
		
		res->inter.y += d.height;
		res->inter.x += d.width; 
		res->depth += delta_depth;
	}
}

static void	vert_cast(t_raycast_res *res, double ray_angle, t_hook_vars *hook)
{
	t_point		o;
	t_map_pos	map;
	t_size		d;
	double		delta_depth;

	o = hook->player->p;
	map = (t_map_pos){hook->player->p.x, hook->player->p.y};

	if (cos(ray_angle) > 0)
	{
			res->inter.x = map.x + 1;
			d.width = 1;
	}
	else
	{
		res->inter.x = map.x - 0.0001;
		d.width = -1;
	}
	res->depth = (res->inter.x - o.x) / cos(ray_angle);
	res->inter.x = o.x + res->depth * sin(ray_angle);

	delta_depth = d.width / cos(ray_angle);
	d.height = delta_depth / sin(ray_angle);
	
	int depth = 10;
	while (((int)res->inter.y < hook->game->height
		&& (int)res->inter.x < hook->game->width
		&& (int)res->inter.y >= 0 && (int)res->inter.x >= 0)
		&& hook->game->path[(int)res->inter.y][(int)res->inter.x] != '1'
		&& depth-- > 0)
	{
		
		res->inter.y += d.height;
		res->inter.x += d.width; 
		res->depth += delta_depth;
	}
}

void	send_rays(t_raycast_res *res, t_hook_vars *hook)
{
	double			ray_angle;
	int				ray;
	t_raycast_res	resy;
	t_raycast_res	resx;

	(void)res;
	ray_angle = (hook->player->angle * PI / 180) - (FOV / 2) + 0.0001;
	
	ray = NUM_RAYS;
	while (ray)
	{
		// if (hook->player->angle == 0 || hook->player->angle == 180)
		// 	return ;
		
		hor_cast(&resy, ray_angle, hook);
		vert_cast(&resx, ray_angle, hook);
		--ray;
		ray_angle += DELTA_ANGLE;

		if (resy.depth <= resx.depth &&
			(((int)resy.inter.y < hook->game->height && (int)resy.inter.x < hook->game->width
			&& (int)resy.inter.y >= 0 && (int)resy.inter.x >= 0)
			&& hook->game->path[(int)resy.inter.y][(int)resy.inter.x] == '1'))
			draw_line(hook->mlx_vars->main_img,
				(t_point){hook->player->p.x * hook->side_length, hook->player->p.y * hook->side_length},
				(t_point){resy.inter.x * hook->side_length, resy.inter.y * hook->side_length}, RED);
		else if (resy.depth > resx.depth &&
			(((int)resx.inter.y < hook->game->height && (int)resx.inter.x < hook->game->width
			&& (int)resx.inter.y >= 0 && (int)resx.inter.x >= 0)
			&& hook->game->path[(int)resx.inter.y][(int)resx.inter.x] == '1'))
			draw_line(hook->mlx_vars->main_img,
				(t_point){hook->player->p.x * hook->side_length, hook->player->p.y * hook->side_length},
				(t_point){resx.inter.x * hook->side_length, resx.inter.y * hook->side_length}, RED);
	}
}
