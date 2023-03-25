/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:00:24 by bammar            #+#    #+#             */
/*   Updated: 2023/03/25 17:47:03 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int temp_exit(t_hook_vars *hook_vars)
{
	mlx_clear_window(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->win_ptr);
	exit(0);
	return 0;
}

int	key_hook(int keycode, t_hook_vars *hook_vars)
{
    t_vec *player;

    player = hook_vars->player;
	if (keycode == ESC)
		temp_exit(hook_vars);
    move_by_key(keycode, player);
	printf("(%.02f,%.02f), angle: %.02f\n", player->p.x, player->p.y, player->angle);
    draw2d(hook_vars);
	return (0);
}
