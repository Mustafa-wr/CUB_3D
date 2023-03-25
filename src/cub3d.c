/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:20 by bammar            #+#    #+#             */
/*   Updated: 2023/03/26 02:11:06 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_grid(t_mlx_vars *mlx)
{
    int map[6][13] =
    {
        {1,1,0,0,0,0,0,0,1,1,0,1},
        {1,1,0,0,0,1,0,0,1,1,0,1},
        {1,1,0,1,0,0,0,0,0,1,0,1},
        {1,1,0,0,0,0,0,0,0,1,0,1},
        {1,1,0,0,0,0,0,1,1,1,0,1},
        {1,1,0,0,0,0,1,0,1,1,0,1},
    };
    int side_length = SWIDTH/12 - (int)(SWIDTH%12 == 0);
    if (SHEIGHT/6 - (SWIDTH%6 == 0) < side_length)
        side_length = SHEIGHT/6 - (SWIDTH%6 == 0);
    t_size sq_size = (t_size){side_length, side_length};
    int i = 0;
    int j;
    while (i < 6)
    {
        j = 0;
        while (j < 12)
        {
            if (map[i][j] == 1)
                draw_rect(mlx->main_img, (t_point){side_length*j, side_length*i}, sq_size, WHT);
            j++;
        }
        i++;
    }
}


void draw_player(t_mlx_vars *mlx, t_vec *vec)
{
    t_point p2;
    float   r;

    r = 10;
    p2.x = r * cos(vec->angle * PI/180) + vec->p.x;
    p2.y = r * sin(vec->angle * PI/180) + vec->p.y;
    if (p2.y < SHEIGHT && p2.x < SWIDTH && p2.y > 0 && p2.y > 0)
        draw_line(mlx->main_img, vec->p, p2, BLUE);
    render_pixel(mlx->main_img, vec->p, RED);
}

void draw2d(t_hook_vars *hook_vars)
{
    clear_img(hook_vars->mlx_vars->main_img, SWIDTH, SHEIGHT);
    draw_grid(hook_vars->mlx_vars);
    draw_player(hook_vars->mlx_vars, hook_vars->player);
    mlx_put_image_to_window(hook_vars->mlx_vars->mlx_ptr,
        hook_vars->mlx_vars->win_ptr, hook_vars->mlx_vars->main_img, 0,0);
}

int	main(void)
{
	t_mlx_vars	mlx;
	t_hook_vars	hook;
    t_vec       player;

	hook.mlx_vars = &mlx;
    mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SWIDTH, SHEIGHT, PNAME);	
    mlx.main_img = mlx_new_image(mlx.mlx_ptr, SWIDTH, SHEIGHT);
    
    // test
    hook.player = &player;
    player.angle = 0;
    player.p = (t_point){SWIDTH/2, SHEIGHT/2};
    draw2d(&hook);

    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.main_img, 0, 0);
	mlx_hook(mlx.win_ptr, ON_DESTROY, 0, temp_exit, &hook);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, key_hook, &(hook));
	mlx_loop(mlx.mlx_ptr);
}
