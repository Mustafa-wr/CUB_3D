/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:20 by bammar            #+#    #+#             */
/*   Updated: 2023/03/28 17:00:49 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_mapvalue(t_ht *map, int i, int j)
{
	char *index_string;
	char *val;
	int int_val;

	index_string = ft_strfjoin(ft_itoa(i), ft_itoa(j));
	val = ht_get(map, index_string);
	if (!val)
		return (free(index_string), 0);
	int_val = ft_atoi(val);
	free(index_string);
	return (int_val);
}

void set_mapvalue(t_ht *map, int i, int j, int val)
{
	char *index_string;
	char *vals;

	index_string = ft_strfjoin(ft_itoa(i), ft_itoa(j));
	vals = ft_itoa(val);
	ht_set(map, index_string, vals);
	free(vals);
	free(index_string);
}

void draw_grid(t_mlx_vars *mlx, t_ht *map)
{
	int side_length = SWIDTH / 12 - (int)(SWIDTH % 12 == 0);
	if (SHEIGHT / 6 - (SWIDTH % 6 == 0) < side_length)
		side_length = SHEIGHT / 6 - (SWIDTH % 6 == 0);
	t_size sq_size = (t_size){side_length, side_length};
	int i = 0;
	int j;
	while (i < 6)
	{
		j = 0;
		while (j < 13)
		{
			if (get_mapvalue(map, i, j) == 1)
				draw_rect(mlx->main_img, (t_point){side_length * j, side_length * i}, sq_size, WHT);
			j++;
		}
		i++;
	}
}

void draw_player(t_mlx_vars *mlx, t_vec *vec)
{
	t_point p2;
	float r;

	r = 10;
	p2.x = r * cos(vec->angle * PI / 180) + vec->p.x;
	p2.y = r * sin(vec->angle * PI / 180) + vec->p.y;
	if (p2.y < SHEIGHT && p2.x < SWIDTH && p2.y > 0 && p2.y > 0)
		draw_line(mlx->main_img, vec->p, p2, BLUE);
	render_pixel(mlx->main_img, vec->p, RED);
}

void draw2d(t_hook_vars *hook_vars)
{
	clear_img(hook_vars->mlx_vars->main_img, SWIDTH, SHEIGHT);
	draw_grid(hook_vars->mlx_vars, hook_vars->map);
	draw_player(hook_vars->mlx_vars, hook_vars->player);
	mlx_put_image_to_window(hook_vars->mlx_vars->mlx_ptr,
							hook_vars->mlx_vars->win_ptr, hook_vars->mlx_vars->main_img, 0, 0);
}

// int get_pressed()

int main(int ac, char **av)
{
	t_mlx_vars mlx;
	t_hook_vars hook;
	t_vec player;
	t_cub3d game;

	if(!main_parse(&game, ac, av))
		return (0);
	hook.mlx_vars = &mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SWIDTH, SHEIGHT, PNAME);
	mlx.main_img = mlx_new_image(mlx.mlx_ptr, SWIDTH, SHEIGHT);
	hook.map = ht_new(13 * 6);
	hook.keys = ht_new(256);
	// test
	int grid[6][13] =
		{
			{1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
			{1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1},
			{1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
			{1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
			{1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
			{1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
		};
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 13; j++)
			set_mapvalue(hook.map, i, j, grid[i][j]);
	hook.player = &player;
	player.angle = 0;
	player.p = (t_point){SWIDTH / 2, SHEIGHT / 2};
	draw2d(&hook);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.main_img, 0, 0);
	mlx_hook(mlx.win_ptr, ON_DESTROY, 0, temp_exit, &hook);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, pressed, &(hook));
	mlx_hook(mlx.win_ptr, 3, 1L << 1, released, &(hook));
	mlx_loop_hook(mlx.mlx_ptr, update, &hook);
	mlx_loop(mlx.mlx_ptr);
}
