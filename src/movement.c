/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:02:27 by bammar            #+#    #+#             */
/*   Updated: 2023/05/05 19:39:41 by bammar           ###   ########.fr       */
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

static void	handle_move(int keycode, t_point *change, t_vec *vec)
{
	if (keycode == KEY_W)
	{
		change->x = PLAYERSPEED * cos(vec->angle * PI / 180);
		change->y = PLAYERSPEED * sin(vec->angle * PI / 180);
	}
	if (keycode == KEY_S)
	{
		change->x = -PLAYERSPEED * cos(vec->angle * PI / 180);
		change->y = -PLAYERSPEED * sin(vec->angle * PI / 180);
	}
	if (keycode == KEY_A)
	{
		change->x = PLAYERSPEED * sin(vec->angle * PI / 180);
		change->y = -PLAYERSPEED * cos(vec->angle * PI / 180);
	}
	if (keycode == KEY_D)
	{
		change->x = -PLAYERSPEED * sin(vec->angle * PI / 180);
		change->y = PLAYERSPEED * cos(vec->angle * PI / 180);
	}
}

void	move_by_key(int keycode, t_vec *vec, int height, int width)
{
	t_point	change;

	ft_bzero(&change, sizeof(t_size));
	handle_move(keycode, &change, vec);
	handle_direction(keycode, vec);
	if (vec->p.x + change.x < width && (vec->p.x + change.x > 0))
		vec->p.x += change.x;
	if (vec->p.y + change.y < height && (vec->p.y + change.y > 0))
		vec->p.y += change.y;
}
