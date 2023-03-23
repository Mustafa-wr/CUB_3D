/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:20 by bammar            #+#    #+#             */
/*   Updated: 2023/03/24 02:22:34 by bammar           ###   ########.fr       */
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
	if (keycode == ESC)
		temp_exit(hook_vars);
	return (0);
}


int	main(void)
{
	t_mlx_vars	mlx;
	t_hook_vars	hook;

	hook.mlx_vars = &mlx;
    mlx.mlx_ptr = mlx_init();
    mlx.width = SWIDTH;
    mlx.height = SHEIGHT;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width, mlx.height, PNAME);	
	mlx.main_img = mlx_xpm_file_to_image(mlx.mlx_ptr, MAINIMG, &mlx.width, &mlx.height);
	
    // test
    draw_line(mlx.main_img, (t_point){10,20}, (t_point){50, 300}, RED);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.main_img, 0, 0);
	mlx_hook(mlx.win_ptr, ON_DESTROY, 0, temp_exit, &hook);
	mlx_key_hook(mlx.win_ptr, key_hook, &(hook));
	mlx_loop(mlx.mlx_ptr);
}
