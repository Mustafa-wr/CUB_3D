/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:26 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/24 21:24:12 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LOCAL ENDIAN = 0

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"
# include <math.h>
# include "enums.h"

# define SWIDTH 500
# define SHEIGHT 500
# define PNAME "cub3d"
# define MAINIMG "assets/500black.xpm"
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
	int		height;
	int		width;
}	t_mlx_vars;


typedef struct s_hook_vars
{
	t_mlx_vars		*mlx_vars;
}	t_hook_vars;

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


typedef struct s_color		t_color;
struct s_color
{
	double	r;
	double	g;
	double	b;
	double	a;
};

/*********************        Parsing         ********************/
int		store_the_rpg(t_cub3d *map);
int		init_textures(t_cub3d *t);
void	free_strings(char **av);

/*********************       Rendering         ********************/
void	render_pixel(void *img, t_point p1, int color);
void	draw_line(void *img, t_point p1, t_point p2, int color);
void	draw_rect(void *img, t_point s, t_size size, int color);

#endif