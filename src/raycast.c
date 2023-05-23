/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/05/24 02:40:07 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool intersection(const t_vec* ray, const t_bound* bound, t_point* col)
{
    double x1 = bound->start.x;
    double y1 = bound->start.y;
    double x2 = bound->end.x;
    double y2 = bound->end.y;

    double x3 = ray->p.x;
    double y3 = ray->p.y;
    double x4 = ray->p.x + cos(ray->angle);
    double y4 = ray->p.y + sin(ray->angle);

    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (fabs(denominator) < 0.001) {
        // The lines are parallel
        return false;
    }
    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

    if (t > 0 && t < 1 && u > 0) {
        // The lines intersect within the line segments
        col->x = x1 + t * (x2 - x1);
        col->y = y1 + t * (y2 - y1);
        return true;
    }

    return false;
}

static void fill_result(t_vec ray, t_ray *res, t_hook_vars *hook)
{
    int     b;
    double  d;
    t_point col;

    res->dist = INT_MAX;
    res->collision = hook->player->p;
    b = -1;
    while (++b < hook->bound_count)
    {
        if (!intersection(&ray, &(hook->bounds[b]), &col))
            continue ;
        d = dist(hook->player->p, col) * cos(ray.angle - hook->player->angle);
        if (d < res->dist)
        {
            res->dist = d;
            res->collision = col;
            res->side = b % 4;
        }
    }
}

static void check_walls(t_ray*res, t_hook_vars *hook)
{
    t_vec   ray;

    ray = (t_vec){hook->player->p, hook->player->angle};
    fill_result(ray, res, hook);
}

/**
 * https://www.youtube.com/watch?v=TOEi6T2mtHo
 * maybe set the intersection point inside the bound struct 
 	and update it only when a smaller one is found.
*/
void send_rays(t_hook_vars *hook)
{
    int ray_count;
    t_vec   ray;

    ray_count = -1;
    while (++ray_count < NUM_RAYS)
    {
        ray = (t_vec){hook->player->p,
            hook->player->angle - HALF_FOV + (ray_count * DELTA_ANGLE)};
		fill_result(ray, &(hook->res[ray_count]), hook);
		draw_ver_line(hook, ray_count);
    }
    check_walls(&(hook->res[NUM_RAYS + 0]), hook);
    check_walls(&(hook->res[NUM_RAYS + 1]), hook);
    check_walls(&(hook->res[NUM_RAYS + 2]), hook);
    check_walls(&(hook->res[NUM_RAYS + 3]), hook);
}
