/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:21:18 by bammar            #+#    #+#             */
/*   Updated: 2023/04/27 14:58:40 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include "hashtable/ht.h"
typedef struct s_vars
{
	int		i;
	int		j;
	int		len;
	int		flag;
	int		flag2;
	int		tmp;
	int		c;
	int		max_len;
	int		num_spaces;
	char	*new_str;
	char	*sub;
}	t_vars;

typedef struct s_cub3d
{
	char	**map;
	char	**path;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*ceiling_tmp;
	char	*floor_tmp;
	int		*floor;
	int		*cieling;
	int		y;
	int		x;
	int		width;
	int		height;
	int		pos[2];
	float 	*d;
}	t_cub3d;

typedef struct s_mlx_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*main_img;
}	t_mlx_vars;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_size
{
	int	width;
	int	height;
}	t_size;

typedef struct s_vec
{
	t_point	p;
	double	angle;
}	t_vec;

typedef struct s_hook_vars
{
	t_mlx_vars		*mlx_vars;
	t_vec			*player;
	t_ht        	*map;
	t_ht			*keys;
	t_cub3d			*game;
}	t_hook_vars;

typedef struct s_raycast_res
{
	double length;
	int side;
} t_raycast_res;

// typedef struct	s_ray_offset
// {
// 	float x;
// 	float y;
// }				t_ray_offset;

#endif
