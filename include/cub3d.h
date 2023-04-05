/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:26 by mradwan           #+#    #+#             */
/*   Updated: 2023/04/05 22:05:16 by mradwan          ###   ########.fr       */
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

/*********************       Rendering         ********************/
void	render_pixel(void *img, t_point p1, int color);
void	draw_line(void *img, t_point p1, t_point p2, int color);
void	draw_rect(void *img, t_point s, t_size size, int color);

int		game_exit(t_hook_vars *hook_vars);
int		pressed(int keycode, t_hook_vars *hook_vars);
int		released(int keycode, t_hook_vars *hook_vars);
int		update(t_hook_vars *hook_vars);
void	clear_img(void *img, int width, int height);
void	draw2d(t_hook_vars *hook_vars); // remove later
void	move_by_key(int keycode, t_vec *vec);

#endif
