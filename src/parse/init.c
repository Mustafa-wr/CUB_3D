/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:46:05 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/22 22:34:02 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	calcu_map(t_cub3d *map, char *k)
{
	int		fd;
	char	*line;

	fd = open(k, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nfile error", 2), 0);
	line = get_next_line(fd);
	free(line);
	map->y = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		map->y++;
	}
	close(fd);
	map->map = malloc(sizeof(char *) * (map->y + 1));
	if (!map->map)
		return (0);
	return (1);
}

int	init_map(t_cub3d *map, char *k)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if (!calcu_map(map, k))
		return (0);
	fd = open(k, O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < map->y)
	{
		line = get_next_line(fd);
		map->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	map->map[i] = NULL;
	i = 0;
	close(fd);
	return (1);
}

static int	last_wall(t_cub3d *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p->path[i])
		i++;
	i--;
	while (p->path[i][j])
	{
		if (p->path[i][j] != ' ' && p->path[i][j] != '1')
			return (free_all(p), ft_putendl_fd("Error\nincorrect", 2), 0);
		j++;
	}
	return (1);
}

static int	unaccept(char c)
{
	return (c == '0' || c == 'N' || c == 'E' || c == 'S' || c == 'W');
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
				if (unaccept(p->path[i][j]) && p->path[i + 1][j] == ' ')
					return (free_all(p), \
						ft_putendl_fd("Error\nincorrect", 2), 0);
				if (unaccept(p->path[i][j]) && p->path[i - 1][j] == ' ')
					return (free_all(p), \
						ft_putendl_fd("Error\nincorrect", 2), 0);
			}
			j++;
		}
		i++;
	}
	return (last_wall(p));
}
