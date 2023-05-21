/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/05/21 21:23:02 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool intersection(const t_vec* ray, const t_bound* bound, t_point* col,
	double *trig)
{
	double x1 = bound->start.x;
	double y1 = bound->start.y;
	double x2 = bound->end.x;
	double y2 = bound->end.y;

	double x3 = ray->p.x;
	double y3 = ray->p.y;
	double x4 = ray->p.x + trig[0];
	double y4 = ray->p.y + trig[1];

	double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (fabs(denominator) < 0.001)
        return false;
    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

	if (t > 0 && t < 1 && u > 0)
	{
		// The lines intersect within the line segments
		col->x = x1 + t * (x2 - x1);
		col->y = y1 + t * (y2 - y1);
		return true;
	}

	return false;
}

/**
 * https://www.youtube.com/watch?v=TOEi6T2mtHo
 * maybe set the intersection point inside the bound struct 
 	and update it only when a smaller one is found.
*/
void send_rays(t_hook_vars *hook)
{
    int b;
    double d;
	double trig[2];
    t_point col;
    int ray_count;
    t_vec   ray;

    ray_count = -1;
    while (++ray_count < NUM_RAYS)
    {
        ray = (t_vec){hook->player->p,
            hook->player->angle - HALF_FOV + (ray_count * DELTA_ANGLE)};
        hook->res[ray_count].dist = INT_MAX;
        hook->res[ray_count].collision = hook->player->p;
        b = -1;
        while (++b < hook->bound_count)
        {
			trig[0] = cos(ray.angle);
			trig[1] = sin(ray.angle);
            if (!intersection(&ray, &(hook->bounds[b]), &col, trig))
                continue ;
            d = dist(hook->player->p, col);
            if (d < hook->res[ray_count].dist)
            {
                hook->res[ray_count].dist = d;
                hook->res[ray_count].collision = col;
                if (b % 2 == 0)
                    hook->res[ray_count].side = HOR;
                else
                    hook->res[ray_count].side = VER;
            }
        }
    }
}
