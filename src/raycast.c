/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/05/21 22:14:59 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	intersection(const t_vec *ray, const t_bound *bound, t_point *col)
{
	t_vars	v;

	v.x1 = bound->start.x;
	v.y1 = bound->start.y;
	v.x2 = bound->end.x;
	v.y2 = bound->end.y;
	v.x3 = ray->p.x;
	v.y3 = ray->p.y;
	v.x4 = ray->p.x + cos(ray->angle);
	v.y4 = ray->p.y + sin(ray->angle);
	v.denominator = (v.x1 - v.x2) * (v.y3 - v.y4) - \
		(v.y1 - v.y2) * (v.x3 - v.x4);
	if (fabs(v.denominator) < 0.001)
		return (false);
	v.t = ((v.x1 - v.x3) * (v.y3 - v.y4) - (v.y1 - v.y3) * (v.x3 - v.x4))
		/ v.denominator;
	v.u = -((v.x1 - v.x2) * (v.y1 - v.y3) - (v.y1 - v.y2) * (v.x1 - v.x3))
		/ v.denominator;
	if (v.t > 0 && v.t < 1 && v.u > 0)
	{
		col->x = v.x1 + v.t * (v.x2 - v.x1);
		col->y = v.y1 + v.t * (v.y2 - v.y1);
		return (true);
	}
	return (false);
}

static void	update_ray(t_ray *ray, int b, double d, t_point col)
{
	ray->dist = d;
	ray->collision = col;
	if (b % 2 == 0)
		ray->side = HOR;
	else
		ray->side = VER;
}

/**
 * https://www.youtube.com/watch?v=TOEi6T2mtHo
 * maybe set the intersection point inside the bound struct 
 	and update it only when a smaller one is found.
*/
void	send_rays(t_hook_vars *hook)
{
	int		b;
	double	d;
	t_point	col;
	int		ray_count;
	t_vec	ray;

	ray_count = -1;
	while (++ray_count < NUM_RAYS)
	{
		ray = (t_vec){hook->player->p, \
						hook->player->angle - HALF_FOV + \
							(ray_count * DELTA_ANGLE)};
		hook->res[ray_count].dist = INT_MAX;
		hook->res[ray_count].collision = hook->player->p;
		b = -1;
		while (++b < hook->bound_count)
		{
			if (!intersection(&ray, &(hook->bounds[b]), &col))
				continue ;
			d = dist(hook->player->p, col);
			if (d < hook->res[ray_count].dist)
				update_ray(&(hook->res[ray_count]), b, d, col);
		}
	}
}
