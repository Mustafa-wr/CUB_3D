/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:02:27 by bammar            #+#    #+#             */
/*   Updated: 2023/03/25 17:54:19 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_by_key(int keycode, t_vec *vec)
{
	int		dx;
	int		dy;

	if (keycode == KEY_W)
	{
		dx = -PLAYERSPEED * sin(vec->angle * PI/180);
		dy = -PLAYERSPEED * cos(vec->angle * PI/180);
	}
    if (keycode == KEY_S)
    {
		dx = PLAYERSPEED * sin(vec->angle * PI/180);
		dy = PLAYERSPEED * cos(vec->angle * PI/180);
	}
    if (keycode == KEY_D)
	{
		vec->angle -= 30;
		if (vec->angle <= 0)
			vec->angle = 360;
	}
    if (keycode == KEY_A)
	{
		vec->angle += 30;
		if (vec->angle >= 360)
			vec->angle = 0;
	}
	vec->p.x += dx * (!(vec->p.x + dx > SWIDTH) && !(vec->p.x + dx < 0));
	vec->p.y += dy * (!(vec->p.y + dy > SHEIGHT) && !(vec->p.y + dy < 0));
}
