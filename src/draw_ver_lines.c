/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:50:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/22 22:39:57 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Never changed image pixels, so only one image copy is needed.
static int	get_pixel(t_tex *tex, int x, int y)
{
	int			index;
	int			*data;

	index = ((y * tex->size_line) + (x * (tex->bpp / 8)));
	data = (int *)(tex->data + index);
	return (*data);
}

/**
 * @brief draws the vertical lines
 * @param hook_vars
 */
void	draw_ver_line(t_hook_vars *hook, int r)
{
	double	line_height;
	t_ray	ray;
	double	wallX;
	double		texX;
	double	stepY;

	ray = hook->res[r];
	line_height = SHEIGHT / ray.fdist;
	int drawStart = -line_height / 2 + SHEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = line_height / 2 + SHEIGHT / 2;
	if (drawEnd >= SHEIGHT)
		drawEnd = SHEIGHT - 1;
	if (ray.side % 2 == 0)
		wallX = hook->player->p.y + ray.fdist * sin(ray.ray.angle);
	else
	 	wallX = hook->player->p.x + ray.fdist * cos(ray.ray.angle);
	wallX -= floor(wallX);
	texX = wallX * hook->textures[ray.side].w;
	if (ray.side % 2 == 0 && cos(ray.ray.angle) > 0)
		texX = hook->textures[ray.side].w - texX - 1;
	if (ray.side % 2 != 0 && sin(ray.ray.angle) < 0)
		texX = hook->textures[ray.side].w - texX - 1;
	stepY = 1.0 * hook->textures[ray.side].h / line_height;
	double texPos = (drawStart - SHEIGHT / 2.0 + line_height / 2) * stepY;
	int	y = drawStart - 1;
	while (++y < drawEnd)
	{
		int texY = (int)texPos & (hook->textures[ray.side].h - 1);
		texPos += stepY;
		unsigned int color = get_pixel(&(hook->textures[ray.side]), texX, texY);
		render_pixel(hook->mlx_vars->main_img, (t_point){r, y}, color);
	}
}
