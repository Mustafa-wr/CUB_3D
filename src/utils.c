/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:30 by bammar            #+#    #+#             */
/*   Updated: 2023/05/16 21:30:26 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	angle(double rad)
{
	if (rad >= 2 * PI)
		rad -= 2 * PI;
	else if (rad < 0)
		rad += 2 * PI;
	return (rad);
}

void	side_length_init(t_hook_vars *hook)
{
	int	side_length[2];
	int	map_width;
	int	map_height;

	map_width = hook->game->width;
	map_height = hook->game->height;
	side_length[0] = SWIDTH / map_width;
	side_length[1] = SHEIGHT / map_height;
	if (SWIDTH % map_width == 0)
		side_length[0]--;
	if (SHEIGHT % map_height == 0)
		side_length[1]--;
	if (side_length[0] < side_length[1])
		hook->side_length = side_length[0];
	else
		hook->side_length = side_length[1];
	hook->big_height = (map_height - 1) * hook->side_length;
	hook->big_width = (map_width - 1) * hook->side_length;
}

double	dist(t_point p1, t_point p2)
{
	return (sqrt((p1.x - p2.x) * (p1.x - p2.x)
		+ (p1.y - p2.y) * (p1.y - p2.y)));
}

int	rgb2hex(int *colors)
{
	int	hex;

	hex = (colors[0] << 16) | (colors[1] << 8) | colors[2];
	return (hex);
}
