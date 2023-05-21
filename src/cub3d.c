/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:20 by bammar            #+#    #+#             */
/*   Updated: 2023/05/21 22:28:33 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_grid(t_hook_vars *hook)
{
	int	i;

	i = -1;
	while (++i < hook->bound_count)
		draw_line(hook->mlx_vars->main_img, hook->bounds[i].start, \
				hook->bounds[i].end, RED);
}

void	draw_player(t_hook_vars *hook)
{
	t_vec	vec;
	int		i;

	vec = *(hook->player);
	render_pixel(hook->mlx_vars->main_img, vec.p, RED);
	draw_rect(hook->mlx_vars->main_img, (t_point){vec.p.x - 5, vec.p.y - 5}, \
		(t_size){10, 10}, RED);
	i = -1;
	while (++i < NUM_RAYS)
		draw_line(hook->mlx_vars->main_img, hook->player->p,
			hook->res[i].collision, WHT);
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

int	main_helper(int ac, char **av, t_hook_vars *hook, t_cub3d *game)
{
	ft_bzero(hook, sizeof(t_hook_vars));
	hook->game = game;
	if (!main_parse(game, ac, av))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_mlx_vars	mlx;
	t_hook_vars	hook;
	t_cub3d		game;
	t_vec		player;
	t_pressed	pressed_keys;

	if (!main_helper(ac, av, &hook, &game))
		return (EXIT_FAILURE);
	ft_bzero(&player, sizeof(player));
	ft_bzero(&pressed_keys, sizeof(t_pressed));
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
	mlx_hook(mlx.win_ptr, 2, 1L << 0, pressed, &(hook));
	mlx_hook(mlx.win_ptr, 3, 1L << 1, released, &(hook));
	mlx_loop_hook(mlx.mlx_ptr, update, &hook);
	mlx_loop(mlx.mlx_ptr);
}
