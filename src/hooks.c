/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:00:24 by bammar            #+#    #+#             */
/*   Updated: 2023/05/25 16:54:18 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_exit(t_hook_vars *hook_vars)
{
	mlx_clear_window(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->win_ptr);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->main_img);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->textures[NORTH].img);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->textures[EAST].img);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->textures[WEST].img);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->textures[SOUTH].img);
	mlx_destroy_window(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->win_ptr);
	free(hook_vars->walls);
	free_all(hook_vars->game);
	exit(0);
}

int	pressed(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == ESC)
		game_exit(hook_vars);
	if (keycode == KEY_W)
		hook_vars->keys->w = true;
	else if (keycode == KEY_A)
		hook_vars->keys->a = true;
	else if (keycode == KEY_S)
		hook_vars->keys->s = true;
	else if (keycode == KEY_D)
		hook_vars->keys->d = true;
	else if (keycode == KEY_LEFT)
		hook_vars->keys->left = true;
	else if (keycode == KEY_RIGHT)
		hook_vars->keys->right = true;
	return (0);
}

int	released(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == ESC)
		game_exit(hook_vars);
	if (keycode == KEY_W)
		hook_vars->keys->w = false;
	else if (keycode == KEY_A)
		hook_vars->keys->a = false;
	else if (keycode == KEY_S)
		hook_vars->keys->s = false;
	else if (keycode == KEY_D)
		hook_vars->keys->d = false;
	else if (keycode == KEY_LEFT)
		hook_vars->keys->left = false;
	else if (keycode == KEY_RIGHT)
		hook_vars->keys->right = false;
	return (0);
}

static void	move_if_pressed(int keycode, t_hook_vars *hook_vars)
{
	t_pressed	*keys;

	keys = hook_vars->keys;
	if (((keycode == KEY_W) && keys->w)
		|| ((keycode == KEY_A) && keys->a)
		|| ((keycode == KEY_S) && keys->s)
		|| ((keycode == KEY_D) && keys->d)
		|| ((keycode == KEY_LEFT) && keys->left)
		|| ((keycode == KEY_RIGHT) && keys->right))
		move_by_key(keycode, hook_vars->player, hook_vars->big_height - 10,
			hook_vars->big_width - 10);
}

// By adding 4 more rays for each side we can check for walls.
int	update(t_hook_vars *hook_vars)
{
	t_ray	rays[NUM_RAYS + 4];

	hook_vars->res = rays;
	mlx_do_sync(hook_vars->mlx_vars->mlx_ptr);
	
	clear_img(hook_vars->mlx_vars->main_img, SWIDTH, SHEIGHT);
	send_rays(hook_vars);
	draw2d(hook_vars);
	mlx_put_image_to_window(hook_vars->mlx_vars->mlx_ptr,
							hook_vars->mlx_vars->win_ptr,
							hook_vars->mlx_vars->main_img, 0, 0);
	move_if_pressed(KEY_W, hook_vars);
	move_if_pressed(KEY_S, hook_vars);
	move_if_pressed(KEY_A, hook_vars);
	move_if_pressed(KEY_D, hook_vars);
	move_if_pressed(KEY_LEFT, hook_vars);
	move_if_pressed(KEY_RIGHT, hook_vars);
	return (0);
}
