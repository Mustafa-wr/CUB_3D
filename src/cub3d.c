/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:20 by bammar            #+#    #+#             */
/*   Updated: 2023/05/25 19:05:30 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_init	init;

	if (!main_helper(ac, av, &init.hook, &init.game))
		return (EXIT_FAILURE);
	// free_all(&init.game);
	// exit(0);
	ft_bzero(&init.player, sizeof(init.player));
	ft_bzero(&init.pressed_keys, sizeof(t_pressed));
	init.hook.keys = &init.pressed_keys;
	init.hook.player = &init.player;
	side_length_init(&init.hook);
	map_init(&init.hook);
	walls_init(&init.hook);
	init.hook.mlx_vars = &init.mlx;
	init.mlx.mlx_ptr = mlx_init();
	init.mlx.win_ptr = mlx_new_window(init.mlx.mlx_ptr, SWIDTH, SHEIGHT, PNAME);
	init.mlx.main_img = mlx_new_image(init.mlx.mlx_ptr, SWIDTH, SHEIGHT);
	init.hook.textures = init.texs;
	textures_init(&init.hook);
	mlx_hook(init.mlx.win_ptr, ON_DESTROY, 0, game_exit, &init.hook);
	mlx_hook(init.mlx.win_ptr, 2, 1L << 0, pressed, &(init.hook));
	mlx_hook(init.mlx.win_ptr, 3, 1L << 1, released, &(init.hook));
	mlx_loop_hook(init.mlx.mlx_ptr, update, &init.hook);
	mlx_loop(init.mlx.mlx_ptr);
}
