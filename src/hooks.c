/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:00:24 by bammar            #+#    #+#             */
/*   Updated: 2023/03/25 03:07:41 by bammar           ###   ########.fr       */
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
    int    step_size = 20;

    player = hook_vars->player;
	if (keycode == ESC)
		temp_exit(hook_vars);
    if (keycode == KEY_W)
        player->p = (t_point){player->p.x, player->p.y-step_size * (int)(player->p.y > step_size)}; 
    if (keycode == KEY_S)
        player->p = (t_point){player->p.x, player->p.y+step_size * (int)(player->p.y + step_size < SHEIGHT)}; 
    if (keycode == KEY_A)
        player->p = (t_point){player->p.x-step_size * (int)(player->p.x > step_size), player->p.y}; 
    if (keycode == KEY_D)
        player->p = (t_point){player->p.x+step_size * (int)(player->p.x + step_size < SWIDTH), player->p.y}; 
    draw2d(hook_vars);
	return (0);
}
