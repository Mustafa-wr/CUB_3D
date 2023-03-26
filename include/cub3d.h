/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:26 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/25 16:15:43 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"
# include <math.h>
# include "enums.h"
# include "defines.h"
# include "types.h"

/*********************        Parsing         ********************/
int		store_the_rpg(t_cub3d *map);
int		init_textures(t_cub3d *t);
void	free_strings(char **av);
int	  main_parse(t_cub3d *cub, int ac, char **av);

/*********************       Rendering         ********************/
void	render_pixel(void *img, t_point p1, int color);
void	draw_line(void *img, t_point p1, t_point p2, int color);
void	draw_rect(void *img, t_point s, t_size size, int color);

int		temp_exit(t_hook_vars *hook_vars);
int		key_hook(int keycode, t_hook_vars *hook_vars);
void	clear_img(void *img, int width, int height);
void	draw2d(t_hook_vars *hook_vars); // remove later
void	move_by_key(int keycode, t_vec *vec);

#endif
