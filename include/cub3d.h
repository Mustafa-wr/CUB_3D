/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:26 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/22 22:08:43 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"
# include <math.h>
# include "enums.h"
# include "defines.h"
# include "types.h"

/*********************        Parsing         ********************/
int		store_the_rgb(t_cub3d *map);
int		init_textures(t_cub3d *t);
int		init_map(t_cub3d *map, char *k);
int		check_and_init_the_path(t_cub3d *p);
int		main_parse(t_cub3d *cub, int ac, char **av);
int		validation(t_cub3d *map);
void	free_strings(char **av);
void	put_spaces(char **arr);
int		check_for_spaces(t_cub3d *map);
int		valid_path(t_cub3d *p);
void	free_all(t_cub3d *p);
void	free_tools(t_cub3d *p);
int		store_the_cieling(t_cub3d *map, t_vars *v);
int		store_the_floor(t_cub3d *map, t_vars *v);
int		check_dup(t_cub3d *t);

// float	calc_rays(t_ray *ray, t_cub3d *map, int x, int y);
// float *cast_rays(float player_x, float player_y, float player_angle, char **map, int map_width, int map_height);

/*********************       Rendering         ********************/
void	render_pixel(void *img, t_point p1, int color);
void	draw_line(void *img, t_point p1, t_point p2, int color);
void	draw_rect(void *img, t_point s, t_size size, int color);

/* UTILS */
double	angle(double rad);
void	side_length_init(t_hook_vars *hook);
double	dist(t_point p1, t_point p2);
int		rgb2hex(int *colors);
void	bounds_init(t_hook_vars *hook);
void	textures_init(t_hook_vars *hook);

/*
 *	@brief Sends one single ray towrds the given angle.
 *		this is used inside a loop.
 *	@return Ray length, or -1 if it hits nothing within the max depth.
*/
void	send_rays(t_hook_vars *hook);
void	draw_ver_line(t_hook_vars *hook, int r);


void	draw2d(t_hook_vars *hook_vars); // remove later
int		game_exit(t_hook_vars *hook_vars);
int		pressed(int keycode, t_hook_vars *hook_vars);
int		released(int keycode, t_hook_vars *hook_vars);
int		update(t_hook_vars *hook_vars);
void	clear_img(void *img, int height, int width);

void	move_by_key(int keycode, t_vec *vec, int width, int height);

#endif
