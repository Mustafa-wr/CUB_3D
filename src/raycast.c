/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/05/11 01:08:28 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hor_cast(t_raycast_res *res, double ray_angle, t_hook_vars *hook)
{
	double	rev_tan;

	rev_tan = -(1 / tan(ray_angle));
	if (ray_angle > PI)
	{
		res->step.y = -hook->side_length;
		res->step.x = hook->side_length * rev_tan;
		res->inter.y = (((int)hook->player->p.y / hook->side_length)
			* hook->side_length) - 0.0001;
		res->inter.x = (hook->player->p.y - res->inter.y)
			* rev_tan + hook->player->p.x;
	}
	else if (ray_angle < PI)
	{
		res->step.y = hook->side_length;
		res->step.x = -hook->side_length * rev_tan;
		res->inter.y = (((int)hook->player->p.y / hook->side_length)
			* hook->side_length) + hook->side_length;
		res->inter.x = (hook->player->p.y - res->inter.y)
			* rev_tan + hook->player->p.x;
	}
	else
		res->inter = hook->player->p;
}

static void	vert_cast(t_raycast_res *res, double ray_angle, t_hook_vars *hook)
{
	double	rev_tan;

	rev_tan = -(tan(ray_angle));
	if (ray_angle > PI / 2 && ray_angle < 3 * PI / 2)
	{
		res->step.x = -hook->side_length;
		res->step.y = hook->side_length * rev_tan;
		res->inter.x = (((int)hook->player->p.x / hook->side_length)
			* hook->side_length) - 0.0001;
		res->inter.y = (hook->player->p.x - res->inter.x)
			* rev_tan + hook->player->p.y;
	}
	else if (ray_angle < PI / 2 || ray_angle > 3 * PI / 2)
	{
		res->step.x = hook->side_length;
		res->step.y = -hook->side_length * rev_tan;
		res->inter.x = (((int)hook->player->p.x / hook->side_length)
			* hook->side_length) + hook->side_length;
		res->inter.y = (hook->player->p.x - res->inter.x)
			* rev_tan + hook->player->p.y;
	}
	else
		res->inter = hook->player->p;
}

void	move_ray(t_raycast_res *res, t_hook_vars *hook)
{
	int			view_depth;

	res->depth = INT_MAX;
	view_depth = 0;
	while (view_depth++ < MAX_DEPTH)
	{
		res->map.x = res->inter.x / hook->side_length;
		res->map.y = res->inter.y / hook->side_length;
		if (res->map.x >= 0 && res->map.y >= 0
			&& res->map.x < hook->game->width && res->map.y < hook->game->height
			&& hook->game->path[res->map.y][res->map.x] == '1')
			break ;
		res->inter.x += res->step.x;
		res->inter.y += res->step.y;
	}
}

/**
 * https://www.youtube.com/watch?v=gYRrGTC7GtA
 * 
*/
void	send_rays(t_hook_vars *hook)
{
	double			ray_angle;
	int				ray;
	t_raycast_res	resy;
	t_raycast_res	resx;

	ray_angle = angle(hook->player->angle - (DELTA_ANGLE * SWIDTH) / 2);
	ray = NUM_RAYS;
	while (ray)
	{
		hor_cast(&resy, (ray_angle), hook);
		vert_cast(&resx, (ray_angle), hook);
		resy.depth = sqrt(pow(resy.inter.y - hook->player->p.y, 2) +
			pow(resy.inter.x - hook->player->p.x, 2));
		resx.depth = sqrt(pow(resx.inter.y - hook->player->p.y, 2) +
			pow(resx.inter.x - hook->player->p.x, 2));
		move_ray(&resy, hook);
		move_ray(&resx, hook);
		if (resx.depth > resy.depth)
		{
			if (resy.map.x >= 0 && resy.map.y >= 0
			&& resy.map.x < hook->game->width && resy.map.y < hook->game->height
			&& hook->game->path[resy.map.y][resy.map.x] == '1')
				draw_line(hook->mlx_vars->main_img,
				(t_point){hook->player->p.x * hook->side_length, hook->player->p.y * hook->side_length},
				(t_point){resy.map.x * hook->side_length, resy.map.y * hook->side_length}, RED);
		}
		else if (resx.map.x >= 0 && resx.map.y >= 0
			&& resx.map.x < hook->game->width && resx.map.y < hook->game->height
			&& hook->game->path[resx.map.y][resx.map.x] == '1')
				draw_line(hook->mlx_vars->main_img,
				(t_point){hook->player->p.x * hook->side_length, hook->player->p.y * hook->side_length},
				(t_point){resx.map.x * hook->side_length, resx.map.y * hook->side_length}, RED);
		--ray;
		ray_angle = angle(ray_angle + DELTA_ANGLE);
	}
}
