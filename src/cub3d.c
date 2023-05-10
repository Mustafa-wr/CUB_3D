/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:20 by bammar            #+#    #+#             */
/*   Updated: 2023/05/11 00:40:51 by bammar           ###   ########.fr       */
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
	int_val = (int)*val;
	free(index_string);
	return (int_val);
}

void set_mapvalue(t_ht *map, int i, int j, int val)
{
	char	*index_string;
	char	*vals;

	index_string = ft_strfjoin(ft_itoa(i), ft_itoa(j));
	vals = malloc(2);
	vals[0] = val;
	vals[1] = 0;
	ht_set(map, index_string, vals);
	free(vals);
	free(index_string);
}

void draw_grid(t_hook_vars *hook)
{
	int	height;
	int	width;
	int i;
	int j;

	height = hook->game->height;
	width = hook->game->width;
	t_size sq_size = (t_size){hook->side_length, hook->side_length};
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			if (hook->game->path[i][j] == '1')
				draw_rect(hook->mlx_vars->main_img,
					(t_point){hook->side_length * j,
					hook->side_length * i}, sq_size, WHT);
	}
}

void	draw_player(t_hook_vars *hook)
{
	t_point	p2;
	float	r;
	t_vec	vec = *(hook->player);

	vec.p.x *= hook->side_length;
	vec.p.y *= hook->side_length;
	r = 100;
	p2.x = (r * cos(vec.angle) + vec.p.x);
	p2.y = (r * sin(vec.angle) + vec.p.y);
	draw_line(hook->mlx_vars->main_img, vec.p, p2, BLUE);
	render_pixel(hook->mlx_vars->main_img, vec.p, RED);
	draw_rect(hook->mlx_vars->main_img, (t_point){vec.p.x - 5, vec.p.y - 5},
				(t_size){10,10}, RED);
}

void draw2d(t_hook_vars *hook_vars)
{
	draw_grid(hook_vars);
	draw_player(hook_vars);
	mlx_put_image_to_window(hook_vars->mlx_vars->mlx_ptr,
							hook_vars->mlx_vars->win_ptr,
							hook_vars->mlx_vars->main_img, 0, 0);
}

void	set_map(t_hook_vars *hook)
{
	int	i;
	int	j;

	i = -1;
    while (++i < hook->game->height)
	{
		j = -1;
        while (++j < hook->game->width)
		{
			if (hook->game->path[i][j] == 'E')
				hook->player->angle = 0;
			else if (hook->game->path[i][j] == 'N')
				hook->player->angle = PI / 2;
			else if (hook->game->path[i][j] == 'W')
				hook->player->angle = PI;
			else if (hook->game->path[i][j] == 'S')
				hook->player->angle = 3 * PI / 2;
			if (hook->game->path[i][j] == 'E' || hook->game->path[i][j] == 'W'
				|| hook->game->path[i][j] == 'N'
				|| hook->game->path[i][j] == 'S')
			hook->player->p = (t_point){j, i};
		}
	}
}

int	main(int ac, char **av)
{
	t_mlx_vars	mlx;
	t_hook_vars	hook;
    t_cub3d     game;
	t_vec		player;
	t_pressed	pressed_keys;

	ft_bzero(&hook, sizeof(t_hook_vars));
    hook.game = &game;
	if (!main_parse(&game, ac, av))
        return (EXIT_FAILURE);
	hook.side_length = fmin(SWIDTH / game.width - (int)(SWIDTH % game.width
		== 0), SHEIGHT / game.height - (SWIDTH % game.height == 0));
    hook.mlx_vars = &mlx;
    mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SWIDTH, SHEIGHT, PNAME);	
    mlx.main_img = mlx_new_image(mlx.mlx_ptr, SWIDTH, SHEIGHT);
	ft_bzero(&player, sizeof(player));
	ft_bzero(&pressed_keys, sizeof(t_pressed));
    hook.keys = &pressed_keys;
	hook.player = &player;
	set_map(&hook);

	mlx_hook(mlx.win_ptr, ON_DESTROY, 0, game_exit, &hook);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, pressed, &(hook));
    mlx_hook(mlx.win_ptr, 3, 1L<<1, released, &(hook));
    mlx_loop_hook(mlx.mlx_ptr, update, &hook);
	mlx_loop(mlx.mlx_ptr);
}
