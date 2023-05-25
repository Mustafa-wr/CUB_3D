/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:21:18 by bammar            #+#    #+#             */
/*   Updated: 2023/05/25 19:02:59 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "hashtable/ht.h"
# include "enums.h"

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
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	x3;
	double	y3;
	double	x4;
	double	y4;
	double	denominator;
	double	t;
	double	u;
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
	int		width2;
	int		height2;
	float	*d;
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

typedef struct s_wall
{
	t_point	start;
	t_point	end;
	bool	hide;
}	t_wall;

typedef struct s_ray
{
	t_vec	ray;
	t_point	collision;
	double	dist;
	t_side	side;
}	t_ray;

typedef struct s_tex
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
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
	t_wall			*walls;
	int				wall_count;
	t_ray			*res;
	t_tex			*textures;
}	t_hook_vars;

typedef struct s_init
{
	t_mlx_vars	mlx;
	t_hook_vars	hook;
	t_cub3d		game;
	t_vec		player;
	t_tex		texs[4];
	t_pressed	pressed_keys;
}	t_init;

#endif
