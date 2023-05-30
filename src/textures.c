/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:35:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/27 15:40:42 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_init(t_tex *tex, t_mlx_vars *mlx_vars, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx_vars->mlx_ptr, \
		path, &(tex->w), &(tex->h));
	if (!tex->img)
		return ;
	tex->data = mlx_get_data_addr(tex->img, &(tex->bpp), &(tex->size_line), \
		&(tex->endian));
}

bool	textures_init(t_hook_vars *hook)
{
	texture_init(&hook->textures[NORTH], hook->mlx_vars, hook->game->no);
	texture_init(&hook->textures[SOUTH], hook->mlx_vars, hook->game->so);
	texture_init(&hook->textures[EAST], hook->mlx_vars, hook->game->ea);
	texture_init(&hook->textures[WEST], hook->mlx_vars, hook->game->we);
	if (!hook->textures[NORTH].img || !hook->textures[SOUTH].img
		|| !hook->textures[EAST].img || !hook->textures[WEST].img)
		return (ft_putendl_fd("Error\nBad xpm", 2), false);
	return (true);
}
