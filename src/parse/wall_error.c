/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:12:30 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/10 16:40:49 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	check_dhelper(t_cub3d *t, t_vars *v)
{
	if (ft_strncmp(t->map[v->i] + v->j, "NO", 2) == 0)
		v->flag++;
	else if (ft_strncmp(t->map[v->i] + v->j, "SO", 2) == 0)
		v->flag++;
	else if (ft_strncmp(t->map[v->i] + v->j, "WE", 2) == 0)
		v->flag++;
	else if (ft_strncmp(t->map[v->i] + v->j, "EA", 2) == 0)
		v->flag++;
	else if (ft_strncmp(t->map[v->i] + v->j, "C", 1) == 0)
		v->flag++;
	else if (ft_strncmp(t->map[v->i] + v->j, "F", 1) == 0)
		v->flag++;
	else
		return (0);
	return (1);
}

int	check_dup(t_cub3d *t)
{
	t_vars	v;

	v.flag = 0;
	v.i = 0;
	// v.j = 0;
	while (t->map[v.i])
	{
		v.j = 0;
		while (t->map[v.i][v.j] && t->map[v.i][v.j] == ' ')
			v.j++;
		if (t->map[v.i][v.j] == '\0')
		{
			v.i++;
			continue ;
		}
		if (t->map[v.i][v.j] == '1')
			break ;
		if (!check_dhelper(t, &v))
			return (0);
		v.i++;
	}
	return (v.flag == 6);
}
