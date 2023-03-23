/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:02:28 by bammar            #+#    #+#             */
/*   Updated: 2023/03/24 02:02:44 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_pixel(void *img, t_point p1, int color)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		index;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	index = ((int)p1.y * size_line) + ((int)p1.x * (bpp / 8));
	data[index] = color & 0xFF;
	data[index + 1] = (color >> 8) & 0xFF;
	data[index + 2] = (color >> 16) & 0xFF;
}
