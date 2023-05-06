/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:54:52 by bammar            #+#    #+#             */
/*   Updated: 2023/05/06 18:14:37 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void set_stepsize(double *x, double *y, double angle)
{
	*y = -1;
	if ((angle < 180))
		*y = 1;
	*x = -1;
	if ((angle < 90) || (angle > 270))
		*x = 1;
}

/**
 * Squares are unit squares (side length is 1)
 * https://www.youtube.com/watch?v=eOCQfxRQ2pY
 * https://www.youtube.com/watch?v=ECqUrT7IdqQ
*/
void	send_rays(t_raycast_res *res, t_hook_vars *hook)
{
	t_size	map_pos;
	double	length_x;
	double	length_y;
	double	xoffset;
	double	yoffset;
	double	stepsize_x;
	double	stepsize_y;
	double	ray_angle;
	int		ray;

	xoffset = fabs((hook->player->p.x - (int)hook->player->p.x));
	yoffset = fabs((hook->player->p.y - (int)hook->player->p.y));
	set_stepsize(&stepsize_x, &stepsize_y, hook->player->angle);
	map_pos = (t_size){hook->player->p.x + stepsize_x == -1,
		hook->player->p.y + stepsize_y == -1};
	ray_angle = hook->player->angle - FOV / 2 + 0.0001;
	ray = NUM_RAYS + 1;
	printf("map pos : (%.02f, %.02f)\nray_angle:%.02f\n", stepsize_x, stepsize_y, ray_angle);
	
	
}
