/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:26 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/20 23:01:02 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "get_next_line.h"
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

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


/*********************        parsing         ********************/
int		store_the_rpg(t_cub3d *map);
int		init_textures(t_cub3d *t);
void	free_strings(char **av);

#endif