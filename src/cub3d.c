/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:20 by bammar            #+#    #+#             */
/*   Updated: 2023/05/16 03:01:29 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_grid(t_hook_vars *hook)
{
	int	i;

	i = -1;
	while (++i < hook->bound_count)
	{
		// printf("i: %d\n", hook->bound_count);

		draw_line(hook->mlx_vars->main_img, hook->bounds[i].start,
				hook->bounds[i].end, RED);
	}
}

void	draw_player(t_hook_vars *hook)
{
	// t_point	p2;
	// float	r;
	t_vec	vec;
	
	vec = *(hook->player);
	// r = 100;
	// p2.x = (r * cos(vec.angle) + vec.p.x);
	// p2.y = (r * sin(vec.angle) + vec.p.y);
	// draw_line(hook->mlx_vars->main_img, vec.p, p2, BLUE);
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

void	map_init(t_hook_vars *hook)
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
				hook->player->p = (t_point){j * hook->side_length,
					i * hook->side_length};
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
	ft_bzero(&player, sizeof(player));
	ft_bzero(&pressed_keys, sizeof(t_pressed));
	// game.width++;
	hook.keys = &pressed_keys;
	hook.player = &player;
	side_length_init(&hook);
	map_init(&hook);
	bounds_init(&hook);
    hook.mlx_vars = &mlx;
    mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SWIDTH, SHEIGHT, PNAME);	
    mlx.main_img = mlx_new_image(mlx.mlx_ptr, SWIDTH, SHEIGHT);
	mlx_hook(mlx.win_ptr, ON_DESTROY, 0, game_exit, &hook);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, pressed, &(hook));
    mlx_hook(mlx.win_ptr, 3, 1L<<1, released, &(hook));
    mlx_loop_hook(mlx.mlx_ptr, update, &hook);
	mlx_loop(mlx.mlx_ptr);
}
