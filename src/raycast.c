/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/05/15 20:57:45 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool intersection(const t_vec* ray, const t_bound* bound, t_point* col) {
    double x1 = bound->start.x;
    double y1 = bound->start.y;
    double x2 = bound->end.x;
    double y2 = bound->end.y;

    double x3 = ray->p.x;
    double y3 = ray->p.y;
    double x4 = ray->p.x + cos(ray->angle);
    double y4 = ray->p.y + sin(ray->angle);

    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (denominator == 0) {
        // The lines are parallel
        return false;
    }

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

    if (t > 0 && t < 1 && u > 0 && u < 1) {
        // The lines intersect within the line segments
        col->x = x1 + t * (x2 - x1);
        col->y = y1 + t * (y2 - y1);
        return true;
    }

    return false;
}

/**
 * https://www.youtube.com/watch?v=gYRrGTC7GtA
 * maybe set the intersection point inside the bound struct 
 	and update it only when a smaller one is found.
*/
void send_rays(t_hook_vars *hook)
{
    t_ray rays[NUM_RAYS];
    int b;
    int i;
    double record;
    double dist;
    t_point col;

    i = -1;
    while (++i < NUM_RAYS)
    {
        rays[i].ray = *(hook->player);
        rays[i].ray.angle = angle(hook->player->angle - FOV / 2 + DELTA_ANGLE * i);
        record = MAXFLOAT;
        b = -1;
        while (++b < hook->bound_count)
        {
            if (!intersection(&(rays[i].ray), &(hook->bounds[b]), &col))
                continue;
            dist = sqrt(pow((rays[i].ray.p.x - col.x), 2) + pow((rays[i].ray.p.y - col.y), 2));
            if (dist > record)
                continue;
            record = dist;
            rays[i].collision = col;
            printf("(%.02f, %.02f)\n", col.x, col.y);
        }
        draw_line(hook->mlx_vars->main_img, hook->player->p, rays[i].collision, WHT);
    }
}
