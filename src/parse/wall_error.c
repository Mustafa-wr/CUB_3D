/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:12:30 by mradwan           #+#    #+#             */
/*   Updated: 2023/04/23 18:11:14 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	wall_error(t_cub3d *map, t_vars *v)
{
	v->tmp = v->j;
	while (map->path[v->i][v->tmp] == ' ')
		v->tmp++;
	if (map->path[v->i][v->tmp] != '1' && map->path[v->i][v->tmp] != '\0' && \
		map->path[v->i][v->tmp] != '\n')
		return (free_all(map), ft_putendl_fd("Error", 2), 0);
	v->tmp = v->j;
	while (map->path[v->i][v->tmp] == ' ' && v->tmp > 0)
		v->tmp--;
	if (map->path[v->i][v->tmp] != '1' && v->tmp != 0)
		return (free_all(map), ft_putendl_fd("Error", 2), 0);
	return (1);
}

int	check_for_spaces(t_cub3d *map)
{
	t_vars	v;

	v.i = 0;
	v.j = 0;
	v.tmp = 0;
	while (map->path[v.i])
	{
		v.j = 0;
		while (map->path[v.i][v.j])
		{
			if (map->path[v.i][v.j] == ' ')
			{
				if (!wall_error(map, &v))
					return (0);
			}
			v.j++;
		}
		v.i++;
	}
	return (1);
}

int	valid_path(t_cub3d *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p->path[i])
	{
		j = 0;
		while (p->path[i][j])
		{
			if (p->path[i + 1] && i > 0)
			{
				if (p->path[i][j] == '0')
					if (p->path[i + 1][j] == ' ')
						return (free_all(p), ft_putendl_fd("Error", 2), 0);
				if (p->path[i][j] == '0')
					if (p->path[i - 1][j] == ' ')
						return (free_all(p), ft_putendl_fd("Error", 2), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}