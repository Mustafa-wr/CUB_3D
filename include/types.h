/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:56:10 by bammar            #+#    #+#             */
/*   Updated: 2023/03/25 02:15:04 by bammar           ###   ########.fr       */
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
	float	angle;
}	t_vec;

typedef struct s_hook_vars
{
	t_mlx_vars		*mlx_vars;
	t_vec			*player;
}	t_hook_vars;

#endif