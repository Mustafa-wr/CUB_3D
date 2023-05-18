/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:35:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/18 17:00:38 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures_init(t_hook_vars *hook)
{
	hook->textures[NORTH].img = mlx_xpm_file_to_image(hook->mlx_vars->mlx_ptr,
		"../assets/tile000.xpm", &(hook->textures[NORTH].w),
		&(hook->textures[NORTH].h));
	mlx_get_data_addr
	hook->textures[SOUTH].img = mlx_xpm_file_to_image(hook->mlx_vars->mlx_ptr,
		"../assets/tile001.xpm", &(hook->textures[SOUTH].w),
		&(hook->textures[SOUTH].h));
	hook->textures[EAST].img = mlx_xpm_file_to_image(hook->mlx_vars->mlx_ptr,
		"../assets/tile002.xpm", &(hook->textures[EAST].w),
		&(hook->textures[EAST].h));
	hook->textures[WEST].img = mlx_xpm_file_to_image(hook->mlx_vars->mlx_ptr,
		"../assets/tile003.xpm", &(hook->textures[WEST].w),
		&(hook->textures[WEST].h));
}
