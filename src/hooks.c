/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:00:24 by bammar            #+#    #+#             */
/*   Updated: 2023/03/28 16:43:07 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int game_exit(t_hook_vars *hook_vars)
{
	mlx_clear_window(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->win_ptr);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->main_img);
	mlx_destroy_window(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->win_ptr);
	ht_destroy(hook_vars->map);
	ht_destroy(hook_vars->keys);
	exit(0);
	return (0);
}

int	pressed(int keycode, t_hook_vars *hook_vars)
{
	char	*key;
	bool	val;

	if (keycode == ESC)
		game_exit(hook_vars);
	key = ft_itoa(keycode);
	val = true;
	ht_set(hook_vars->keys, key, &val);
	return (free(key), 0);
}

int		released(int keycode, t_hook_vars *hook_vars)
{
	char	*key;

	if (keycode == ESC)
		game_exit(hook_vars);
	key = ft_itoa(keycode);
	ht_remove(hook_vars->keys, key);
	return (free(key), 0);
}

static void	move_if_pressed(int keycode, t_ht *keys, t_vec *player)
{
	char	*key;

	key = ft_itoa(keycode);
	if (ht_contains(keys, key))
		move_by_key(keycode, player);
	free(key);
}

int	update(t_hook_vars *hook_vars)
{
	t_vec	*player;

	player = (hook_vars->player);
	mlx_do_sync(hook_vars->mlx_vars->mlx_ptr);
	move_if_pressed(KEY_W, hook_vars->keys, player);
	move_if_pressed(KEY_S, hook_vars->keys, player);
	move_if_pressed(KEY_A, hook_vars->keys, player);
	move_if_pressed(KEY_D, hook_vars->keys, player);
	move_if_pressed(KEY_LEFT, hook_vars->keys, player);
	move_if_pressed(KEY_RIGHT, hook_vars->keys, player);
	// *hook_vars->player = player;
	// printf("pos:(%.02f, %.02f)\n", player.p.x, player.p.y);
	draw2d(hook_vars);
	return (0);	
}
