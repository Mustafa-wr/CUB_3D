/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:02:27 by bammar            #+#    #+#             */
/*   Updated: 2023/04/23 21:14:48 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_direction(int keycode, t_vec *vec)
{
	if (keycode == KEY_LEFT)
	{
		vec->angle -= ROTSPEED;
		if (vec->angle <= 0)
			vec->angle += 360;
	}
	if (keycode == KEY_RIGHT)
	{
		vec->angle += ROTSPEED;
		if (vec->angle >= 360)
			vec->angle -= 360;
	}
}

static void	handle_move(int keycode, t_size *change, t_vec *vec)
{
	if (keycode == KEY_W)
	{
		change->width = PLAYERSPEED * cos(vec->angle * PI / 180);
		change->height = PLAYERSPEED * sin(vec->angle * PI / 180);
	}
	if (keycode == KEY_S)
	{
		change->width = -PLAYERSPEED * cos(vec->angle * PI / 180);
		change->height = -PLAYERSPEED * sin(vec->angle * PI / 180);
	}
	if (keycode == KEY_A)
	{
		change->width = PLAYERSPEED * sin(vec->angle * PI / 180);
		change->height = -PLAYERSPEED * cos(vec->angle * PI / 180);
	}
	if (keycode == KEY_D)
	{
		change->width = -PLAYERSPEED * sin(vec->angle * PI / 180);
		change->height = PLAYERSPEED * cos(vec->angle * PI / 180);
	}
}

void	move_by_key(int keycode, t_vec *vec)
{
	t_size	change;

	ft_bzero(&change, sizeof(t_size));
	handle_move(keycode, &change, vec);
	handle_direction(keycode, vec);
	if (vec->p.x + change.width < SWIDTH && (vec->p.x + change.width > 0))
		vec->p.x += change.width;
	if (vec->p.y + change.height < SHEIGHT && (vec->p.y + change.height > 0))
		vec->p.y += change.height;
}
