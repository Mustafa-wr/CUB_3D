/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:02:28 by bammar            #+#    #+#             */
/*   Updated: 2023/05/20 16:57:43 by bammar           ###   ########.fr       */
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

	if (p1.x > SWIDTH - 1 || p1.y > SHEIGHT - 1 || p1.x < 0 || p1.y < 0)
		return ;
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	index = (((int)p1.y) * size_line) + (((int)p1.x) * (bpp / 8));
	data[index] = color & 0xFF;
	data[index + 1] = (color >> 8) & 0xFF;
	data[index + 2] = (color >> 16) & 0xFF;
}
