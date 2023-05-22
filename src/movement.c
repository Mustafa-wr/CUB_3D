/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:02:27 by bammar            #+#    #+#             */
/*   Updated: 2023/05/22 14:43:38 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_direction(int keycode, t_vec *vec)
{
	if (keycode == KEY_LEFT)
	{
		vec->angle -= ROTSPEED;
		angle(vec->angle);
	}
	if (keycode == KEY_RIGHT)
	{
		vec->angle += ROTSPEED;
		angle(vec->angle);
	}
}

static void	handle_move(int keycode, t_point *change, t_vec *vec)
{
	if (keycode == KEY_W)
	{
		change->x = PLAYERSPEED * (cos(angle(vec->angle)));
		change->y = PLAYERSPEED * (sin(angle(vec->angle)));
	}
	if (keycode == KEY_S)
	{
		change->x = -PLAYERSPEED * (cos(angle(vec->angle)));
		change->y = -PLAYERSPEED * (sin(angle(vec->angle)));
	}
	if (keycode == KEY_A)
	{
		change->x = PLAYERSPEED * (sin(angle(vec->angle)));
		change->y = -PLAYERSPEED * (cos(angle(vec->angle)));
	}
	if (keycode == KEY_D)
	{
		change->x = -PLAYERSPEED * (sin(angle(vec->angle)));
		change->y = PLAYERSPEED * (cos(angle(vec->angle)));
	}
}

void	move_by_key(int keycode, t_vec *vec, int height, int width)
{
	t_point	change;

	ft_bzero(&change, sizeof(t_size));
	handle_move(keycode, &change, vec);
	handle_direction(keycode, vec);
	change.x += 0.001;
	change.y += 0.001;
	if (vec->p.x + change.x < width && (vec->p.x + change.x > 0))
		vec->p.x += change.x;
	if (vec->p.y + change.y < height && (vec->p.y + change.y > 0))
		vec->p.y += change.y;
}
