/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:35:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/19 14:27:43 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures_init(t_hook_vars *hook)
{
	hook->textures[NORTH].img = mlx_xpm_file_to_image(hook->mlx_vars->mlx_ptr,
		IMG0_PATH, &(hook->textures[NORTH].w),
		&(hook->textures[NORTH].h));
	mlx_get_data_addr(hook->textures[NORTH].img, hook->textures[NORTH].bpp,
		&(hook->textures[NORTH].size_line), &(hook->textures[NORTH].endian));
	hook->textures[SOUTH].img = mlx_xpm_file_to_image(hook->mlx_vars->mlx_ptr,
		IMG1_PATH, &(hook->textures[SOUTH].w),
		&(hook->textures[SOUTH].h));
	mlx_get_data_addr(hook->textures[SOUTH].img, hook->textures[SOUTH].bpp,
		&(hook->textures[SOUTH].size_line), &(hook->textures[SOUTH].endian));
	hook->textures[EAST].img = mlx_xpm_file_to_image(hook->mlx_vars->mlx_ptr,
		IMG2_PATH, &(hook->textures[EAST].w),
		&(hook->textures[EAST].h));
	mlx_get_data_addr(hook->textures[EAST].img, hook->textures[EAST].bpp,
		&(hook->textures[EAST].size_line), &(hook->textures[EAST].endian));
	hook->textures[WEST].img = mlx_xpm_file_to_image(hook->mlx_vars->mlx_ptr,
		IMG3_PATH, &(hook->textures[WEST].w),
		&(hook->textures[WEST].h));
	mlx_get_data_addr(hook->textures[WEST].img, hook->textures[WEST].bpp,
		&(hook->textures[WEST].size_line), &(hook->textures[WEST].endian));
}
