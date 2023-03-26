/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:02:27 by bammar            #+#    #+#             */
/*   Updated: 2023/03/27 01:56:41 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_dir(int keycode, t_vec *vec)
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

void	move_by_key(int keycode, t_vec *vec)
{
	t_size	change;

	ft_bzero(&change, sizeof(t_size));
	handle_move(keycode, &change, vec);
	change_dir(keycode, vec);
	vec->p.x += change.width * (vec->p.x + change.width < SWIDTH && vec->p.x
			+ change.width > 0);
	vec->p.y += change.height * (vec->p.y + change.height < SHEIGHT && vec->p.y
			+ change.height > 0);
}
