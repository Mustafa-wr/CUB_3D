/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:21:18 by bammar            #+#    #+#             */
/*   Updated: 2023/05/17 18:21:32 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include "hashtable/ht.h"
#include "enums.h"

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
	char	*cieling_tmp;
	char	*floor_tmp;
	int		*floor;
	int		*cieling;
	int		pos[2];
	int		y;
	int		x;
	int		width;
	int		height;
	float 	*d;
}	t_cub3d;

typedef struct s_mlx_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*main_img;
}	t_mlx_vars;

typedef struct s_pressed
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	right;
	bool	left;
}	t_pressed; 

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

typedef struct s_map_pos
{
	int	x;
	int	y;
}	t_map_pos;

typedef struct s_vec
{
	t_point	p;
	double	angle;
}	t_vec;

typedef struct s_bound
{
	t_point	start;
	t_point	end;
}	t_bound;

typedef struct s_ray
{
	t_vec	ray;
	t_point	collision;
	double	dist;
	t_side	side;
}	t_ray;

typedef struct s_tex
{
	char	*data;
	int		bpp;
	int		endian;
	int		w;
	int		h;
}	t_tex;

typedef struct s_hook_vars
{
	t_mlx_vars		*mlx_vars;
	t_vec			*player;
	t_pressed		*keys;
	t_cub3d			*game;
	int				big_width;
	int				big_height;
	int				side_length;
	t_bound			*bounds;
	int				bound_count;
	t_ray			*res;
	t_tex			*textures;
}	t_hook_vars;


#endif
