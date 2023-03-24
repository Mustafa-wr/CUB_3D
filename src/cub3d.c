/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:20 by bammar            #+#    #+#             */
/*   Updated: 2023/03/25 01:44:49 by bammar           ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void draw_grid(t_mlx_vars *mlx)
{
    int map[6][13] =
    {
        {1,1,0,0,0,0,0,0,1,1,0,1},
        {1,1,0,0,0,1,0,0,1,1,0,1},
        {1,1,0,1,0,0,0,0,0,1,0,1},
        {1,1,0,0,0,1,0,0,0,1,0,1},
        {1,1,0,0,0,0,0,0,1,1,0,1},
        {1,1,0,0,0,0,0,0,1,1,0,1},
    };
    int sq_width = SWIDTH/12 - (int)(SWIDTH%12 == 0);
    int sq_height = SHEIGHT/6 - (int)(SHEIGHT%6 == 0);
    t_size sq_size = (t_size){sq_width, sq_height};
    int i = 0;
    int j;
    while (i < 6)
    {
        j = 0;
        while (j < 12)
        {
            if (map[i][j] == 1)
                draw_rect(mlx->main_img, (t_point){sq_width*j, sq_height*i}, sq_size, WHT);
            j++;
        }
        i++;
    }
}

void img_init(void *img, int width, int height)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            render_pixel(img, (t_point){j, i}, 0);
}

void test(t_mlx_vars *mlx)
{
    draw_grid(mlx);
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
    mlx.main_img = mlx_new_image(mlx.mlx_ptr, SWIDTH, SHEIGHT);
    img_init(mlx.main_img, SWIDTH, SHEIGHT);
    // test
    test(&mlx);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.main_img, 0, 0);
	mlx_hook(mlx.win_ptr, ON_DESTROY, 0, temp_exit, &hook);
	mlx_key_hook(mlx.win_ptr, key_hook, &(hook));
	mlx_loop(mlx.mlx_ptr);
}
