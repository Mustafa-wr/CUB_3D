/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:20 by bammar            #+#    #+#             */
/*   Updated: 2023/05/25 17:40:54 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_grid(t_hook_vars *hook)
{
	int	i;
	t_point	s;
	t_point	e;

	i = -1;
	while (++i < hook->wall_count)
	{
		if (hook->walls[i].hide)
			continue ;
		s = (t_point){hook->walls[i].start.x / 4, hook->walls[i].start.y / 4};
		e = (t_point){hook->walls[i].end.x / 4, hook->walls[i].end.y / 4};	
		draw_line(hook->mlx_vars->main_img, s, e, RED);
	}
}

void	draw_player(t_hook_vars *hook)
{
	t_point	p;
	int		i;
	
	p = (t_point){hook->player->p.x / 4, hook->player->p.y / 4};
	render_pixel(hook->mlx_vars->main_img, p, RED);
	draw_rect(hook->mlx_vars->main_img, (t_point){p.x, p.y},
				(t_size){2,2}, RED);
	i = -1;
	while (++i < NUM_RAYS)
		draw_line(hook->mlx_vars->main_img, p,
			(t_point){hook->res[i].collision.x / 4, hook->res[i].collision.y / 4}, WHT);
}

void draw2d(t_hook_vars *hook_vars)
{
	draw_grid(hook_vars);
	draw_player(hook_vars);	
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
	t_tex		texs[4];
	t_pressed	pressed_keys;

	ft_bzero(&hook, sizeof(t_hook_vars));
    hook.game = &game;
	if (!main_parse(&game, ac, av))
        return (EXIT_FAILURE);
	ft_bzero(&player, sizeof(player));
	ft_bzero(&pressed_keys, sizeof(t_pressed));
	hook.keys = &pressed_keys;
	hook.player = &player;
	side_length_init(&hook);
	map_init(&hook);
	walls_init(&hook);
    hook.mlx_vars = &mlx;
    mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SWIDTH, SHEIGHT, PNAME);	
    mlx.main_img = mlx_new_image(mlx.mlx_ptr, SWIDTH, SHEIGHT);
	hook.textures = texs;
	textures_init(&hook);
	mlx_hook(mlx.win_ptr, ON_DESTROY, 0, game_exit, &hook);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, pressed, &(hook));
    mlx_hook(mlx.win_ptr, 3, 1L<<1, released, &(hook));
    mlx_loop_hook(mlx.mlx_ptr, update, &hook);
	mlx_loop(mlx.mlx_ptr);
}
