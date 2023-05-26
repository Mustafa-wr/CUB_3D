/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:01:21 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/22 22:36:18 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_nl_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static int	walls_check(t_cub3d *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->path[i])
	{
		if (m->path[i][0] != '1' && m->path[i][0] != ' ' && \
			m->path[i][0] != '\0')
			return (0);
		i++;
	}
	i--;
	while (m->path[i][j])
	{
		if (m->path[i][j] == '0')
			return (0);
		j++;
	}
	return (1);
}

int	validation(t_cub3d *map)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (map->path[i])
	{
		tmp = ft_nl_strlen(map->path[i]);
		if (tmp)
			tmp--;
		while (map->path[i][tmp] && map->path[i][tmp] == ' ' && tmp > 0)
			tmp--;
		if (map->path[i][tmp] != '1' && \
				map->path[i][tmp] != ' ' && map->path[i][tmp] != '\0')
			return (free_all(map), ft_putendl_fd("Error\nincorrect", 2), 0);
		i++;
	}
	if (!walls_check(map))
		return (free_all(map), ft_putendl_fd("Error\nincorrect", 2), 0);
	return (1);
}

static int	string_isempty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (2);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		return (!str[i]);
	}
	return (1);
}

int	empty_line(t_cub3d *line)
{
	int	i;

	i = 0;
	while (line->path[i])
	{
		if (string_isempty(line->path[i]))
		{
			while (string_isempty(line->path[i]) == 1)
				i++;
			if (!string_isempty(line->path[i]))
				return (free_all(line), ft_putendl_fd("Error", 2), 0);
		}
		if (line->path[i])
			i++;
	}
	return (1);
}