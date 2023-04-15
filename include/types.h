/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:56:10 by bammar            #+#    #+#             */
/*   Updated: 2023/04/12 03:14:46 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_vars
{
	int	i;
	int	j;
	int	len;
	int	flag;
	int	tmp;
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
	float *d;
}	t_cub3d;

typedef struct s_mlx_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*main_img;
}	t_mlx_vars;

typedef struct s_point
{
	float	x;
	float	y;
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
}	t_hook_vars;

// typedef struct	s_ray
// {
// 	float start[2];
// 	float end[2];
// 	float ra;
// 	char dir;
// }				t_ray;

// typedef struct	s_ray_offset
// {
// 	float x;
// 	float y;
// }				t_ray_offset;

#endif
