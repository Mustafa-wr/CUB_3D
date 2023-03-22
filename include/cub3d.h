/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:26 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/22 22:38:22 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"

#ifdef Linux
typedef enum key_map
{
	ON_DESTROY = 17,
	ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363,
	KEY_LEFT = 65361,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
}					t_key_map;
#else
typedef enum key_map
{
	ON_DESTROY = 17,
	ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_RIGHT = 124,
	KEY_LEFT = 123,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
}					t_key_map;
#endif
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
	void			*mlx_ptr;
	void			*win_ptr;
}	t_mlx_vars;


typedef struct s_hook_vars
{
	t_mlx_vars		*mlx_vars;
}	t_hook_vars;


/*********************        parsing         ********************/
int		store_the_rpg(t_cub3d *map);
int		init_textures(t_cub3d *t);
void	free_strings(char **av);

#endif