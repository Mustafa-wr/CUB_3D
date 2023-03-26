/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:02:27 by bammar            #+#    #+#             */
/*   Updated: 2023/03/27 02:15:10 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_direction(int keycode, t_vec *vec)
{
	if (keycode == KEY_LEFT)
	{
		if (vec->angle <= 0)
			vec->angle = 360;
		vec->angle -= 30;
	}
	if (keycode == KEY_RIGHT)
	{
		if (vec->angle >= 360)
			vec->angle = 0;
		vec->angle += 30;
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

// static bool	is_collided(t_point p, t_size change, /* hash map for the grid map*/)
// {
	
// }

void	move_by_key(int keycode, t_vec *vec/*, int **map*/)
{
	t_size	change;

	ft_bzero(&change, sizeof(t_size));
	handle_move(keycode, &change, vec);
	handle_direction(keycode, vec);

	if (vec->p.x + change.width < SWIDTH && (vec->p.x
			+ change.width > 0) /*&& !is_collided(vec->p, change, map)*/)
		vec->p.x += change.width;
	if (vec->p.y + change.height < SHEIGHT && (vec->p.y
			+ change.height > 0) /*&& !is_collided(vec->p, change, map)*/)
		vec->p.y += change.height;
}
